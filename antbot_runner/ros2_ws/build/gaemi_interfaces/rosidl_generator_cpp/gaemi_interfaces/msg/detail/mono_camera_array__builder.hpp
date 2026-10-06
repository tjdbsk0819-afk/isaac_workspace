// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gaemi_interfaces:msg/MonoCameraArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaemi_interfaces/msg/mono_camera_array.hpp"


#ifndef GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__BUILDER_HPP_
#define GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gaemi_interfaces/msg/detail/mono_camera_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gaemi_interfaces
{

namespace msg
{

namespace builder
{

class Init_MonoCameraArray_images
{
public:
  Init_MonoCameraArray_images()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gaemi_interfaces::msg::MonoCameraArray images(::gaemi_interfaces::msg::MonoCameraArray::_images_type arg)
  {
    msg_.images = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gaemi_interfaces::msg::MonoCameraArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gaemi_interfaces::msg::MonoCameraArray>()
{
  return gaemi_interfaces::msg::builder::Init_MonoCameraArray_images();
}

}  // namespace gaemi_interfaces

#endif  // GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__BUILDER_HPP_
