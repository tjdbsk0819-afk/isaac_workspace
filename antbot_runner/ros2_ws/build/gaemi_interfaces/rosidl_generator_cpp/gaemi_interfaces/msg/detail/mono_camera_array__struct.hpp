// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gaemi_interfaces:msg/MonoCameraArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gaemi_interfaces/msg/mono_camera_array.hpp"


#ifndef GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__STRUCT_HPP_
#define GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gaemi_interfaces__msg__MonoCameraArray __attribute__((deprecated))
#else
# define DEPRECATED__gaemi_interfaces__msg__MonoCameraArray __declspec(deprecated)
#endif

namespace gaemi_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MonoCameraArray_
{
  using Type = MonoCameraArray_<ContainerAllocator>;

  explicit MonoCameraArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MonoCameraArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _images_type =
    std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>>;
  _images_type images;

  // setters for named parameter idiom
  Type & set__images(
    const std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>> & _arg)
  {
    this->images = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gaemi_interfaces__msg__MonoCameraArray
    std::shared_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gaemi_interfaces__msg__MonoCameraArray
    std::shared_ptr<gaemi_interfaces::msg::MonoCameraArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MonoCameraArray_ & other) const
  {
    if (this->images != other.images) {
      return false;
    }
    return true;
  }
  bool operator!=(const MonoCameraArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MonoCameraArray_

// alias to use template instance with default allocator
using MonoCameraArray =
  gaemi_interfaces::msg::MonoCameraArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gaemi_interfaces

#endif  // GAEMI_INTERFACES__MSG__DETAIL__MONO_CAMERA_ARRAY__STRUCT_HPP_
