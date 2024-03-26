#pragma once
#include <string>
#include <Windows.h>
#include <stdio.h>

using namespace std;

class Debug
{
public:
	static int VDebugPrintF(const char* format, va_list args);
	static int DebugPrintF(const char* format, ...);
	//void printDebug(int pString);

	//void printDebug(float pFloat);

private:
	char sz[1024] = { 0 };
};

