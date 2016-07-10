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
    /* === READ CURRENT POSITION === */
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

    return System::Void();
}

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
    this->tb_x->Text = this->listView->SelectedItems[0]->SubItems[0]->Text; // X
    this->tb_y->Text = this->listView->SelectedItems[0]->SubItems[1]->Text; // Y
    this->tb_z->Text = this->listView->SelectedItems[0]->SubItems[2]->Text; // Z
    this->tb_a->Text = this->listView->SelectedItems[0]->SubItems[3]->Text; // A
}