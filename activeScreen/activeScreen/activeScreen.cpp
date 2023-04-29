// activeScreen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <shlobj.h>
#include <fstream>
#include <random>
#include <thread>


std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,;'\"!@#$%^&*(){}[]\|~`?><-_+= ";

HWND hwndWindowNotepad = NULL;
TCHAR filePath[MAX_PATH];
HRESULT hr = SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, SHGFP_TYPE_CURRENT, filePath);
std::wstring fileName = std::wstring(filePath) + L"\\_activeScreen_funproject_renjith.txt";
std::wstring windowTitle = L"_activeScreen_funproject_renjith.txt - Notepad";


void MoveMouseandLeftClick(bool leftClick, int iSleep) {
	while (true) {
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
}


void CreateNotepadFile() {
	//if file note presents, creates a notepad file.	
	if (SUCCEEDED(hr)) {		
		std::ifstream file(fileName.c_str());
		if (!file.good()) {
			std::wofstream outputfile(fileName);
			outputfile.close();
			Sleep(500);
		}
	}
}

void OpenNotepadFile() {
	ShellExecute(0, L"open", fileName.c_str(), L"", L"", SW_SHOW);
	Sleep(500);
	hwndWindowNotepad = FindWindow(nullptr, windowTitle.c_str());
}


HWND MakeWindowActive() {
	Sleep(500);

	if (hwndWindowNotepad == NULL) {
		hwndWindowNotepad = FindWindow(nullptr, windowTitle.c_str());
	}

	if (hwndWindowNotepad == NULL){
		//MessageBox(nullptr, L"SendKeysToNotePad - concerning situtation!", L"ERROR", MB_OK | MB_ICONERROR);
		OpenNotepadFile();
		hwndWindowNotepad = FindWindow(nullptr, windowTitle.c_str());
	}

	if (hwndWindowNotepad == NULL) {
		//MessageBox(nullptr, L"SendKeysToNotePad - critical situtation!", L"ERROR", MB_OK | MB_ICONERROR);
		CreateNotepadFile();
		OpenNotepadFile();
		hwndWindowNotepad = FindWindow(nullptr, windowTitle.c_str());
	}

	if (hwndWindowNotepad == NULL) {
		MessageBox(nullptr, L"Creation or activating a file has failed.  Aborting.", L"ERROR", MB_OK | MB_ICONERROR);
		abort();
	}

	if (IsIconic(hwndWindowNotepad)) {
		ShowWindow(hwndWindowNotepad, SW_RESTORE);
		Sleep(500);
	}

	SetForegroundWindow(hwndWindowNotepad);
	Sleep(500);
	
	return hwndWindowNotepad;
}

void SendKeysToNotePad(int iSleep) {

	while (true) {
		UINT i, character_count, keystrokes_to_send, keystrokes_sent;

		Sleep(500);
		HWND hwndWindowNotepad = MakeWindowActive();
		
		if (hwndWindowNotepad != NULL) {		
			std::string strWord = "";
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, alphabet.size() - 1);

			for (int i = 0; i < 10; i++) {
				//Fill in the array of keystrokes to send.
				char c = alphabet[dis(gen)];
				strWord += c;
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

			////Bring the Notepad window to the front.
			//if (!SetForegroundWindow(hwndWindowNotepad)) {
			//	delete[] keystroke;
			//	return;
			//}
			//Send the keystrokes.
			keystrokes_sent = SendInput((UINT)keystrokes_to_send, keystroke, sizeof(*keystroke));

			//return keystrokes_sent == keystrokes_to_send;
			delete[] keystroke;
		}
		Sleep(iSleep);
	}
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


	std::thread thread_Mouse;
	std::thread thread_Keys;
	
	thread_Keys = std::thread(SendKeysToNotePad, iSleep);
	thread_Mouse = std::thread(MoveMouseandLeftClick, bLeftClick, iSleep);

	thread_Keys.join();
	thread_Mouse.join();	

	return 0;
}

