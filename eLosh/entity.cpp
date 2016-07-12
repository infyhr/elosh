#include "entity.h"
#include <iostream>

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

// int iMaxDistance, int iSleep, int iFoodHP, int iFoodMP, int iRestartPet, 
void Entity::Bot(bool bNoCollision, bool bRotateCamera, bool bTeleport, Algorithm eAlgorithm, std::map<std::string, int> &data) {
    /*if(this->objEngine->iCurrentTarget != 0) {
        // Check if we attack in reasonable time.
        if ((GetTickCount() - this->objEngine->iTargetBotTick) > 5000 && this->objEngine->iTargetBotHPTick == this->objEngine->iTargetHP) {
            std::cout << this->objEngine->iTargetBotHPTick << std::endl;
            std::cout << this->objEngine->iTargetHP << std::endl;

            int aa = 0;
            this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &aa);
        }
    }*/

    // Read maxInView (static)
    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);

    int iClosestPosition = 1000000; // Max distance.
    for (register unsigned short i = 0; i < iMaxInView; i++) { // For each possible target...
                                                               // Do we have a target? If so, there is no point in this...
        if (this->iCurrentTarget != 0) return;

        // This is our candidate.
        int iCandidateTarget;
        int iCandidateTargetType;
        int iCandidateTargetHP;
        int iCandidatePositionA; // ALL position
        int iCandidateLevel;

        // Read the ID, target type and their HP.
        this->objEngine->ReadStaticMemory(i * 4 + this->objEngine->dwTargetLoopBaseOffset, &iCandidateTarget); // This holds the ID now
        this->objEngine->ReadStaticMemory(iCandidateTarget + 4, &iCandidateTargetType, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwHPOffset, &iCandidateTargetHP, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwLevelOffset, &iCandidateLevel, false);

        printf("N: %d\ni: %d\nID: %d\nType: %d\nHP: %d\n\n", iMaxInView, i, iCandidateTarget, iCandidateTargetType, iCandidateTargetHP);

        // Now read our own ID and compare.
        int iOwnId;
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwIdOffset, &iOwnId);
        if (iOwnId == iCandidateTarget) continue;  // No point.

                                                   // Check if out of bounds.
        if (iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0 || iCandidateLevel == 1) continue;

        // All good, log their position...
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwAOffset, &iCandidatePositionA, false);
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
        }

    }
}