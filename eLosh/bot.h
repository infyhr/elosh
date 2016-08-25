#pragma once
#include "engine.h"
#include "entity.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Bot {
    public:
        Bot(Engine *e, Entity *_e);
        void _1v1(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data);
        void AoE(std::map<std::string, bool>& dataBool, std::map<std::string, int>& data);

    private:
        Engine *objEngine;
        Entity *objEntity;
        std::vector<int> ignoredEntities;
        std::map<std::string, bool> dataBool;
        std::map<std::string, int> data;

        int iNewTargetTick; // New target that has /just/ been selected.
        int iNewTargetHP; // and its HP.

        // AoE
        bool inAOE;
        unsigned short j;
};