#include <stdio.h>
#include <Windows.h>
#include "PersonStruct.h"

extern "C"
{
	__declspec(dllexport) void __cdecl PrintATextFromDll()
	{
		printf("This is printed from the DLL Project.!\n");
	}

	__declspec(dllexport) void FillString(char* myString, int length)
	{
		strcpy_s(myString, length, "Hello, the DLL composed this string.");
	}

	__declspec(dllexport) void __cdecl UpdateAStruct(Name* name)
	{
		printf("DLL received a struct with Name: %s, Address: %s.\r\n", name->FirstName, name->Address);
		strcpy_s(name->FirstName, 50, "my name");
		strcpy_s(name->Address, 100, "my street address, state, zip");
		name->Height = 1000;
	}

	//__declspec(dllexport) BSTR __cdecl GetMyString()
	//{
	//	return SysAllocStringByteLen("This is my from cpp dll.", 24);
	//}

	__declspec(dllexport) BSTR __stdcall GetMyString()
	{
		return SysAllocString(L"CPP dll returing BSTR.");
	}

}


