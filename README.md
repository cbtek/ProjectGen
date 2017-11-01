# ProjectGen

[![ProjectGen Demo](http://img.youtube.com/vi/Gxvsf9IKB8o/0.jpg)](https://www.youtube.com/watch?v=Gxvsf9IKB8o "ProjectGen Demo")

This is a CMake scaffolding tool for generating skeleton projects for C++ and Qt.

**The Command Line Version**    
pgen - The command line version of the application does not require Qt to build.  

**Qt Version**  
pgen_qt - This version provides a GUI that can be integerated with your IDE as an external tool.  Pass "-DBUILD_PGEN_QT" to the command line when building with cmake to compile the Qt version. 

#Building 

1) git clone https://github.com/cbtek/ProjectGen.git  
2) cd ProjectGen  
3) mkdir build  
4) cd build  


**For Linux (GCC)**  
cmake ..  
make 

**For Windows (MinGW)**  
cmake -G "MinGW Makefiles" ..  
mingw32-make 

**For Windows (MSVC)**  
cmake .. 
nmake 


# Documentation
```------------------------------------
ProjectGen Help 
------------------------------------
--project-name   [-n] <name of project>    (required)
--project-type   [-t] <type of project>    (optional, see class types below)
--project-path   [-p] <path of project>    (optional, defaults to current directory)
--enable-logging [-l]                      (writes log to $HOME/.pgen.log)
--help           [-h]                      (displays this help message)
------------------------------------
Valid project-types:
	1) CPA   (C++ Application, default)
	2) CPL   (C++ Library)
	3) QTA   (Qt Application)
	4) QTL   (Qt Library)
	5) BASE  (Top-level CMake for new Code-base)
------------------------------------
Example:
pgen -n "MyProject" -t "CPL" -p "/home/user/project"
------------------------------------
```

Currently there are four templates used for generating projects and one for generating an entire codebase.

If you are starting a new project from scratch, then use the "BASE" type: 
```
pgen -n "MyGames" -t "BASE"
```

The command above will generate the following:
* MyGames/cmake - Location of generic cmake scripts 
* MyGames/cmake/flags.cmake - List of compiler flags per platform for debug and release 
* MyGames/cmake/build.cmake - CMake commands to copy all build output (.dll,.a,.lib,.so,.exe,etc) to a single folder 
* MyGames/common - This folder will hold generic,common and 3rd party libraries used by all projects 
* MyGames/products - This folder will hold only the projects related to the product you are building 
* MyGames/products/test_MyGames - simple C++ project that can be used for unit/integration testing all other products 
* MyGames/CMakeLists.txt - This is the toplevel cmake for the entire code base 

Once you have generated a base project, you can enter the products or common folder and begin generating sub projects using the CPA, CPL, QTA and QTL projectgen types:
 
```
cd products
pgen -n "MyTetrisClone" -t "QTA" 
```

This command will generate a folder in products called "MyTetrisClone" with the following contents: 
* MyTetrisClone/inc - Location to put all C++ header files (.h / .hpp / .hxx)
* MyTetrisClone/src - Location to put all C++ source files (.cpp /.cc /.cxx)
* MyTetrisClone/CMakeLists.txt - CMake setup project relative to current folder

