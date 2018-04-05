/*
    ProjectGen.h

    
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once
#include <string>


namespace cbtek {
namespace products {
namespace development {
namespace projectgen {

enum class ProjectGenType
{
    CODEBASE,
    CPP_APPLICATION,
    CPP_LIBRARY,
    VS_SOLUTION,
    VS_APPLICATION,
    VS_LIBRARY,
    QT_APPLICATION,
    QT_LIBRARY
};

class ProjectGen 
{
public:

    /**
     * @brief Constructor for ProjectGen
     *  Detailed description for ProjectGen
     */
    ProjectGen(ProjectGenType type,
               const std::string & projectName,
               const std::string & path,
               bool enableLog = false);

    void generate();
    //! Destructor
    ~ProjectGen();	
private:

    /**
     * @brief isValidTemplatePath Attempts to validate location of share folder
     * @param path
     * @return
     */
    bool isValidTemplatePath(const std::string &path);

    /**
     * @brief buildProject
     */
    void buildProject();


    bool m_enableLogging;
    ProjectGenType m_type;
    std::string m_name;
    std::string m_path;
    std::string m_buildCMakePath;    
    std::string m_cppLibCMakePath;
    std::string m_qtLibCMakePath;
    std::string m_cppAppCMakePath;
    std::string m_qtAppCMakePath;
    std::string m_vsAppPath;
    std::string m_vsLibPath;
    std::string m_vsSlnPath;
    std::string m_cppMainPath;
    std::string m_qtMainPath;
    std::string m_basePath;

};
}}}}//end namespace

