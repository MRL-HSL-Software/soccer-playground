cmake_minimum_required(VERSION 3.0)
project(YourProjectName)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11) # You can change this to a higher standard if needed

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add your executable
add_executable(footbalfield main2.cpp)

# Link OpenCV libraries to your executable
target_link_libraries(footbalfield ${OpenCV_LIBRARIES})

