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

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/SystemUtils.hpp"

#include "pgen_utils/inc/ProjectGen.h"

using namespace cbtek::common::utility;
using namespace cbtek::products::development::projectgen;

int main(int argc , char ** argv)
{
    std::string projectType = StringUtils::toUpperTrimmed(StringUtils::getCommandLineArg(argc,argv,"--project-type","-t"));
    std::string projectName = StringUtils::getCommandLineArg(argc,argv,"--project-name","-n");
    std::string projectPath = StringUtils::getCommandLineArg(argc,argv,"--project-path","-p");
    bool showHelp = StringUtils::commandLineArgExists(argc,argv,"--help") || StringUtils::commandLineArgExists(argc,argv,"-h");
    if (StringUtils::trimmed(projectName).empty())
    {
        std::cout << "ERROR: No name specified for this project."<<std::endl;
        showHelp=true;
    }

    if (showHelp)
    {
        std::cout << "------------------------------------\n";
        std::cout << "ProjectGen Help \n";
        std::cout << "------------------------------------\n";
        std::cout << "--project-name [-n] <name of project>    (required)\n";\
        std::cout << "--project-type [-t] <type of project>    (optional, see class types below)\n";
        std::cout << "--project-path [-p] <path of project>    (optional)\n";
        std::cout << "--help         [-h]                      (displays this help message)\n";
        std::cout << "------------------------------------\n";
        std::cout << "Valid project-types:\n";
        std::cout << "\t1) CPA   (C++ Application, default)\n";
        std::cout << "\t2) CPL   (C++ Library)\n";
        std::cout << "\t3) QTA   (Qt Application)\n";
        std::cout << "\t4) QTL   (Qt Library)\n";
        std::cout << "\t5) BASE  (Top-level CMake for new Code-base)\n";
        std::cout << "------------------------------------\n";
        std::cout << "Example:\n";
        std::cout << "projectgen -n \"MyProject\" -t \"CPL\" -p \"/home/user/project\"\n";
        std::cout << "------------------------------------"<<std::endl;
        return 0;
    }

    ProjectGenType type;
    if (StringUtils::equals(projectType,"BASE"))
    {
        type = ProjectGenType::CODEBASE;
    }
    else if (StringUtils::equals(projectType, "CPL"))
    {
        type = ProjectGenType::CPP_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "QLA"))
    {
        type = ProjectGenType::QT_LIBRARY;
    }
    else if (StringUtils::equals(projectType, "QPA"))
    {
        type = ProjectGenType::QT_APPLICATION;
    }
    else
    {
        type = ProjectGenType::CPP_APPLICATION;
    }

    ProjectGen(type,projectName,projectPath).generate();
    return 0;
}

