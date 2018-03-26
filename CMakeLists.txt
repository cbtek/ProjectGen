#==============================================================================
# CMakeLists file for CBTEK_UTILITY_LIBRARY
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CBTEK_UTILITY_LIBRARY utility)
set(CURR_TARGET ${CBTEK_UTILITY_LIBRARY})
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#==============================================================================
# Include Source Files
#==============================================================================
include_directories(inc)
include_directories(external/tinyxml2/inc)
include_directories(external/backward/inc)
include_directories(external/tiny-process-library/inc)

if (WIN32)
    set(TPL_SOURCES "external/tiny-process-library/src/process.cpp"
                   "external/tiny-process-library/src/process_windows.cpp")
else(WIN32)
    set(TPL_SOURCES "external/tiny-process-library/src/process.cpp"
                   "external/tiny-process-library/src/process_unix.cpp")
endif(WIN32)

file(GLOB CURR_TARGET_SOURCES "src/*.cpp"
                              "external/tinyxml2/src/*.cpp"
                              "external/backward/src/*.cpp"
                              ${TPL_SOURCES})
file(GLOB CURR_TARGET_HEADERS "inc/*.h*"
                              "external/tinyxml2/inc/*.h*"
                              "external/backward/inc/*.h*"
                              "external/tiny-process-library/inc/*.h*")

if (${CBTEK_UNIT_TESTS_ENABLED} MATCHES ON)
    add_subdirectory(tests)
endif()

#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS}
           )
#==============================================================================
# Install 
#==============================================================================
#if(BUILD_CBTEK_UTILS_STATIC_LIBRARY)
#    INSTALL(TARGETS ${CURR_TARGET} ARCHIVE DESTINATION bin)
#else(BUILD_CBTEK_UTILS_STATIC_LIBRARY)
#    INSTALL(TARGETS ${CURR_TARGET} RUNTIME DESTINATION bin)
#endif(BUILD_CBTEK_UTILS_STATIC_LIBRARY)


