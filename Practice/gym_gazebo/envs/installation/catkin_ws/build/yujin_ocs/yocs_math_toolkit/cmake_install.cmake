# Install script for directory: /home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/yujin_ocs/yocs_math_toolkit

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/yujin_ocs/yocs_math_toolkit/catkin_generated/installspace/yocs_math_toolkit.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/yocs_math_toolkit/cmake" TYPE FILE FILES
    "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/yujin_ocs/yocs_math_toolkit/catkin_generated/installspace/yocs_math_toolkitConfig.cmake"
    "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/yujin_ocs/yocs_math_toolkit/catkin_generated/installspace/yocs_math_toolkitConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/yocs_math_toolkit" TYPE FILE FILES "/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/src/yujin_ocs/yocs_math_toolkit/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/yujin_ocs/yocs_math_toolkit/include/cmake_install.cmake")
  include("/home/howoongjun/gym-gazebo/gym_gazebo/envs/installation/catkin_ws/build/yujin_ocs/yocs_math_toolkit/src/cmake_install.cmake")

endif()

