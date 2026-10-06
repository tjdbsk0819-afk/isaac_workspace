#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to gaemi_interfaces__msg__MonoCameraArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MonoCameraArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub images: Vec<sensor_msgs::msg::Image>,

}



impl Default for MonoCameraArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MonoCameraArray::default())
  }
}

impl rosidl_runtime_rs::Message for MonoCameraArray {
  type RmwMsg = super::msg::rmw::MonoCameraArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        images: msg.images
          .into_iter()
          .map(|elem| sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        images: msg.images
          .iter()
          .map(|elem| sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      images: msg.images
          .into_iter()
          .map(sensor_msgs::msg::Image::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to gaemi_interfaces__msg__DepthCameraArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DepthCameraArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub color_images: Vec<sensor_msgs::msg::Image>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub depth_images: Vec<sensor_msgs::msg::Image>,

}



impl Default for DepthCameraArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DepthCameraArray::default())
  }
}

impl rosidl_runtime_rs::Message for DepthCameraArray {
  type RmwMsg = super::msg::rmw::DepthCameraArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        color_images: msg.color_images
          .into_iter()
          .map(|elem| sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        depth_images: msg.depth_images
          .into_iter()
          .map(|elem| sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        color_images: msg.color_images
          .iter()
          .map(|elem| sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        depth_images: msg.depth_images
          .iter()
          .map(|elem| sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      color_images: msg.color_images
          .into_iter()
          .map(sensor_msgs::msg::Image::from_rmw_message)
          .collect(),
      depth_images: msg.depth_images
          .into_iter()
          .map(sensor_msgs::msg::Image::from_rmw_message)
          .collect(),
    }
  }
}


