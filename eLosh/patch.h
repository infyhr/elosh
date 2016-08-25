#pragma once
#include <iostream>
#include "engine.h"

class Patch {
    public:
        Patch(Engine *e);
        void Range(bool restore = false);
        void Ground(bool restore = false);

        DWORD dwRange;

    private:
        Engine *objEngine;
        DWORD dwFindPattern(HANDLE hP, BYTE bSig[], unsigned const int uByteCount);

        // Range
        DWORD dwPushAddress;
        DWORD dwJNEAddress;
        DWORD dwJAAddress;

        // ToggleGround (flyhack)
        DWORD dwGroundFirstAddress;
        DWORD dwGroundSecondAddress;
};