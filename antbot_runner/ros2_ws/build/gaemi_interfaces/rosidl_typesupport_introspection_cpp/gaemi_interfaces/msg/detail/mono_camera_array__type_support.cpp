// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from gaemi_interfaces:msg/MonoCameraArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "gaemi_interfaces/msg/detail/mono_camera_array__functions.h"
#include "gaemi_interfaces/msg/detail/mono_camera_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gaemi_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MonoCameraArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gaemi_interfaces::msg::MonoCameraArray(_init);
}

void MonoCameraArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gaemi_interfaces::msg::MonoCameraArray *>(message_memory);
  typed_message->~MonoCameraArray();
}

size_t size_function__MonoCameraArray__images(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MonoCameraArray__images(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__MonoCameraArray__images(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void fetch_function__MonoCameraArray__images(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::Image *>(
    get_const_function__MonoCameraArray__images(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::Image *>(untyped_value);
  value = item;
}

void assign_function__MonoCameraArray__images(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::Image *>(
    get_function__MonoCameraArray__images(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::Image *>(untyped_value);
  item = value;
}

void resize_function__MonoCameraArray__images(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MonoCameraArray_message_member_array[1] = {
  {
    "images",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaemi_interfaces::msg::MonoCameraArray, images),  // bytes offset in struct
    nullptr,  // default value
    size_function__MonoCameraArray__images,  // size() function pointer
    get_const_function__MonoCameraArray__images,  // get_const(index) function pointer
    get_function__MonoCameraArray__images,  // get(index) function pointer
    fetch_function__MonoCameraArray__images,  // fetch(index, &value) function pointer
    assign_function__MonoCameraArray__images,  // assign(index, value) function pointer
    resize_function__MonoCameraArray__images  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MonoCameraArray_message_members = {
  "gaemi_interfaces::msg",  // message namespace
  "MonoCameraArray",  // message name
  1,  // number of fields
  sizeof(gaemi_interfaces::msg::MonoCameraArray),
  false,  // has_any_key_member_
  MonoCameraArray_message_member_array,  // message members
  MonoCameraArray_init_function,  // function to initialize message memory (memory has to be allocated)
  MonoCameraArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MonoCameraArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MonoCameraArray_message_members,
  get_message_typesupport_handle_function,
  &gaemi_interfaces__msg__MonoCameraArray__get_type_hash,
  &gaemi_interfaces__msg__MonoCameraArray__get_type_description,
  &gaemi_interfaces__msg__MonoCameraArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace gaemi_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gaemi_interfaces::msg::MonoCameraArray>()
{
  return &::gaemi_interfaces::msg::rosidl_typesupport_introspection_cpp::MonoCameraArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gaemi_interfaces, msg, MonoCameraArray)() {
  return &::gaemi_interfaces::msg::rosidl_typesupport_introspection_cpp::MonoCameraArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
