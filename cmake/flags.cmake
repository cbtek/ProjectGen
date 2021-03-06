# This file contains compiler flags for different platforms
if (WIN32)
    if (MSVC)

    else(MSVC)
		if(CMAKE_BUILD_TYPE MATCHES DEBUG)
			set(CMAKE_CXX_FLAGS_DEBUG "-Wl,--no-as-needed -std=c++11  -D_GLIBCXX_USE_CXX11_ABI=0")
		elseif(CMAKE_BUILD_TYPE MATCHES RELEASE)
			set(CMAKE_CXX_FLAGS_RELEASE "-g -Wl,--no-as-needed -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0")
		else()
			set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -g -Wl,--no-as-needed -std=c++11  -D_GLIBCXX_USE_CXX11_ABI=0")
	    endif()
	endif(MSVC)
else()
		if(CMAKE_BUILD_TYPE MATCHES DEBUG)
		    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
		elseif(CMAKE_BUILD_TYPE MATCHES RELEASE)
		    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
		else()
    		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wl,--no-as-needed -std=c++11 -pthread  -D_GLIBCXX_USE_CXX11_ABI=0")
		endif()
endif()
