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
        DWORD dwSpeedMultiplier = 0x824;

        DWORD dwMarkerXOffset = 0x1084;
        DWORD dwMarkerZOffset = 0x108C;

        // do tu

        DWORD dwInvisibilityPointer = 0x008D947C; // STATIC
        DWORD dwInvisibilityOffset = 0x1264 + 0x100;
        #define INVISIBILITY_MAGIC_VALUE 1024

        DWORD dwCameraScrollOffset = 0x008DA9EC; // STATIC
        DWORD dwCameraMovementOffset = 0x008DA9EC; // STATIC
        DWORD dwMaxInView; // STATIC
        DWORD dwFlyingCameraOffset; // STATIC

        DWORD dwBattlePointerOffset; // STATIC
        DWORD dwBattleOffset;

        DWORD dwTargetBase;
        DWORD dwTargetIdOffset; // Like player x/y/z...
        DWORD dwTargetLoopBaseOffset;

        DWORD dwRangeCALLOffset; // STATIC
        int byteRangeArrayOriginal;
        int byteRangeArrayModified;
};