#pragma once

#include <memory>
#include <map>
#include <mutex>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <image_transport/image_transport.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include "vision_interface/msg/detections.hpp"

#include "vision_interface/msg/line_segments.hpp"
#include "vision_interface/msg/cal_param.hpp"
#include "vision_interface/msg/ball.hpp"

#include <yaml-cpp/yaml.h>

#include "booster_vision/base/intrin.h"
#include "booster_vision/base/pose.h"

#include "booster_vision/color_classifier.hpp"

namespace booster_vision {

class DataLogger;
class DataSyncer;
class PoseEstimator;
class YoloV8Detector;
class YoloV8Segmentor;
class SyncedDataBlock;

class VisionNode : public rclcpp::Node {
public:
    VisionNode(const std::string &node_name, const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
    ~VisionNode() = default;

    void Init(const std::string &cfg_template_path, const std::string &cfg_path, const std::string &cfg_user_path = "");
    void ColorCallback(const sensor_msgs::msg::Image::ConstSharedPtr &msg);
    void CompressedColorCallback(const sensor_msgs::msg::CompressedImage::SharedPtr msg);
    void SegmentationCallback(const sensor_msgs::msg::Image::ConstSharedPtr &msg);
    void CompressedSegmentationCallback(const sensor_msgs::msg::CompressedImage::SharedPtr msg);
    void DepthCallback(const sensor_msgs::msg::Image::ConstSharedPtr &msg);
    void CompressedDepthCallback(const sensor_msgs::msg::CompressedImage::SharedPtr msg);
    void PoseTFCallBack(const geometry_msgs::msg::TransformStamped::SharedPtr msg);
    void PoseCallBack(const geometry_msgs::msg::Pose::SharedPtr msg);
    void CalParamCallback(const vision_interface::msg::CalParam::SharedPtr msg);
    void CameraInfoCallback(const sensor_msgs::msg::CameraInfo::SharedPtr msg);
    void ColorPickerCommandCallback(const std_msgs::msg::String::SharedPtr msg);
    void ColorPickerPointCallback(const geometry_msgs::msg::PointStamped::SharedPtr msg);
    void ProcessData(SyncedDataBlock &synced_data, vision_interface::msg::Detections &detections);
    void ProcessSegmentationData(SyncedDataBlock &synced_data, vision_interface::msg::LineSegments &field_line_segs_msg);

private:
    bool ApplyColorPick(const std::string &label, int x, int y, int radius, int h_tolerance, int s_tolerance, int v_tolerance, bool save);
    bool SaveRobotColorConfig();
    void PublishColorPickerStatus(const std::string &status);

    bool use_depth_ = false;
    bool show_det_ = false;
    bool show_seg_ = false;
    bool save_data_ = false;
    bool save_depth_ = false;
    bool offline_mode_ = false;
    std::string detection_model_path;
    std::string segmentation_model_path;

    int save_cnt_ = 0;
    int save_every_n_frame_ = 0;

    std::string color_topic_;
    std::string depth_topic_;
    std::string intrin_topic_;
    std::string img_log_path_;
    std::string team_color_ = "red";
    std::string cfg_save_path_;
    std::string active_color_pick_label_ = "Teammate";

    Intrinsics intr_;
    Pose p_eye2head_;
    Pose p_headprime2head_;
    Pose p_previous_head2base_;
    float z_compensation_ = 0;
    int line_segment_area_threshold_ = 10; // threshold for line segment detection

    // post processing
    bool enable_post_process_ = false;
    bool single_ball_assumption_ = false;
    std::vector<std::string> classnames_;
    // std::vector<float> duration_list_;
    // std::vector<std::string> duration_name_list_;
    std::map<std::string, float> confidence_map_;
    // std::string profiler_log_path_;
    // bool first_write_profiler_log_ = true;


    std::shared_ptr<rclcpp::Node> nh_;
    rclcpp::Publisher<vision_interface::msg::Detections>::SharedPtr detection_pub_;
    rclcpp::Publisher<vision_interface::msg::LineSegments>::SharedPtr field_line_pub_;
    rclcpp::Publisher<vision_interface::msg::Ball>::SharedPtr ball_pub_;

    image_transport::Publisher detection_img_pub_;
    image_transport::Publisher segmentation_img_pub_;

    rclcpp::Publisher<geometry_msgs::msg::TransformStamped>::SharedPtr pose_tf_pub_;
    rclcpp::Subscription<geometry_msgs::msg::TransformStamped>::SharedPtr pose_tf_sub_;

    std::shared_ptr<image_transport::ImageTransport> it_;
    image_transport::Subscriber color_sub_;
    image_transport::Subscriber depth_sub_;
    image_transport::Subscriber color_seg_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr compressed_color_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr compressed_depth_sub_;
    rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr compressed_color_seg_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr pose_sub_;
    rclcpp::Subscription<vision_interface::msg::CalParam>::SharedPtr calParam_sub_; // Sub for calibration params
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr color_picker_command_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr color_picker_point_sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr color_picker_status_pub_;

    rclcpp::CallbackGroup::SharedPtr callback_group_sub_1_;
    rclcpp::CallbackGroup::SharedPtr callback_group_sub_2_;
    rclcpp::CallbackGroup::SharedPtr callback_group_sub_3_;
    rclcpp::CallbackGroup::SharedPtr callback_group_sub_4_;

    std::shared_ptr<ColorClassifier> color_classifier_;
    cv::Mat latest_color_image_;
    std::mutex color_picker_mutex_;

    std::shared_ptr<DataLogger> data_logger_;
    std::shared_ptr<DataSyncer> data_syncer_;
    std::shared_ptr<DataSyncer> seg_data_syncer_;
    std::shared_ptr<YoloV8Detector> detector_;
    std::shared_ptr<YoloV8Segmentor> segmentor_;
    std::shared_ptr<PoseEstimator> pose_estimator_;
    std::map<std::string, std::shared_ptr<PoseEstimator>> pose_estimator_map_;
    
    YAML::Node config_node_;  // Store config for recreating pose estimators
};

} // namespace booster_vision
