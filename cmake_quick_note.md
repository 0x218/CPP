A simple example of using CMake 
- using a client cpp file (main.cpp) and a library (contains mylib.h and mylib.cpp).
--------------------------------------------------------
folder struct:
	./src/{main.cpp, mylib.cpp, mylib.h}
	./src/CMakeLists.cpp
	./out
---------------------------------------------------------
file contents:
#mylib.h...............
int sum(int a, int b);
---------------------------------------------------------
#mylib.cpp..............
void sum(int a, int b) {
	return a+b'
}
---------------------------------------------------------
#main.cpp...............
#include "mylib.h"
int main(){
	cout<<sum(10,50);
}
---------------------------------------------------------
#CMakeLists.cpp..........
cmake_minimum_required(VERSION 3.13)

project(MyExample)

#create libary
add_library(
	mylib 
	mylib.h
	mylib.cpp
)

add_executable(main.cpp, mylib.cpp)

target_link_libraries(MyExample mylib)
--------------------------------------------------------
##create make files........
#option 1.
cmake -S . -B ./out

#option 2.
cd ./out
cmake ..

--------------------------------------------------------
#create executable with cmake command.
cd ./out
cmake

--------------------------------------------------------
