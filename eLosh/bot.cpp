#include "bot.h"

Bot::Bot(Engine *e, Entity *_e, std::map<std::string, bool>& dataBool, std::map<std::string, int>& data) {
    this->objEngine = e; // Assign engine.
    this->objEntity = _e; // Assign entity.
    this->dataBool = dataBool; // Get booleans.
    this->data     = data; // And regular data.
}

void Bot::_1v1() {
    // Anti collision check
    if (this->objEntity->iCurrentTarget != 0 && this->dataBool["collision"]) {
        if (this->iNewTargetTick && this->iNewTargetHP && (GetTickCount() - this->iNewTargetTick) > 5000 && this->iNewTargetHP == this->objEntity->iTargetHP) {
            // Can we just teleport to them?
            if (dataBool["targettp"]) {
                this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &this->objEntity->fTargetX);
                this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &this->objEntity->fTargetY);
                this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &this->objEntity->fTargetZ);
                return;
            }

            // No teleport, blacklist them...
            this->ignoredEntities.push_back(this->objEntity->iCurrentTarget);

            this->objEngine->SendESC();
            this->objEntity->iCurrentTarget = 0;
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
        if (iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0 || iCandidateLevel == 1 || iCandidateLevel > data["maxlvl"])
            continue;

        // Check if blacklisted?
        if (iCandidateTarget == this->iNewTargetLastBlacklist) {
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
        switch (eAlgorithm) {
        case BLANK: // Simplest, 2D point blank
            if (delta <= iClosestPosition) {
                // Got new closest target.
                iClosestPosition = delta;

                // Log the time when we got the target and their starting HP.
                this->iNewTargetTick = GetTickCount();
                this->iNewTargetHP = iCandidateTargetHP;

                // Sleep if any...
                if (data["delay"] > 0)
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

    }
}