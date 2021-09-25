#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include <assert.h>
#include "data.h"
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#pragma comment (lib, "winmm.lib")

BYTE* lowerWavAudio();

void main() {
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	BYTE* audio = lowerWavAudio();
	while (1) {
		PlaySound((LPCWSTR)audio, NULL, SND_MEMORY);
		Sleep( (rand() % 5)+1 * 60000);
	}
}


BYTE* lowerWavAudio() {
  //yoinked this bad boy from stack overflow and I forgot to document the url, whoops
	DWORD dwFileSize = sizeof(AUDIOBYTES) / sizeof(AUDIOBYTES[0]);;
	BYTE* pFileBytes = AUDIOBYTES;
	BYTE* pDataOffset = (pFileBytes + 40);
	float fVolume = 0.02;

	__int16* p = (__int16*)(pDataOffset + 8);
	std::cout << sizeof(*p) << std::endl;
	for (int i = 80 / sizeof(*p); i < dwFileSize / sizeof(*p); i++) {
		p[i] = (float)p[i] * fVolume;
	}

	return pFileBytes;
}
