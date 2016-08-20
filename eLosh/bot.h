#pragma once
#include "engine.h"
#include "entity.h"
#include <map>
#include <vector>

class Bot {
    public:
        Bot(Engine *e, Entity *_e, std::map<std::string, bool> &dataBool, std::map<std::string, int> &data);
        void _1v1();

    private:
        Engine *objEngine;
        Entity *objEntity;
        std::vector<int> ignoredEntities;
        std::map<std::string, bool> dataBool;
        std::map<std::string, int> data;

        int iNewTargetTick; // New target that has /just/ been selected.
        int iNewTargetHP; // and its HP.
        
        void SendAtk(int iAtk);
};