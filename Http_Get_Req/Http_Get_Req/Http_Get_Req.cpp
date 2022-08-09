// Http_Get_Req.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <string>

#pragma comment (lib, "Wininet.lib")

#define URI "www.google.com"


using namespace std;

int main(int argc, char* argv[])
{
	HINTERNET hSession = InternetOpen("Mozilla/5.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	HINTERNET hConnect = InternetConnect(hSession, URI, INTERNET_DEFAULT_HTTPS_PORT, "", "", INTERNET_SERVICE_HTTP, 0, 0);

	HINTERNET hHttpRequest = HttpOpenRequest(hConnect, "GET", "/", NULL, NULL, NULL, INTERNET_FLAG_SECURE, 0);

	if (!HttpSendRequest(hHttpRequest, NULL, 0, 0, 0))
	{
		cout << "Err sending Http Request error : " << GetLastError() << endl;
		return -1;
	}

	DWORD dwFileSize = 1024;

	char* tmpBuffer = new char[dwFileSize + 1];

	while (true)
	{
		DWORD dwBytesRead;
		BOOL bReadStream = false;

		bReadStream = InternetReadFile(hHttpRequest, tmpBuffer, dwFileSize + 1, &dwBytesRead);

		if (dwBytesRead == 0)
		{
			cout << "No data returned.  Exiting." << endl;
			break;
		}

		if (!bReadStream)
		{
			cout << "InternetReadFile error : " << GetLastError() << endl;
			return -2;
		}
		else
		{
			tmpBuffer[dwBytesRead] = 0;
			cout << "Retrieved " << dwBytesRead << " data bytes : " << tmpBuffer << endl;
		}
	}

	InternetCloseHandle(hHttpRequest);
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hSession);

	return 0;
}
