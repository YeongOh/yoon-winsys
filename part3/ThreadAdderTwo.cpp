#include <stdio.h>
#include <tchar.h>
#include <windows.h>

static int total = 0;

DWORD WINAPI ThreadProc(LPVOID lpParam) {
	DWORD* nPtr = (DWORD*)lpParam;

	DWORD numOne = *nPtr;
	DWORD numTwo = *(nPtr + 1);

	for (DWORD i = numOne; i <= numTwo; i++) {
		total += i;
	}
	return 0;
}

int _tmain(int argc, TCHAR* argv[]) {
	DWORD dwThreadID[3];
	HANDLE hThread[3];

	DWORD paramThread[] = { 1, 3, 4, 7, 8, 10 };

	hThread[0] = CreateThread(
		NULL, 0,
		ThreadProc,
		(LPVOID)(&paramThread[0]),
		0, &dwThreadID[0]
	);
	hThread[1] = CreateThread(
		NULL, 0,
		ThreadProc,
		(LPVOID)(&paramThread[2]),
		0, &dwThreadID[1]
	);
	hThread[2] = CreateThread(
		NULL, 0,
		ThreadProc,
		(LPVOID)(&paramThread[4]),
		0, &dwThreadID[2]
	);

	WaitForMultipleObjects(
		3,
		hThread,
		TRUE,
		INFINITE
	);

	_tprintf(_T("total (1 ~ 10): %d \n"), total);

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);
	return 0;
}