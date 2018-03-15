#==============================================================================
# CMakeLists file for test_DILIsymUtility
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET test_DILIsymUtility)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")

#==============================================================================
# Include Source Files
#==============================================================================
include_directories(inc)
file(GLOB CURR_TARGET_SOURCES "src/*.c*")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")
file(GLOB CURR_TARGET_DATA "data/*.*")
file(COPY ${CURR_TARGET_DATA} DESTINATION ${PROJECT_ROOT}/bin/testData/utility)

#==============================================================================
# Add Library
#==============================================================================
add_executable(${CURR_TARGET}
               ${PLATFORM}
               ${CURR_TARGET_SOURCES}
               ${CURR_TARGET_HEADERS})

#==============================================================================
# Linking and dependencies
#==============================================================================
add_dependencies(${CURR_TARGET} ${CBTEK_UTILITY_LIBRARY})
target_link_libraries(${CURR_TARGET} ${CBTEK_UTILITY_LIBRARY})
