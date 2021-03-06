#pragma once
#include "engine.h"
#include "entity.h"
#include "bot.h"
#include "patch.h"

namespace eLosh {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form {
	    public:
    private: System::Windows::Forms::CheckBox^  cb_bot_collision;
    private: System::Windows::Forms::CheckBox^  cb_range;

    private: System::Windows::Forms::CheckBox^  cb_flyingcamera;

    private: System::Windows::Forms::CheckBox^  cb_stance;
    private: System::Windows::Forms::Label^  label12;
    private: System::Windows::Forms::TrackBar^  trackbar_scroll;
    private: System::Windows::Forms::Label^  label11;
    private: System::Windows::Forms::TrackBar^  trackbar_speed;
    private: int trackbarValue;
    private: System::Windows::Forms::CheckBox^  cb_teleport_mark;
    private: System::Windows::Forms::CheckBox^  cb_jumphack;
    private: System::Windows::Forms::TextBox^  tb_players;
    private: System::Windows::Forms::Label^  label13;
    private: System::Windows::Forms::Label^  label14;
    private: System::Windows::Forms::TextBox^  tb_target_distance;
    private: System::Windows::Forms::CheckBox^  cb_bot_autobuff;

    private: System::Windows::Forms::Label^  label15;
    private: System::Windows::Forms::NumericUpDown^  numeric_maxlvl;
    public: System::Windows::Forms::Timer^  timerBuff;
    private: System::Windows::Forms::Label^  label6;
    public:
    private: System::Windows::Forms::TextBox^  tb_target_type;
    private: System::Windows::Forms::Label^  label17;
    private: System::Windows::Forms::NumericUpDown^  numeric_range;

    private: System::Windows::Forms::Label^  label16;
    private: System::Windows::Forms::NumericUpDown^  numeric_speedhack;
    private: System::Windows::Forms::CheckBox^  cb_dommt;
    private:


    public:
        Entity *objEntity;
        Engine *objEngine;
        Bot *objBot;
    private: System::Windows::Forms::CheckBox^  cb_flyhack;
    private: System::Windows::Forms::Label^  label19;
    private: System::Windows::Forms::NumericUpDown^  numeric_mobs;
    private: System::Windows::Forms::CheckBox^  cb_bot_aoe;

    private: System::Windows::Forms::Label^  label18;
    private: System::Windows::Forms::NumericUpDown^  numeric_minlvl;
    private: System::Windows::Forms::CheckBox^  cb_bot_abort;
    private: System::Windows::Forms::CheckBox^  cb_doubledmg;

    public:
        Patch *objPatch;

            Main();

	    protected:
		    /// <summary>
		    /// Clean up any resources being used.
		    /// </summary>
            ~Main();

    private: System::Void tick(System::Object^  sender, System::EventArgs^  e);
    private: System::Void tickBuff(System::Object^  sender, System::EventArgs^  e);
    private: System::Windows::Forms::TabControl^  tabControl1;
    protected:
    private: System::Windows::Forms::TabPage^  tabPage1;
    private: System::Windows::Forms::Label^  label_x;
    private: System::Windows::Forms::TextBox^  tb_x;



    private: System::Windows::Forms::GroupBox^  gb_teleport;


    private: System::Windows::Forms::Label^  label_z;
    private: System::Windows::Forms::TextBox^  tb_y;
    private: System::Windows::Forms::TextBox^  tb_z;

    private: System::Windows::Forms::Label^  label_y;






    private: System::Windows::Forms::CheckBox^  cb_teleport_click;
    private: System::Windows::Forms::TextBox^  tb_x_readonly;

    private: System::Windows::Forms::Label^  label_z_readonly;
    private: System::Windows::Forms::TextBox^  tb_y_readonly;
    private: System::Windows::Forms::TextBox^  tb_z_readonly;

    private: System::Windows::Forms::Label^  label_y_readonly;


    private: System::Windows::Forms::PictureBox^  pictureBox1;




    private: System::Windows::Forms::GroupBox^  gb_misc;

    private: System::Windows::Forms::CheckBox^  cb_gm;










    private: System::Windows::Forms::Label^  label9;
    public: System::Windows::Forms::Label^  label_version;
    private:

    private: System::Windows::Forms::Label^  label_x_readonly;
    private: System::Windows::Forms::Button^  btn_teleport;
    public: System::Windows::Forms::Timer^  timer;
    private: System::Windows::Forms::Button^  btn_getcoordinates;



    private: System::Windows::Forms::BindingSource^  bindingSource1;
    private: System::Windows::Forms::ListView^  listView;

    private: System::Windows::Forms::ColumnHeader^  column_name;
    private: System::Windows::Forms::ColumnHeader^  column_x;
    private: System::Windows::Forms::ColumnHeader^  column_y;
    private: System::Windows::Forms::ColumnHeader^  column_z;

    private: System::Windows::Forms::Button^  btn_remove;
    private: System::Windows::Forms::Button^  btn_add;
    private: System::Windows::Forms::TextBox^  tb_posname;
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::TextBox^  tb_bot_eatfood;
    private: System::Windows::Forms::CheckBox^  cb_bot_eathp;

    private: System::Windows::Forms::CheckBox^  cb_bot_targettp;
    private: System::Windows::Forms::CheckBox^  cb_bot_rotatecamera;
    private: System::Windows::Forms::Label^  label_bot_delay;
    private: System::Windows::Forms::NumericUpDown^  numeric_bot_delay;
    private: System::Windows::Forms::CheckBox^  cb_bot_active;


    private: System::Windows::Forms::TextBox^  tb_bot_eatmana;

private: System::Windows::Forms::CheckBox^  cb_bot_eatmp;

private: System::Windows::Forms::ComboBox^  combobox_bot_eathp;
private: System::Windows::Forms::ComboBox^  combobox_bot_eatmp;
private: System::Windows::Forms::GroupBox^  Character;



private: System::Windows::Forms::TextBox^  tb_bot_ignore;

private: System::Windows::Forms::CheckBox^  cb_bot_ignore;
private: System::Windows::Forms::ComboBox^  combobox_bot_pet;
private: System::Windows::Forms::CheckBox^  cb_bot_restartpet;
private: System::Windows::Forms::Label^  label_name;
private: System::Windows::Forms::Label^  label_mp;
private: System::Windows::Forms::Label^  label_level;
private: System::Windows::Forms::TextBox^  tb_character_hp;
private: System::Windows::Forms::TextBox^  tb_character_mp;


private: System::Windows::Forms::TextBox^  tb_character_level;

private: System::Windows::Forms::TextBox^  tb_character_name;

private: System::Windows::Forms::Label^  label_hp;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  tb_target_fp;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::TextBox^  tb_target_hp;
private: System::Windows::Forms::TextBox^  tb_target_mp;
private: System::Windows::Forms::TextBox^  tb_target_level;
private: System::Windows::Forms::TextBox^  tb_target_name;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label_fp;
private: System::Windows::Forms::TextBox^  tb_character_fp;



private: System::Windows::Forms::TextBox^  tb_target_x;

private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::TextBox^  tb_target_y;
private: System::Windows::Forms::TextBox^  tb_target_z;


private: System::Windows::Forms::Label^  label10;




    public:

    public:
    private:

    private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->tb_players = (gcnew System::Windows::Forms::TextBox());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->tb_target_type = (gcnew System::Windows::Forms::TextBox());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->tb_target_distance = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tb_target_fp = (gcnew System::Windows::Forms::TextBox());
            this->tb_target_x = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->tb_target_y = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->tb_target_z = (gcnew System::Windows::Forms::TextBox());
            this->tb_target_hp = (gcnew System::Windows::Forms::TextBox());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->tb_target_mp = (gcnew System::Windows::Forms::TextBox());
            this->tb_target_level = (gcnew System::Windows::Forms::TextBox());
            this->tb_target_name = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->Character = (gcnew System::Windows::Forms::GroupBox());
            this->cb_flyhack = (gcnew System::Windows::Forms::CheckBox());
            this->cb_dommt = (gcnew System::Windows::Forms::CheckBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->numeric_range = (gcnew System::Windows::Forms::NumericUpDown());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->numeric_speedhack = (gcnew System::Windows::Forms::NumericUpDown());
            this->cb_jumphack = (gcnew System::Windows::Forms::CheckBox());
            this->cb_range = (gcnew System::Windows::Forms::CheckBox());
            this->cb_flyingcamera = (gcnew System::Windows::Forms::CheckBox());
            this->cb_stance = (gcnew System::Windows::Forms::CheckBox());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->trackbar_scroll = (gcnew System::Windows::Forms::TrackBar());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->trackbar_speed = (gcnew System::Windows::Forms::TrackBar());
            this->cb_gm = (gcnew System::Windows::Forms::CheckBox());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->cb_bot_abort = (gcnew System::Windows::Forms::CheckBox());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->numeric_mobs = (gcnew System::Windows::Forms::NumericUpDown());
            this->cb_bot_aoe = (gcnew System::Windows::Forms::CheckBox());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->numeric_minlvl = (gcnew System::Windows::Forms::NumericUpDown());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->numeric_maxlvl = (gcnew System::Windows::Forms::NumericUpDown());
            this->cb_bot_autobuff = (gcnew System::Windows::Forms::CheckBox());
            this->cb_bot_collision = (gcnew System::Windows::Forms::CheckBox());
            this->tb_bot_ignore = (gcnew System::Windows::Forms::TextBox());
            this->cb_bot_ignore = (gcnew System::Windows::Forms::CheckBox());
            this->combobox_bot_pet = (gcnew System::Windows::Forms::ComboBox());
            this->cb_bot_restartpet = (gcnew System::Windows::Forms::CheckBox());
            this->combobox_bot_eatmp = (gcnew System::Windows::Forms::ComboBox());
            this->combobox_bot_eathp = (gcnew System::Windows::Forms::ComboBox());
            this->tb_bot_eatmana = (gcnew System::Windows::Forms::TextBox());
            this->cb_bot_eatmp = (gcnew System::Windows::Forms::CheckBox());
            this->tb_bot_eatfood = (gcnew System::Windows::Forms::TextBox());
            this->cb_bot_eathp = (gcnew System::Windows::Forms::CheckBox());
            this->cb_bot_targettp = (gcnew System::Windows::Forms::CheckBox());
            this->cb_bot_rotatecamera = (gcnew System::Windows::Forms::CheckBox());
            this->label_bot_delay = (gcnew System::Windows::Forms::Label());
            this->numeric_bot_delay = (gcnew System::Windows::Forms::NumericUpDown());
            this->cb_bot_active = (gcnew System::Windows::Forms::CheckBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->gb_misc = (gcnew System::Windows::Forms::GroupBox());
            this->label_fp = (gcnew System::Windows::Forms::Label());
            this->tb_character_fp = (gcnew System::Windows::Forms::TextBox());
            this->label_name = (gcnew System::Windows::Forms::Label());
            this->label_mp = (gcnew System::Windows::Forms::Label());
            this->label_level = (gcnew System::Windows::Forms::Label());
            this->tb_character_hp = (gcnew System::Windows::Forms::TextBox());
            this->tb_character_mp = (gcnew System::Windows::Forms::TextBox());
            this->tb_character_level = (gcnew System::Windows::Forms::TextBox());
            this->tb_character_name = (gcnew System::Windows::Forms::TextBox());
            this->label_hp = (gcnew System::Windows::Forms::Label());
            this->gb_teleport = (gcnew System::Windows::Forms::GroupBox());
            this->cb_teleport_mark = (gcnew System::Windows::Forms::CheckBox());
            this->tb_posname = (gcnew System::Windows::Forms::TextBox());
            this->btn_remove = (gcnew System::Windows::Forms::Button());
            this->btn_add = (gcnew System::Windows::Forms::Button());
            this->listView = (gcnew System::Windows::Forms::ListView());
            this->column_name = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_x = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_y = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_z = (gcnew System::Windows::Forms::ColumnHeader());
            this->btn_getcoordinates = (gcnew System::Windows::Forms::Button());
            this->btn_teleport = (gcnew System::Windows::Forms::Button());
            this->cb_teleport_click = (gcnew System::Windows::Forms::CheckBox());
            this->tb_x_readonly = (gcnew System::Windows::Forms::TextBox());
            this->label_x_readonly = (gcnew System::Windows::Forms::Label());
            this->label_z_readonly = (gcnew System::Windows::Forms::Label());
            this->tb_y_readonly = (gcnew System::Windows::Forms::TextBox());
            this->tb_z_readonly = (gcnew System::Windows::Forms::TextBox());
            this->label_y_readonly = (gcnew System::Windows::Forms::Label());
            this->tb_x = (gcnew System::Windows::Forms::TextBox());
            this->label_x = (gcnew System::Windows::Forms::Label());
            this->label_z = (gcnew System::Windows::Forms::Label());
            this->tb_y = (gcnew System::Windows::Forms::TextBox());
            this->tb_z = (gcnew System::Windows::Forms::TextBox());
            this->label_y = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label_version = (gcnew System::Windows::Forms::Label());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
            this->timerBuff = (gcnew System::Windows::Forms::Timer(this->components));
            this->cb_doubledmg = (gcnew System::Windows::Forms::CheckBox());
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->Character->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_range))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_speedhack))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_scroll))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_speed))->BeginInit();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_mobs))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_minlvl))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_maxlvl))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bot_delay))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->gb_misc->SuspendLayout();
            this->gb_teleport->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Location = System::Drawing::Point(12, 12);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1040, 544);
            this->tabControl1->TabIndex = 0;
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->tb_players);
            this->tabPage1->Controls->Add(this->label13);
            this->tabPage1->Controls->Add(this->groupBox2);
            this->tabPage1->Controls->Add(this->Character);
            this->tabPage1->Controls->Add(this->groupBox1);
            this->tabPage1->Controls->Add(this->pictureBox1);
            this->tabPage1->Controls->Add(this->gb_misc);
            this->tabPage1->Controls->Add(this->gb_teleport);
            this->tabPage1->Location = System::Drawing::Point(4, 22);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(1032, 518);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Main";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // tb_players
            // 
            this->tb_players->Location = System::Drawing::Point(828, 129);
            this->tb_players->Name = L"tb_players";
            this->tb_players->ReadOnly = true;
            this->tb_players->Size = System::Drawing::Size(101, 20);
            this->tb_players->TabIndex = 16;
            this->tb_players->Text = L"\?\?";
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(740, 132);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(82, 13);
            this->label13->TabIndex = 17;
            this->label13->Text = L"Players in range";
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->label6);
            this->groupBox2->Controls->Add(this->tb_target_type);
            this->groupBox2->Controls->Add(this->label14);
            this->groupBox2->Controls->Add(this->tb_target_distance);
            this->groupBox2->Controls->Add(this->label1);
            this->groupBox2->Controls->Add(this->tb_target_fp);
            this->groupBox2->Controls->Add(this->tb_target_x);
            this->groupBox2->Controls->Add(this->label7);
            this->groupBox2->Controls->Add(this->label2);
            this->groupBox2->Controls->Add(this->label8);
            this->groupBox2->Controls->Add(this->label3);
            this->groupBox2->Controls->Add(this->tb_target_y);
            this->groupBox2->Controls->Add(this->label4);
            this->groupBox2->Controls->Add(this->tb_target_z);
            this->groupBox2->Controls->Add(this->tb_target_hp);
            this->groupBox2->Controls->Add(this->label10);
            this->groupBox2->Controls->Add(this->tb_target_mp);
            this->groupBox2->Controls->Add(this->tb_target_level);
            this->groupBox2->Controls->Add(this->tb_target_name);
            this->groupBox2->Controls->Add(this->label5);
            this->groupBox2->Location = System::Drawing::Point(293, 359);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(294, 153);
            this->groupBox2->TabIndex = 15;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Target";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(161, 129);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(14, 13);
            this->label6->TabIndex = 41;
            this->label6->Text = L"T";
            // 
            // tb_target_type
            // 
            this->tb_target_type->Location = System::Drawing::Point(181, 126);
            this->tb_target_type->Name = L"tb_target_type";
            this->tb_target_type->ReadOnly = true;
            this->tb_target_type->Size = System::Drawing::Size(101, 20);
            this->tb_target_type->TabIndex = 40;
            this->tb_target_type->Text = L"\?\?";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(161, 103);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(15, 13);
            this->label14->TabIndex = 39;
            this->label14->Text = L"D";
            // 
            // tb_target_distance
            // 
            this->tb_target_distance->Location = System::Drawing::Point(181, 100);
            this->tb_target_distance->Name = L"tb_target_distance";
            this->tb_target_distance->ReadOnly = true;
            this->tb_target_distance->Size = System::Drawing::Size(101, 20);
            this->tb_target_distance->TabIndex = 38;
            this->tb_target_distance->Text = L"\?\?";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(6, 126);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(23, 13);
            this->label1->TabIndex = 37;
            this->label1->Text = L"FP:";
            // 
            // tb_target_fp
            // 
            this->tb_target_fp->Location = System::Drawing::Point(50, 126);
            this->tb_target_fp->Name = L"tb_target_fp";
            this->tb_target_fp->ReadOnly = true;
            this->tb_target_fp->Size = System::Drawing::Size(98, 20);
            this->tb_target_fp->TabIndex = 36;
            this->tb_target_fp->Text = L"\?\?";
            // 
            // tb_target_x
            // 
            this->tb_target_x->Location = System::Drawing::Point(181, 22);
            this->tb_target_x->Name = L"tb_target_x";
            this->tb_target_x->ReadOnly = true;
            this->tb_target_x->Size = System::Drawing::Size(101, 20);
            this->tb_target_x->TabIndex = 29;
            this->tb_target_x->Text = L"\?\?";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(161, 25);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(14, 13);
            this->label7->TabIndex = 30;
            this->label7->Text = L"X";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(6, 25);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(38, 13);
            this->label2->TabIndex = 29;
            this->label2->Text = L"Name:";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(161, 77);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(14, 13);
            this->label8->TabIndex = 34;
            this->label8->Text = L"Z";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(6, 103);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(26, 13);
            this->label3->TabIndex = 35;
            this->label3->Text = L"MP:";
            // 
            // tb_target_y
            // 
            this->tb_target_y->Location = System::Drawing::Point(181, 48);
            this->tb_target_y->Name = L"tb_target_y";
            this->tb_target_y->ReadOnly = true;
            this->tb_target_y->Size = System::Drawing::Size(101, 20);
            this->tb_target_y->TabIndex = 31;
            this->tb_target_y->Text = L"\?\?";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(6, 51);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(36, 13);
            this->label4->TabIndex = 31;
            this->label4->Text = L"Level:";
            // 
            // tb_target_z
            // 
            this->tb_target_z->Location = System::Drawing::Point(181, 74);
            this->tb_target_z->Name = L"tb_target_z";
            this->tb_target_z->ReadOnly = true;
            this->tb_target_z->Size = System::Drawing::Size(101, 20);
            this->tb_target_z->TabIndex = 33;
            this->tb_target_z->Text = L"\?\?";
            // 
            // tb_target_hp
            // 
            this->tb_target_hp->Location = System::Drawing::Point(50, 74);
            this->tb_target_hp->Name = L"tb_target_hp";
            this->tb_target_hp->ReadOnly = true;
            this->tb_target_hp->Size = System::Drawing::Size(98, 20);
            this->tb_target_hp->TabIndex = 32;
            this->tb_target_hp->Text = L"\?\?";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(161, 51);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(14, 13);
            this->label10->TabIndex = 32;
            this->label10->Text = L"Y";
            // 
            // tb_target_mp
            // 
            this->tb_target_mp->Location = System::Drawing::Point(50, 100);
            this->tb_target_mp->Name = L"tb_target_mp";
            this->tb_target_mp->ReadOnly = true;
            this->tb_target_mp->Size = System::Drawing::Size(98, 20);
            this->tb_target_mp->TabIndex = 34;
            this->tb_target_mp->Text = L"\?\?";
            // 
            // tb_target_level
            // 
            this->tb_target_level->Location = System::Drawing::Point(50, 48);
            this->tb_target_level->Name = L"tb_target_level";
            this->tb_target_level->ReadOnly = true;
            this->tb_target_level->Size = System::Drawing::Size(98, 20);
            this->tb_target_level->TabIndex = 30;
            this->tb_target_level->Text = L"\?\?";
            // 
            // tb_target_name
            // 
            this->tb_target_name->Location = System::Drawing::Point(50, 22);
            this->tb_target_name->Name = L"tb_target_name";
            this->tb_target_name->ReadOnly = true;
            this->tb_target_name->Size = System::Drawing::Size(98, 20);
            this->tb_target_name->TabIndex = 28;
            this->tb_target_name->Text = L"\?\?";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(6, 77);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(25, 13);
            this->label5->TabIndex = 33;
            this->label5->Text = L"HP:";
            // 
            // Character
            // 
            this->Character->Controls->Add(this->cb_doubledmg);
            this->Character->Controls->Add(this->cb_flyhack);
            this->Character->Controls->Add(this->cb_dommt);
            this->Character->Controls->Add(this->label17);
            this->Character->Controls->Add(this->numeric_range);
            this->Character->Controls->Add(this->label16);
            this->Character->Controls->Add(this->numeric_speedhack);
            this->Character->Controls->Add(this->cb_jumphack);
            this->Character->Controls->Add(this->cb_range);
            this->Character->Controls->Add(this->cb_flyingcamera);
            this->Character->Controls->Add(this->cb_stance);
            this->Character->Controls->Add(this->label12);
            this->Character->Controls->Add(this->trackbar_scroll);
            this->Character->Controls->Add(this->label11);
            this->Character->Controls->Add(this->trackbar_speed);
            this->Character->Controls->Add(this->cb_gm);
            this->Character->Location = System::Drawing::Point(593, 158);
            this->Character->Name = L"Character";
            this->Character->Size = System::Drawing::Size(433, 354);
            this->Character->TabIndex = 14;
            this->Character->TabStop = false;
            this->Character->Text = L"Hacks";
            // 
            // cb_flyhack
            // 
            this->cb_flyhack->AutoSize = true;
            this->cb_flyhack->ForeColor = System::Drawing::Color::DarkCyan;
            this->cb_flyhack->ImageKey = L"(none)";
            this->cb_flyhack->Location = System::Drawing::Point(6, 186);
            this->cb_flyhack->Name = L"cb_flyhack";
            this->cb_flyhack->Size = System::Drawing::Size(66, 17);
            this->cb_flyhack->TabIndex = 56;
            this->cb_flyhack->Text = L"Fly hack";
            this->cb_flyhack->UseVisualStyleBackColor = true;
            this->cb_flyhack->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_flyhack_CheckedChanged);
            // 
            // cb_dommt
            // 
            this->cb_dommt->AutoSize = true;
            this->cb_dommt->ForeColor = System::Drawing::Color::DarkViolet;
            this->cb_dommt->ImageKey = L"(none)";
            this->cb_dommt->Location = System::Drawing::Point(6, 111);
            this->cb_dommt->Name = L"cb_dommt";
            this->cb_dommt->Size = System::Drawing::Size(112, 17);
            this->cb_dommt->TabIndex = 55;
            this->cb_dommt->Text = L"Maximum DoMMT";
            this->cb_dommt->UseVisualStyleBackColor = true;
            this->cb_dommt->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_dommt_CheckedChanged);
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Location = System::Drawing::Point(3, 162);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(39, 13);
            this->label17->TabIndex = 54;
            this->label17->Text = L"Range";
            // 
            // numeric_range
            // 
            this->numeric_range->Location = System::Drawing::Point(48, 160);
            this->numeric_range->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
            this->numeric_range->Name = L"numeric_range";
            this->numeric_range->Size = System::Drawing::Size(67, 20);
            this->numeric_range->TabIndex = 53;
            this->numeric_range->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 18, 0, 0, 0 });
            this->numeric_range->ValueChanged += gcnew System::EventHandler(this, &Main::numeric_range_ValueChanged);
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(206, 52);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(81, 13);
            this->label16->TabIndex = 52;
            this->label16->Text = L"Speed multiplier";
            // 
            // numeric_speedhack
            // 
            this->numeric_speedhack->Location = System::Drawing::Point(296, 50);
            this->numeric_speedhack->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->numeric_speedhack->Name = L"numeric_speedhack";
            this->numeric_speedhack->Size = System::Drawing::Size(48, 20);
            this->numeric_speedhack->TabIndex = 51;
            this->numeric_speedhack->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numeric_speedhack->ValueChanged += gcnew System::EventHandler(this, &Main::numeric_speedhack_ValueChanged);
            // 
            // cb_jumphack
            // 
            this->cb_jumphack->AutoSize = true;
            this->cb_jumphack->ForeColor = System::Drawing::Color::ForestGreen;
            this->cb_jumphack->ImageKey = L"(none)";
            this->cb_jumphack->Location = System::Drawing::Point(6, 88);
            this->cb_jumphack->Name = L"cb_jumphack";
            this->cb_jumphack->Size = System::Drawing::Size(78, 17);
            this->cb_jumphack->TabIndex = 9;
            this->cb_jumphack->Text = L"Jump hack";
            this->cb_jumphack->UseVisualStyleBackColor = true;
            // 
            // cb_range
            // 
            this->cb_range->AutoSize = true;
            this->cb_range->ForeColor = System::Drawing::Color::Brown;
            this->cb_range->ImageKey = L"(none)";
            this->cb_range->Location = System::Drawing::Point(6, 134);
            this->cb_range->Name = L"cb_range";
            this->cb_range->Size = System::Drawing::Size(151, 17);
            this->cb_range->TabIndex = 8;
            this->cb_range->Text = L"Range hack + No collision";
            this->cb_range->UseVisualStyleBackColor = true;
            this->cb_range->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_range_CheckedChanged);
            // 
            // cb_flyingcamera
            // 
            this->cb_flyingcamera->AutoSize = true;
            this->cb_flyingcamera->Location = System::Drawing::Point(6, 65);
            this->cb_flyingcamera->Name = L"cb_flyingcamera";
            this->cb_flyingcamera->Size = System::Drawing::Size(110, 17);
            this->cb_flyingcamera->TabIndex = 7;
            this->cb_flyingcamera->Text = L"Use flying camera";
            this->cb_flyingcamera->UseVisualStyleBackColor = true;
            this->cb_flyingcamera->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_flyingcamera_CheckedChanged);
            // 
            // cb_stance
            // 
            this->cb_stance->AutoSize = true;
            this->cb_stance->Location = System::Drawing::Point(6, 42);
            this->cb_stance->Name = L"cb_stance";
            this->cb_stance->Size = System::Drawing::Size(151, 17);
            this->cb_stance->TabIndex = 6;
            this->cb_stance->Text = L"Force casual battle stance";
            this->cb_stance->UseVisualStyleBackColor = true;
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(206, 100);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(57, 13);
            this->label12->TabIndex = 5;
            this->label12->Text = L"Scrollhack";
            // 
            // trackbar_scroll
            // 
            this->trackbar_scroll->AutoSize = false;
            this->trackbar_scroll->LargeChange = 5000;
            this->trackbar_scroll->Location = System::Drawing::Point(269, 98);
            this->trackbar_scroll->Maximum = 200000;
            this->trackbar_scroll->Name = L"trackbar_scroll";
            this->trackbar_scroll->Size = System::Drawing::Size(151, 28);
            this->trackbar_scroll->SmallChange = 2000;
            this->trackbar_scroll->TabIndex = 4;
            this->trackbar_scroll->TickStyle = System::Windows::Forms::TickStyle::None;
            this->trackbar_scroll->Scroll += gcnew System::EventHandler(this, &Main::trackbar_scroll_Scroll);
            this->trackbar_scroll->ValueChanged += gcnew System::EventHandler(this, &Main::trackbar_scroll_ValueChanged);
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(206, 20);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(62, 13);
            this->label11->TabIndex = 3;
            this->label11->Text = L"Speedhack";
            // 
            // trackbar_speed
            // 
            this->trackbar_speed->AutoSize = false;
            this->trackbar_speed->Location = System::Drawing::Point(268, 20);
            this->trackbar_speed->Maximum = 250;
            this->trackbar_speed->Minimum = 30;
            this->trackbar_speed->Name = L"trackbar_speed";
            this->trackbar_speed->Size = System::Drawing::Size(151, 28);
            this->trackbar_speed->TabIndex = 2;
            this->trackbar_speed->TickStyle = System::Windows::Forms::TickStyle::None;
            this->trackbar_speed->Value = 30;
            this->trackbar_speed->Scroll += gcnew System::EventHandler(this, &Main::trackbar_speed_Scroll);
            // 
            // cb_gm
            // 
            this->cb_gm->AutoSize = true;
            this->cb_gm->Location = System::Drawing::Point(6, 19);
            this->cb_gm->Name = L"cb_gm";
            this->cb_gm->Size = System::Drawing::Size(136, 17);
            this->cb_gm->TabIndex = 0;
            this->cb_gm->Text = L"Become a Gamemaster";
            this->cb_gm->UseVisualStyleBackColor = true;
            this->cb_gm->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_gm_CheckedChanged);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->cb_bot_abort);
            this->groupBox1->Controls->Add(this->label19);
            this->groupBox1->Controls->Add(this->numeric_mobs);
            this->groupBox1->Controls->Add(this->cb_bot_aoe);
            this->groupBox1->Controls->Add(this->label18);
            this->groupBox1->Controls->Add(this->numeric_minlvl);
            this->groupBox1->Controls->Add(this->label15);
            this->groupBox1->Controls->Add(this->numeric_maxlvl);
            this->groupBox1->Controls->Add(this->cb_bot_autobuff);
            this->groupBox1->Controls->Add(this->cb_bot_collision);
            this->groupBox1->Controls->Add(this->tb_bot_ignore);
            this->groupBox1->Controls->Add(this->cb_bot_ignore);
            this->groupBox1->Controls->Add(this->combobox_bot_pet);
            this->groupBox1->Controls->Add(this->cb_bot_restartpet);
            this->groupBox1->Controls->Add(this->combobox_bot_eatmp);
            this->groupBox1->Controls->Add(this->combobox_bot_eathp);
            this->groupBox1->Controls->Add(this->tb_bot_eatmana);
            this->groupBox1->Controls->Add(this->cb_bot_eatmp);
            this->groupBox1->Controls->Add(this->tb_bot_eatfood);
            this->groupBox1->Controls->Add(this->cb_bot_eathp);
            this->groupBox1->Controls->Add(this->cb_bot_targettp);
            this->groupBox1->Controls->Add(this->cb_bot_rotatecamera);
            this->groupBox1->Controls->Add(this->label_bot_delay);
            this->groupBox1->Controls->Add(this->numeric_bot_delay);
            this->groupBox1->Controls->Add(this->cb_bot_active);
            this->groupBox1->Location = System::Drawing::Point(293, 6);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(294, 347);
            this->groupBox1->TabIndex = 13;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Bot";
            // 
            // cb_bot_abort
            // 
            this->cb_bot_abort->AutoSize = true;
            this->cb_bot_abort->Location = System::Drawing::Point(6, 148);
            this->cb_bot_abort->Name = L"cb_bot_abort";
            this->cb_bot_abort->Size = System::Drawing::Size(119, 17);
            this->cb_bot_abort->TabIndex = 56;
            this->cb_bot_abort->Text = L"Abort at player sight";
            this->cb_bot_abort->UseVisualStyleBackColor = true;
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Location = System::Drawing::Point(161, 133);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(55, 13);
            this->label19->TabIndex = 55;
            this->label19->Text = L"AoE mobs";
            // 
            // numeric_mobs
            // 
            this->numeric_mobs->Location = System::Drawing::Point(220, 131);
            this->numeric_mobs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
            this->numeric_mobs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numeric_mobs->Name = L"numeric_mobs";
            this->numeric_mobs->Size = System::Drawing::Size(48, 20);
            this->numeric_mobs->TabIndex = 54;
            this->numeric_mobs->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            // 
            // cb_bot_aoe
            // 
            this->cb_bot_aoe->AutoSize = true;
            this->cb_bot_aoe->Location = System::Drawing::Point(164, 18);
            this->cb_bot_aoe->Name = L"cb_bot_aoe";
            this->cb_bot_aoe->Size = System::Drawing::Size(75, 17);
            this->cb_bot_aoe->TabIndex = 53;
            this->cb_bot_aoe->Text = L"AoE mode";
            this->cb_bot_aoe->UseVisualStyleBackColor = true;
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Location = System::Drawing::Point(161, 105);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(49, 13);
            this->label18->TabIndex = 52;
            this->label18->Text = L"Min level";
            // 
            // numeric_minlvl
            // 
            this->numeric_minlvl->Location = System::Drawing::Point(220, 103);
            this->numeric_minlvl->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
            this->numeric_minlvl->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numeric_minlvl->Name = L"numeric_minlvl";
            this->numeric_minlvl->Size = System::Drawing::Size(48, 20);
            this->numeric_minlvl->TabIndex = 51;
            this->numeric_minlvl->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(161, 78);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(52, 13);
            this->label15->TabIndex = 50;
            this->label15->Text = L"Max level";
            // 
            // numeric_maxlvl
            // 
            this->numeric_maxlvl->Location = System::Drawing::Point(220, 76);
            this->numeric_maxlvl->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
            this->numeric_maxlvl->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numeric_maxlvl->Name = L"numeric_maxlvl";
            this->numeric_maxlvl->Size = System::Drawing::Size(48, 20);
            this->numeric_maxlvl->TabIndex = 49;
            this->numeric_maxlvl->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // cb_bot_autobuff
            // 
            this->cb_bot_autobuff->AutoSize = true;
            this->cb_bot_autobuff->Location = System::Drawing::Point(164, 46);
            this->cb_bot_autobuff->Name = L"cb_bot_autobuff";
            this->cb_bot_autobuff->Size = System::Drawing::Size(120, 17);
            this->cb_bot_autobuff->TabIndex = 48;
            this->cb_bot_autobuff->Text = L"Autobuff 15 minutes";
            this->cb_bot_autobuff->UseVisualStyleBackColor = true;
            // 
            // cb_bot_collision
            // 
            this->cb_bot_collision->AutoSize = true;
            this->cb_bot_collision->Location = System::Drawing::Point(6, 125);
            this->cb_bot_collision->Name = L"cb_bot_collision";
            this->cb_bot_collision->Size = System::Drawing::Size(122, 17);
            this->cb_bot_collision->TabIndex = 47;
            this->cb_bot_collision->Text = L"Try to avoid collision";
            this->cb_bot_collision->UseVisualStyleBackColor = true;
            // 
            // tb_bot_ignore
            // 
            this->tb_bot_ignore->Location = System::Drawing::Point(125, 248);
            this->tb_bot_ignore->Name = L"tb_bot_ignore";
            this->tb_bot_ignore->ReadOnly = true;
            this->tb_bot_ignore->Size = System::Drawing::Size(100, 20);
            this->tb_bot_ignore->TabIndex = 43;
            this->tb_bot_ignore->Text = L"20";
            // 
            // cb_bot_ignore
            // 
            this->cb_bot_ignore->AutoSize = true;
            this->cb_bot_ignore->Location = System::Drawing::Point(6, 248);
            this->cb_bot_ignore->Name = L"cb_bot_ignore";
            this->cb_bot_ignore->Size = System::Drawing::Size(122, 17);
            this->cb_bot_ignore->TabIndex = 44;
            this->cb_bot_ignore->Text = L"Ignore if distance >=";
            this->cb_bot_ignore->UseVisualStyleBackColor = true;
            this->cb_bot_ignore->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_bot_ignore_CheckedChanged);
            // 
            // combobox_bot_pet
            // 
            this->combobox_bot_pet->FormattingEnabled = true;
            this->combobox_bot_pet->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
                L"F1", L"F2", L"F3", L"F4", L"F5", L"F6",
                    L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"
            });
            this->combobox_bot_pet->Location = System::Drawing::Point(106, 219);
            this->combobox_bot_pet->Name = L"combobox_bot_pet";
            this->combobox_bot_pet->Size = System::Drawing::Size(80, 21);
            this->combobox_bot_pet->TabIndex = 42;
            // 
            // cb_bot_restartpet
            // 
            this->cb_bot_restartpet->AutoSize = true;
            this->cb_bot_restartpet->Location = System::Drawing::Point(6, 217);
            this->cb_bot_restartpet->Name = L"cb_bot_restartpet";
            this->cb_bot_restartpet->Size = System::Drawing::Size(81, 17);
            this->cb_bot_restartpet->TabIndex = 41;
            this->cb_bot_restartpet->Text = L"Restart pet ";
            this->cb_bot_restartpet->UseVisualStyleBackColor = true;
            // 
            // combobox_bot_eatmp
            // 
            this->combobox_bot_eatmp->FormattingEnabled = true;
            this->combobox_bot_eatmp->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
                L"F1", L"F2", L"F3", L"F4", L"F5", L"F6",
                    L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"
            });
            this->combobox_bot_eatmp->Location = System::Drawing::Point(192, 194);
            this->combobox_bot_eatmp->Name = L"combobox_bot_eatmp";
            this->combobox_bot_eatmp->Size = System::Drawing::Size(80, 21);
            this->combobox_bot_eatmp->TabIndex = 39;
            // 
            // combobox_bot_eathp
            // 
            this->combobox_bot_eathp->FormattingEnabled = true;
            this->combobox_bot_eathp->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
                L"F1", L"F2", L"F3", L"F4", L"F5", L"F6",
                    L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"
            });
            this->combobox_bot_eathp->Location = System::Drawing::Point(192, 170);
            this->combobox_bot_eathp->Name = L"combobox_bot_eathp";
            this->combobox_bot_eathp->Size = System::Drawing::Size(80, 21);
            this->combobox_bot_eathp->TabIndex = 38;
            // 
            // tb_bot_eatmana
            // 
            this->tb_bot_eatmana->Location = System::Drawing::Point(106, 194);
            this->tb_bot_eatmana->Name = L"tb_bot_eatmana";
            this->tb_bot_eatmana->ReadOnly = true;
            this->tb_bot_eatmana->Size = System::Drawing::Size(80, 20);
            this->tb_bot_eatmana->TabIndex = 36;
            this->tb_bot_eatmana->Text = L"50";
            // 
            // cb_bot_eatmp
            // 
            this->cb_bot_eatmp->AutoSize = true;
            this->cb_bot_eatmp->Location = System::Drawing::Point(6, 194);
            this->cb_bot_eatmp->Name = L"cb_bot_eatmp";
            this->cb_bot_eatmp->Size = System::Drawing::Size(105, 17);
            this->cb_bot_eatmp->TabIndex = 37;
            this->cb_bot_eatmp->Text = L"Eat food if MP < ";
            this->cb_bot_eatmp->UseVisualStyleBackColor = true;
            this->cb_bot_eatmp->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_bot_eatmp_CheckedChanged);
            // 
            // tb_bot_eatfood
            // 
            this->tb_bot_eatfood->Location = System::Drawing::Point(106, 171);
            this->tb_bot_eatfood->Name = L"tb_bot_eatfood";
            this->tb_bot_eatfood->ReadOnly = true;
            this->tb_bot_eatfood->Size = System::Drawing::Size(80, 20);
            this->tb_bot_eatfood->TabIndex = 14;
            this->tb_bot_eatfood->Text = L"5000";
            // 
            // cb_bot_eathp
            // 
            this->cb_bot_eathp->AutoSize = true;
            this->cb_bot_eathp->Location = System::Drawing::Point(6, 171);
            this->cb_bot_eathp->Name = L"cb_bot_eathp";
            this->cb_bot_eathp->Size = System::Drawing::Size(104, 17);
            this->cb_bot_eathp->TabIndex = 35;
            this->cb_bot_eathp->Text = L"Eat food if HP < ";
            this->cb_bot_eathp->UseVisualStyleBackColor = true;
            this->cb_bot_eathp->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_bot_eathp_CheckedChanged);
            // 
            // cb_bot_targettp
            // 
            this->cb_bot_targettp->AutoSize = true;
            this->cb_bot_targettp->Location = System::Drawing::Point(6, 100);
            this->cb_bot_targettp->Name = L"cb_bot_targettp";
            this->cb_bot_targettp->Size = System::Drawing::Size(107, 17);
            this->cb_bot_targettp->TabIndex = 33;
            this->cb_bot_targettp->Text = L"Teleport to target";
            this->cb_bot_targettp->UseVisualStyleBackColor = true;
            this->cb_bot_targettp->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_bot_targettp_CheckedChanged);
            // 
            // cb_bot_rotatecamera
            // 
            this->cb_bot_rotatecamera->AutoSize = true;
            this->cb_bot_rotatecamera->Location = System::Drawing::Point(6, 74);
            this->cb_bot_rotatecamera->Name = L"cb_bot_rotatecamera";
            this->cb_bot_rotatecamera->Size = System::Drawing::Size(96, 17);
            this->cb_bot_rotatecamera->TabIndex = 32;
            this->cb_bot_rotatecamera->Text = L"Rotate camera";
            this->cb_bot_rotatecamera->UseVisualStyleBackColor = true;
            // 
            // label_bot_delay
            // 
            this->label_bot_delay->AutoSize = true;
            this->label_bot_delay->Location = System::Drawing::Point(6, 45);
            this->label_bot_delay->Name = L"label_bot_delay";
            this->label_bot_delay->Size = System::Drawing::Size(37, 13);
            this->label_bot_delay->TabIndex = 31;
            this->label_bot_delay->Text = L"Delay:";
            // 
            // numeric_bot_delay
            // 
            this->numeric_bot_delay->Location = System::Drawing::Point(49, 43);
            this->numeric_bot_delay->Name = L"numeric_bot_delay";
            this->numeric_bot_delay->Size = System::Drawing::Size(44, 20);
            this->numeric_bot_delay->TabIndex = 30;
            // 
            // cb_bot_active
            // 
            this->cb_bot_active->AutoSize = true;
            this->cb_bot_active->Location = System::Drawing::Point(6, 18);
            this->cb_bot_active->Name = L"cb_bot_active";
            this->cb_bot_active->Size = System::Drawing::Size(98, 17);
            this->cb_bot_active->TabIndex = 29;
            this->cb_bot_active->Text = L"Active (autokill)";
            this->cb_bot_active->UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(742, 6);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(284, 113);
            this->pictureBox1->TabIndex = 12;
            this->pictureBox1->TabStop = false;
            // 
            // gb_misc
            // 
            this->gb_misc->Controls->Add(this->label_fp);
            this->gb_misc->Controls->Add(this->tb_character_fp);
            this->gb_misc->Controls->Add(this->label_name);
            this->gb_misc->Controls->Add(this->label_mp);
            this->gb_misc->Controls->Add(this->label_level);
            this->gb_misc->Controls->Add(this->tb_character_hp);
            this->gb_misc->Controls->Add(this->tb_character_mp);
            this->gb_misc->Controls->Add(this->tb_character_level);
            this->gb_misc->Controls->Add(this->tb_character_name);
            this->gb_misc->Controls->Add(this->label_hp);
            this->gb_misc->Location = System::Drawing::Point(593, 6);
            this->gb_misc->Name = L"gb_misc";
            this->gb_misc->Size = System::Drawing::Size(144, 146);
            this->gb_misc->TabIndex = 11;
            this->gb_misc->TabStop = false;
            this->gb_misc->Text = L"Character";
            // 
            // label_fp
            // 
            this->label_fp->AutoSize = true;
            this->label_fp->Location = System::Drawing::Point(5, 123);
            this->label_fp->Name = L"label_fp";
            this->label_fp->Size = System::Drawing::Size(23, 13);
            this->label_fp->TabIndex = 27;
            this->label_fp->Text = L"FP:";
            // 
            // tb_character_fp
            // 
            this->tb_character_fp->Location = System::Drawing::Point(49, 120);
            this->tb_character_fp->Name = L"tb_character_fp";
            this->tb_character_fp->ReadOnly = true;
            this->tb_character_fp->Size = System::Drawing::Size(82, 20);
            this->tb_character_fp->TabIndex = 26;
            this->tb_character_fp->Text = L"\?\?";
            // 
            // label_name
            // 
            this->label_name->AutoSize = true;
            this->label_name->Location = System::Drawing::Point(5, 22);
            this->label_name->Name = L"label_name";
            this->label_name->Size = System::Drawing::Size(38, 13);
            this->label_name->TabIndex = 19;
            this->label_name->Text = L"Name:";
            // 
            // label_mp
            // 
            this->label_mp->AutoSize = true;
            this->label_mp->Location = System::Drawing::Point(5, 100);
            this->label_mp->Name = L"label_mp";
            this->label_mp->Size = System::Drawing::Size(26, 13);
            this->label_mp->TabIndex = 25;
            this->label_mp->Text = L"MP:";
            // 
            // label_level
            // 
            this->label_level->AutoSize = true;
            this->label_level->Location = System::Drawing::Point(5, 48);
            this->label_level->Name = L"label_level";
            this->label_level->Size = System::Drawing::Size(36, 13);
            this->label_level->TabIndex = 21;
            this->label_level->Text = L"Level:";
            // 
            // tb_character_hp
            // 
            this->tb_character_hp->Location = System::Drawing::Point(49, 71);
            this->tb_character_hp->Name = L"tb_character_hp";
            this->tb_character_hp->ReadOnly = true;
            this->tb_character_hp->Size = System::Drawing::Size(82, 20);
            this->tb_character_hp->TabIndex = 22;
            this->tb_character_hp->Text = L"\?\?";
            // 
            // tb_character_mp
            // 
            this->tb_character_mp->Location = System::Drawing::Point(49, 97);
            this->tb_character_mp->Name = L"tb_character_mp";
            this->tb_character_mp->ReadOnly = true;
            this->tb_character_mp->Size = System::Drawing::Size(82, 20);
            this->tb_character_mp->TabIndex = 24;
            this->tb_character_mp->Text = L"\?\?";
            // 
            // tb_character_level
            // 
            this->tb_character_level->Location = System::Drawing::Point(49, 45);
            this->tb_character_level->Name = L"tb_character_level";
            this->tb_character_level->ReadOnly = true;
            this->tb_character_level->Size = System::Drawing::Size(82, 20);
            this->tb_character_level->TabIndex = 20;
            this->tb_character_level->Text = L"\?\?";
            // 
            // tb_character_name
            // 
            this->tb_character_name->Location = System::Drawing::Point(49, 19);
            this->tb_character_name->Name = L"tb_character_name";
            this->tb_character_name->ReadOnly = true;
            this->tb_character_name->Size = System::Drawing::Size(82, 20);
            this->tb_character_name->TabIndex = 18;
            this->tb_character_name->Text = L"\?\?";
            // 
            // label_hp
            // 
            this->label_hp->AutoSize = true;
            this->label_hp->Location = System::Drawing::Point(5, 74);
            this->label_hp->Name = L"label_hp";
            this->label_hp->Size = System::Drawing::Size(25, 13);
            this->label_hp->TabIndex = 23;
            this->label_hp->Text = L"HP:";
            // 
            // gb_teleport
            // 
            this->gb_teleport->Controls->Add(this->cb_teleport_mark);
            this->gb_teleport->Controls->Add(this->tb_posname);
            this->gb_teleport->Controls->Add(this->btn_remove);
            this->gb_teleport->Controls->Add(this->btn_add);
            this->gb_teleport->Controls->Add(this->listView);
            this->gb_teleport->Controls->Add(this->btn_getcoordinates);
            this->gb_teleport->Controls->Add(this->btn_teleport);
            this->gb_teleport->Controls->Add(this->cb_teleport_click);
            this->gb_teleport->Controls->Add(this->tb_x_readonly);
            this->gb_teleport->Controls->Add(this->label_x_readonly);
            this->gb_teleport->Controls->Add(this->label_z_readonly);
            this->gb_teleport->Controls->Add(this->tb_y_readonly);
            this->gb_teleport->Controls->Add(this->tb_z_readonly);
            this->gb_teleport->Controls->Add(this->label_y_readonly);
            this->gb_teleport->Controls->Add(this->tb_x);
            this->gb_teleport->Controls->Add(this->label_x);
            this->gb_teleport->Controls->Add(this->label_z);
            this->gb_teleport->Controls->Add(this->tb_y);
            this->gb_teleport->Controls->Add(this->tb_z);
            this->gb_teleport->Controls->Add(this->label_y);
            this->gb_teleport->Location = System::Drawing::Point(6, 6);
            this->gb_teleport->Name = L"gb_teleport";
            this->gb_teleport->Size = System::Drawing::Size(281, 506);
            this->gb_teleport->TabIndex = 7;
            this->gb_teleport->TabStop = false;
            this->gb_teleport->Text = L"Teleport";
            // 
            // cb_teleport_mark
            // 
            this->cb_teleport_mark->AutoSize = true;
            this->cb_teleport_mark->Location = System::Drawing::Point(6, 129);
            this->cb_teleport_mark->Name = L"cb_teleport_mark";
            this->cb_teleport_mark->Size = System::Drawing::Size(129, 17);
            this->cb_teleport_mark->TabIndex = 29;
            this->cb_teleport_mark->Text = L"Teleport on map mark";
            this->cb_teleport_mark->UseVisualStyleBackColor = true;
            // 
            // tb_posname
            // 
            this->tb_posname->Location = System::Drawing::Point(7, 467);
            this->tb_posname->Name = L"tb_posname";
            this->tb_posname->Size = System::Drawing::Size(103, 20);
            this->tb_posname->TabIndex = 28;
            // 
            // btn_remove
            // 
            this->btn_remove->Location = System::Drawing::Point(192, 466);
            this->btn_remove->Name = L"btn_remove";
            this->btn_remove->Size = System::Drawing::Size(78, 23);
            this->btn_remove->TabIndex = 27;
            this->btn_remove->Text = L"Remove";
            this->btn_remove->UseVisualStyleBackColor = true;
            this->btn_remove->Click += gcnew System::EventHandler(this, &Main::btn_remove_Click);
            // 
            // btn_add
            // 
            this->btn_add->Location = System::Drawing::Point(116, 465);
            this->btn_add->Name = L"btn_add";
            this->btn_add->Size = System::Drawing::Size(70, 23);
            this->btn_add->TabIndex = 26;
            this->btn_add->Text = L"Add";
            this->btn_add->UseVisualStyleBackColor = true;
            this->btn_add->Click += gcnew System::EventHandler(this, &Main::btn_add_Click);
            // 
            // listView
            // 
            this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
                this->column_name, this->column_x,
                    this->column_y, this->column_z
            });
            this->listView->FullRowSelect = true;
            this->listView->Location = System::Drawing::Point(7, 175);
            this->listView->Name = L"listView";
            this->listView->Size = System::Drawing::Size(261, 285);
            this->listView->TabIndex = 25;
            this->listView->UseCompatibleStateImageBehavior = false;
            this->listView->View = System::Windows::Forms::View::Details;
            this->listView->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::listView_SelectedIndexChanged);
            // 
            // column_name
            // 
            this->column_name->Text = L"Name";
            this->column_name->Width = 101;
            // 
            // column_x
            // 
            this->column_x->Text = L"X";
            this->column_x->Width = 51;
            // 
            // column_y
            // 
            this->column_y->Text = L"Y";
            this->column_y->Width = 41;
            // 
            // column_z
            // 
            this->column_z->Text = L"Z";
            this->column_z->Width = 49;
            // 
            // btn_getcoordinates
            // 
            this->btn_getcoordinates->Location = System::Drawing::Point(165, 100);
            this->btn_getcoordinates->Name = L"btn_getcoordinates";
            this->btn_getcoordinates->Size = System::Drawing::Size(103, 23);
            this->btn_getcoordinates->TabIndex = 23;
            this->btn_getcoordinates->Text = L"Get coordinates";
            this->btn_getcoordinates->UseVisualStyleBackColor = true;
            this->btn_getcoordinates->Click += gcnew System::EventHandler(this, &Main::btn_getcoordinates_Click);
            // 
            // btn_teleport
            // 
            this->btn_teleport->Location = System::Drawing::Point(31, 100);
            this->btn_teleport->Name = L"btn_teleport";
            this->btn_teleport->Size = System::Drawing::Size(100, 23);
            this->btn_teleport->TabIndex = 22;
            this->btn_teleport->Text = L"Manual teleport";
            this->btn_teleport->UseVisualStyleBackColor = true;
            this->btn_teleport->Click += gcnew System::EventHandler(this, &Main::btn_teleport_Click);
            // 
            // cb_teleport_click
            // 
            this->cb_teleport_click->AutoSize = true;
            this->cb_teleport_click->Location = System::Drawing::Point(6, 152);
            this->cb_teleport_click->Name = L"cb_teleport_click";
            this->cb_teleport_click->Size = System::Drawing::Size(105, 17);
            this->cb_teleport_click->TabIndex = 13;
            this->cb_teleport_click->Text = L"Teleport on click";
            this->cb_teleport_click->UseVisualStyleBackColor = true;
            // 
            // tb_x_readonly
            // 
            this->tb_x_readonly->Location = System::Drawing::Point(167, 19);
            this->tb_x_readonly->Name = L"tb_x_readonly";
            this->tb_x_readonly->ReadOnly = true;
            this->tb_x_readonly->Size = System::Drawing::Size(101, 20);
            this->tb_x_readonly->TabIndex = 7;
            this->tb_x_readonly->Text = L"\?\?";
            // 
            // label_x_readonly
            // 
            this->label_x_readonly->AutoSize = true;
            this->label_x_readonly->Location = System::Drawing::Point(147, 22);
            this->label_x_readonly->Name = L"label_x_readonly";
            this->label_x_readonly->Size = System::Drawing::Size(14, 13);
            this->label_x_readonly->TabIndex = 8;
            this->label_x_readonly->Text = L"X";
            // 
            // label_z_readonly
            // 
            this->label_z_readonly->AutoSize = true;
            this->label_z_readonly->Location = System::Drawing::Point(147, 74);
            this->label_z_readonly->Name = L"label_z_readonly";
            this->label_z_readonly->Size = System::Drawing::Size(14, 13);
            this->label_z_readonly->TabIndex = 12;
            this->label_z_readonly->Text = L"Z";
            // 
            // tb_y_readonly
            // 
            this->tb_y_readonly->Location = System::Drawing::Point(167, 45);
            this->tb_y_readonly->Name = L"tb_y_readonly";
            this->tb_y_readonly->ReadOnly = true;
            this->tb_y_readonly->Size = System::Drawing::Size(101, 20);
            this->tb_y_readonly->TabIndex = 9;
            this->tb_y_readonly->Text = L"\?\?";
            // 
            // tb_z_readonly
            // 
            this->tb_z_readonly->Location = System::Drawing::Point(167, 71);
            this->tb_z_readonly->Name = L"tb_z_readonly";
            this->tb_z_readonly->ReadOnly = true;
            this->tb_z_readonly->Size = System::Drawing::Size(101, 20);
            this->tb_z_readonly->TabIndex = 11;
            this->tb_z_readonly->Text = L"\?\?";
            // 
            // label_y_readonly
            // 
            this->label_y_readonly->AutoSize = true;
            this->label_y_readonly->Location = System::Drawing::Point(147, 48);
            this->label_y_readonly->Name = L"label_y_readonly";
            this->label_y_readonly->Size = System::Drawing::Size(14, 13);
            this->label_y_readonly->TabIndex = 10;
            this->label_y_readonly->Text = L"Y";
            // 
            // tb_x
            // 
            this->tb_x->Location = System::Drawing::Point(31, 19);
            this->tb_x->Name = L"tb_x";
            this->tb_x->Size = System::Drawing::Size(100, 20);
            this->tb_x->TabIndex = 0;
            // 
            // label_x
            // 
            this->label_x->AutoSize = true;
            this->label_x->Location = System::Drawing::Point(11, 22);
            this->label_x->Name = L"label_x";
            this->label_x->Size = System::Drawing::Size(14, 13);
            this->label_x->TabIndex = 1;
            this->label_x->Text = L"X";
            // 
            // label_z
            // 
            this->label_z->AutoSize = true;
            this->label_z->Location = System::Drawing::Point(11, 74);
            this->label_z->Name = L"label_z";
            this->label_z->Size = System::Drawing::Size(14, 13);
            this->label_z->TabIndex = 5;
            this->label_z->Text = L"Z";
            // 
            // tb_y
            // 
            this->tb_y->Location = System::Drawing::Point(31, 45);
            this->tb_y->Name = L"tb_y";
            this->tb_y->Size = System::Drawing::Size(100, 20);
            this->tb_y->TabIndex = 2;
            // 
            // tb_z
            // 
            this->tb_z->Location = System::Drawing::Point(31, 71);
            this->tb_z->Name = L"tb_z";
            this->tb_z->Size = System::Drawing::Size(100, 20);
            this->tb_z->TabIndex = 4;
            // 
            // label_y
            // 
            this->label_y->AutoSize = true;
            this->label_y->Location = System::Drawing::Point(11, 48);
            this->label_y->Name = L"label_y";
            this->label_y->Size = System::Drawing::Size(14, 13);
            this->label_y->TabIndex = 3;
            this->label_y->Text = L"Y";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(13, 556);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(202, 13);
            this->label9->TabIndex = 8;
            this->label9->Text = L"Created by infy // www.github.com/infyhr";
            // 
            // label_version
            // 
            this->label_version->AutoSize = true;
            this->label_version->Location = System::Drawing::Point(730, 466);
            this->label_version->Name = L"label_version";
            this->label_version->Size = System::Drawing::Size(0, 13);
            this->label_version->TabIndex = 9;
            this->label_version->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            // 
            // timer
            // 
            this->timer->Enabled = true;
            this->timer->Tick += gcnew System::EventHandler(this, &Main::tick);
            // 
            // timerBuff
            // 
            this->timerBuff->Enabled = true;
            this->timerBuff->Tick += gcnew System::EventHandler(this, &Main::tickBuff);
            // 
            // cb_doubledmg
            // 
            this->cb_doubledmg->AutoSize = true;
            this->cb_doubledmg->ForeColor = System::Drawing::Color::MidnightBlue;
            this->cb_doubledmg->ImageKey = L"(none)";
            this->cb_doubledmg->Location = System::Drawing::Point(6, 209);
            this->cb_doubledmg->Name = L"cb_doubledmg";
            this->cb_doubledmg->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->cb_doubledmg->Size = System::Drawing::Size(129, 17);
            this->cb_doubledmg->TabIndex = 57;
            this->cb_doubledmg->Text = L"Blade double damage";
            this->cb_doubledmg->UseVisualStyleBackColor = true;
            this->cb_doubledmg->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_doubledmg_CheckedChanged);
            // 
            // Main
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1064, 568);
            this->Controls->Add(this->label_version);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->tabControl1);
            this->Name = L"Main";
            this->Text = L"E Lo� [eLosh]";
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->Character->ResumeLayout(false);
            this->Character->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_range))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_speedhack))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_scroll))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_speed))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_mobs))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_minlvl))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_maxlvl))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bot_delay))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->gb_misc->ResumeLayout(false);
            this->gb_misc->PerformLayout();
            this->gb_teleport->ResumeLayout(false);
            this->gb_teleport->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion    
    private: System::Void btn_getcoordinates_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_teleport_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_add_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_remove_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void listView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void cb_bot_eathp_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
        this->tb_bot_eatfood->ReadOnly = !this->tb_bot_eatfood->ReadOnly;
    }
    private: System::Void cb_bot_targettp_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
        this->tb_bot_eatfood->ReadOnly = !this->tb_bot_eatfood->ReadOnly;
    }
    private: System::Void cb_bot_ignore_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
        this->tb_bot_ignore->ReadOnly = !this->tb_bot_ignore->ReadOnly;
    }
    private: System::Void cb_bot_eatmp_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
        this->tb_bot_eatmana->ReadOnly = !this->tb_bot_eatmana->ReadOnly;
    }
    private: System::Void cb_gm_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void trackbar_speed_Scroll(System::Object^  sender, System::EventArgs^  e);
    private: System::Void trackbar_scroll_Scroll(System::Object^  sender, System::EventArgs^  e);
    private: System::Void trackbar_scroll_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
        this->trackbarValue = this->trackbar_scroll->Value;
    }
    private: System::Void cb_range_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void cb_flyingcamera_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void numeric_speedhack_ValueChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void numeric_range_ValueChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void cb_flyhack_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void cb_dommt_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void cb_doubledmg_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}