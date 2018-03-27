#============================================
# This file was generated by the CBTek ProjectGen tool (version 2018.04)
#============================================
cmake_minimum_required(VERSION 3.0)
project(%%PROJECT_NAME%%)
set(LIBRARY_TYPE STATIC)
include(${PROJECT_SOURCE_DIR}/build_config.cmake)
if (WIN32)
    set (PLATFORM WIN32)
endif()

#============================================
#Directories to include
#============================================
include_directories("${PROJECT_SOURCE_DIR}/common")
include_directories("${PROJECT_SOURCE_DIR}/products")

#============================================
#Add high level integration tests here
#============================================
add_subdirectory("${PROJECT_SOURCE_DIR}/products/test_%%PROJECT_NAME%%")

#============================================
#Add common libraries here
#============================================
#add_subdirectory("${PROJECT_SOURCE_DIR}/common/<YOUR COMMON LIBRARY>")

#============================================
#Add products here
#============================================
#add_subdirectory("${PROJECT_SOURCE_DIR}/products/<YOUR PRODUCT>")