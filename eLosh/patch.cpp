#include "patch.h"

Patch::Patch(Engine *e) {
    this->objEngine = e;
    // Antidbg on load.
    BYTE bAntiDebug[] = { 0x85, 0xC0, 0x0F, 0x85, 0x00, 0x00, 0x00, 0x00, 0x6A, 0x01, 0xFF, 0x15, 0x00, 0x00, 0x00, 0x00, 0x6A, 0x64 };
    DWORD dwTestAddress = this->dwFindPattern(e->hFlyff, bAntiDebug, sizeof(bAntiDebug) / sizeof(BYTE));
    DWORD dwJnzAddress = dwTestAddress + 2;

    BYTE bPatchDebug[] = { 0xEB, 0xFC, 0x90, 0x90, 0x90, 0x90 };

    //printf("Landed on: %x\nJnz address is: %x. Patching...", dwTestAddress, dwJnzAddress);

    if(this->objEngine->WriteStaticMemory(dwJnzAddress, &bPatchDebug, false)) {
        __LOG("Successfully patched anti-debugging protection!");

        return;
    }

    __LOG("Anti-debug patched failed!", 0);
}

void Patch::Range(bool restore) {
    /*
    __asm {
        push 00
        push 5a
        movss [ebp-04],xmm0
        movss [ebp+08],xmm0
    }
    */
    BYTE bPushAOB[] = { 0x6A, 0x5A, 0xF3, 0x0F, 0x11, 0x45, 0xFC, 0xF3, 0x0F, 0x11, 0x45, 0x08, 0xE8, 0x75, 0x28, 0x00, 0x00, 0x00, 0x00};
    //BYTE bPushAOB[] = { 0x6A, 0x5A };
    BYTE bRangeCallAOB[] = {
        0x75, 0x10, 0xFF, 0xB0, 0x38, 0x01, 0x00, 0x00, 0x8B, 0xCF, 0xE8, 0xB2, 0x0B, 0x00, 0x00
    };
    DWORD dwPushAddress = this->dwFindPattern(this->objEngine->hFlyff, bPushAOB, sizeof(bPushAOB) / sizeof(BYTE));
    DWORD dwJNEAddress  = this->dwFindPattern(this->objEngine->hFlyff, bRangeCallAOB, sizeof(bRangeCallAOB) / sizeof(BYTE));
    DWORD dwJAAddress   = dwPushAddress - 0x5F;
    this->dwRange       = 0x755644; // Neuz.exe+2D9980 - F3 0F10 05 4456A200   - movss xmm0,[Neuz.exe+755644]
    int r1, r2; // temp to store the results of calls.

    //printf("JA address is: %x\nJNE address is: %x", dwJAAddress, dwJNEAddress);

    BYTE bRangeOriginal[20] = {
        0x0F, 0x87, 0x93, 0x00, 0x00, 0x00,              // ja Neuz.exe+2D99C4
        0xFF, 0x24, 0x85, 0xD4, 0x99, 0x5A, 0x00,        // jmp dword ptr[eax * 4 + Neuz.exe + 2D99D4]
        0xC7, 0x45, 0x08, 0x00, 0x00, 0x00, 0x40         // mov[ebp + 08],40000000
    };
    BYTE bRangeNew[13] = {
        0x90,
        0x90,
        0x90,
        0x90,
        0x90,
        0x90,
        0xEB, 0x4D,
        0x90,
        0x90,
        0x90,
        0x90,
        0x90
    };

    BYTE bRangeCallOriginal[] = { 0x75, 0x10 };
    BYTE bRangeCallNew[]      = { 0x90, 0x90 };

    if(restore) {
        r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)dwJAAddress,  &bRangeOriginal, 20, NULL);
        r2 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)dwJNEAddress, &bRangeCallOriginal, 2, NULL);

        if(r1 & r2) {
            __LOG("Restored original rangehack instructions.", 2);
        }else {
            __LOG("Failed to restore the original rangehack instructions!", 0);
        }

        return;
    }

    r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)dwJAAddress,  &bRangeNew, 13, NULL);
    r2 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)dwJNEAddress, &bRangeCallNew, 2, NULL);

    if(r1 & r2) {
        __LOG("Successfully patched range calls.");
    }else {
        __LOG("Failed to patch the range call!", 0);
    }
}

/* original: https://github.com/Icclear/OsuBot-3.0/blob/master/Include/aobscan.cpp */
DWORD Patch::dwFindPattern(HANDLE hP, BYTE bSig[], unsigned const int uByteCount) {
#ifdef _DEBUG
    __LOG("Sigscanning -- Looking for an Array of Bytes (AoB) ...", 2);
#endif
    const static unsigned int uMultiplier = 4096;
    unsigned int uStartAddress = this->objEngine->dwNeuzBase;
    //const unsigned int uStartAddress = 0x0;
    const static unsigned int uEndAddress = 0x7FFFFFFF;
    static bool hit;

    BYTE ByteInMemory[uMultiplier];

    for (unsigned int i = uStartAddress; i < uEndAddress; i += uMultiplier - uByteCount) {
        ReadProcessMemory(hP, (LPCVOID)i, &ByteInMemory, uMultiplier, NULL);
#ifdef VERBOSE
        printf("reading: %x\n", i);
#endif
        for (unsigned int a = 0; a < uMultiplier; a++) {
            hit = true;

            for (unsigned int j = 0; j < uByteCount && hit; j++) {
                if (ByteInMemory[a + j] != bSig[j] && bSig[j] != 0x0) {
                    hit = false;
                }
                else {
#ifdef VERBOSE
                    //printf("%x is the same!\n", ByteInMemory[a + j]);
#endif
                }
            }

            if (hit) return i + a;
        }
    }
    return 0;
}