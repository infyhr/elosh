#include "Main.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args) {
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    freopen("CON", "w", stdout);

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    std::cout << "eLosh initialized..." << std::endl;

    //eLosh::Main form(e);
    eLosh::Main form;
    Application::Run(%form);

    FreeConsole();
}

eLosh::Main::Main() {
    Engine *e  = new Engine;
    this->objEngine = e;
    Entity *e_ = new Entity(e);
    this->objEntity = e_;

    InitializeComponent();

    this->timer->Interval = 100; // 100ms
    this->combobox_bot_pet->SelectedIndex = 2;
    this->combobox_bot_eatmp->SelectedIndex = 1;
    this->combobox_bot_eathp->SelectedIndex = 0;

    this->timerBuff->Interval = 600000; // 10 min
}

eLosh::Main::~Main() {
    if (components) {
        delete components;
    }
}

System::Void eLosh::Main::tickBuff(System::Object ^ sender, System::EventArgs ^ e) {
    std::cout << "Taking autobuff..." << std::endl;
    if (!cb_autobuff->Checked) return;
    this->cb_bot_active->Checked = false;
    Sleep(500);
    this->objEngine->SendESC();
    Sleep(500);
    this->objEntity->SendAtk(0);
    Sleep(500);
    this->objEntity->iCurrentTarget = 0;
    Sleep(500);
    this->objEngine->SendESC();
    Sleep(15000);
    this->objEngine->SendKey(9);
    Sleep(15000);
    this->objEngine->SendESC();
    Sleep(500);
    this->objEntity->iNewTargetLastBlacklist = NULL; // Remove any blacklists.
    this->cb_bot_active->Checked = true;
}

// Tick event, update everything here
System::Void eLosh::Main::tick(System::Object ^ sender, System::EventArgs ^ e) {
    this->objEntity->Tick();

    /* === UPDATE EVERYTHING FOR THE PLAYER === */
    // Feed X
    this->tb_x_readonly->Text = Convert::ToString(this->objEntity->fX);
    // Read Y
    this->tb_y_readonly->Text = Convert::ToString(this->objEntity->fY);
    // Read Z
    this->tb_z_readonly->Text = Convert::ToString(this->objEntity->fZ);
    // Read name
    this->tb_character_name->Text = gcnew String(this->objEntity->szName);
    // Read HP
    this->tb_character_hp->Text = Convert::ToString(this->objEntity->iHP);
    // Read MP
    this->tb_character_mp->Text = Convert::ToString(this->objEntity->iMP);
    // Read FP
    this->tb_character_fp->Text = Convert::ToString(this->objEntity->iFP);
    // Read Level
    this->tb_character_level->Text = Convert::ToString(this->objEntity->iLv);
    // Read Player count
    this->tb_players->Text = Convert::ToString(this->objEntity->iPlayerCount);

    /* === UPDATE EVERYTHING FOR THE TARGET === */
    int __tmp;
    // Read X
    this->tb_target_x->Text = Convert::ToString(this->objEntity->fTargetX);
    // Read Y
    this->tb_target_y->Text = Convert::ToString(this->objEntity->fTargetY);
    // Read Z
    this->tb_target_z->Text = Convert::ToString(this->objEntity->fTargetZ);
    // Read name
    this->tb_target_name->Text = gcnew String(this->objEntity->szTargetName);
    // Read HP
    this->tb_target_hp->Text = Convert::ToString(this->objEntity->iTargetHP);
    // Read MP
    this->tb_target_mp->Text = Convert::ToString(this->objEntity->iTargetMP);
    // Read FP
    this->tb_target_fp->Text = Convert::ToString(this->objEntity->iTargetFP);
    // Read Level
    this->tb_target_level->Text = Convert::ToString(this->objEntity->iTargetLv);
    // Read distance from Entity
    this->tb_target_distance->Text = Convert::ToString(this->objEntity->iTargetDistance);

    /* === TELEPORT TO CLICK? === */
    /*if(this->cb_teleport_click->Checked && (GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        // Find out the current "click" position.
        int iClickedPosition;
        this->objEngine->ReadStaticMemory(this->objEngine->dwClickedPositionOffset, &iClickedPosition);

        // Update the new position if we tp to A
        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAOffset, &iClickedPosition);
    }*/

    /* === TELEPORT TO MAP? === */
    if (this->cb_teleport_mark->Checked && (GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        // Find out the new X and Z position. Y we'll grab current I guess.
        float iNewX, iNewY, iNewZ;

        // Read X, Y, Z
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwMapMarkerOffsetX, &iNewX);
        iNewY = this->objEntity->fY + 50.0f; // use current Y I guess. Bump it up by 50.
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwMapMarkerOffsetZ, &iNewZ);

        // teleport...
        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &iNewX);
        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &iNewY);
        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &iNewZ);
    }

    /* === BOT === */
    // Check whether the bot is even active
    if(this->cb_bot_active->Checked) {
        // Contains all integer values from the main form, like maxHP to eat when damaged and such.
        std::map<std::string, int> data;
        data["delay"]    = Convert::ToInt32(this->numeric_bot_delay->Text);
        data["hp"]       = Convert::ToInt32(this->tb_bot_eatfood->Text->Length > 0 ? this->tb_bot_eatfood->Text : gcnew System::String("0"));
        data["hp_key"]   = this->combobox_bot_eathp->SelectedIndex;
        data["mp"]       = Convert::ToInt32(this->tb_bot_eatmana->Text->Length > 0 ? this->tb_bot_eatmana->Text : gcnew System::String("0"));
        data["mp_key"]   = this->combobox_bot_eatmp->SelectedIndex;
        data["pet_key"]  = this->combobox_bot_pet->SelectedIndex;
        data["distance"] = Convert::ToInt32(this->tb_bot_ignore->Text);
        data["maxlvl"]   = Convert::ToInt32(this->numeric_maxlvl->Text);

        std::map<std::string, bool> data_bool;
        data_bool["hp"]             = this->cb_bot_eathp->Checked;
        data_bool["mp"]             = this->cb_bot_eatmp->Checked;
        data_bool["collision"]      = this->cb_bot_collision->Checked;
        data_bool["ignore"]         = this->cb_bot_ignore->Checked;
        data_bool["rotatecamera"]   = this->cb_bot_rotatecamera->Checked;
        data_bool["pet"]            = this->cb_bot_restartpet->Checked;
        data_bool["targettp"]       = this->cb_bot_targettp->Checked;

        this->objEntity->Food(data_bool, data);

        this->objEntity->Bot(
            data_bool,
            data
        );

        //this->objEntity->AoE();
    }

    /* === Super Jump === */
    if(this->cb_jumphack->Checked && (GetAsyncKeyState(VK_SPACE) & 0x8000)) {
        float fToWrite;
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &fToWrite);
        fToWrite += 8;

        this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &fToWrite);
    }

    /* === Camera rotation === */
    if(this->cb_bot_rotatecamera->Checked) {
        int iCamera;
        this->objEngine->ReadStaticMemory(this->objEngine->dwCameraMovementOffset, &iCamera);
        if (iCamera >= 1135745891) iCamera = 1103252096;
        iCamera += 500000;
        this->objEngine->WriteStaticMemory(this->objEngine->dwCameraMovementOffset, &iCamera);
    }

    return System::Void();
}

System::Void eLosh::Main::btn_getcoordinates_Click(System::Object^  sender, System::EventArgs^  e) {
    this->tb_x->Text = this->tb_x_readonly->Text;
    this->tb_y->Text = this->tb_y_readonly->Text;
    this->tb_z->Text = this->tb_z_readonly->Text;
}

System::Void eLosh::Main::btn_teleport_Click(System::Object^  sender, System::EventArgs^  e) {
    // We are teleporting to some exact coordinates, so just teleport!
    float temp_x = Convert::ToDouble(this->tb_x->Text);
    float temp_y = Convert::ToDouble(this->tb_y->Text);
    float temp_z = Convert::ToDouble(this->tb_z->Text);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &temp_x);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &temp_y);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &temp_z);
}

// Add a coordinate to the coordinate logger.
System::Void eLosh::Main::btn_add_Click(System::Object^  sender, System::EventArgs^  e) {
    int iRowCount = this->listView->Items->Count; // Get the row count

    // Add the current coordinates to the list.
    this->listView->Items->Add(this->tb_posname->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_x_readonly->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_y_readonly->Text);
    this->listView->Items[iRowCount]->SubItems->Add(this->tb_z_readonly->Text);

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
}

// GM Auth
System::Void eLosh::Main::cb_gm_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    int iToWrite = (this->cb_gm->Checked ? 80 : 70);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAuthOffset, &iToWrite);
}

// Rangehax
System::Void eLosh::Main::cb_range_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    int iToWrite = (this->cb_range->Checked ? this->objEngine->byteRangeArrayModified : this->objEngine->byteRangeArrayOriginal);

    //std::cout << "I will write: " << iToWrite << std::endl;
    printf("I will write %x\n", iToWrite);

    this->objEngine->WriteStaticMemory(this->objEngine->dwRangeCALLOffset, &iToWrite);
}

// Speedhax
System::Void eLosh::Main::trackbar_speed_Scroll(System::Object^  sender, System::EventArgs^  e) {
    // Just write the new value directly.
    int iToWrite = this->trackbar_speed->Value;

    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwSpeedOffset, &iToWrite);
}

// Zoomhack
System::Void eLosh::Main::trackbar_scroll_Scroll(System::Object^  sender, System::EventArgs^  e) {
    // Increase/Decrease by X
    int iCurrentZoom, iNewZoom;

    this->objEngine->ReadStaticMemory(this->objEngine->dwCameraScrollOffset, &iCurrentZoom);
    if(this->trackbar_scroll->Value > this->trackbarValue) {
        iNewZoom = iCurrentZoom + this->trackbar_scroll->Value;
    }else {
        iNewZoom = iCurrentZoom - this->trackbar_scroll->Value;
    }

    this->objEngine->WriteStaticMemory(this->objEngine->dwCameraScrollOffset, &iNewZoom);
}

System::Void eLosh::Main::cb_flyingcamera_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    int iToWrite = (this->cb_flyingcamera->Checked ? 0 : 1);

    this->objEngine->WriteStaticMemory(this->objEngine->dwFlyingCameraOffset, &iToWrite);
}
