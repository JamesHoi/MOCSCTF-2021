#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <intrin.h>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <iostream>
#include <assert.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <WtsApi32.h>
#include <locale.h>
#include <ShObjIdl.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <thread>


int xor_cipher = 0;

#pragma region 反调试
bool CheckDebugExe()
{
	DWORD ID;
	DWORD ret = 0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		xor_cipher += 0x15;
		return FALSE;
	}
	BOOL bMore = Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (_stricmp(pe32.szExeFile, "OllyDBG.EXE") == 0 || _stricmp(pe32.szExeFile, "ida64.exe") == 0 
			|| _stricmp(pe32.szExeFile, "x32dbg.exe") == 0 || _stricmp(pe32.szExeFile, "x64dbg.exe") == 0 
			|| _stricmp(pe32.szExeFile, "ida.exe") == 0 || _stricmp(pe32.szExeFile, "吾爱破解[LCG].exe") == 0)
		{
			return TRUE;
		}
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	CloseHandle(hProcessSnap);
	xor_cipher += 0x15;
	return FALSE;
}

void CheckDebug_SEH() {
	__asm {
		// install SEH
		push handler
		push DWORD ptr fs : [0]
		mov DWORD ptr fs : [0], esp
		__emit(0xcc)
		// 只检测有无调试器
		// 在调试器中就会跑飞
		__emit(0xE9)
		jmp normal_code
		handler :
			mov eax, dword ptr ss : [esp + 0xc];// ContextRecord
			mov dword ptr ds : [eax + 0xb8], offset normal_code
			xor eax, eax
			retn
		normal_code :
			//   remove SEH
			pop dword ptr fs : [0]
			add esp, 4
	}
	xor_cipher += 0x15;
}

using namespace std;
typedef enum _THREADINFOCLASS {
	ThreadBasicInformation,
	ThreadTimes,
	ThreadPriority,
	ThreadBasePriority,
	ThreadAffinityMask,
	ThreadImpersonationToken,
	ThreadDescriptorTableEntry,
	ThreadEnableAlignmentFaultFixup,
	ThreadEventPair_Reusable,
	ThreadQuerySetWin32StartAddress,
	ThreadZeroTlsCell,
	ThreadPerformanceCount,
	ThreadAmILastThread,
	ThreadIdealProcessor,
	ThreadPriorityBoost,
	ThreadSetTlsArrayAddress,
	ThreadIsIoPending,
	ThreadHideFromDebugger,
	ThreadBreakOnTermination,
	MaxThreadInfoClass
} THREADINFOCLASS;

typedef NTSTATUS(WINAPI *NtSetInformationThreadPtr)(
	HANDLE threadHandle,
	THREADINFOCLASS threadInformationClass,
	PVOID threadInformation,
	ULONG threadInformationLength
	);

// 反调试函数
void HideFromDebugger() {
	HMODULE hNtDll = LoadLibrary(TEXT("ntdll.dll"));
	NtSetInformationThreadPtr NtSetInformationThread = (NtSetInformationThreadPtr)GetProcAddress(hNtDll, "NtSetInformationThread");
	NTSTATUS status = NtSetInformationThread(GetCurrentThread(), ThreadHideFromDebugger, NULL, 0);
	xor_cipher += 0x0E;
}
#pragma endregion

#pragma region 加密运算
const int plus_len = 23;
const char plus_asm[] = {
  0x6D, 0xB3, 0xD4, 0x6B, 0x6E, 0x6F, 0xBD, 0xF8, 0x4D, 0x3A,
  0xD1, 0xD5, 0xB3, 0x7D, 0x30, 0x3B, 0x7D, 0x34, 0x67, 0x66,
  0x63, 0x65, 0xFB
};

const int minus_len = 23;
const char minus_asm[] = {
  0x6D, 0xB3, 0xD4, 0x6B, 0x6E, 0x6F, 0xBD, 0xF8, 0x4D, 0x3A,
  0xD1, 0xD5, 0xB3, 0x7D, 0x30, 0x13, 0x7D, 0x34, 0x67, 0x66,
  0x63, 0x65, 0xFB
}; 

const int multi_len = 24;
const char multi_asm[] = {
  0x6D, 0xB3, 0xD4, 0x6B, 0x6E, 0x6F, 0xBD, 0xF8, 0x4D, 0x3A,
  0xD1, 0xD5, 0xB3, 0x7D, 0x30, 0x37, 0x97, 0x7D, 0x34, 0x67,
  0x66, 0x63, 0x65, 0xFB
}; 

const int divided_len = 24;
const char divided_asm[] = {
  0x6D, 0xB3, 0xD4, 0x6B, 0x6E, 0x6F, 0xBD, 0xF8, 0x4D, 0x3A,
  0xD1, 0xD5, 0xB3, 0x7D, 0x30, 0xA1, 0xCF, 0x45, 0x34, 0x67,
  0x66, 0x63, 0x65, 0xFB
}; 

const int xor_len = 43;
const char xor_asm[] = {
  0x6D, 0xB3, 0xD4, 0x6B, 0x6E, 0x6F, 0xBD, 0xF8, 0x4D, 0x3A,
  0xD1, 0xD5, 0xB3, 0x7D, 0x30, 0x33, 0x7D, 0x34, 0xB3, 0x75,
  0x30, 0x1B, 0x75, 0x34, 0xCF, 0xE9, 0x1B, 0xF9, 0x67, 0x66,
  0x63, 0x65, 0xFB
};

const int six_len = 30;
const char six_asm[] =
{
  0x6D, 0xB3, 0xD4, 0x6B, 0x6E, 0x6F, 0xBD, 0xF8, 0x4D, 0x3A,
  0xD1, 0xD5, 0xB3, 0x7D, 0x30, 0xA1, 0x81, 0x52, 0x3C, 0x39,
  0x38, 0xCF, 0xC1, 0xB3, 0xFA, 0x67, 0x66, 0x63, 0x65, 0xFB
}; 

uintptr_t decode_asm(const char asm_code[],int len){
	char *arr = new char[len];
	for (int i = 0; i < len; i++)
		arr[i] = asm_code[i] ^ xor_cipher;
	return (uintptr_t)arr;
}

int asm_cal(int a, int b, int mode) {
	uintptr_t addr;
	if(mode == 0)addr = decode_asm(divided_asm, divided_len);
	else if(mode == 1)addr = decode_asm(minus_asm, minus_len);
	else if (mode == 2)addr = decode_asm(xor_asm,xor_len);
	else if (mode == 3)addr = decode_asm(multi_asm,multi_len);
	else if (mode == 4)addr = decode_asm(six_asm, six_len);
	else if (mode == 5)addr = decode_asm(plus_asm, plus_len);
	else return -1;
	__asm {
		push b
		push a
		mov eax, addr
		call eax
	}
}
#pragma endregion

const char enflag[] = {
  0x0C,0x17,0x80,0x40,0x29,0x34,0x0C,0x29,0x28,0xA1,
  0x3A,0x80,0x82,0x1D,0x00,0x18,0xC3,0xCA,0x10,0x2E,
  0xD3,0x21,0x48,0xA5,0x3A,0x99,0xFB,0x46,0x0F,0xC6,
  0x78
};
#define rand100 rand()%100+1
// 线程函数, 验证flag
void judge() {
	HideFromDebugger();
	printf("Welcome to MOCSCTF, please input your flag:");
	char *input = new char[40];
	scanf("%s", input);
	if (strlen(input) != 31)printf("Failed. Please try again.");
	else {
		srand(0);
		for (int i = 0; i < 31; i++) {
			input[i] = asm_cal(input[i], rand100, 2);
			input[i] = asm_cal(input[i], rand100, 5);
			input[i] = asm_cal(input[i], rand100, 3);
			input[i] = asm_cal(input[i], rand100, 1);
			input[i] = asm_cal(input[i], rand100, 4);
			input[i] = asm_cal(input[i], 1, 0);
			if (input[i] != enflag[i])
			{
				printf("Failed. Please try again.");
				break;
			}
		}
		printf("Congratulations! You cracked this software.");
	}
}

int main()
{
	printf("Please close ida, x32dbg and ollydbg first");
	system("pause");
	if (CheckDebugExe())return 0;
	CheckDebug_SEH();
	char fake_flag[] = "MOCSCTF{I_am_a_fake_flag}";

	// 创建线程
	thread thr(judge);
	thr.join();
	return 0;
}
