#include "entity.h"
#include <iostream>
#include <chrono>
#include <math.h>

Entity::Entity(Engine *e) {
    this->objEngine = e;
}

void Entity::Tick() {
    /* Player */
    // Read X
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &this->fX);
    // Read Y
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &this->fY);
    // Read Z
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &this->fZ);
    // Read name
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwNameOffset, &this->szName, true, 32);
    // Read HP
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwHPOffset, &this->iHP);
    // Read MP
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwMPOffset, &this->iMP);
    // Read FP
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwFPOffset, &this->iFP);
    // Read Level
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwLevelOffset, &this->iLv);
    // Read number of current players around us
    this->iPlayerCount = this->getPlayers();

    /* Target */
    // Current target
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &this->iCurrentTarget);
    // Read X
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwXOffset, &this->fTargetX, false);
    // Read Y
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwYOffset, &this->fTargetY, false);
    // Read Z
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwZOffset, &this->fTargetZ, false);
    // Read name
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwNameOffset, this->szTargetName, false, 32);
    // Read HP
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwHPOffset, &this->iTargetHP, false);
    // Read MP
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwMPOffset, &this->iTargetMP, false);
    // Read FP
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwFPOffset, &this->iTargetFP, false);
    // Read Level
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwLevelOffset, &this->iTargetLv, false);
    // Read their type
    this->objEngine->ReadStaticMemory(this->iCurrentTarget + this->objEngine->dwTypeOffset, &this->iTargetType, false);
}

int Entity::getPlayers() {
    int iPlayerCount = -1; // Because we count as a player as well.

    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);
    for(int i = 0; i < iMaxInView; i++) {
        int iNewTarget;
        int iNewTargetType;

        this->objEngine->ReadStaticMemory(i * 4 + this->objEngine->dwTargetLoopBaseOffset, &iNewTarget); // This holds the ID now
        this->objEngine->ReadStaticMemory(iNewTarget + this->objEngine->dwTypeOffset, &iNewTargetType, false); // This is their type.

        if (iNewTargetType == 2) iPlayerCount++;
    }

    return (iPlayerCount > -1) ? iPlayerCount : 0;
}

void Entity::TeleportTo(float x, float y, float z) {
    bool r1, r2, r3;
    r1 = this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &x);
    r2 = this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &y);
    r3 = this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &z);
    if(r1 & r2 & r3) {
        __LOG("Teleported successfully.");
        return;
    }

    __LOG("Teleportation failed.", 0);
}

void Entity::Food(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data) {
    if (dataBool["hp"] && this->iHP < data["hp"]) {
        this->objEngine->SendKey(data["hp_key"]);
    }
    if(dataBool["mp"] && this->iMP < data["mp"])
        this->objEngine->SendKey(data["mp_key"]);
    if(dataBool["pet"]) {
        this->objEngine->SendKey(data["pet_key"]);
    }
}

/*void Entity::AoE() {
    this->inAOE = true;
    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);

    float iClosestPosition = 100000; // Max distance.
    this->iPlayerCount = 0;

    if(this->iCurrentTarget != 0) {
        std::cout << "tick: " << GetTickCount() - this->iNewTargetTick << std::endl;
        if(this->iNewTargetTick && this->iNewTargetHP && (GetTickCount() - this->iNewTargetTick) > 5000 && this->iNewTargetHP == this->iTargetHP) {
            //this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &fTargetX);
            //this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &fTargetY);
            //this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &fTargetZ);
            std::cout << "too far blacklisted~" << std::endl;
            this->blacklists.push_back(this->iCurrentTarget);
            this->SendAtk(0);
            Sleep(200);
            this->objEngine->SendESC();
            Sleep(200);
            this->iCurrentTarget = 0;

            return;
        }
        if (this->iNewTargetHP == this->iTargetHP) return;
        j++;
        this->blacklists.push_back(this->iCurrentTarget);
        std::cout << "Added " << this->iCurrentTarget << std::endl;
        this->SendAtk(0);
        Sleep(200);
        this->objEngine->SendESC();
        Sleep(200);
        this->iCurrentTarget = 0;
    }

    for(register unsigned short i = 0; i < iMaxInView; i++) { // For each possible target...
        if (j == 10) {
            std::cout << "AOE GO!" << std::endl;
            this->objEngine->SendESC();
            Sleep(500);
            this->objEngine->SendKey(3);
            Sleep(1000);
            for(int k = 0; k < 10; k++) {
                this->objEngine->SendKey(9);
                Sleep(800);
            }
            Sleep(1000);
            this->j = 0;
            //std::cout << "I caught 5 now I stop!" << std::endl;
            //Sleep(10000);
            this->blacklists.clear();
            return;
        }

        //asdadsa
        // This is our candidate.
        int iCandidateTarget;
        int iCandidateTargetType;
        int iCandidateTargetHP;
        int iCandidatePositionA; // ALL position
        float iCandidatePositionX;
        float iCandidatePositionY;
        float iCandidatePositionZ;
        int iCandidateLevel;

        // Read the ID, target type and their HP and position
        this->objEngine->ReadStaticMemory(i * 4 + this->objEngine->dwTargetLoopBaseOffset, &iCandidateTarget); // This holds the ID now
        this->objEngine->ReadStaticMemory(iCandidateTarget + 4, &iCandidateTargetType, false); // I don't know how this works. ID+4 = Type? But it should be address... :/
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwHPOffset, &iCandidateTargetHP, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwLevelOffset, &iCandidateLevel, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwAOffset, &iCandidatePositionA, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwXOffset, &iCandidatePositionX, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwYOffset, &iCandidatePositionY, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwZOffset, &iCandidatePositionZ, false);

        // Now read our own ID and compare.
        int iOwnId;
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwIdOffset, &iOwnId);
        if (iOwnId == iCandidateTarget) continue;  // No poin.

        // Check if a player.
        if (iCandidateTargetType == 2) {
            this->iPlayerCount++;
            return; // Don't do anything fishy.
        }

        // Check if out of bounds.
        if (iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0 || iCandidateLevel == 1)
            continue;

        // Check if blacklisted?
        if (std::find(blacklists.begin(), blacklists.end(), iCandidateTarget) != blacklists.end()) {
            std::cout << "blacklisted!" << std::endl;
            continue; // blacklisted.
        }

        // Log the time when we got the target and their starting HP.
        this->iNewTargetTick = GetTickCount();
        this->iNewTargetHP = iCandidateTargetHP;

        // Feed into current target selector
        this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iCandidateTarget);

        // Attack
        this->SendAtk(1);
    }
    //Sleep(10000);
}*/
