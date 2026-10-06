// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gaemi_interfaces:msg/DepthCameraArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaemi_interfaces/msg/depth_camera_array.hpp"


#ifndef GAEMI_INTERFACES__MSG__DETAIL__DEPTH_CAMERA_ARRAY__TRAITS_HPP_
#define GAEMI_INTERFACES__MSG__DETAIL__DEPTH_CAMERA_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gaemi_interfaces/msg/detail/depth_camera_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'color_images'
// Member 'depth_images'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace gaemi_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DepthCameraArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: color_images
  {
    if (msg.color_images.size() == 0) {
      out << "color_images: []";
    } else {
      out << "color_images: [";
      size_t pending_items = msg.color_images.size();
      for (auto item : msg.color_images) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: depth_images
  {
    if (msg.depth_images.size() == 0) {
      out << "depth_images: []";
    } else {
      out << "depth_images: [";
      size_t pending_items = msg.depth_images.size();
      for (auto item : msg.depth_images) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DepthCameraArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: color_images
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.color_images.size() == 0) {
      out << "color_images: []\n";
    } else {
      out << "color_images:\n";
      for (auto item : msg.color_images) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: depth_images
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.depth_images.size() == 0) {
      out << "depth_images: []\n";
    } else {
      out << "depth_images:\n";
      for (auto item : msg.depth_images) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DepthCameraArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace gaemi_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use gaemi_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gaemi_interfaces::msg::DepthCameraArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  gaemi_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gaemi_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const gaemi_interfaces::msg::DepthCameraArray & msg)
{
  return gaemi_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gaemi_interfaces::msg::DepthCameraArray>()
{
  return "gaemi_interfaces::msg::DepthCameraArray";
}

template<>
inline const char * name<gaemi_interfaces::msg::DepthCameraArray>()
{
  return "gaemi_interfaces/msg/DepthCameraArray";
}

template<>
struct has_fixed_size<gaemi_interfaces::msg::DepthCameraArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gaemi_interfaces::msg::DepthCameraArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gaemi_interfaces::msg::DepthCameraArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAEMI_INTERFACES__MSG__DETAIL__DEPTH_CAMERA_ARRAY__TRAITS_HPP_
