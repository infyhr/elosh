#include "patch.h"

Patch::Patch(Engine *e) {
    this->objEngine = e;
    // Antidbg on load.
    /*BYTE bAntiDebug[] = { 0x85, 0xC0, 0x0F, 0x85, 0x00, 0x00, 0x00, 0x00, 0x6A, 0x01, 0xFF, 0x15, 0x00, 0x00, 0x00, 0x00, 0x6A, 0x64 };
    DWORD dwTestAddress = this->dwFindPattern(e->hFlyff, bAntiDebug, sizeof(bAntiDebug) / sizeof(BYTE));
    DWORD dwJnzAddress = dwTestAddress + 2;

    BYTE bPatchDebug[] = { 0xEB, 0xFC, 0x90, 0x90, 0x90, 0x90 };

    //printf("Landed on: %x\nJnz address is: %x. Patching...", dwTestAddress, dwJnzAddress);

    if(this->objEngine->WriteStaticMemory(dwJnzAddress, &bPatchDebug, false)) {
        __LOG("Successfully patched anti-debugging protection!");

        return;
    }*/

    __LOG("Anti-debug patched failed!", 0);
}

void Patch::Ground(bool restore) {
    BYTE bGroundAOB_1[] = {
        //0x8D, 0x45, 0xE4, 0x50, 0x8D, 0x45, 0xE0, 0x50, 0x8D, 0x45, 0xF0, 0x50
        0xF3, 0x0F, 0x10, 0x45, 0xC8, 0x0F, 0x57, 0xC9, 0x0F, 0x2F, 0xC8, 0x0F, 0x86, 0x99, 0x01
    };
    BYTE bGroundAOB_2[] = {
        0x6A, 0x02, 0x6A, 0x0E, 0x8B, 0xCF

    };
    BYTE bGroundOriginal_1[] = {
        0x83, 0xBF, 0x04, 0x28, 0x00, 0x00, 0x01
    };
    BYTE bGroundOriginal_2[] = {
        0x83, 0xBE, 0x04, 0x28, 0x00, 0x00, 0x00
    };
    BYTE bGroundModified_1[7] = {
        0x83, 0xBF, 0x04, 0x28, 0x00, 0x00, 0x00 // last byte flipped
    };
    BYTE bGroundModified_2[7] = {
        0x83, 0xBE, 0x04, 0x28, 0x00, 0x00, 0x01 // last byte flipped
    };

    this->dwGroundFirstAddress = this->dwFindPattern(this->objEngine->hFlyff, bGroundAOB_1, sizeof(bGroundAOB_1) / sizeof(BYTE));
    this->dwGroundFirstAddress += 0x11;
    this->dwGroundSecondAddress = this->dwFindPattern(this->objEngine->hFlyff, bGroundAOB_2, sizeof(bGroundAOB_2) / sizeof(BYTE));
    this->dwGroundSecondAddress += 0x7A;

    if(restore) {
        r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwGroundFirstAddress, &bGroundOriginal_1, 7, NULL);
        r2 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwGroundSecondAddress, &bGroundOriginal_2, 7, NULL);

        if (r1 & r2) {
            __LOG("Flyhack disabled.", 2);
        }
        else {
            __LOG("Failed to disable flyhack!", 0);
        }

        return;
    }

    r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwGroundFirstAddress,  &bGroundModified_1, 7, NULL);
    r2 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwGroundSecondAddress, &bGroundModified_2, 7, NULL);

    if (r1 & r2) {
        __LOG("Successfully patched fly hack.");
    }
    else {
        __LOG("Failed to patch the fly hack!", 0);
    }
}

void Patch::DoubleDamage(bool restore) {
    BYTE bDoubleDamageAOB[] = {
        0x6A, 0x05, 0x6A, 0x01, 0x6A, 0x17
    };
    BYTE bDoubleDamageNew[2] = {
        0x6A, 0x1A
    };
    BYTE bDoubleDamageOriginal[3][2] = {
        { 0x6A, 0x17 },
        { 0x6A, 0x18 },
        { 0x6A, 0x19 }
    };
    DWORD dwAobAddress;
    DWORD iFirstHop = 4;
    DWORD iSecondHop = 0x1F;
    DWORD iThirdHop = 0x3A;

    if (restore) {
        for (int i = 0; i < 3; i++) {
            r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwDDAddresses[i], &bDoubleDamageOriginal[i], 2, NULL);
        }
        if (r1) {
            __LOG("Successfully restored the double damage hack");
        }
        else {
            __LOG("Failed to restore the double damage.", 0);
        }
        return;
    }

    dwAobAddress = this->dwFindPattern(this->objEngine->hFlyff, bDoubleDamageAOB, sizeof(bDoubleDamageAOB) / sizeof(BYTE));
    this->dwDDAddresses[0] = dwAobAddress + iFirstHop;
    this->dwDDAddresses[1] = dwAobAddress + iSecondHop;
    this->dwDDAddresses[2] = dwAobAddress + iThirdHop;

    for(int i = 0; i < 3; i++) {
        r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwDDAddresses[i], &bDoubleDamageNew, 2, NULL);
    }

    if(r1) {
        __LOG("Successfully patched double damage");
    }else {
        __LOG("Failed to patch the double damage.", 0);
    }
}

void Patch::Range(bool restore) {
    /*
    015D9988 - 6A 00                 - push 00
    015D998A - 6A 5A                 - push 5A
    015D998C - F3 0F11 45 FC         - movss [ebp-04],xmm0
    015D9991 - F3 0F11 45 08         - movss [ebp+08],xmm0
    015D9996 - E8 75280000           - call 015DC210
    */
    BYTE bPushAOB[] = { 0x6A, 0x5A, 0xF3, 0x0F, 0x11, 0x45, 0xFC, 0xF3, 0x0F, 0x11, 0x45, 0x08, 0xE8, 0x75, 0x28, 0x00, 0x00, 0x00, 0x00 };
    /*
    015D8D5F - 75 10                 - jne 015D8D71
    015D8D61 - FF B0 38010000        - push [eax+00000138]
    015D8D67 - 8B CF                 - mov ecx,edi
    015D8D69 - E8 B20B0000           - call 015D9920
    */
    BYTE bRangeCallAOB[] = { 
        0x75, 0x10, 0xFF, 0xB0, 0x38, 0x01, 0x00, 0x00, 0x8B, 0xCF, 0xE8, 0xB2, 0x0B, 0x00, 0x00
    };
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
        0xEB, 0x4D, // jmp
        0x90,
        0x90,
        0x90,
        0x90,
        0x90
    };
    BYTE bRangeCallOriginal[] = { 0x75, 0x10 };
    BYTE bRangeCallNew[]      = { 0x90, 0x90 };

    // Restore to original values.
    if (restore) {
        r1 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwJAAddress,  &bRangeOriginal, 20, NULL);
        r2 = WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)this->dwJNEAddress, &bRangeCallOriginal, 2, NULL);

        if (r1 & r2) {
            __LOG("Restored original rangehack instructions.", 2);
        }
        else {
            __LOG("Failed to restore the original rangehack instructions!", 0);
        }

        return;
    }

    // Patch it up.
    this->dwPushAddress = this->dwFindPattern(this->objEngine->hFlyff, bPushAOB, sizeof(bPushAOB) / sizeof(BYTE));
    this->dwJNEAddress  = this->dwFindPattern(this->objEngine->hFlyff, bRangeCallAOB, sizeof(bRangeCallAOB) / sizeof(BYTE));
    this->dwJAAddress   = dwPushAddress - 0x5F;
    this->dwRange       = 0x755644; // Neuz.exe+2D9980 - F3 0F10 05 4456A200   - movss xmm0,[Neuz.exe+755644]

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