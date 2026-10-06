// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gaemi_interfaces:msg/DepthCameraArray.idl
// generated code does not contain a copyright notice
#include "gaemi_interfaces/msg/detail/depth_camera_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `color_images`
// Member `depth_images`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
gaemi_interfaces__msg__DepthCameraArray__init(gaemi_interfaces__msg__DepthCameraArray * msg)
{
  if (!msg) {
    return false;
  }
  // color_images
  if (!sensor_msgs__msg__Image__Sequence__init(&msg->color_images, 0)) {
    gaemi_interfaces__msg__DepthCameraArray__fini(msg);
    return false;
  }
  // depth_images
  if (!sensor_msgs__msg__Image__Sequence__init(&msg->depth_images, 0)) {
    gaemi_interfaces__msg__DepthCameraArray__fini(msg);
    return false;
  }
  return true;
}

void
gaemi_interfaces__msg__DepthCameraArray__fini(gaemi_interfaces__msg__DepthCameraArray * msg)
{
  if (!msg) {
    return;
  }
  // color_images
  sensor_msgs__msg__Image__Sequence__fini(&msg->color_images);
  // depth_images
  sensor_msgs__msg__Image__Sequence__fini(&msg->depth_images);
}

bool
gaemi_interfaces__msg__DepthCameraArray__are_equal(const gaemi_interfaces__msg__DepthCameraArray * lhs, const gaemi_interfaces__msg__DepthCameraArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // color_images
  if (!sensor_msgs__msg__Image__Sequence__are_equal(
      &(lhs->color_images), &(rhs->color_images)))
  {
    return false;
  }
  // depth_images
  if (!sensor_msgs__msg__Image__Sequence__are_equal(
      &(lhs->depth_images), &(rhs->depth_images)))
  {
    return false;
  }
  return true;
}

bool
gaemi_interfaces__msg__DepthCameraArray__copy(
  const gaemi_interfaces__msg__DepthCameraArray * input,
  gaemi_interfaces__msg__DepthCameraArray * output)
{
  if (!input || !output) {
    return false;
  }
  // color_images
  if (!sensor_msgs__msg__Image__Sequence__copy(
      &(input->color_images), &(output->color_images)))
  {
    return false;
  }
  // depth_images
  if (!sensor_msgs__msg__Image__Sequence__copy(
      &(input->depth_images), &(output->depth_images)))
  {
    return false;
  }
  return true;
}

gaemi_interfaces__msg__DepthCameraArray *
gaemi_interfaces__msg__DepthCameraArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaemi_interfaces__msg__DepthCameraArray * msg = (gaemi_interfaces__msg__DepthCameraArray *)allocator.allocate(sizeof(gaemi_interfaces__msg__DepthCameraArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gaemi_interfaces__msg__DepthCameraArray));
  bool success = gaemi_interfaces__msg__DepthCameraArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gaemi_interfaces__msg__DepthCameraArray__destroy(gaemi_interfaces__msg__DepthCameraArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gaemi_interfaces__msg__DepthCameraArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gaemi_interfaces__msg__DepthCameraArray__Sequence__init(gaemi_interfaces__msg__DepthCameraArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaemi_interfaces__msg__DepthCameraArray * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(gaemi_interfaces__msg__DepthCameraArray)) {
      return false;
    }
    data = (gaemi_interfaces__msg__DepthCameraArray *)allocator.zero_allocate(size, sizeof(gaemi_interfaces__msg__DepthCameraArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gaemi_interfaces__msg__DepthCameraArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gaemi_interfaces__msg__DepthCameraArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gaemi_interfaces__msg__DepthCameraArray__Sequence__fini(gaemi_interfaces__msg__DepthCameraArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gaemi_interfaces__msg__DepthCameraArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gaemi_interfaces__msg__DepthCameraArray__Sequence *
gaemi_interfaces__msg__DepthCameraArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaemi_interfaces__msg__DepthCameraArray__Sequence * array = (gaemi_interfaces__msg__DepthCameraArray__Sequence *)allocator.allocate(sizeof(gaemi_interfaces__msg__DepthCameraArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gaemi_interfaces__msg__DepthCameraArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gaemi_interfaces__msg__DepthCameraArray__Sequence__destroy(gaemi_interfaces__msg__DepthCameraArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gaemi_interfaces__msg__DepthCameraArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gaemi_interfaces__msg__DepthCameraArray__Sequence__are_equal(const gaemi_interfaces__msg__DepthCameraArray__Sequence * lhs, const gaemi_interfaces__msg__DepthCameraArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gaemi_interfaces__msg__DepthCameraArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gaemi_interfaces__msg__DepthCameraArray__Sequence__copy(
  const gaemi_interfaces__msg__DepthCameraArray__Sequence * input,
  gaemi_interfaces__msg__DepthCameraArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(gaemi_interfaces__msg__DepthCameraArray)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(gaemi_interfaces__msg__DepthCameraArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gaemi_interfaces__msg__DepthCameraArray * data =
      (gaemi_interfaces__msg__DepthCameraArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gaemi_interfaces__msg__DepthCameraArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gaemi_interfaces__msg__DepthCameraArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gaemi_interfaces__msg__DepthCameraArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
