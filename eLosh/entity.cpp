#include "entity.h"
#include <iostream>
#include <chrono>
#include <math.h>

Entity::Entity(Engine *e) {
    this->objEngine = e;

    printf("I can access, proof: %x", this->objEngine->dwXOffset);
}

void Entity::Tick() {
    /* Player */
    // Read X
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &this->fX);
    // Read Y
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &this->fY);
    // Read Z
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &this->fZ);
    // Read A
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &this->iA);
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

    /* Target */
    int __tmp;
    // Read X
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwXOffset, &this->fTargetX, false);
    // Read Y
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwYOffset, &this->fTargetY, false);
    // Read Z
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwZOffset, &this->fTargetZ, false);
    // Read A
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwAOffset, &this->iTargetA, false);
    // Read name
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwNameOffset, this->szTargetName, false, 32);
    // Read HP
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwHPOffset, &this->iTargetHP, false);
    // Read MP
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwMPOffset, &this->iTargetMP, false);
    // Read FP
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwFPOffset, &this->iTargetFP, false);
    // Read Level
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwLevelOffset, &this->iTargetLv, false);
    // Read CurrentTarget
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &this->iCurrentTarget);
}

void Entity::Food(std::map<std::string, bool> &dataBool, std::map<std::string, int> &data) {
    if(dataBool["hp"] && this->iHP < data["hp"])
        this->objEngine->SendKey(data["hp_key"]);
    if(dataBool["mp"] && this->iMP < data["mp"])
        this->objEngine->SendKey(data["mp_key"]);
    if(dataBool["pet"]) {
        this->objEngine->SendKey(data["pet_key"]);
    }
}

void Entity::SendAtk(int iAtk) {
    int iTemp = NULL;
    this->objEngine->ReadStaticMemory(this->objEngine->dwBattlePointerOffset, &iTemp);
    this->objEngine->WriteStaticMemory(this->objEngine->dwBattleOffset + iTemp, &iAtk, false);
}

// int iMaxDistance, int iSleep, int iFoodHP, int iFoodMP, int iRestartPet, 
void Entity::Bot(std::map<std::string, bool> &dataBool, Algorithm eAlgorithm, std::map<std::string, int> &data) {
    // Anti collision check
    if(this->iCurrentTarget != 0 && dataBool["collision"]) {
        //std::cout << "tick: " << GetTickCount() - this->iNewTargetTick << std::endl;
        if(this->iNewTargetTick && this->iNewTargetHP && (GetTickCount() - this->iNewTargetTick) > 5000 && this->iNewTargetHP == this->iTargetHP) {
            // Blacklist!... and teleport...
            if(dataBool["targettp"]) {
                //this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &iTargetA);
                this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &fTargetX);
                this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &fTargetY);
                this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &fTargetZ);
                return;
            }

            this->iNewTargetLastBlacklist = this->iCurrentTarget;

            this->objEngine->SendESC();
            this->SendAtk(0);
            this->iCurrentTarget = 0;
        }

        return;
    }

    // Read maxInView (static)
    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);

    float iClosestPosition = 100000; // Max distance.
    this->iPlayerCount = 0;
    for (register unsigned short i = 0; i < iMaxInView; i++) { // For each possible target...
        // Do we have a target?
        if (this->iCurrentTarget != 0) continue;

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

        /*if (iCandidateLevel < data["maxlvl"]) {
            std::cout << "manji je" << std::endl;
            continue;
        }*/

        // Check if out of bounds.
        if(iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0 || iCandidateLevel == 1 || iCandidateLevel > data["maxlvl"])
            continue;

        // Check if blacklisted?
        if(iCandidateTarget == this->iNewTargetLastBlacklist) {
            std::cout << "This target is blacklisted!" << std::endl;
            continue;
        }

        // Check out if too far away
        float delta = pow((iCandidatePositionX - this->fX), 2) +
                    pow((iCandidatePositionY - this->fY), 2) +
                    pow((iCandidatePositionZ - this->fZ), 2);
        delta = sqrt(delta);
        this->iTargetDistance = delta;
        std::cout << "Distance to target " << delta << std::endl;
        if (delta > data["distance"] && dataBool["ignore"]) {
            std::cout << "ignoring..." << std::endl;
            continue;
        }

        /*
        MAXSCROLL: 1107859072 dodat checkbox.
        */
        switch(eAlgorithm) {
            case BLANK: // Simplest, 2D point blank
                if(delta <= iClosestPosition) {
                    // Got new closest target.
                    iClosestPosition = delta;

                    // Log the time when we got the target and their starting HP.
                    this->iNewTargetTick = GetTickCount();
                    this->iNewTargetHP   = iCandidateTargetHP;

                    // Sleep if any...
                    if(data["delay"] > 0)
                        Sleep((DWORD)data["delay"] * 1000);

                    // Feed into current target selector
                    this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iCandidateTarget);
                }/*else {
                    continue; // Not the closest, not interested.
                }*/
            break;
            case NONE:
                // Just select it anyway.
                this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iCandidateTarget);
            break;
        }

        // Teleport if teleport

        // Attack
        this->SendAtk(1);

        // All good, log their position...
        /*this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwAOffset, &iCandidatePositionA, false);
        // Check if closest by subtracting ours A positions (just an idea now), 
        // add more algorithms later like Quake FastInverse with Pythagora or Fast Distance Algorithm
        if (abs(this->objEngine->fA - iCandidatePositionA) < iClosestPosition) {
            // New closest!
            iClosestPosition = this->objEngine->fA - iCandidatePositionA;

            // Feed into current target.
            this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iCandidateTarget);

            // Get the timestamp of atk
            this->objEngine->iTargetBotTick = GetTickCount();
            this->objEngine->iTargetBotHPTick = this->objEngine->iTargetHP;

            // Attack
            int iAtk = 1;
            int iTemp = NULL;
            this->objEngine->ReadStaticMemory(this->objEngine->dwBattlePointerOffset, &iTemp);
            this->objEngine->WriteStaticMemory(this->objEngine->dwBattleOffset + iTemp, &iAtk, false);
        }
        else {
            continue; // not the closest, not interested.
        }*/

    }
}