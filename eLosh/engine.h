#pragma once
#include <windows.h>
#define VERSION L"Version: 1.1"

class Engine {
    public:
        Engine();
        ~Engine();
        bool Engine::ReadMemory(DWORD dwBase, DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase = true, int length = false);
        bool Engine::ReadStaticMemory(DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase = true, int length = false);
        bool Engine::WriteStaticMemory(DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase = true);
        bool Engine::WriteMemory(DWORD dwBase, DWORD dwOffset, LPVOID lpBuffer);
        void Engine::SendKey(int iKeyCode);
        void Engine::SendESC();

    private:
        HWND hwndFlyff;
        DWORD dwFlyffPID;
        
    public:
        HANDLE hFlyff;
        DWORD dwNeuzBase;
        DWORD dwPlayerBase = 0x00ADD794;

        DWORD dwTypeOffset = 4;

        DWORD dwXOffset = 0x164;
        DWORD dwYOffset = 0x168;
        DWORD dwZOffset = 0x16C;

        DWORD dwClickedX = 0x8CED54; // Neuz.exe+8CED54 (doubleclick)
        DWORD dwClickedY = 0x8CED58;
        DWORD dwClickedZ = 0x8CED5C;

        DWORD dwHPOffset = 0x720;
        DWORD dwMPOffset = 0x724;
        DWORD dwFPOffset = 0x728;
        DWORD dwNameOffset = 0xB6C;
        DWORD dwIdOffset = 0x41C; // Is this needed?
        DWORD dwLevelOffset = 0x6FC;
        DWORD dwAuthOffset = 0x768;
        DWORD dwSpeedOffset = 0x1290;
        DWORD dwSpeedMultiplier = 0x824; // it's an offset as well.

        DWORD dwMarkerXOffset = 0x1084;
        DWORD dwMarkerZOffset = 0x108C;

        DWORD dwCameraScroll = 0x8DBA10; // Neuz.exe+8DBA10
        DWORD dwCameraMovement = 0x8DB9E4; // Neuz.exe+8DB9E4
        DWORD dwMaxInView = 0xB68778; // Neuz.exe+B68778
        DWORD dwFlyingCamera = 0x8DB9FC; // Neuz.exe+8DB9FC

        DWORD dwTargetBase = 0x008DAA78;
        DWORD dwTargetIdOffset = 0x20;   
        DWORD dwTargetLoopBaseOffset = 0xB68370; // This is gotten from inspecting dwMaxInView.
};