/**
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

#include <iostream>

#include "utility/inc/StringUtils.h"
#include "utility/inc/FileUtils.h"
#include "utility/inc/SystemUtils.h"
#include "utility/inc/CommandLineArgs.h"

#include "pgen_utils/inc/ProjectGen.h"

using namespace cbtek::common::utility;
using namespace cbtek::products::development::projectgen;

int main(int argc , char ** argv)
{
    std::ostringstream info;
    info << std::endl;
    info << "Project Types:";
    info << "    CCC - CMake Code Base"<< std::endl;
    info << "    CCA - CMake C++ Console Application" << std::endl;
    info << "    CCL - CMake C++ Library" << std::endl;
    info << "    CQL - CMake Qt Library" << std::endl;
    info << "    CQA - CMake Qt Application" << std::endl;
    info << "    MCC - Visual Studio Code Base (Solution)" << std::endl;
    info << "    MCA - Visual Studio Console Application" << std::endl;
    info << "    MDL - Visual Studio Dynamic (Shared) Library" << std::endl;
    info << "    MSL - Visual Studio Static Library" << std::endl;
    CommandLineArgs args("ProjectGen (2018)",argc,argv);
    args.addSwitch("--project-name","-n",true,"Name for project");
    args.addSwitch("--project-path","-p",false,"Location to create project. Defaults to current directory (" + SystemUtils::getCurrentDirectory()+"\")");
    args.addSwitch("--debug-log","-d",false,"Saves debug log to file");
    args.addSwitch("--project-type","-t",true,info.str());
    args.exec();
    std::string projectName = args.value("-n");
    std::string projectType = args.value("-t");
    std::string projectPath = args.value("-o");
    bool enableLog = args.exists("-d");

    ProjectGenType type;
    if (StringUtils::equals(projectType,"CCC") || StringUtils::equals(projectType,"BASE"))
    {
        type = ProjectGenType::CMAKE_CPP_CODEBASE;
    }
    else if (StringUtils::equals(projectType, "CCL") || StringUtils::equals(projectType, "CPL"))
    {
        type = ProjectGenType::CMAKE_CPP_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "CQL") || StringUtils::equals(projectType, "QTL"))
    {
        type = ProjectGenType::CMAKE_QT_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "CQA") || StringUtils::equals(projectType, "QTA"))
    {
        type = ProjectGenType::CMAKE_QT_APPLICATION;
    }    
    else if (StringUtils::equals(projectType, "CCA") || StringUtils::equals(projectType, "CPA"))
    {
        type = ProjectGenType::CMAKE_CPP_APPLICATION;
    }
    else if (StringUtils::equals(projectType, "MCC"))
    {
        type = ProjectGenType::MSVC_CPP_CODEBASE;
    }
    else if (StringUtils::equals(projectType, "MCA"))
    {
        type = ProjectGenType::MSVC_CPP_APPLICATION;
    }
    else if (StringUtils::equals(projectType, "MDL"))
    {
        type = ProjectGenType::MSVC_CPP_DYNAMIC_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "MSL"))
    {
        type = ProjectGenType::MSVC_CPP_STATIC_LIBRARY;
    }
    else THROW_GENERIC_EXCEPTION(projectType + " Undefined!");
    ProjectGen(type,projectName,projectPath, enableLog).generate();
    return 0;
}

