// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from gaemi_interfaces:msg/MonoCameraArray.idl
// generated code does not contain a copyright notice
#ifndef GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gaemi_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gaemi_interfaces/msg/detail/mono_camera_array__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
bool cdr_serialize_gaemi_interfaces__msg__MonoCameraArray(
  const gaemi_interfaces__msg__MonoCameraArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
bool cdr_deserialize_gaemi_interfaces__msg__MonoCameraArray(
  eprosima::fastcdr::Cdr &,
  gaemi_interfaces__msg__MonoCameraArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t get_serialized_size_gaemi_interfaces__msg__MonoCameraArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t max_serialized_size_gaemi_interfaces__msg__MonoCameraArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
bool cdr_serialize_key_gaemi_interfaces__msg__MonoCameraArray(
  const gaemi_interfaces__msg__MonoCameraArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t get_serialized_size_key_gaemi_interfaces__msg__MonoCameraArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t max_serialized_size_key_gaemi_interfaces__msg__MonoCameraArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gaemi_interfaces, msg, MonoCameraArray)();

#ifdef __cplusplus
}
#endif

#endif  // GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
