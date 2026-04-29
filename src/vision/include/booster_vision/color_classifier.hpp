#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <yaml-cpp/yaml.h>

namespace booster_vision {
class ColorClassifier {
public:
    ColorClassifier() = default;
    ~ColorClassifier() = default;

    void Init(const YAML::Node &node) {
        class_bounds_.clear();
        if (node["red_bounds"]) {
            red_bounds_.clear();
            for (const auto &bound : node["red_bounds"]) {
                if (bound.size() != 6) {
                    std::cerr << "Invalid red bounds size: " << bound.size() << std::endl;
                    continue;
                }
                red_bounds_.emplace_back(
                    cv::Scalar(bound[0].as<int>(), bound[1].as<int>(), bound[2].as<int>()),
                    cv::Scalar(bound[3].as<int>(), bound[4].as<int>(), bound[5].as<int>()));
            }
        }

        if (node["blue_bounds"]) {
            blue_bounds_.clear();
            for (const auto &bound : node["blue_bounds"]) {
                if (bound.size() != 6) {
                    std::cerr << "Invalid blue bounds size: " << bound.size() << std::endl;
                    continue;
                }
                blue_bounds_.emplace_back(
                    cv::Scalar(bound[0].as<int>(), bound[1].as<int>(), bound[2].as<int>()),
                    cv::Scalar(bound[3].as<int>(), bound[4].as<int>(), bound[5].as<int>()));
            }
        }

        if (node["white_bounds"]) {
            white_bounds_.clear();
            for (const auto &bound : node["white_bounds"]) {
                if (bound.size() != 6) {
                    std::cerr << "Invalid white bounds size: " << bound.size() << std::endl;
                    continue;
                }
                white_bounds_.emplace_back(
                    cv::Scalar(bound[0].as<int>(), bound[1].as<int>(), bound[2].as<int>()),
                    cv::Scalar(bound[3].as<int>(), bound[4].as<int>(), bound[5].as<int>()));
            }
        }

        if (node["green_bounds"]) {
            green_bounds_.clear();
            for (const auto &bound : node["green_bounds"]) {
                if (bound.size() != 6) {
                    std::cerr << "Invalid green bounds size: " << bound.size() << std::endl;
                    continue;
                }
                green_bounds_.emplace_back(
                    cv::Scalar(bound[0].as<int>(), bound[1].as<int>(), bound[2].as<int>()),
                    cv::Scalar(bound[3].as<int>(), bound[4].as<int>(), bound[5].as<int>()));
            }
        }

        if (node["class_bounds"]) {
            for (const auto &item : node["class_bounds"]) {
                const std::string label = item.first.as<std::string>();
                auto &bounds = class_bounds_[label];
                bounds.clear();
                for (const auto &bound : item.second) {
                    if (bound.size() != 6) {
                        std::cerr << "Invalid " << label << " bounds size: " << bound.size() << std::endl;
                        continue;
                    }
                    bounds.emplace_back(
                        cv::Scalar(bound[0].as<int>(), bound[1].as<int>(), bound[2].as<int>()),
                        cv::Scalar(bound[3].as<int>(), bound[4].as<int>(), bound[5].as<int>()));
                }
            }
        }
    }

    std::string Classify(const cv::Mat &input_img) {
        auto [color, mask, counts] = getDominantColorAndMask(input_img);
        return color;
    }

    std::string ClassifyRobotLabel(const cv::Mat &input_img) {
        if (class_bounds_.empty()) {
            return "";
        }

        cv::Mat hsv;
        cv::cvtColor(input_img, hsv, cv::COLOR_BGR2HSV);
        cv::GaussianBlur(hsv, hsv, cv::Size(5, 5), 0);

        std::string best_label;
        int best_count = 0;
        for (const auto &entry : class_bounds_) {
            cv::Mat mask = getColorMask(hsv, entry.second);
            const int count = cv::countNonZero(mask);
            if (count > best_count) {
                best_label = entry.first;
                best_count = count;
            }
        }

        return best_count > 0 ? best_label : "";
    }

    void SetClassBounds(const std::string &label, const std::vector<std::pair<cv::Scalar, cv::Scalar>> &bounds) {
        class_bounds_[label] = bounds;
    }

    cv::Mat getColorMask(const cv::Mat &input_img, const std::vector<std::pair<cv::Scalar, cv::Scalar>> &color_bounds) {
        cv::Mat mask = cv::Mat::zeros(input_img.size(), CV_8UC1);
        for (const auto &bounds : color_bounds) {
            cv::Mat mask_tmp;
            cv::inRange(input_img, bounds.first, bounds.second, mask_tmp);
            cv::bitwise_or(mask, mask_tmp, mask);
        }
        return mask;
    }
    std::tuple<std::string, cv::Mat, std::vector<int>> getDominantColorAndMask(const cv::Mat &input_img) {
        // preprocess
        cv::Mat img = input_img.clone();
        cv::Mat hsv;
        cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
        cv::GaussianBlur(hsv, hsv, cv::Size(5, 5), 0);

        // Create masks for each color
        cv::Mat blue_mask = getColorMask(hsv, blue_bounds_);
        cv::Mat red_mask = getColorMask(hsv, red_bounds_);
        cv::Mat white_mask = getColorMask(hsv, white_bounds_);
        cv::Mat green_mask = getColorMask(hsv, green_bounds_);

        // Count non-zero pixels in each mask
        int red_count = cv::countNonZero(red_mask);
        int blue_count = cv::countNonZero(blue_mask);
        int white_count = cv::countNonZero(white_mask);
        int green_count = cv::countNonZero(green_mask);

        // Determine the dominant color
        cv::Mat mask;
        std::string color = "None";
        if (green_count > ((red_count + blue_count + white_count) * 5)) {
            mask = cv::Mat::zeros(red_mask.size(), CV_8UC1);
        } else if (red_count > blue_count && red_count > white_count) {
            mask = red_mask;
            color = "red";
        } else if (blue_count > red_count && blue_count > white_count) {
            mask = blue_mask;
            color = "blue";
        } else if (white_count > red_count && white_count > blue_count) {
            mask = white_mask;
            color = "white";
        } else {
            mask = cv::Mat::zeros(red_mask.size(), CV_8UC1);
        }

        return {color, mask, {red_count, blue_count, white_count, green_count}};
    }

private:
    std::vector<std::pair<cv::Scalar, cv::Scalar>> red_bounds_ = {
        {cv::Scalar(0, 80, 50), cv::Scalar(20, 255, 255)},
        {cv::Scalar(160, 80, 100), cv::Scalar(179, 255, 255)}};
    std::vector<std::pair<cv::Scalar, cv::Scalar>> blue_bounds_ = {
        {cv::Scalar(100, 140, 50), cv::Scalar(140, 255, 255)}};
    std::vector<std::pair<cv::Scalar, cv::Scalar>> white_bounds_ = {
        {cv::Scalar(0, 0, 180), cv::Scalar(179, 70, 255)}};
    std::vector<std::pair<cv::Scalar, cv::Scalar>> green_bounds_ = {
        {cv::Scalar(30, 45, 45), cv::Scalar(80, 255, 255)}};
    std::map<std::string, std::vector<std::pair<cv::Scalar, cv::Scalar>>> class_bounds_;
};

} // namespace booster_vision
