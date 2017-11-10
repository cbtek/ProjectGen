#============================================
#Location to place build output
#============================================
if(CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/debug")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/debug")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/debug")
else()
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/release")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/release")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/release")
endif()
