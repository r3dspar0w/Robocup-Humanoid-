#include "booster_vision/model/detector.h"

#include <stdexcept>
#include <filesystem>
#include <iomanip>
#include <sstream>

#ifdef NO_CUDA
#include "booster_vision/model/onnx/detection_impl.h"
#else
#include "booster_vision/model/trt/impl.h"
#endif

namespace booster_vision {

const std::vector<std::string> YoloV8Detector::kClassLabels{"Ball", "Goalpost", "Person", "LCross",
                                                            "TCross", "XCross", "PenaltyPoint", "Opponent", "BRMarker"};

std::shared_ptr<YoloV8Detector> YoloV8Detector::CreateYoloV8Detector(const YAML::Node &node, const std::string model_path_override) {
    try {        
        std::string model_path = model_path_override.empty() ? node["model_path"].as<std::string>() : model_path_override;
        float conf_thresh = node["confidence_threshold"].as<float>();
        float nms_thresh = node["nms_threshold"].as<float>();

        std::shared_ptr<YoloV8Detector> detector_ptr = nullptr;
        #ifdef NO_CUDA
        // Use ONNX when CUDA is not available
        detector_ptr = std::shared_ptr<YoloV8Detector>(new YoloV8DetectorONNX(model_path));
        #else
        // Use TensorRT when CUDA is available
        detector_ptr = std::shared_ptr<YoloV8Detector>(new YoloV8DetectorTRT(model_path));
        #endif
        if (detector_ptr) {
            detector_ptr->setConfidenceThreshold(conf_thresh);
            detector_ptr->setNMSThreshold(nms_thresh);
        }
        return detector_ptr;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

cv::Mat YoloV8Detector::DrawDetection(const cv::Mat &img, const std::vector<DetectionRes> &detections) {
    // Curated HSV-based stable palette — one vivid color per class (BGR order)
    static const std::vector<cv::Scalar> kPalette = {
        cv::Scalar(  0, 200, 255),  // Ball        — orange
        cv::Scalar(255, 200,   0),  // Goalpost    — cyan-blue
        cv::Scalar( 80, 255,  80),  // Person      — lime green
        cv::Scalar(255,  80, 200),  // LCross      — pink-magenta
        cv::Scalar( 50, 180, 255),  // TCross      — amber
        cv::Scalar(255,  80,  80),  // XCross      — sky blue
        cv::Scalar(180, 255,  80),  // PenaltyPoint— yellow-green
        cv::Scalar( 80,  80, 255),  // Opponent    — red
        cv::Scalar(200, 200, 200),  // BRMarker    — light gray
    };
    auto get_color = [&](int class_id) -> cv::Scalar {
        return kPalette[class_id % static_cast<int>(kPalette.size())];
    };

    cv::Mat img_out = img.clone();
    for (const auto &detection : detections) {
        const cv::Rect &bbox = detection.bbox;
        cv::Scalar color = get_color(detection.class_id);
        const std::string class_label = detection.class_name.empty() ? kClassLabels[detection.class_id] : detection.class_name;

        // — main bounding box (2 px thick) —
        cv::rectangle(img_out, bbox, color, 2);

        // — corner bracket accents (L-shaped tick marks) —
        int clen = std::min(12, std::min(bbox.width, bbox.height) / 4);
        int cx = bbox.x, cy = bbox.y, cw = bbox.width, ch = bbox.height;
        auto drawCorner = [&](cv::Point p, int dx, int dy) {
            cv::line(img_out, p, p + cv::Point(dx * clen, 0), color, 3);
            cv::line(img_out, p, p + cv::Point(0, dy * clen), color, 3);
        };
        drawCorner({cx,      cy},      1,  1);
        drawCorner({cx+cw,   cy},     -1,  1);
        drawCorner({cx,      cy+ch},   1, -1);
        drawCorner({cx+cw,   cy+ch},  -1, -1);

        // — confidence bar (bottom of bbox, filled) —
        int bar_h = 4;
        int bar_w = static_cast<int>(bbox.width * detection.confidence);
        cv::rectangle(img_out, cv::Rect(bbox.x, bbox.y + bbox.height - bar_h, bbox.width, bar_h),
                      cv::Scalar(60, 60, 60), cv::FILLED);
        cv::rectangle(img_out, cv::Rect(bbox.x, bbox.y + bbox.height - bar_h, bar_w, bar_h),
                      color, cv::FILLED);

        // — label pill (filled rounded rectangle behind text) —
        std::stringstream ss;
        ss << class_label << " "
           << std::fixed << std::setprecision(1) << detection.confidence * 100.0f << "%";
        std::string label = ss.str();
        int baseline = 0;
        double font_scale = 0.45;
        int font_thickness = 1;
        cv::Size text_sz = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, font_scale, font_thickness, &baseline);
        int pad = 3;
        int lx = bbox.x;
        int ly = bbox.y - text_sz.height - 2 * pad;
        if (ly < 0) ly = bbox.y + 1;  // flip below if out of frame
        cv::rectangle(img_out,
                      cv::Rect(lx, ly, text_sz.width + 2 * pad, text_sz.height + 2 * pad),
                      color, cv::FILLED);
        cv::putText(img_out, label,
                    cv::Point(lx + pad, ly + text_sz.height + pad - 1),
                    cv::FONT_HERSHEY_SIMPLEX, font_scale,
                    cv::Scalar(0, 0, 0), font_thickness, cv::LINE_AA);
    }
    return img_out;
}

} // namespace booster_vision
