# ProjectGen 
Generates CMake project templates for Qt / C++ 

**The Command Line Version** 
pgen - The command line version of the application does not require Qt to build.  

**Qt Version** 
pgen_qt - This version provides a GUI that can be integerated with IDEs as an external tool.  Pass "-DBUILD_PGEN_QT" to the command line when building with cmake to compile the Qt version. 

**Building** 
git clone https://github.com/cbtek/ProjectGen.git
mkdir build
cd build

**Linux** 
cmake .. 
make 

**Windows (MinGW)** 
cmake -G "MinGW Makefiles" .. 
 
**Windows (MSVC)** 
cmake .. 


