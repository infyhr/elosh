#pragma once
#include "entity.h"
#include "engine.h"
#include <map>
#include <vector>

class Entity {
    public:
        Entity(Engine *e);
        //~Entity();
        void Tick();
        void Food(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data);
        void TeleportTo(float x, float y, float z);

        int iBattle; // 0 || 1. Currently in battle?
        float fX; // X pos
        float fY; // Y pos
        float fZ; // Z pos
        char szName[32]; // player name
        int iHP, iMP, iFP, iLv;

        int iCurrentTarget;
        int iTargetType;
        float fTargetX;
        float fTargetY;
        float fTargetZ;
        char szTargetName[32]; // target name
        int iTargetHP, iTargetMP, iTargetFP, iTargetLv;
        float iTargetDistance;

        // Players around us?
        int iPlayerCount;

    private:
        Engine *objEngine;
        int getPlayers();
};