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

    // Hello world!
    __LOG(":: eLosh ::", 2);

    //eLosh::Main form(e);
    eLosh::Main form;
    Application::Run(%form);

    FreeConsole();
}

eLosh::Main::Main() {
    // Init all objects.
    this->objEngine = new Engine;
    this->objEntity = new Entity(this->objEngine);
    this->objBot    = new Bot(this->objEngine, this->objEntity);
    this->objPatch  = new Patch(this->objEngine);
    __LOG("Initialized all objects");
    /*Engine *e  = new Engine;
    this->objEngine = e;
    Entity *e_ = new Entity(e);
    this->objEntity = e_;
    Bot *b = new Bot(e, e_);
    this->objBot = b;
    Patch *p = new Patch(e);
    this->objPatch = p;*/

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
    __LOG("tickBuff", 2);
}

/*System::Void eLosh::Main::tickBuff(System::Object ^ sender, System::EventArgs ^ e) {
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
}*/

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
    // Read their type
    this->tb_target_type->Text = Convert::ToString(this->objEntity->iTargetType);

    /* === TELEPORT TO CLICK === */
    if(this->cb_teleport_click->Checked && (GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        // Find out where we clicked.
        float iClickedX, iClickedY, iClickedZ;
        this->objEngine->ReadStaticMemory(this->objEngine->dwClickedX, &iClickedX);
        this->objEngine->ReadStaticMemory(this->objEngine->dwClickedY, &iClickedY);
        this->objEngine->ReadStaticMemory(this->objEngine->dwClickedZ, &iClickedZ);

        // Update the new position
        this->objEntity->TeleportTo(iClickedX, iClickedY, iClickedZ);
    }

    /* === TELEPORT TO MAP === */
    if (this->cb_teleport_mark->Checked && (GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        // Find out the new X and Z position. Y we'll grab current I guess.
        float iNewX, iNewY, iNewZ;

        // Read X, Y, Z
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwMarkerXOffset, &iNewX);
        iNewY = this->objEntity->fY + 30.0f; // use current Y I guess. Bump it up by 30.
        this->objEngine->ReadMemory(this->objEngine->dwPlayerBase, this->objEngine->dwMarkerZOffset, &iNewZ);

        // teleport...
        this->objEntity->TeleportTo(iNewX, iNewY, iNewZ);
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
        data["minlvl"]   = Convert::ToInt32(this->numeric_minlvl->Text);
        data["mobs"]     = Convert::ToInt32(this->numeric_mobs->Text);

        // Contains boolean values.
        std::map<std::string, bool> data_bool;
        data_bool["hp"]             = this->cb_bot_eathp->Checked;
        data_bool["mp"]             = this->cb_bot_eatmp->Checked;
        data_bool["collision"]      = this->cb_bot_collision->Checked;
        data_bool["ignore"]         = this->cb_bot_ignore->Checked;
        data_bool["rotatecamera"]   = this->cb_bot_rotatecamera->Checked;
        data_bool["pet"]            = this->cb_bot_restartpet->Checked;
        data_bool["targettp"]       = this->cb_bot_targettp->Checked;
        data_bool["abortplayer"]    = this->cb_bot_abort->Checked;
        data_bool["aoe"]            = this->cb_bot_aoe->Checked;

        //this->objBot->_1v1(data_bool, data);
        this->objEntity->Food(data_bool, data);
        if(data_bool["aoe"]) {
            this->objBot->AoE(data_bool, data);
        }else {
            this->objBot->_1v1(data_bool, data);
        }

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
        this->objEngine->ReadStaticMemory(this->objEngine->dwCameraMovement, &iCamera);
        if (iCamera >= 1135745891) iCamera = 1103252096;
        iCamera += 500000;
        this->objEngine->WriteStaticMemory(this->objEngine->dwCameraMovement, &iCamera);
    }

    return System::Void();
}

/// <summary>
/// Returns the current coordinates.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::btn_getcoordinates_Click(System::Object^  sender, System::EventArgs^  e) {
    this->tb_x->Text = this->tb_x_readonly->Text;
    this->tb_y->Text = this->tb_y_readonly->Text;
    this->tb_z->Text = this->tb_z_readonly->Text;
}

/// <summary>
/// Teleports on click
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::btn_teleport_Click(System::Object^  sender, System::EventArgs^  e) {
    // We are teleporting to some exact coordinates, so just teleport!
    float temp_x = Convert::ToDouble(this->tb_x->Text);
    float temp_y = Convert::ToDouble(this->tb_y->Text);
    float temp_z = Convert::ToDouble(this->tb_z->Text);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwXOffset, &temp_x);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwYOffset, &temp_y);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwZOffset, &temp_z);
}

/// <summary>
/// Add a coordinate to the coordinate logger.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
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

/// <summary>
/// Remove a coordinate from the coordinate logger.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::btn_remove_Click(System::Object^  sender, System::EventArgs^  e) {
    // Loop through all of them and see which ones are selected, delete those who are.
    for(int i = this->listView->Items->Count - 1; i >= 0; i--) {
        if(this->listView->Items[i]->Selected) this->listView->Items[i]->Remove();
    }
}

/// <summary>
/// Clicked on a coordinate in the coordinate logger.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::listView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
    /* This is a common problem.
    Unlike a ListBox or several other controls, when you change the selection in a ListView it will raise the SelectedIndexChanged event twice:
    once as it deselects the previously-selected item and the second time as it selects the new item.
    Because no items are selected when the event is raised the first time, your attempt to access the first selected item fails.
    You must add an If statement to check that there is at least one selected item and only try to access it if there is. */
    if(this->listView->SelectedItems->Count <= 0) return;

    // Feed the selected item into the wanted coordinate.
    // SubItems -> columns, SelectedItems -> koliko ih selectirash (poplavish).
    this->tb_x->Text = this->listView->SelectedItems[0]->SubItems[1]->Text; // X
    this->tb_y->Text = this->listView->SelectedItems[0]->SubItems[2]->Text; // Y
    this->tb_z->Text = this->listView->SelectedItems[0]->SubItems[3]->Text; // Z
}

/// <summary>
/// Gamemaster authentication
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::cb_gm_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    int iToWrite = (this->cb_gm->Checked ? 90 : 70);
    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwAuthOffset, &iToWrite);
    __LOG("Auth level changed", 2);
}

/// <summary>
/// Speedhack.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::trackbar_speed_Scroll(System::Object^  sender, System::EventArgs^  e) {
    // Just write the new value directly.
    int iToWrite = this->trackbar_speed->Value;

    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwSpeedOffset, &iToWrite);
}
System::Void eLosh::Main::numeric_speedhack_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
    // Write the new value
    float iNewMultiplier = Convert::ToDouble(this->numeric_speedhack->Value);

    this->objEngine->WriteMemory(this->objEngine->dwPlayerBase, this->objEngine->dwSpeedMultiplier, &iNewMultiplier);
}

/// <summary>
/// Zoomhack
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::trackbar_scroll_Scroll(System::Object^  sender, System::EventArgs^  e) {
    // Increase/Decrease by X
    int iCurrentZoom, iNewZoom;

    this->objEngine->ReadStaticMemory(this->objEngine->dwCameraScroll, &iCurrentZoom);
    if(this->trackbar_scroll->Value > this->trackbarValue) {
        iNewZoom = iCurrentZoom + this->trackbar_scroll->Value;
    }else {
        iNewZoom = iCurrentZoom - this->trackbar_scroll->Value;
    }

    this->objEngine->WriteStaticMemory(this->objEngine->dwCameraScroll, &iNewZoom);
}

/// <summary>
/// Flying camera
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::cb_flyingcamera_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    int iToWrite = (this->cb_flyingcamera->Checked ? 0 : 1);

    this->objEngine->WriteStaticMemory(this->objEngine->dwFlyingCamera, &iToWrite);
}

/// <summary>
/// Range hack, range change.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::cb_range_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    this->objPatch->Range((this->cb_range->Checked ? 0 : 1));
}
System::Void eLosh::Main::numeric_range_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
    float fToWrite = Convert::ToDouble(this->numeric_range->Value);
    DWORD dwRangeAddress = this->objEngine->dwNeuzBase + this->objPatch->dwRange;

    DWORD Protect = NULL;
    DWORD dummy = NULL;
    VirtualProtectEx(this->objEngine->hFlyff, (LPVOID)dwRangeAddress, sizeof(fToWrite), PAGE_READWRITE, &Protect);
    WriteProcessMemory(this->objEngine->hFlyff, (LPVOID)(this->objEngine->dwNeuzBase + this->objPatch->dwRange), &fToWrite, sizeof(fToWrite), NULL);
    VirtualProtectEx(this->objEngine->hFlyff, (LPVOID)dwRangeAddress, sizeof(fToWrite), Protect, &dummy);

    /*LPTSTR pTmp = NULL;
    DWORD errnum = GetLastError();
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY,
        NULL,
        errnum,
        LANG_NEUTRAL,
        (LPTSTR)&pTmp,
        0,
        NULL
    );

    std::cout << "Error(" << errnum << "): " << pTmp << std::endl;*/
}

/// <summary>
/// flyhack
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
System::Void eLosh::Main::cb_flyhack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    this->objPatch->Ground((this->cb_flyhack->Checked ? 0 : 1));
}

/// <summary>
/// max dommt
/// </summary>
System::Void eLosh::Main::cb_dommt_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    // First grab the real address.
    DWORD dwHopAddr;
    //int DCTValue;
    this->objEngine->ReadStaticMemory(this->objEngine->DCTPtr, &dwHopAddr);
    //this->objEngine->ReadStaticMemory(dwHopAddr + this->objEngine->DCTOffset, &DCTValue, false);

    // Update :)
    int __tmp = 3000;
    this->objEngine->WriteStaticMemory(dwHopAddr + this->objEngine->DCTOffset, &__tmp, false);
}