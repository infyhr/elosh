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
        void Bot(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data);
        void Food(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data);
        void SendAtk(int iAtk);

        int iBattle; // 0 || 1. Currently in battle?
        float fX; // X pos
        float fY; // Y pos
        float fZ; // Z pos
        int   iA; // A pos
        char szName[32]; // player name
        int iHP, iMP, iFP, iLv;

        int iCurrentTarget;
        int iTargeType;
        float fTargetX;
        float fTargetY;
        float fTargetZ;
        int   iTargetA;
        char szTargetName[32]; // target name
        int iTargetHP, iTargetMP, iTargetFP, iTargetLv;
        int iTargetDistance;

        // Players around us?
        int iPlayerCount;

    private:
        Engine *objEngine;
        void 
        
};