// MoveMousePointer.cpp
// A fun Win32 console program.
// Keep your workstation active when you are away.
// Hide console window and move mouse pointer at random postion.

#include <iostream>
#include <random>
#include <Windows.h>

int main()
{
    int iW, iH = 0;
    
    double screenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    double screenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
    
    ////Resize console window
    //RECT rect;
    //HWND hWndConsole = GetConsoleWindow(); //handle to the console window
    //GetWindowRect(hWndConsole, &rect);
    //MoveWindow(hWndConsole, rect.left, rect.top, 1000, 300, TRUE); // new dimension for the Console
    
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE); //hide console

    while (TRUE) {
        std::random_device rand;
        std::mt19937 generator(rand()); //get a random number and seed the generator

        //Define a range
        std::uniform_int_distribution<> distScreenWidth(10, screenWidth); 
        std::uniform_int_distribution<> distScreenHeight(10, screenHeight); 
        
        //Generate random numbers within the range
        iW = distScreenWidth(generator); 
        iH = distScreenHeight(generator);
        //std::cout << "Mouse position (R x C) " << iW <<  " x " << iH << std::endl;
        
        //move the cusor
        SetCursorPos(iW, iH);
        Sleep(3000);
        //system("cls");
    }

    return 0;
}
