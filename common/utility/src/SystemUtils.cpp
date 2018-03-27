//utility headers
#include "SystemUtils.h"
#include "FileUtils.h"
#include "StringUtils.h"

BEG_NAMESPACE_CBTEK_UTILITY
std::string SystemUtils::getUserHomeDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];

    SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, dir);

    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr, "\\", "/");
    return dirStr;
#else
    return std::string(getenv("HOME"));
#endif
}

std::string SystemUtils::getUserDesktopDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, dir);
    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr, "\\", "/");
    return dirStr;
#else
    return std::string(getenv("HOME"))+"/Desktop";
#endif
}


std::string SystemUtils::getUserAppDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, dir);
    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr, "\\", "/");
    return dirStr;
#else
    std::string path = FileUtils::buildFilePath(getUserHomeDirectory(), ".local");
    FileUtils::createDirectory(path);
    path = FileUtils::buildFilePath(getUserHomeDirectory(), ".local/share");
    FileUtils::createDirectory(path);
    return path;
#endif
}

std::string SystemUtils::getUserTempDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];

    GetTempPathA(c_MAX_PATH, dir);
    GetLongPathNameA(dir, dir, c_MAX_PATH);

    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr, "\\", "/");
    return dirStr;
#else
    return std::string("/tmp");
#endif
}

std::string SystemUtils::getUserName()
{
#ifdef _WIN32
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserNameA(username, &username_len);
    return std::string(username);
#else
    struct passwd *passwd;
    passwd = getpwuid(getuid());
    return std::string(passwd->pw_name);
#endif
}

std::string SystemUtils::getCurrentDirectory()
{
    char dir[c_MAX_PATH];
#ifdef _WIN32
    GetCurrentDirectoryA(MAX_PATH, dir);
#else
    getcwd(dir, c_MAX_PATH);
#endif
    return std::string(dir);
}

std::string SystemUtils::getCurrentExecutableDirectory()
{
    std::string appPath;
    char buffer[c_MAX_PATH];
#ifdef _WIN32
    GetModuleFileNameA(NULL, buffer, 256);
    appPath = std::string(buffer);
    appPath = FileUtils::getDirPath(appPath);

#else
    ssize_t len = ::readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1)
    {
        buffer[len] = '\0';
        appPath = std::string(buffer);
    }
    //Fix to remove exe name
    appPath = FileUtils::getDirPath(appPath);
#endif
    return appPath;
}

size_t SystemUtils::getTotalSystemMemory()
{
#ifdef _WIN32
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return static_cast<size_t>(status.ullTotalPhys);
#else
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return static_cast<size_t>(pages * page_size);
#endif
}

size_t SystemUtils::getNumCPUThreads()
{
    return static_cast<size_t>(std::thread::hardware_concurrency());
}

END_NAMESPACE_CBTEK_UTILITY
