// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gaemi_interfaces:msg/MonoCameraArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaemi_interfaces/msg/mono_camera_array.h"


#ifndef GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__STRUCT_H_
#define GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/MonoCameraArray in the package gaemi_interfaces.
typedef struct gaemi_interfaces__msg__MonoCameraArray
{
  sensor_msgs__msg__Image__Sequence images;
} gaemi_interfaces__msg__MonoCameraArray;

// Struct for a sequence of gaemi_interfaces__msg__MonoCameraArray.
typedef struct gaemi_interfaces__msg__MonoCameraArray__Sequence
{
  gaemi_interfaces__msg__MonoCameraArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gaemi_interfaces__msg__MonoCameraArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__STRUCT_H_
