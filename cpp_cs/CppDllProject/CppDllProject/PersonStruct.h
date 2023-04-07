#pragma once

#include <Windows.h>

extern "C" {
	struct Name {
		CHAR FirstName[50];
		CHAR Address[100];
		DWORD Height;
	};
}