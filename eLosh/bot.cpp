#include "bot.h"

Bot::Bot(Engine *e, Entity *_e) {
    this->objEngine = e; // Assign engine.
    this->objEntity = _e; // Assign entity.
    this->dataBool = dataBool; // Get booleans.
    this->data     = data; // And regular data.
}

void Bot::_1v1(std::map<std::string, bool>& dataBool, std::map<std::string, int>& data) {
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
            __LOG("Current target blacklisted.", 2);

            this->objEngine->SendESC();
            this->objEntity->iCurrentTarget = 0;
        }

        return;
    }

    // Read maxInView (static)
    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);

    float iClosestPosition = 100000; // Max distance.
    for (register unsigned short i = 0; i < iMaxInView; i++) { // For each possible target...
        if (this->objEntity->iCurrentTarget != 0) continue; // Do we have a target?

        // This is our candidate.
        int iCandidateTarget;
        int iCandidateTargetType;
        int iCandidateTargetHP;
        float iCandidatePositionX;
        float iCandidatePositionY;
        float iCandidatePositionZ;
        int iCandidateLevel;

        // Read the ID, target type and their HP and position
        this->objEngine->ReadStaticMemory(i * 4 + this->objEngine->dwTargetLoopBaseOffset, &iCandidateTarget); // This holds the ID now
        this->objEngine->ReadStaticMemory(iCandidateTarget + 4, &iCandidateTargetType, false); // I don't know how this works. ID+4 = Type? But it should be address... :/
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwHPOffset, &iCandidateTargetHP, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwLevelOffset, &iCandidateLevel, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwXOffset, &iCandidatePositionX, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwYOffset, &iCandidatePositionY, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwZOffset, &iCandidatePositionZ, false);

        // Now read our own ID and compare.
        int iOwnId;
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwIdOffset, &iOwnId);
        if (iOwnId == iCandidateTarget) continue;  // No point.

        // Check if a player.
        if(iCandidateTargetType == 2) {
            __LOG("There is a player nearby, time to give up...", 2);
            return; // Don't do anything fishy.
        }

        // Check if out of bounds.
        if (iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0 || iCandidateLevel < 10 || iCandidateLevel > data["maxlvl"]) {
            __LOG("Candidate out of bounds.", 2);
            continue;
        }

        // Check if blacklisted?
        /*if (iCandidateTarget == this->iNewTargetLastBlacklist) {
            std::cout << "This target is blacklisted!" << std::endl;
            continue;
        }*/
        if(std::find(this->ignoredEntities.begin(), this->ignoredEntities.end(), iCandidateTarget) != this->ignoredEntities.end()) {
            __LOG("Candidate blacklisted already!", 2);
            continue;
        }

        // Check the distance betwee two points -- just simple Pythagorea.
        float delta = pow((iCandidatePositionX - this->objEntity->fX), 2) +
                      pow((iCandidatePositionY - this->objEntity->fY), 2) +
                      pow((iCandidatePositionZ - this->objEntity->fZ), 2);
        delta = sqrt(delta);
        this->objEntity->iTargetDistance = delta;
        if (delta > data["distance"] && dataBool["ignore"]) {
            __LOG("Target too far away...", 2);
            continue;
        }

        if(delta <= iClosestPosition) {
            // Got new closest target.
            iClosestPosition = delta;

            // Log the time when we got the target and their starting HP.
            this->iNewTargetTick = GetTickCount();
            this->iNewTargetHP   = iCandidateTargetHP;

            // Sleep if any...
            if (data["delay"] > 0)
                Sleep((DWORD)data["delay"] * 1000);

            // Feed into current target selector
            this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iCandidateTarget);
        }

        // Teleport to target if we must.
        if(dataBool["targettp"]) {
            __LOG("Teleporting to target...", 2);
            this->objEntity->TeleportTo(iCandidatePositionX, iCandidatePositionY, iCandidatePositionZ);
        }

        // Attack
        this->objEngine->SendKey(0); // F1
    }
}