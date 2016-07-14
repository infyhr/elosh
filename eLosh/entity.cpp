#include "entity.h"
#include <iostream>
#include <chrono>

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

// int iMaxDistance, int iSleep, int iFoodHP, int iFoodMP, int iRestartPet, 
void Entity::Bot(std::map<std::string, bool> &dataBool, Algorithm eAlgorithm, std::map<std::string, int> &data) {
    // Read maxInView (static)
    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);

    int iClosestPosition = 100000; // Max distance.
    for (register unsigned short i = 0; i < iMaxInView; i++) { // For each possible target...
        // Do we have a target?
        if (this->iCurrentTarget != 0) continue;

        // This is our candidate.
        int iCandidateTarget;
        int iCandidateTargetType;
        int iCandidateTargetHP;
        int iCandidatePositionA; // ALL position
        int iCandidateLevel;

        // Read the ID, target type and their HP and position
        this->objEngine->ReadStaticMemory(i * 4 + this->objEngine->dwTargetLoopBaseOffset, &iCandidateTarget); // This holds the ID now
        this->objEngine->ReadStaticMemory(iCandidateTarget + 4, &iCandidateTargetType, false); // I don't know how this works. ID+4 = Type? But it should be address... :/
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwHPOffset, &iCandidateTargetHP, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwLevelOffset, &iCandidateLevel, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwAOffset, &iCandidatePositionA, false);

        //printf("N: %d\ni: %d\nID: %d\nType: %d\nHP: %d\n\n", iMaxInView, i, iCandidateTarget, iCandidateTargetType, iCandidateTargetHP);

        // Now read our own ID and compare.
        int iOwnId;
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwIdOffset, &iOwnId);
        if (iOwnId == iCandidateTarget) continue;  // No poin.

        // Check if out of bounds.
        if(iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0 || iCandidateLevel == 1)
            continue;

        // Check if blacklisted.
        /*std::cout << "Blacklist: " << this->iNewTargetLastBlacklist << std::endl;
        std::cout << "Candidate: " << iCandidateTarget << std::endl;
        if ((iCandidateTarget == this->iNewTargetLastBlacklist)) {
            std::cout << "I am avoiding this target now." << std::endl;
            continue;
        }*/

        // Check out if too far away
        int delta = iCandidatePositionA - this->iA;
        if (delta > data["distance"] && dataBool["ignore"]) {
            std::cout << "ignoring..." << std::endl;
            continue;
        }

        switch(eAlgorithm) {
            case BLANK: // Simplest, 2D point blank
                if(fabs(delta) <= iClosestPosition) {
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
        if (dataBool["targettp"])
            this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &iCandidatePositionA);

        // Attack
        int iAtk = 1;
        int iTemp = NULL;
        this->objEngine->ReadStaticMemory(this->objEngine->dwBattlePointerOffset, &iTemp);
        this->objEngine->WriteStaticMemory(this->objEngine->dwBattleOffset + iTemp, &iAtk, false);

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