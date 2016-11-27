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

#ifndef _CBTEK_PRODUCTS_DEVELOPMENT_CMAKE_PROJECT_STUDIO_PRODUCTS_PROJECT_GENERATOR_PROJECTGEN_H
#define _CBTEK_PRODUCTS_DEVELOPMENT_CMAKE_PROJECT_STUDIO_PRODUCTS_PROJECT_GENERATOR_PROJECTGEN_H

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
               const std::string & path);

    void generate();
    //! Destructor
    ~ProjectGen();	
private:
    ProjectGenType m_type;
    std::string m_name;
    std::string m_path;
};
}}}}//end namespace

#endif // _CBTEK_PRODUCTS_DEVELOPMENT_CMAKE_PROJECT_STUDIO_PRODUCTS_PROJECT_GENERATOR_PROJECTGEN_H

