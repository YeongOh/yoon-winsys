#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>

#define STR_LEN 256
#define MAX_STR_LEN 100

void SortString(void) {
	TCHAR result[MAX_STR_LEN][STR_LEN];

	int n;
	for (n = 0; n < MAX_STR_LEN; n++) {
		TCHAR* isEOF = _fgetts(result[n], MAX_STR_LEN, stdin);
		if (isEOF == NULL) {
			break;
		}
	}

	TCHAR buf[MAX_STR_LEN];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (_tcscmp(result[i], result[j]) > 0) {
				_tcscpy(buf, result[i]);
				_tcscpy(result[i], result[j]);
				_tcscpy(result[j], buf);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		_fputts(result[i], stdout);
	}
}

int _tmain(int argc, TCHAR* argv[]) {
	SortString();

	return 0;
}