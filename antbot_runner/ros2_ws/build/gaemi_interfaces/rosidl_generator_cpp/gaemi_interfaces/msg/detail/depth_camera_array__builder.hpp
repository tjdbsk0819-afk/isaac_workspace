// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gaemi_interfaces:msg/DepthCameraArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaemi_interfaces/msg/depth_camera_array.hpp"


#ifndef GAEMI_INTERFACES__MSG__DETAIL__DEPTH_CAMERA_ARRAY__BUILDER_HPP_
#define GAEMI_INTERFACES__MSG__DETAIL__DEPTH_CAMERA_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gaemi_interfaces/msg/detail/depth_camera_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gaemi_interfaces
{

namespace msg
{

namespace builder
{

class Init_DepthCameraArray_depth_images
{
public:
  explicit Init_DepthCameraArray_depth_images(::gaemi_interfaces::msg::DepthCameraArray & msg)
  : msg_(msg)
  {}
  ::gaemi_interfaces::msg::DepthCameraArray depth_images(::gaemi_interfaces::msg::DepthCameraArray::_depth_images_type arg)
  {
    msg_.depth_images = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gaemi_interfaces::msg::DepthCameraArray msg_;
};

class Init_DepthCameraArray_color_images
{
public:
  Init_DepthCameraArray_color_images()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DepthCameraArray_depth_images color_images(::gaemi_interfaces::msg::DepthCameraArray::_color_images_type arg)
  {
    msg_.color_images = std::move(arg);
    return Init_DepthCameraArray_depth_images(msg_);
  }

private:
  ::gaemi_interfaces::msg::DepthCameraArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gaemi_interfaces::msg::DepthCameraArray>()
{
  return gaemi_interfaces::msg::builder::Init_DepthCameraArray_color_images();
}

}  // namespace gaemi_interfaces

#endif  // GAEMI_INTERFACES__MSG__DETAIL__DEPTH_CAMERA_ARRAY__BUILDER_HPP_
