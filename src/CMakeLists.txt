
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

add_library(apple_model SHARED apple/AppleModel.cc)
target_link_libraries(apple_model ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES})

add_library(apple_world SHARED apple/AppleWorld.cc)
target_link_libraries(apple_world ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES})

add_library(car_model SHARED car/CarModel.cc)
target_link_libraries(car_model ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES})
