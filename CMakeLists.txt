#==============================================================================
# CMakeLists file for utility
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET ${CBTEK_UTILITY_LIBRARY})
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
if (${ENABLE_COMMON_UTILS_UNIT_TESTS})
    add_subdirectory(tests)
endif()

#==============================================================================
# Include Source Files
#==============================================================================
include(${CMAKE_MODULE_PATH}/flags.cmake)
include_directories(inc)
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")

#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})
#==============================================================================
# Install 
#==============================================================================
#if (${ENABLE_COMMON_UTILS_DYNAMIC_LIB})
#    install(TARGETS ${CURR_TARGET} LIBRARY DESTINATION lib)
#else()
#    install(TARGETS ${CURR_TARGET} ARCHIVE DESTINATION lib)
#endif()

