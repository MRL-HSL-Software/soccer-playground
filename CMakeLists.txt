cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Locate OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Create an executable from your source files
add_executable(MyProject main.cpp play_ground.cpp)

# Link OpenCV libraries to the executable
target_link_libraries(MyProject ${OpenCV_LIBRARIES})
