#pragma once
#include "entity.h"
#include "engine.h"
#include <map>

enum Algorithm {
    BLANK = 0,
    FDA = 1,
    PYTHAGORA = 2,
};

class Entity {
    public:
        Entity(Engine *e);
        //~Entity();
        void Tick();
        void Bot(bool bNoCollision, bool bRotateCamera, bool bTeleport, Algorithm eAlgorithm, std::map<std::string, int> &data);
        
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
        //int iTargetTick; // or smth
};