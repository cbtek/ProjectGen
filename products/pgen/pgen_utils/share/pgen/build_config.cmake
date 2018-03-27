#============================================
# This section is for defining library / include path aliases (if desired)
#============================================
# set(CBTEK_UTILITY_LIBRARY cbtek_utility)
# set(CBTEK_MATH_LIBRARY cbtek_math)

#============================================
# All output is placed in out of source "bin" folder by default.  
# Edit/remove these lines to adjust to your project needs.
#============================================
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}")

#============================================
# This file contains global compiler flags for different platforms
#============================================
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14 --std=c++1y")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wl,--no-as-needed -std=c++11 -std=gnu++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MINGW")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
endif()
