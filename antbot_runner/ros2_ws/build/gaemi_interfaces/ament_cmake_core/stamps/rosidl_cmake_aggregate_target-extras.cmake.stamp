# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target gaemi_interfaces::gaemi_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${gaemi_interfaces_TARGETS}.
if(gaemi_interfaces_TARGETS AND NOT TARGET gaemi_interfaces::gaemi_interfaces)
  add_library(gaemi_interfaces::gaemi_interfaces INTERFACE IMPORTED)
  set_target_properties(gaemi_interfaces::gaemi_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${gaemi_interfaces_TARGETS}")
endif()
