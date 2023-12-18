cmake_minimum_required(VERSION 3.0)
project(SoccerPlayGround)

# Locate OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Create an executable from your source files
add_executable(SoccerPlayGround main.cpp play_ground.cpp)

# Link OpenCV libraries to the executable
target_link_libraries(SoccerPlayGround ${OpenCV_LIBRARIES})
