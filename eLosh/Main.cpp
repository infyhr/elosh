#include "Main.h"
#include "engine.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args) {
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    freopen("CON", "w", stdout);

    Engine *e = new Engine;

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    eLosh::Main form(e);
    Application::Run(%form);

    FreeConsole();
}

// Tick event, update everything here
System::Void eLosh::Main::tick(System::Object ^ sender, System::EventArgs ^ e) {
    /* === UPDATE EVERYTHING FOR THE PLAYER === */
    // Read X
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &this->objEngine->fX);
    this->tb_x_readonly->Text = Convert::ToString(this->objEngine->fX);
    // Read Y
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &this->objEngine->fY);
    this->tb_y_readonly->Text = Convert::ToString(this->objEngine->fY);
    // Read Z
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &this->objEngine->fZ);
    this->tb_z_readonly->Text = Convert::ToString(this->objEngine->fZ);
    // Read A
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &this->objEngine->fA);
    this->tb_a_readonly->Text = Convert::ToString(this->objEngine->fA);
    // Read name
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwNameOffset, &this->objEngine->szName, true, 32);
    this->tb_character_name->Text = gcnew String(this->objEngine->szName);
    // Read HP
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwHPOffset, &this->objEngine->iHP);
    this->tb_character_hp->Text = Convert::ToString(this->objEngine->iHP);
    // Read MP
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwMPOffset, &this->objEngine->iMP);
    this->tb_character_mp->Text = Convert::ToString(this->objEngine->iMP);
    // Read FP
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwFPOffset, &this->objEngine->iFP);
    this->tb_character_fp->Text = Convert::ToString(this->objEngine->iFP);
    // Read Level
    this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwLevelOffset, &this->objEngine->iLv);
    this->tb_character_level->Text = Convert::ToString(this->objEngine->iLv);

    /* === UPDATE EVERYTHING FOR THE TARGET === */
    int __tmp;
    // Read X
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwXOffset, &this->objEngine->fTargetX, false);
    this->tb_target_x->Text = Convert::ToString(this->objEngine->fTargetX);
    // Read Y
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwYOffset, &this->objEngine->fTargetY, false);
    this->tb_target_y->Text = Convert::ToString(this->objEngine->fTargetY);
    // Read Z
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwZOffset, &this->objEngine->fTargetZ, false);
    this->tb_target_z->Text = Convert::ToString(this->objEngine->fTargetZ);
    // Read A
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwAOffset, &this->objEngine->iTargetA, false);
    this->tb_target_a->Text = Convert::ToString(this->objEngine->iTargetA);
    // Read name
    //char *test = new char[32];
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwNameOffset, this->objEngine->szTargetName, false, 32);
    //std::cout << this->objEngine->szTargetName << std::endl;
    //System::String^ a = Convert::ToString(this->objEngine->szTargetName);
    this->tb_target_name->Text = gcnew String(this->objEngine->szTargetName);
    // Read HP
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwHPOffset, &this->objEngine->iTargetHP, false);
    this->tb_target_hp->Text = Convert::ToString(this->objEngine->iTargetHP);
    // Read MP
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwMPOffset, &this->objEngine->iTargetMP, false);
    this->tb_target_mp->Text = Convert::ToString(this->objEngine->iTargetMP);
    // Read FP
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwFPOffset, &this->objEngine->iTargetFP, false);
    this->tb_target_fp->Text = Convert::ToString(this->objEngine->iTargetFP);
    // Read Level
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &__tmp);
    this->objEngine->ReadStaticMemory(__tmp + this->objEngine->dwLevelOffset, &this->objEngine->iTargetLv, false);
    this->tb_target_level->Text = Convert::ToString(this->objEngine->iTargetLv);
    // Read CurrentTarget
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &this->objEngine->iCurrentTarget);

    /* === TELEPORT TO CLICK? === */
    if(this->cb_teleport_click->Checked && (GetAsyncKeyState(VK_LBUTTON) & 0x1)) {
        // Find out the current "click" position.
        this->objEngine->ReadStaticMemory(this->objEngine->dwClickedPositionOffset, &this->objEngine->iClickedPosition);
        
        // Delta correction
        this->objEngine->iClickedPosition += Convert::ToInt32(this->numeric_tpdelta->Text);

#ifdef _DEBUG
        this->richtb_debug->Text = this->richtb_debug->Text + "Want to go here: " + this->objEngine->iClickedPosition + "\r\n";
#endif

        // Check if the current position is NOT the same as the wanted position, if so update!
        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &this->objEngine->iClickedPosition);
    }

    /* === BOT === */
    // Check whether the bot is even active
    if(this->cb_bot_active->Checked) {
        this->Bot();
    }

    return System::Void();
}

// Thanks to: lava phox
System::Void eLosh::Main::Bot() {
    // Read maxInView (static)
    int iMaxInView;
    this->objEngine->ReadStaticMemory(this->objEngine->dwMaxInView, &iMaxInView);

    int iClosestPosition = 1000000; // Max distance
    for (register unsigned short i = 0; i < iMaxInView; i++) { // For each possible target...
        // Do we have a target? If so, there is no point in this...
        if (this->objEngine->iCurrentTarget != 0) return;

        // This is our candidate.
        int iCandidateTarget;
        int iCandidateTargetType;
        int iCandidateTargetHP;
        int iCandidatePositionA; // ALL position

        // Read the ID, target type and their HP.
        this->objEngine->ReadStaticMemory(i * 4 + this->objEngine->dwTargetLoopBaseOffset, &iCandidateTarget); // This holds the ID now
        this->objEngine->ReadStaticMemory(iCandidateTarget + 4, &iCandidateTargetType, false);
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwHPOffset, &iCandidateTargetHP, false);

        printf("N: %d\ni: %d\nID: %d\nType: %d\nHP: %d\n\n", iMaxInView, i, iCandidateTarget, iCandidateTargetType, iCandidateTargetHP);

        // Now read our own ID and compare.
        int iOwnId;
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwIdOffset, &iOwnId);
        if (iOwnId == iCandidateTarget) continue;  // No point.

        // Check if out of bounds.
        if (iCandidateTarget >= 100000000 || iCandidateTargetType != 18 || iCandidateTargetHP == 0) continue;

        // All good, log their position...
        this->objEngine->ReadStaticMemory(iCandidateTarget + this->objEngine->dwAOffset, &iCandidatePositionA, false);
        // Check if closest by subtracting ours A positions (just an idea now), 
        // add more algorithms later like Quake FastInverse with Pythagora or Fast Distance Algorithm
        if (abs(this->objEngine->fA - iCandidatePositionA) < iClosestPosition) {
            // New closest!
            iClosestPosition = this->objEngine->fA - iCandidatePositionA;
            // Feed into current target.
            this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iCandidateTarget);

            // Attack
            int iAtk = 1;
            int iTemp = NULL;
            this->objEngine->ReadStaticMemory(this->objEngine->dwBattlePointerOffset, &iTemp);
            this->objEngine->WriteStaticMemory(this->objEngine->dwBattleOffset + iTemp, &iAtk, false);
        }else {
            continue; // not the closest, not interested.
        }

    }
}

/*System::Void eLosh::Main::Bot() {
    int iHpTemp; // Get target health
    int iHpOwn; // Own health
    int iTemp = NULL; // temp
    this->objEngine->ReadStaticMemory(this->objEngine->dwBattlePointerOffset, &iTemp);
    this->objEngine->ReadStaticMemory(this->objEngine->dwBattleOffset + iTemp, &this->objEngine->iBattle, false);

    // Get the current target.
    this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &this->objEngine->iCurrentTarget);
    //if(this->objEngine->iBattle == 0) { // We are NOT in battle, so pick a new target.
    if (this->objEngine->iCurrentTarget == 0) { // No target!
        // Get a candidate.
        this->objEngine->ReadStaticMemory(this->objEngine->dwRandomTargetOffset, &this->objEngine->iRandomTarget);

        std::cout << "got a new random target " << this->objEngine->iRandomTarget << std::endl;
        if (this->objEngine->iRandomTarget == this->objEngine->iLastKilled) {
            std::cout << "new target is the same as the last killed! Avoiding SEGFAULT..." << std::endl;
            return;
        }

        // Feed that into the current target.
        this->objEngine->WriteMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &this->objEngine->iRandomTarget);

        // Check our new (which is current) target HP.
        this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iHpTemp);
        this->objEngine->ReadStaticMemory(iHpTemp + this->objEngine->dwHPOffset, &iHpTemp, false);

        // If the health is 0... then return.
        if (iHpTemp <= 0) return;

        std::cout << "their hp: " << iHpTemp << "  my hp: " << iHpOwn << std::endl;

        int iAtk = 1; // construct atk magic
        this->objEngine->WriteStaticMemory(this->objEngine->dwBattleOffset + iTemp, &iAtk, false);
    }
    else {
        //std::cout << "we are in battle?" << std::endl;
        // We are in battle, check HP?
        this->objEngine->ReadMemory(this->objEngine->dwTargetBase, this->objEngine->dwTargetIdOffset, &iHpTemp);
        this->objEngine->ReadStaticMemory(iHpTemp + this->objEngine->dwHPOffset, &iHpTemp, false);
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwHPOffset, &iHpOwn);

        std::cout << "their hp: " << iHpTemp << std::endl;

        // Or, perhaps, if we selected ourselves.
        if (iHpTemp == iHpOwn) return;

        // If the target HP is... 0, then stop.
        if (iHpTemp == 0) {
            this->objEngine->iLastKilled = this->objEngine->iCurrentTarget;
            std::cout << "I killed " << this->objEngine->iLastKilled << std::endl;
            this->objEngine->iCurrentTarget = 0; // reset
            return;
        }
    }

    // Rotate the camera now?
    if (this->cb_bot_rotatecamera->Checked) {
        int iCameraMovementCurrent;
        this->objEngine->ReadStaticMemory(this->objEngine->dwCameraMovementOffset, &iCameraMovementCurrent);
        if (iCameraMovementCurrent > 1135713252)
            iCameraMovementCurrent = 1070000000;

        iCameraMovementCurrent += 1000000;
        this->objEngine->WriteStaticMemory(this->objEngine->dwCameraMovementOffset, &iCameraMovementCurrent);
    }
}*/

System::Void eLosh::Main::btn_getcoordinates_Click(System::Object^  sender, System::EventArgs^  e) {
    this->tb_x->Text = this->tb_x_readonly->Text;
    this->tb_y->Text = this->tb_y_readonly->Text;
    this->tb_z->Text = this->tb_z_readonly->Text;
    this->tb_a->Text = this->tb_a_readonly->Text;
}

System::Void eLosh::Main::btn_teleport_Click(System::Object^  sender, System::EventArgs^  e) {
    // Do the teleport
    // Check if we are teleporting to A? If so, do it and return.
    if(this->cb_teleport_a->Checked) {
        int temp = Convert::ToInt32(this->tb_a->Text);
        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &temp); // Looking for the ADDRESS of the variable temp
        return;
    }

    // We are teleporting to some exact coordinates, so just teleport!
    float temp_x = Convert::ToDouble(this->tb_x->Text);
    float temp_y = Convert::ToDouble(this->tb_y->Text);
    float temp_z = Convert::ToDouble(this->tb_z->Text);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &temp_x);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &temp_y);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &temp_z);
}

// 
System::Void eLosh::Main::cb_invisibility_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    int iTemp;
    if(!this->objEngine->ReadStaticMemory(this->objEngine->dwInvisibilityPointerOffset, &iTemp)) return;
    // iTemp + this->objEngine->dwInivisibilityOffset;

    //std::cout << "To write: " << iToWrite << std::endl << iTemp + this->objEngine->dwInvisibilityOffset << std::endl;

    int iToWrite = (this->cb_invisibility->Checked ? INVISIBILITY_MAGIC_VALUE : 0);

    //WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)(iTemp + this->objEngine->dwInvisibilityOffset), &iToWrite, sizeof(&iToWrite), NULL);
    this->objEngine->WriteStaticMemory(iTemp + this->objEngine->dwInvisibilityOffset, &iToWrite, false);
}

// Add a coordinate to the coordinate logger.
System::Void eLosh::Main::btn_add_Click(System::Object^  sender, System::EventArgs^  e) {
    int iRowCount = this->listView->Items->Count; // Get the row count

    // Add the current coordinates to the list.
    this->listView->Items->Add(this->tb_posname->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_x_readonly->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_y_readonly->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_z_readonly->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_a_readonly->Text);

    // Remove the name, make it more convenient.
    this->tb_posname->Text = "";
}

// Remove a coordinate from the coordinate logger.
System::Void eLosh::Main::btn_remove_Click(System::Object^  sender, System::EventArgs^  e) {
    // Loop through all of them and see which ones are selected, delete those who are.
    for(int i = this->listView->Items->Count - 1; i >= 0; i--) {
        if(this->listView->Items[i]->Selected) this->listView->Items[i]->Remove();
    }
}

// Coordinate clicked.
System::Void eLosh::Main::listView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
    /* This is a common problem. Unlike a ListBox or several other controls, when you change the selection in a ListView it will raise the SelectedIndexChanged event twice: once as it deselects the previously-selected item and the second time as it selects the new item. Because no items are selected when the event is raised the first time, your attempt to access the first selected item fails. You must add an If statement to check that there is at least one selected item and only try to access it if there is. */
    if(this->listView->SelectedItems->Count <= 0) return;

    // Feed the selected item into the wanted coordinate.
    // SubItems -> columns, SelectedItems -> koliko ih selectirash (poplavish).
    this->tb_x->Text = this->listView->SelectedItems[0]->SubItems[1]->Text; // X
    this->tb_y->Text = this->listView->SelectedItems[0]->SubItems[2]->Text; // Y
    this->tb_z->Text = this->listView->SelectedItems[0]->SubItems[3]->Text; // Z
    this->tb_a->Text = this->listView->SelectedItems[0]->SubItems[4]->Text; // A
}

// Figure out the delta between teleports automatically
System::Void eLosh::Main::btn_figuredelta_Click(System::Object^  sender, System::EventArgs^  e) {
    // current+X=wanted.
    this->numeric_tpdelta->Text = Convert::ToString(this->objEngine->iClickedPosition - this->objEngine->fA);
}