#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO siNORMAL = { 0, };
	siNORMAL.cb = sizeof(siNORMAL);
	PROCESS_INFORMATION piNORMAL;
	TCHAR commandOne[] = _T("NORMAL_PRIORITY_CLASS.exe");

	STARTUPINFO siBELOW = { 0, };
	siBELOW.cb = sizeof(siBELOW);
	PROCESS_INFORMATION piBELOW;
	TCHAR commandTwo[] = _T("BELOW_NORMAL_PRIORITY_CLASS.exe");

	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);

	CreateProcess(
		NULL, commandOne,
		NULL, NULL, TRUE,
		0, NULL, NULL,
		&siNORMAL, &piNORMAL
	);

	CreateProcess(
		NULL, commandTwo,
		NULL, NULL, TRUE,
		0, NULL, NULL,
		&siBELOW, &piBELOW
	);

	while (1) {
		for (DWORD i = 0; i < 10000; i++) {
			for (DWORD i = 0; i < 10000; i++);

			// Sleep(10);

			_fputts(_T("ABOVE_NORMAL_PRIORITY_CLASS Process \n"), stdout);
		}
	}
	return 0;
}
