// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gaemi_interfaces:msg/MonoCameraArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaemi_interfaces/msg/mono_camera_array.hpp"


#ifndef GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__TRAITS_HPP_
#define GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gaemi_interfaces/msg/detail/mono_camera_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'images'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace gaemi_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MonoCameraArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: images
  {
    if (msg.images.size() == 0) {
      out << "images: []";
    } else {
      out << "images: [";
      size_t pending_items = msg.images.size();
      for (auto item : msg.images) {
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
  const MonoCameraArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: images
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.images.size() == 0) {
      out << "images: []\n";
    } else {
      out << "images:\n";
      for (auto item : msg.images) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MonoCameraArray & msg, bool use_flow_style = false)
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
  const gaemi_interfaces::msg::MonoCameraArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  gaemi_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gaemi_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const gaemi_interfaces::msg::MonoCameraArray & msg)
{
  return gaemi_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gaemi_interfaces::msg::MonoCameraArray>()
{
  return "gaemi_interfaces::msg::MonoCameraArray";
}

template<>
inline const char * name<gaemi_interfaces::msg::MonoCameraArray>()
{
  return "gaemi_interfaces/msg/MonoCameraArray";
}

template<>
struct has_fixed_size<gaemi_interfaces::msg::MonoCameraArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gaemi_interfaces::msg::MonoCameraArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gaemi_interfaces::msg::MonoCameraArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__TRAITS_HPP_
