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
        int iInvisibility;
        #define INVISIBILITY_MAGIC_VALUE 1024

        DWORD dwCameraScrollOffset; // STATIC
        DWORD dwCameraMovementOffset; // STATIC
        DWORD dwMaxInView; // STATIC

        DWORD dwBattlePointerOffset; // STATIC
        DWORD dwBattleOffset;
        int iBattle; // 0 || 1

        DWORD dwRandomTargetOffset; // STATIC
        int iRandomTarget;

        DWORD dwTargetBase;
        DWORD dwTargetIdOffset; // Like player x/y/z...
        DWORD dwTargetLoopBaseOffset;
        // Other offsets are the same as the player's...
        int iCurrentTarget;
        float fTargetX;
        float fTargetY;
        float fTargetZ;
        int iTargetA;
        char szTargetName[32]; // target name
        int iTargetHP, iTargetMP, iTargetFP, iTargetLv;
        int iTargetBotTick = GetTickCount();
        int iTargetBotHPTick;

        float fX; // X pos
        float fY; // Y pos
        float fZ; // Z pos
        int fA; // A pos
        //char szName[4]; // player name
        char szName[32];
        int iHP, iMP, iFP, iLv;
        
        int iClickedPosition;

        int iLastKilled = NULL;
};