#pragma once

typedef HMODULE(WINAPI* LOADLIBRARYA)(LPCSTR);

#define NTDLL_DLL L"ntdll.dll"
#define ADVAPI32_DLL L"Advapi32.dll"
#define LdrLoadDll_SW2_HASH 0xA301ECDA

#define MZ 0x5A4D

HANDLE get_function_address(HMODULE hLibrary, DWORD FunctionHash, WORD Ordinal);
HANDLE get_library_address(LPWSTR LibName, BOOL DoLoad);

typedef NTSTATUS(WINAPI* LdrLoadDll_t)(PWCHAR, ULONG, PUNICODE_STRING, PHANDLE);

typedef struct _ND_LDR_DATA_TABLE_ENTRY
{
    //struct _LIST_ENTRY InLoadOrderLinks;
    struct _LIST_ENTRY InMemoryOrderLinks;
    struct _LIST_ENTRY InInitializationOrderLinks;
    PVOID DllBase;
    PVOID EntryPoint;
    ULONG SizeOfImage;
    UNICODE_STRING FullDllName;
    UNICODE_STRING BaseDllName;
} ND_LDR_DATA_TABLE_ENTRY, *PND_LDR_DATA_TABLE_ENTRY;

typedef struct _ND_PEB_LDR_DATA
{
    ULONG Length;
    UCHAR Initialized;
    PVOID SsHandle;
    struct _LIST_ENTRY InLoadOrderModuleList;
    struct _LIST_ENTRY InMemoryOrderModuleList;
    struct _LIST_ENTRY InInitializationOrderModuleList;
} ND_PEB_LDR_DATA, *PND_PEB_LDR_DATA;

typedef struct _ND_PEB
{
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    BYTE Reserved2[1];
    PVOID Reserved3[2];
    PND_PEB_LDR_DATA Ldr;
} ND_PEB, *PND_PEB;
