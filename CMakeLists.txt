cmake_minimum_required(VERSION 3.10)

project(MyOpenCVProject)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add your source files
add_executable(MyOpenCVProgram soccer_playground.cpp)

# Link against OpenCV
target_link_libraries(MyOpenCVProgram PRIVATE ${OpenCV_LIBS})
