/*
    InterProcessKeyValueStoreUtils.h
    

*/
#pragma once

#include <string>
#include <map>
#include "utility/inc/SystemUtils.hpp"
#include "utility/inc/FileUtils.hpp"

namespace cbtek {
namespace common {
namespace utility {

namespace InterProcessKeyValueStoreUtils
{

    inline static std::string generateFilename(const std::string &session,
                                               const std::string &key)
    {   std::string filename;
        std::string sessionKey = session + key;
        for (size_t a1 = 0; a1 < sessionKey.size(); ++a1)
        {
            int value = (int)sessionKey[a1];
            filename += StringUtils::toString(value);
        }
        return FileUtils::buildFilePath(SystemUtils::getUserTempDirectory(),filename+".dat");
    }

    inline static void write(const std::string &session,
                             const std::string &key,
                             const std::string &value)
    {
        std::string keyFilename = generateFilename(session,key);
        FileUtils::writeFileContents(keyFilename,value);
    }

    inline static bool read(const std::string &session,
                            const std::string &key,
                            std::string &value,
                            bool purge = false)
    {
        std::string keyFilename = generateFilename(session,key);
        if (!FileUtils::fileExists(keyFilename))
        {
            return false;
        }
        value = FileUtils::getFileContents(keyFilename);
        if (purge)
        {
            FileUtils::deleteFile(keyFilename);
        }
        return true;
    }

}
}}}//end namespace
