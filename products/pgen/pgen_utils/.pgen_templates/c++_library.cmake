#==============================================================================
# CMakeLists file for %%PROJECT_NAME%%
#==============================================================================
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET %%PROJECT_NAME%%)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")

#==============================================================================
# Include Source Files
#==============================================================================
include_directories(inc)
include(${CMAKE_MODULE_PATH}/flags.cmake)
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")

#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
                       ${LIBRARY_MODE}
                       ${CURR_TARGET_SOURCES}
                       ${CURR_TARGET_HEADERS})

add_dependencies(${CURR_TARGET} common_utils)
