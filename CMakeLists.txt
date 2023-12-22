# - CMake Message Colors
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(TAB           "   ")
  set(RESET         "${Esc}[m")
  set(GREEN         "${Esc}[38;2;0;255;0m")
  set(RED           "${Esc}[38;2;255;0;0m")
  set(SUCCESS       "${TAB}${GREEN}[SUCCESS]${RESET}")
  set(FAILED        "${TAB}${RED}[FAILED]${RESET}")
  set(BLUE          "${Esc}[38;2;106;140;150m")
  set(CYAN          "${Esc}[38;2;0;255;255m")
  set(LIGHT         "${Esc}[38;2;170;170;170m")
  set(TEXT          "${BLUE}")
  set(MRL           "${CYAN}[MRL]${TEXT}")
endif()

# - Specify CMake Version
cmake_minimum_required(VERSION 3.10)

# - Project Name
message("${MRL} Initializing Project ...${RESET}")
project(SoccerField)
message("${MRL} Set Project Name to ${LIGHT}${PROJECT_NAME}${RESET}")

# - Find Requiered Packages
message("${MRL} Finding Package ${LIGHT}OpenCV${TEXT} ...${RESET}")
find_package(OpenCV REQUIRED)

# - Set C++ Standard
set(CMAKE_CXX_STANDARD 11)

# - Source Files
if (DEFINED _SRC)
    foreach(SOURCE_FILE ${_SRC})
        message("${MRL} Checking Input Source ${LIGHT}${SOURCE_FILE}${RESET}")
        if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_FILE}")
            message("${SUCCESS} Found Source File ${LIGHT}${SOURCE_FILE}${RESET}")
        else()
            message("${FAILED} Source File ${LIGHT}${SOURCE_FILE}${RESET} ${TEXT} Not Found")
        endif()
    endforeach()
else()
    message("${MRL} Using Default Source File ...${RESET}")
    message("${MRL} Adding Source File ...${RESET}")
    set(_SRC # - Default main.cpp
        main.cpp
    )
endif()

# - Add Source Files
message("${MRL} Adding Source Files ...${RESET}")
foreach(SOURCE_FILE ${_SRC})
    message("${SUCCESS} Added ${LIGHT}${SOURCE_FILE}${RESET}")
endforeach()

# - Add Executable
add_executable(${PROJECT_NAME} ${_SRC})

# - Include OpenCV
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

# - Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} X11)

# - Define MRL Project Signiture
target_compile_definitions(${PROJECT_NAME} PRIVATE MRL_HSL=1)
