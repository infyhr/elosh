#pragma once
#include "entity.h"
#include "engine.h"
#include <map>

enum Algorithm {
    BLANK = 0,
    FDA = 1,
    PYTHAGORA = 2,
    NONE = 3
};

class Entity {
    public:
        Entity(Engine *e);
        //~Entity();
        void Tick();
        void Bot(std::map<std::string, bool> &dataBool, Algorithm eAlgorithm, std::map<std::string, int> &data);
        void Food(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data);
        
        int iBattle; // 0 || 1. Currently in battle?
        float fX; // X pos
        float fY; // Y pos
        float fZ; // Z pos
        int   iA; // A pos
        char szName[32]; // player name
        int iHP, iMP, iFP, iLv;

        int iCurrentTarget;
        float fTargetX;
        float fTargetY;
        float fTargetZ;
        int   iTargetA;
        char szTargetName[32]; // target name
        int iTargetHP, iTargetMP, iTargetFP, iTargetLv;

    private:
        Engine *objEngine;
        /* Anti-collision stuff */
        int iNewTargetTick = NULL;
        int iNewTargetHP = NULL;
        int iNewTargetLastBlacklist = NULL;
};

inline int __fastcall fabs(int a) {
    int mask = (a >> (sizeof(int) * CHAR_BIT - 1));
    return (a + mask) ^ mask;
}