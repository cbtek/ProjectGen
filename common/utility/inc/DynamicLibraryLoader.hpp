/*
    DynamicLibraryLoader.hpp  
*/
#pragma once

#include <string>
#include <memory>

#include "UtilityCommon.hpp"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

BEG_NAMESPACE_CBTEK_UTILITY

class DynamicLibraryLoader 
{
public:
    /**
     * @brief DynamicLibraryLoader
     * @param libraryPath
     */
    DynamicLibraryLoader(const std::string &libraryPath)
    {
        #ifdef _WIN32
            m_reference = LoadLibrary(libraryPath.c_str());
        #else
            m_reference = dlopen(libraryPath.c_str(), RTLD_LAZY);
        #endif
    }

    /**
     * @brief ~DynamicLibraryLoader
     */
    ~DynamicLibraryLoader()
    {
        if (m_reference != nullptr)
        {
            #ifdef _WIN32
                FreeLibrary(m_reference);
            #else
                dlclose(m_reference);
            #endif
        }
    }

    /**
     * @brief load
     * @param name
     * @return
     */
    template<typename T>
    T load(const std::string &name)
    {
        T ret = nullptr;
        if (m_reference != nullptr)
        {
            #ifdef _WIN32
                ret = reinterpret_cast<T>(GetProcAddress(m_reference, name.c_str()));
            #else
                ret = reinterpret_cast<T>(dlsym(m_reference, name.c_str()));
            #endif
        }
        return ret;
    }
private:
    #ifdef _WIN32
        HMODULE m_reference;
    #else
        void* m_reference;
    #endif
};
using DynamicLibraryLoaderPtr = std::shared_ptr<DynamicLibraryLoader>;
END_NAMESPACE_CBTEK_UTILITY
