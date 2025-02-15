#ifndef FILTRATION_HPP
#define FILTRATION_HPP
#include <chrono>
#include <memory>
#include "demo_nova_sanctum/srv/filteration.hpp"
#include "demo_nova_sanctum/msg/storage_status.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class Filtration : public rclcpp::Node{
public:
    Filtration();

private:
    void process_water_server_(
        const std::shared_ptr<demo_nova_sanctum::srv::Filteration::Request> request,
        std::shared_ptr<demo_nova_sanctum::srv::Filteration::Response> response);
    void get_waste_(const demo_nova_sanctum::msg::StorageStatus::SharedPtr msg);
    void publish_water_levels();

    rclcpp::Publisher<demo_nova_sanctum::msg::StorageStatus>::SharedPtr storage_status_pub_;
    int status_;
    double waste_water_level_; // Simulate the waste water level
    double clean_water_level_; // Simulate the clean water level
    rclcpp::Subscription<demo_nova_sanctum::msg::StorageStatus>::SharedPtr storage_sub_;
    rclcpp::Service<demo_nova_sanctum::srv::Filteration>::SharedPtr waste_water_process_server_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif  // FILTRATION_HPP
