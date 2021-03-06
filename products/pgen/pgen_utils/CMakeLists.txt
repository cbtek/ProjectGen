#==============================================================================
# CMakeLists file for pgen_utils
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET pgen_utils)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
include_directories(inc)
include_directories(src)

include(${CMAKE_MODULE_PATH}/flags.cmake)
include(${CMAKE_MODULE_PATH}/build.cmake)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")

#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})

# Copy templates folder to build directory
# so that the exe can see them
add_custom_command(TARGET ${CURR_TARGET} POST_BUILD
                 COMMAND ${CMAKE_COMMAND} -E copy_directory
                 ${CMAKE_CURRENT_SOURCE_DIR}/share $<TARGET_FILE_DIR:${CURR_TARGET}>/share)


#==============================================================================
# Install 
#==============================================================================
if (WIN32)

else()
    if (ENABLE_PGEN_UTILS_STATIC_LIB)
            install(TARGETS ${CURR_TARGET} ARCHIVE DESTINATION lib)
    else()
            install(TARGETS ${CURR_TARGET} LIBRARY DESTINATION lib)
    endif()
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/share DESTINATION share)
endif()

#install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.pgen_templates DESTINATION $ENV{HOME} PATTERN "*" PERMISSIONS WORLD_READ WORLD_WRITE)



