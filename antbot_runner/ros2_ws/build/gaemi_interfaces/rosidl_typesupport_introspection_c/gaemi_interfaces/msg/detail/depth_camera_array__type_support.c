// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gaemi_interfaces:msg/DepthCameraArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gaemi_interfaces/msg/detail/depth_camera_array__rosidl_typesupport_introspection_c.h"
#include "gaemi_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gaemi_interfaces/msg/detail/depth_camera_array__functions.h"
#include "gaemi_interfaces/msg/detail/depth_camera_array__struct.h"


// Include directives for member types
// Member `color_images`
// Member `depth_images`
#include "sensor_msgs/msg/image.h"
// Member `color_images`
// Member `depth_images`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gaemi_interfaces__msg__DepthCameraArray__init(message_memory);
}

void gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_fini_function(void * message_memory)
{
  gaemi_interfaces__msg__DepthCameraArray__fini(message_memory);
}

size_t gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__size_function__DepthCameraArray__color_images(
  const void * untyped_member)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return member->size;
}

const void * gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_const_function__DepthCameraArray__color_images(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_function__DepthCameraArray__color_images(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__fetch_function__DepthCameraArray__color_images(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__Image * item =
    ((const sensor_msgs__msg__Image *)
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_const_function__DepthCameraArray__color_images(untyped_member, index));
  sensor_msgs__msg__Image * value =
    (sensor_msgs__msg__Image *)(untyped_value);
  *value = *item;
}

void gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__assign_function__DepthCameraArray__color_images(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__Image * item =
    ((sensor_msgs__msg__Image *)
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_function__DepthCameraArray__color_images(untyped_member, index));
  const sensor_msgs__msg__Image * value =
    (const sensor_msgs__msg__Image *)(untyped_value);
  *item = *value;
}

bool gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__resize_function__DepthCameraArray__color_images(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  sensor_msgs__msg__Image__Sequence__fini(member);
  return sensor_msgs__msg__Image__Sequence__init(member, size);
}

size_t gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__size_function__DepthCameraArray__depth_images(
  const void * untyped_member)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return member->size;
}

const void * gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_const_function__DepthCameraArray__depth_images(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_function__DepthCameraArray__depth_images(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__fetch_function__DepthCameraArray__depth_images(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__Image * item =
    ((const sensor_msgs__msg__Image *)
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_const_function__DepthCameraArray__depth_images(untyped_member, index));
  sensor_msgs__msg__Image * value =
    (sensor_msgs__msg__Image *)(untyped_value);
  *value = *item;
}

void gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__assign_function__DepthCameraArray__depth_images(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__Image * item =
    ((sensor_msgs__msg__Image *)
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_function__DepthCameraArray__depth_images(untyped_member, index));
  const sensor_msgs__msg__Image * value =
    (const sensor_msgs__msg__Image *)(untyped_value);
  *item = *value;
}

bool gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__resize_function__DepthCameraArray__depth_images(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  sensor_msgs__msg__Image__Sequence__fini(member);
  return sensor_msgs__msg__Image__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_member_array[2] = {
  {
    "color_images",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaemi_interfaces__msg__DepthCameraArray, color_images),  // bytes offset in struct
    NULL,  // default value
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__size_function__DepthCameraArray__color_images,  // size() function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_const_function__DepthCameraArray__color_images,  // get_const(index) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_function__DepthCameraArray__color_images,  // get(index) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__fetch_function__DepthCameraArray__color_images,  // fetch(index, &value) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__assign_function__DepthCameraArray__color_images,  // assign(index, value) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__resize_function__DepthCameraArray__color_images  // resize(index) function pointer
  },
  {
    "depth_images",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaemi_interfaces__msg__DepthCameraArray, depth_images),  // bytes offset in struct
    NULL,  // default value
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__size_function__DepthCameraArray__depth_images,  // size() function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_const_function__DepthCameraArray__depth_images,  // get_const(index) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__get_function__DepthCameraArray__depth_images,  // get(index) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__fetch_function__DepthCameraArray__depth_images,  // fetch(index, &value) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__assign_function__DepthCameraArray__depth_images,  // assign(index, value) function pointer
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__resize_function__DepthCameraArray__depth_images  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_members = {
  "gaemi_interfaces__msg",  // message namespace
  "DepthCameraArray",  // message name
  2,  // number of fields
  sizeof(gaemi_interfaces__msg__DepthCameraArray),
  false,  // has_any_key_member_
  gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_member_array,  // message members
  gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_init_function,  // function to initialize message memory (memory has to be allocated)
  gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_type_support_handle = {
  0,
  &gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_members,
  get_message_typesupport_handle_function,
  &gaemi_interfaces__msg__DepthCameraArray__get_type_hash,
  &gaemi_interfaces__msg__DepthCameraArray__get_type_description,
  &gaemi_interfaces__msg__DepthCameraArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gaemi_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gaemi_interfaces, msg, DepthCameraArray)() {
  gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_type_support_handle.typesupport_identifier) {
    gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gaemi_interfaces__msg__DepthCameraArray__rosidl_typesupport_introspection_c__DepthCameraArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
