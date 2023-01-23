// MoveMousePointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <Windows.h>

int main()
{
    double screenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    double screenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
    
    HWND hWndConsole = GetConsoleWindow();
    RECT rect;
    GetWindowRect(hWndConsole, &rect);
    MoveWindow(hWndConsole, rect.left, rect.top, 1000, 300, TRUE); // new dimension
    int iW, iH = 0;

    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    while (TRUE) {
        std::random_device rand; // obtain a random number from hardware
        std::mt19937 generator(rand()); // seed the generator

        // define the range
        std::uniform_int_distribution<> distScreenWidth(10, screenWidth); 
        std::uniform_int_distribution<> distScreenHeight(10, screenHeight); 

        iW = distScreenWidth(generator); // generate numbers
        iH = distScreenHeight(generator);
        std::cout << "Mouse position (R x C) " << iW <<  " x " << iH << std::endl;
        SetCursorPos(iW, iH);
        //mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
    
        Sleep(500000);
        system("cls");
    }

    return 0;
}