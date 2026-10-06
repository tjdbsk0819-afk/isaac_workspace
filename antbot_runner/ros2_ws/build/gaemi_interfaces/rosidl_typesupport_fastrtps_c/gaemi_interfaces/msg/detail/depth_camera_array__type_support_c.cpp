// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gaemi_interfaces:msg/DepthCameraArray.idl
// generated code does not contain a copyright notice
#include "gaemi_interfaces/msg/detail/depth_camera_array__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gaemi_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gaemi_interfaces/msg/detail/depth_camera_array__struct.h"
#include "gaemi_interfaces/msg/detail/depth_camera_array__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "sensor_msgs/msg/detail/image__functions.h"  // color_images, depth_images

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
bool cdr_serialize_sensor_msgs__msg__Image(
  const sensor_msgs__msg__Image * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
bool cdr_deserialize_sensor_msgs__msg__Image(
  eprosima::fastcdr::Cdr & cdr,
  sensor_msgs__msg__Image * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
bool cdr_serialize_key_sensor_msgs__msg__Image(
  const sensor_msgs__msg__Image * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
size_t get_serialized_size_key_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
size_t max_serialized_size_key_sensor_msgs__msg__Image(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gaemi_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();


using _DepthCameraArray__ros_msg_type = gaemi_interfaces__msg__DepthCameraArray;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
bool cdr_serialize_gaemi_interfaces__msg__DepthCameraArray(
  const gaemi_interfaces__msg__DepthCameraArray * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: color_images
  {
    size_t size = ros_message->color_images.size;
    auto array_ptr = ros_message->color_images.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_sensor_msgs__msg__Image(
        &array_ptr[i], cdr);
    }
  }

  // Field name: depth_images
  {
    size_t size = ros_message->depth_images.size;
    auto array_ptr = ros_message->depth_images.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_sensor_msgs__msg__Image(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
bool cdr_deserialize_gaemi_interfaces__msg__DepthCameraArray(
  eprosima::fastcdr::Cdr & cdr,
  gaemi_interfaces__msg__DepthCameraArray * ros_message)
{
  // Field name: color_images
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->color_images.data) {
      sensor_msgs__msg__Image__Sequence__fini(&ros_message->color_images);
    }
    if (!sensor_msgs__msg__Image__Sequence__init(&ros_message->color_images, size)) {
      fprintf(stderr, "failed to create array for field 'color_images'");
      return false;
    }
    auto array_ptr = ros_message->color_images.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_sensor_msgs__msg__Image(cdr, &array_ptr[i]);
    }
  }

  // Field name: depth_images
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->depth_images.data) {
      sensor_msgs__msg__Image__Sequence__fini(&ros_message->depth_images);
    }
    if (!sensor_msgs__msg__Image__Sequence__init(&ros_message->depth_images, size)) {
      fprintf(stderr, "failed to create array for field 'depth_images'");
      return false;
    }
    auto array_ptr = ros_message->depth_images.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_sensor_msgs__msg__Image(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t get_serialized_size_gaemi_interfaces__msg__DepthCameraArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DepthCameraArray__ros_msg_type * ros_message = static_cast<const _DepthCameraArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: color_images
  {
    size_t array_size = ros_message->color_images.size;
    auto array_ptr = ros_message->color_images.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__Image(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: depth_images
  {
    size_t array_size = ros_message->depth_images.size;
    auto array_ptr = ros_message->depth_images.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__Image(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t max_serialized_size_gaemi_interfaces__msg__DepthCameraArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: color_images
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: depth_images
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gaemi_interfaces__msg__DepthCameraArray;
    is_plain =
      (
      offsetof(DataType, depth_images) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
bool cdr_serialize_key_gaemi_interfaces__msg__DepthCameraArray(
  const gaemi_interfaces__msg__DepthCameraArray * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: color_images
  {
    size_t size = ros_message->color_images.size;
    auto array_ptr = ros_message->color_images.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_sensor_msgs__msg__Image(
        &array_ptr[i], cdr);
    }
  }

  // Field name: depth_images
  {
    size_t size = ros_message->depth_images.size;
    auto array_ptr = ros_message->depth_images.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_sensor_msgs__msg__Image(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t get_serialized_size_key_gaemi_interfaces__msg__DepthCameraArray(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DepthCameraArray__ros_msg_type * ros_message = static_cast<const _DepthCameraArray__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: color_images
  {
    size_t array_size = ros_message->color_images.size;
    auto array_ptr = ros_message->color_images.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_sensor_msgs__msg__Image(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: depth_images
  {
    size_t array_size = ros_message->depth_images.size;
    auto array_ptr = ros_message->depth_images.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_sensor_msgs__msg__Image(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gaemi_interfaces
size_t max_serialized_size_key_gaemi_interfaces__msg__DepthCameraArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: color_images
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: depth_images
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_sensor_msgs__msg__Image(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gaemi_interfaces__msg__DepthCameraArray;
    is_plain =
      (
      offsetof(DataType, depth_images) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _DepthCameraArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const gaemi_interfaces__msg__DepthCameraArray * ros_message = static_cast<const gaemi_interfaces__msg__DepthCameraArray *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_gaemi_interfaces__msg__DepthCameraArray(ros_message, cdr);
}

static bool _DepthCameraArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  gaemi_interfaces__msg__DepthCameraArray * ros_message = static_cast<gaemi_interfaces__msg__DepthCameraArray *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_gaemi_interfaces__msg__DepthCameraArray(cdr, ros_message);
}

static uint32_t _DepthCameraArray__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gaemi_interfaces__msg__DepthCameraArray(
      untyped_ros_message, 0));
}

static size_t _DepthCameraArray__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gaemi_interfaces__msg__DepthCameraArray(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DepthCameraArray = {
  "gaemi_interfaces::msg",
  "DepthCameraArray",
  _DepthCameraArray__cdr_serialize,
  _DepthCameraArray__cdr_deserialize,
  _DepthCameraArray__get_serialized_size,
  _DepthCameraArray__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _DepthCameraArray__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DepthCameraArray,
  get_message_typesupport_handle_function,
  &gaemi_interfaces__msg__DepthCameraArray__get_type_hash,
  &gaemi_interfaces__msg__DepthCameraArray__get_type_description,
  &gaemi_interfaces__msg__DepthCameraArray__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gaemi_interfaces, msg, DepthCameraArray)() {
  return &_DepthCameraArray__type_support;
}

#if defined(__cplusplus)
}
#endif
