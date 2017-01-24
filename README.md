# Description 
Generates CMake project templates for Qt / C++ 

**The Command Line Version**    
pgen - The command line version of the application does not require Qt to build.  

**Qt Version**  
pgen_qt - This version provides a GUI that can be integerated with IDEs as an external tool.  Pass "-DBUILD_PGEN_QT" to the command line when building with cmake to compile the Qt version. 

#Building 

1) git clone https://github.com/cbtek/ProjectGen.git  
2) cd ProjectGen  
3) mkdir build  
4) cd build  


**For Linux (GCC)**  
5) cmake ..  
 6) make 


**For Windows (MinGW)**  
5) cmake -G "MinGW Makefiles" ..   
6) mingw32-make  

**For Windows (MSVC)**  
5) cmake ..  
6) nmake 


