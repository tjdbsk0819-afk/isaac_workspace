#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "gaemi_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gaemi_interfaces__msg__MonoCameraArray() -> *const std::ffi::c_void;
}

#[link(name = "gaemi_interfaces__rosidl_generator_c")]
extern "C" {
    fn gaemi_interfaces__msg__MonoCameraArray__init(msg: *mut MonoCameraArray) -> bool;
    fn gaemi_interfaces__msg__MonoCameraArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MonoCameraArray>, size: usize) -> bool;
    fn gaemi_interfaces__msg__MonoCameraArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MonoCameraArray>);
    fn gaemi_interfaces__msg__MonoCameraArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MonoCameraArray>, out_seq: *mut rosidl_runtime_rs::Sequence<MonoCameraArray>) -> bool;
}

// Corresponds to gaemi_interfaces__msg__MonoCameraArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MonoCameraArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub images: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::Image>,

}



impl Default for MonoCameraArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gaemi_interfaces__msg__MonoCameraArray__init(&mut msg as *mut _) {
        panic!("Call to gaemi_interfaces__msg__MonoCameraArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MonoCameraArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gaemi_interfaces__msg__MonoCameraArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gaemi_interfaces__msg__MonoCameraArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gaemi_interfaces__msg__MonoCameraArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MonoCameraArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MonoCameraArray where Self: Sized {
  const TYPE_NAME: &'static str = "gaemi_interfaces/msg/MonoCameraArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gaemi_interfaces__msg__MonoCameraArray() }
  }
}


#[link(name = "gaemi_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gaemi_interfaces__msg__DepthCameraArray() -> *const std::ffi::c_void;
}

#[link(name = "gaemi_interfaces__rosidl_generator_c")]
extern "C" {
    fn gaemi_interfaces__msg__DepthCameraArray__init(msg: *mut DepthCameraArray) -> bool;
    fn gaemi_interfaces__msg__DepthCameraArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DepthCameraArray>, size: usize) -> bool;
    fn gaemi_interfaces__msg__DepthCameraArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DepthCameraArray>);
    fn gaemi_interfaces__msg__DepthCameraArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DepthCameraArray>, out_seq: *mut rosidl_runtime_rs::Sequence<DepthCameraArray>) -> bool;
}

// Corresponds to gaemi_interfaces__msg__DepthCameraArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DepthCameraArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub color_images: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::Image>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub depth_images: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::Image>,

}



impl Default for DepthCameraArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gaemi_interfaces__msg__DepthCameraArray__init(&mut msg as *mut _) {
        panic!("Call to gaemi_interfaces__msg__DepthCameraArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DepthCameraArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gaemi_interfaces__msg__DepthCameraArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gaemi_interfaces__msg__DepthCameraArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gaemi_interfaces__msg__DepthCameraArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DepthCameraArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DepthCameraArray where Self: Sized {
  const TYPE_NAME: &'static str = "gaemi_interfaces/msg/DepthCameraArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gaemi_interfaces__msg__DepthCameraArray() }
  }
}


