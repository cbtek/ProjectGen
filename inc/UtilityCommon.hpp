#pragma once
#ifdef BUILD_CBTEK_UTILITY_DLL
#   ifdef _WIN32
#       define CBTEK_UTILITY_DLL __declspec( dllexport )
#   else
#       define CBTEK_UTILITY_DLL
#   endif
#else
#   define CBTEK_UTILITY_DLL
#endif

//Define namespace constants for easy cleaner code and ease when/if updating or modifying namespace
#define BEG_NAMESPACE_CBTEK_UTILITY namespace cbtek { \
                                    namespace common { \
                                    namespace utility {

#define END_NAMESPACE_CBTEK_UTILITY }}}
#define USE_NAMESPACE_CBTEK_UTILITY using namespace cbtek::common::utility;

BEG_NAMESPACE_CBTEK_UTILITY
    const static int  c_DEFAULT_FLOATING_PRECISION = 12;
    const static bool c_DEFAULT_CASE_SENSITIVE = true;
    const static int  c_MAX_PATH = 1024;
END_NAMESPACE_CBTEK_UTILITY
