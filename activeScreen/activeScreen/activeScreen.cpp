// activeScreen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <random>
#include <thread>

void MoveMouseandLeftClick(bool leftClick, int iSleep) {
	double screenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double screenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	int iW, iH = 0;

	std::random_device rand; // obtain a random number from hardware
	std::mt19937 generator(rand()); // seed the generator

	// define the range
	std::uniform_int_distribution<> distScreenWidth(10, screenWidth);
	std::uniform_int_distribution<> distScreenHeight(10, screenHeight);

	iW = distScreenWidth(generator); // generate numbers
	iH = distScreenHeight(generator);
	//std::cout << "Mouse position (R x C) " << iW << " x " << iH << std::endl;
	SetCursorPos(iW, iH);

	if (leftClick) {
		//mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	}
	Sleep(iSleep);
}


char alphabet[67] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
							'h', 'i', 'j', 'k', 'l', 'm', 'n',
							'o', 'p', 'q', 'r', 's', 't', 'u',
							'v', 'w', 'x', 'y', 'z', 'A', 'B',
							'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
							'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
							'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
							'0', '1', '2', '3', '4', '5', '6', '7',
							'8', '9', ',', ';', ' '
};

void SendKeysToNotePad(int iSleep) {

	UINT i, character_count, keystrokes_to_send, keystrokes_sent;
	//HWND notepad;

	//Get the handle of the Notepad window.
	//notepad = FindWindow("Notepad", NULL);
	//if (notepad == NULL) {
	//	return;
	//}

	HWND hwndWindowTarget;
	HWND hwndWindowNotepad = FindWindow(NULL, L"Untitled - Notepad");
	if (hwndWindowNotepad == NULL) {
		ShellExecute(0, L"open", L"notepad.exe", L"", 0, SW_SHOW);
	}

	//// Find the target Edit window within Notepad.
	//hwndWindowTarget = FindWindowEx(hwndWindowNotepad, NULL, "Edit", NULL);
	//if (hwndWindowTarget)
	//{
	//}

	std::string strWord = "";
	for (int i = 0; i < 10; i++) {
		//Fill in the array of keystrokes to send.
		strWord += alphabet[rand() % 67];
	}

	character_count = strWord.length();

	keystrokes_to_send = character_count * 2;
	INPUT* keystroke = new INPUT[keystrokes_to_send];
	for (i = 0; i < character_count; ++i)
	{
		keystroke[i * 2].type = INPUT_KEYBOARD;
		keystroke[i * 2].ki.wVk = 0;
		keystroke[i * 2].ki.wScan = strWord[i];
		keystroke[i * 2].ki.dwFlags = KEYEVENTF_UNICODE;
		keystroke[i * 2].ki.time = 0;
		keystroke[i * 2].ki.dwExtraInfo = GetMessageExtraInfo();

		keystroke[i * 2 + 1].type = INPUT_KEYBOARD;
		keystroke[i * 2 + 1].ki.wVk = 0;
		keystroke[i * 2 + 1].ki.wScan = strWord[i];
		keystroke[i * 2 + 1].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
		keystroke[i * 2 + 1].ki.time = 0;
		keystroke[i * 2 + 1].ki.dwExtraInfo = GetMessageExtraInfo();
	}

	//Send the keystrokes.
		//Bring the Notepad window to the front.
	if (!SetForegroundWindow(hwndWindowNotepad)) {
		delete[] keystroke;
		return;
	}
	keystrokes_sent = SendInput((UINT)keystrokes_to_send, keystroke, sizeof(*keystroke));

	//return keystrokes_sent == keystrokes_to_send;
	Sleep(iSleep);
}

int main(/*int argc, char* argv[]*/)
{
	//if (argc > 1 && strcmp(argv[1] , "1") == 0) {
	//	mouseLeftClick = true;
	//}
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	std::cout << "WARNING - Once started this application will run in the backgroud until terminated or logoff.\n\n";

	std::string userFlag = "y";
	bool bLeftClick = false;
	std::cout << "do you need a mouse click (y|n) ?  ";
	std::cin >> userFlag;

	DWORD iSleep = 20;
	std::cout << "how many seconds of dealy you need between action (20 and above only)? ";
	std::cin >> iSleep;
	if (iSleep < 20) iSleep = 20;

	iSleep *= 1000;
	system("cls");

	if (userFlag[0] == 'y' || userFlag[0] == 'Y') {
		bLeftClick = true;
	}

	HWND hWndConsole = GetConsoleWindow();
	RECT rect;
	GetWindowRect(hWndConsole, &rect);
	MoveWindow(hWndConsole, rect.left, rect.top, 1000, 300, TRUE); // new dimension
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	for (int i = 0; i < 50000; i++) {
		//while (TRUE) {
		std::thread thread_Mouse = std::thread(MoveMouseandLeftClick, bLeftClick, iSleep);
		std::thread thread_Keys = std::thread(SendKeysToNotePad, iSleep);

		thread_Keys.join();
		thread_Mouse.join();
	}

	return 0;
}

