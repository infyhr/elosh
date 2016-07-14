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
        DWORD dwClickedPositionOffset; // STATIC
        DWORD dwHPOffset;
        DWORD dwMPOffset;
        DWORD dwFPOffset;
        DWORD dwNameOffset;
        DWORD dwIdOffset;
        DWORD dwPlayerOffset;
        DWORD dwLevelOffset;

        DWORD dwInvisibilityPointerOffset; // STATIC
        DWORD dwInvisibilityOffset;
        #define INVISIBILITY_MAGIC_VALUE 1024

        DWORD dwCameraScrollOffset; // STATIC
        DWORD dwCameraMovementOffset; // STATIC
        DWORD dwMaxInView; // STATIC

        DWORD dwBattlePointerOffset; // STATIC
        DWORD dwBattleOffset;

        DWORD dwTargetBase;
        DWORD dwTargetIdOffset; // Like player x/y/z...
        DWORD dwTargetLoopBaseOffset;
};