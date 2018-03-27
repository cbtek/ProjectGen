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
    CommandLineArgs args("ProjectGen (2018)",argc,argv);
    args.addSwitch("--project-type","-t",true,"Type of project:\n\t1)CPA - C++ App\n\t2)CPL - C++ Library\n\t3)QTA - Qt Application\n\t4)QTL - Qt Library\n\t5)BASE - CMake Base Project\n");
    args.addSwitch("--project-name","-n",true,"Name for project");
    args.addSwitch("--project-path","-p",false,"Location to create project. Defaults to current directory (" + SystemUtils::getCurrentDirectory()+"\")");
    args.addSwitch("--debug-log","-d",false,"Saves debug log to file");

    args.exec();
    std::string projectName = args.value("-n");
    std::string projectType = args.value("-t");
    std::string projectPath = args.value("-o");
    bool enableLog = args.exists("-d");


    ProjectGenType type;
    if (StringUtils::equals(projectType,"BASE"))
    {
        type = ProjectGenType::CODEBASE;
    }
    else if (StringUtils::equals(projectType, "CPL"))
    {
        type = ProjectGenType::CPP_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "QTL"))
    {
        type = ProjectGenType::QT_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "QTA"))
    {
        type = ProjectGenType::QT_APPLICATION;
    }
    else
    {
        type = ProjectGenType::CPP_APPLICATION;
    }

    ProjectGen(type,projectName,projectPath, enableLog).generate();
    return 0;
}

