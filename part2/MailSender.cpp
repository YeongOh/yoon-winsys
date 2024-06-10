#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <winBase.h>

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hMailSlot = CreateFile(
		SLOT_NAME,
		GENERIC_WRITE, // �뵵 
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING, // ���� ���
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hMailSlot == INVALID_HANDLE_VALUE) {
		_fputts(_T("Unable to create Mailslot!\n"), stdout);
		return 1;
	}

	TCHAR message[50];
	DWORD bytesWritten;
	while (1) {
		_fputts(_T("MY CMD>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

		if (!WriteFile(hMailSlot, message, _tcsclen(message) * sizeof(TCHAR), &bytesWritten, NULL)) {
			_fputts(_T("Unable to write"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcscmp(message, _T("exit"))) {
			_fputts(_T("Good Bye!"), stdout);
			break;
		}
	}

	CloseHandle(hMailSlot);
	return 0;
}