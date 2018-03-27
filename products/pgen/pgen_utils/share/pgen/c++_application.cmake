#============================================
# CMakeLists file for %%PROJECT_NAME%%
#============================================
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET %%PROJECT_NAME%%)
project(${CURR_TARGET})
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#============================================
# Include Source Files
#============================================
include_directories(inc)
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")

#============================================
# Add Executable
#============================================
add_executable(${CURR_TARGET}
                                ${CURR_TARGET_SOURCES}
                                ${CURR_TARGET_HEADERS})

#============================================
# Add Dependencies
#============================================
#add_dependencies(${CURR_TARGET} ${CBTEK_UTILITY_LIBRARY} )

#============================================
# Target Link Libraries
#============================================
#target_link_libraries(${CURR_TARGET} ${CBTEK_UTILITY_LIBRARY} )

#============================================
# Install 
#============================================
#install(TARGETS ${CURR_TARGET} RUNTIME DESTINATION bin)

#============================================
# Copies share folder to output folder
#============================================
#add_custom_command(TARGET ${CURR_TARGET} POST_BUILD COMMAND 
#                                                              ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/share $<TARGET_FILE_DIR:${CURR_TARGET}>/share)



