#pragma once
#include <windows.h>
#define VERSION L"Version: 1.1"

class Engine {
    public:
        Engine();
        ~Engine();
        bool Engine::ReadMemory(DWORD dwBase, DWORD dwOffset, LPVOID lpBuffer);
        bool Engine::ReadStaticMemory(DWORD dwOffset, LPVOID lpBuffer);
        bool Engine::WriteStaticMemory(DWORD dwOffset, LPVOID lpBuffer, bool doNeuzBase = true);
        bool Engine::WriteMemory(DWORD dwBase, DWORD dwOffset, LPVOID lpBuffer);

    private:
        HWND hwndFlyff;
        DWORD dwFlyffPID;
        

    public:
        HANDLE hFlyff;
        DWORD dwNeuzBase;
        DWORD dwPlayerBase;

        DWORD dwXOffset;
        DWORD dwYOffset;
        DWORD dwZOffset;
        DWORD dwAOffset;

        DWORD dwInvisibilityPointerOffset; // STATIC
        DWORD dwInvisibilityOffset;

        DWORD dwClickedPositionOffset; // STATIC

        DWORD dwCameraScrollOffset;

        int iInvisibility;
        #define INVISIBILITY_MAGIC_VALUE 1024

        float fX; // X pos
        float fY; // Y pos
        float fZ; // Z pos
        int fA; // A pos
        
        int iClickedPosition;
};