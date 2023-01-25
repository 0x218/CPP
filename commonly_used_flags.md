`g++ main.cpp`  
Executes complete compile process and generates ouput file a.out.

`g++ main.cpp -o main`  
Use flag -o to specify the output file name.

`g++ main.cpp -o a.out -lmyLibFile.so`  
-l links the code with the library file (main.cpp is linked with myLibFile.so to create a.out).

`g++ -v main.cpp -o main`  
-V to print verbose information on all the steps g++ takes while compiling a source file.

`g++ -E main.cpp`  
-E generates preprocessor output (g++ -E main.cpp > main.i)

`g++ -S main.cpp`  
-S generates assembly code.

`g++ -Wall main.cpp -o main`  
-Wall Enable all warnings

`g++ -save-temps main.cpp`  
-save-temps produce all the intermediate files (.i, .s, .o and .out)

`g++ -DMY_MACRO main.cpp -o main`  
-D is used to supply macro at compile time.

`g++ main.cpp @compile_options.txt`  
@ is used to provide g++ options through a file



