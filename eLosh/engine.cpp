/*
The engine itself, about everything related to the memory is handled here.
*/

#include "engine.h"
#include <iostream>
#include <chrono>
#include <TlHelp32.h>
#include <tchar.h>
#include <windows.h>
#include <map>
#pragma comment(lib, "user32.lib")

DWORD getNeuz(DWORD targetPID) {
    HANDLE hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, targetPID);
    MODULEENTRY32 me32;
    me32.dwSize = sizeof(MODULEENTRY32);
    Module32First(hModuleSnap, &me32);
    printf("Neuz.exe base address = %x\n", (DWORD)me32.modBaseAddr);
    CloseHandle(hModuleSnap);
    return (DWORD)me32.modBaseAddr;
}

Engine::Engine() {
    std::cout << "Loaded " << std::endl;

    // Try to find the window
    this->hwndFlyff = FindWindow(0, "Insanity Flyff");
    if (!this->hwndFlyff) {
#ifdef _DEBUG
        std::cout << "Cannot find the FlyFF window!" << std::endl;
#endif
        exit(1);
        return;
    }

    // Get the PID
    GetWindowThreadProcessId(this->hwndFlyff, &this->dwFlyffPID);
    if (this->dwFlyffPID == 0) {
#ifdef _DEBUG
        std::cout << "Cannot get the PID." << std::endl;
#endif
        return;
    }

    // Get the handle
    //this->hFlyff = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, false, this->dwFlyffPID);
    this->hFlyff = OpenProcess(PROCESS_ALL_ACCESS, false, this->dwFlyffPID);
    if (this->hFlyff == NULL) {
#ifdef _DEBUG
        std::cout << "Cannot retrieve the handle" << std::endl;
#endif
    }

    // Find the base load address.
    this->dwNeuzBase = getNeuz(this->dwFlyffPID);

    // read test
    /*int temp; // Neuz.exe+0x008D947C
    if (this->ReadStaticMemory(0x008D947C, &temp)) {
        printf("temp adresa je %x\n", temp);
        // temp + 0x1264
        int temp2 = 1024;
        DWORD aa = temp + 0x1264 + 0x100;
        printf("novo: %x\n", temp+0x1264+0x100);
        //this->WriteMemory(temp + 0x1264, 0x100, &temp2);
        WriteProcessMemory(this->hFlyff, (LPVOID)(aa), &temp2, sizeof(&temp2), NULL);
        //this->ReadStaticMemory(aa, &temp2);
        //this->ReadMemory(temp, 0x00001264, &temp2);
        std::cout << temp2 << std::endl;
    }*/

    // read test
    /*int temp; // Neuz.exe+9BDAA8
    if (this->ReadStaticMemory(0x009BDAA8, &temp)) {
        int temp2;
        printf("temp adresa je: %x\n", temp);
        printf("novo: temp+0x7624 = ", temp+0x7624);
        this->ReadStaticMemory(temp+0x7624, &temp2);
        std::cout << "temp2: " << temp2 << std::endl;
    }*/
}
Engine::~Engine(){
    CloseHandle(this->hFlyff);
}

void Engine::SendESC() {
    PostMessage(this->hwndFlyff, WM_KEYDOWN, VK_ESCAPE, MapVirtualKey(VK_ESCAPE, MAPVK_VK_TO_VSC));
    Sleep(20);
    PostMessage(this->hwndFlyff, WM_KEYUP, VK_ESCAPE, MapVirtualKey(VK_ESCAPE, MAPVK_VK_TO_VSC));
}

void Engine::SendKey(int iKeyIndex) {
    std::map<int, int> keymap;
    for(int i = 0; i < 12; i++) {
        keymap[i] = 112 + i;
    }

    auto iKeyCode = keymap[iKeyIndex];
    PostMessage(this->hwndFlyff, WM_KEYDOWN, iKeyCode, MapVirtualKey(iKeyCode, MAPVK_VK_TO_VSC));
    Sleep(20);
    PostMessage(this->hwndFlyff, WM_KEYUP, iKeyCode, MapVirtualKey(iKeyCode, MAPVK_VK_TO_VSC));
}

bool Engine::ReadStaticMemory(DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase, int length) {
    if(!ReadProcessMemory(this->hFlyff, (LPCVOID)((doNeuzBase ? dwNeuzBase : 0) + dwOffset), lpBuffer, (length ? length : sizeof(lpBuffer)), NULL)) return false;

    return true;
}

bool Engine::ReadMemory(DWORD dwBase, DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase, int length) {
    int temp; // This will be the base pointer.

    if(!ReadProcessMemory(this->hFlyff, (LPCVOID)((doNeuzBase ? dwNeuzBase : 0) + dwBase), &temp, 4, NULL)) return false;
    if(!ReadProcessMemory(this->hFlyff, (LPCVOID)(temp + dwOffset), lpBuffer, (length ? length : sizeof(lpBuffer)), NULL)) return false;

    return true;
}

bool Engine::WriteStaticMemory(DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase) {
    if(!WriteProcessMemory(this->hFlyff, (LPVOID)((doNeuzBase ? dwNeuzBase : 0) + dwOffset), lpBuffer, sizeof(lpBuffer), NULL)) return false;

    return true;
}

bool Engine::WriteMemory(DWORD dwBase, DWORD dwOffset, LPVOID lpBuffer) {
    int temp; // This will be the base pointer.

    if(!ReadProcessMemory(this->hFlyff, (LPCVOID)(this->dwNeuzBase + dwBase), &temp, 4, NULL)) return false;

    // temp+dwOffset
#ifdef _DEBUG
    /*printf("temp is %x\n", temp);
    std::cout << "Got ADDRESS of the value: " << lpBuffer << std::endl;
    printf("writing to %x\n", temp+dwOffset);*/
#endif

    if(!WriteProcessMemory(this->hFlyff, (LPVOID)(temp+dwOffset), lpBuffer, sizeof(lpBuffer), NULL)) return false;

    return true;
}
