#pragma once
#include "engine.h"
#include "entity.h"

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
            Engine *objEngine;
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
    private: System::Windows::Forms::CheckBox^  cb_autobuff;
    private: System::Windows::Forms::Label^  label15;
    private: System::Windows::Forms::NumericUpDown^  numeric_maxlvl;
    public: System::Windows::Forms::Timer^  timerBuff;
    private:


    public:
        Entity *objEntity;

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

    private: System::Windows::Forms::TabPage^  tabPage2;
    private: System::Windows::Forms::TabPage^  tabPage3;
    private: System::Windows::Forms::GroupBox^  gb_teleport;


    private: System::Windows::Forms::Label^  label_z;
    private: System::Windows::Forms::TextBox^  tb_y;
    private: System::Windows::Forms::TextBox^  tb_z;

    private: System::Windows::Forms::Label^  label_y;
    private: System::Windows::Forms::Label^  label_a_readonly;
    private: System::Windows::Forms::TextBox^  tb_a_readonly;

    private: System::Windows::Forms::Label^  label_a;
    private: System::Windows::Forms::TextBox^  tb_a;

    private: System::Windows::Forms::CheckBox^  cb_teleport_click;
    private: System::Windows::Forms::TextBox^  tb_x_readonly;

    private: System::Windows::Forms::Label^  label_z_readonly;
    private: System::Windows::Forms::TextBox^  tb_y_readonly;
    private: System::Windows::Forms::TextBox^  tb_z_readonly;

    private: System::Windows::Forms::Label^  label_y_readonly;
    private: System::Windows::Forms::CheckBox^  cb_teleport_a;

    private: System::Windows::Forms::PictureBox^  pictureBox1;




    private: System::Windows::Forms::GroupBox^  gb_misc;
    private: System::Windows::Forms::CheckBox^  cb_invisibility;
    private: System::Windows::Forms::CheckBox^  cb_gm;







    private: System::Windows::Forms::NumericUpDown^  numeric_tpdelta;
    private: System::Windows::Forms::Label^  label_teleportdelta;

    private: System::Windows::Forms::Label^  label9;
    public: System::Windows::Forms::Label^  label_version;
    private:

    private: System::Windows::Forms::Label^  label_x_readonly;
    private: System::Windows::Forms::Button^  btn_teleport;
    public: System::Windows::Forms::Timer^  timer;
    private: System::Windows::Forms::Button^  btn_getcoordinates;
    private: System::Windows::Forms::Button^  btn_figuredelta;


    private: System::Windows::Forms::BindingSource^  bindingSource1;
    private: System::Windows::Forms::ListView^  listView;

    private: System::Windows::Forms::ColumnHeader^  column_name;
    private: System::Windows::Forms::ColumnHeader^  column_x;
    private: System::Windows::Forms::ColumnHeader^  column_y;
    private: System::Windows::Forms::ColumnHeader^  column_z;
    private: System::Windows::Forms::ColumnHeader^  column_a;
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
    private: System::Windows::Forms::GroupBox^  gb_debug;
    private: System::Windows::Forms::RichTextBox^  richtb_debug;
    private: System::Windows::Forms::TextBox^  tb_bot_eatmana;

private: System::Windows::Forms::CheckBox^  cb_bot_eatmp;

private: System::Windows::Forms::ComboBox^  combobox_bot_eathp;
private: System::Windows::Forms::ComboBox^  combobox_bot_eatmp;
private: System::Windows::Forms::GroupBox^  Character;
private: System::Windows::Forms::ComboBox^  combobox_bot_dca;

private: System::Windows::Forms::Label^  label_bot_dca;
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
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  tb_target_a;

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
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->tb_target_distance = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->tb_target_a = (gcnew System::Windows::Forms::TextBox());
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
            this->cb_jumphack = (gcnew System::Windows::Forms::CheckBox());
            this->cb_range = (gcnew System::Windows::Forms::CheckBox());
            this->cb_flyingcamera = (gcnew System::Windows::Forms::CheckBox());
            this->cb_stance = (gcnew System::Windows::Forms::CheckBox());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->trackbar_scroll = (gcnew System::Windows::Forms::TrackBar());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->trackbar_speed = (gcnew System::Windows::Forms::TrackBar());
            this->cb_invisibility = (gcnew System::Windows::Forms::CheckBox());
            this->cb_gm = (gcnew System::Windows::Forms::CheckBox());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->cb_autobuff = (gcnew System::Windows::Forms::CheckBox());
            this->cb_bot_collision = (gcnew System::Windows::Forms::CheckBox());
            this->combobox_bot_dca = (gcnew System::Windows::Forms::ComboBox());
            this->label_bot_dca = (gcnew System::Windows::Forms::Label());
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
            this->column_a = (gcnew System::Windows::Forms::ColumnHeader());
            this->btn_figuredelta = (gcnew System::Windows::Forms::Button());
            this->btn_getcoordinates = (gcnew System::Windows::Forms::Button());
            this->btn_teleport = (gcnew System::Windows::Forms::Button());
            this->numeric_tpdelta = (gcnew System::Windows::Forms::NumericUpDown());
            this->label_teleportdelta = (gcnew System::Windows::Forms::Label());
            this->cb_teleport_a = (gcnew System::Windows::Forms::CheckBox());
            this->label_a_readonly = (gcnew System::Windows::Forms::Label());
            this->tb_a_readonly = (gcnew System::Windows::Forms::TextBox());
            this->label_a = (gcnew System::Windows::Forms::Label());
            this->tb_a = (gcnew System::Windows::Forms::TextBox());
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
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
            this->gb_debug = (gcnew System::Windows::Forms::GroupBox());
            this->richtb_debug = (gcnew System::Windows::Forms::RichTextBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label_version = (gcnew System::Windows::Forms::Label());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->numeric_maxlvl = (gcnew System::Windows::Forms::NumericUpDown());
            this->timerBuff = (gcnew System::Windows::Forms::Timer(this->components));
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->Character->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_scroll))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_speed))->BeginInit();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bot_delay))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->gb_misc->SuspendLayout();
            this->gb_teleport->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_tpdelta))->BeginInit();
            this->tabPage3->SuspendLayout();
            this->gb_debug->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_maxlvl))->BeginInit();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Controls->Add(this->tabPage3);
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
            this->groupBox2->Controls->Add(this->label14);
            this->groupBox2->Controls->Add(this->tb_target_distance);
            this->groupBox2->Controls->Add(this->label6);
            this->groupBox2->Controls->Add(this->label1);
            this->groupBox2->Controls->Add(this->tb_target_a);
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
            this->groupBox2->Location = System::Drawing::Point(293, 316);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(294, 196);
            this->groupBox2->TabIndex = 15;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Target";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(161, 129);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(15, 13);
            this->label14->TabIndex = 39;
            this->label14->Text = L"D";
            // 
            // tb_target_distance
            // 
            this->tb_target_distance->Location = System::Drawing::Point(181, 126);
            this->tb_target_distance->Name = L"tb_target_distance";
            this->tb_target_distance->ReadOnly = true;
            this->tb_target_distance->Size = System::Drawing::Size(101, 20);
            this->tb_target_distance->TabIndex = 38;
            this->tb_target_distance->Text = L"\?\?";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(161, 103);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(14, 13);
            this->label6->TabIndex = 36;
            this->label6->Text = L"A";
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
            // tb_target_a
            // 
            this->tb_target_a->Location = System::Drawing::Point(181, 100);
            this->tb_target_a->Name = L"tb_target_a";
            this->tb_target_a->ReadOnly = true;
            this->tb_target_a->Size = System::Drawing::Size(101, 20);
            this->tb_target_a->TabIndex = 35;
            this->tb_target_a->Text = L"\?\?";
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
            this->Character->Controls->Add(this->cb_jumphack);
            this->Character->Controls->Add(this->cb_range);
            this->Character->Controls->Add(this->cb_flyingcamera);
            this->Character->Controls->Add(this->cb_stance);
            this->Character->Controls->Add(this->label12);
            this->Character->Controls->Add(this->trackbar_scroll);
            this->Character->Controls->Add(this->label11);
            this->Character->Controls->Add(this->trackbar_speed);
            this->Character->Controls->Add(this->cb_invisibility);
            this->Character->Controls->Add(this->cb_gm);
            this->Character->Location = System::Drawing::Point(593, 158);
            this->Character->Name = L"Character";
            this->Character->Size = System::Drawing::Size(433, 354);
            this->Character->TabIndex = 14;
            this->Character->TabStop = false;
            this->Character->Text = L"Miscellaneous";
            // 
            // cb_jumphack
            // 
            this->cb_jumphack->AutoSize = true;
            this->cb_jumphack->ForeColor = System::Drawing::Color::ForestGreen;
            this->cb_jumphack->ImageKey = L"(none)";
            this->cb_jumphack->Location = System::Drawing::Point(6, 132);
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
            this->cb_range->Location = System::Drawing::Point(6, 109);
            this->cb_range->Name = L"cb_range";
            this->cb_range->Size = System::Drawing::Size(114, 17);
            this->cb_range->TabIndex = 8;
            this->cb_range->Text = L"Infinite range hack";
            this->cb_range->UseVisualStyleBackColor = true;
            this->cb_range->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_range_CheckedChanged);
            // 
            // cb_flyingcamera
            // 
            this->cb_flyingcamera->AutoSize = true;
            this->cb_flyingcamera->Location = System::Drawing::Point(6, 87);
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
            this->cb_stance->Location = System::Drawing::Point(6, 65);
            this->cb_stance->Name = L"cb_stance";
            this->cb_stance->Size = System::Drawing::Size(151, 17);
            this->cb_stance->TabIndex = 6;
            this->cb_stance->Text = L"Force casual battle stance";
            this->cb_stance->UseVisualStyleBackColor = true;
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(6, 192);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(57, 13);
            this->label12->TabIndex = 5;
            this->label12->Text = L"Scrollhack";
            // 
            // trackbar_scroll
            // 
            this->trackbar_scroll->AutoSize = false;
            this->trackbar_scroll->LargeChange = 5000;
            this->trackbar_scroll->Location = System::Drawing::Point(68, 192);
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
            this->label11->Location = System::Drawing::Point(6, 158);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(62, 13);
            this->label11->TabIndex = 3;
            this->label11->Text = L"Speedhack";
            // 
            // trackbar_speed
            // 
            this->trackbar_speed->AutoSize = false;
            this->trackbar_speed->Location = System::Drawing::Point(68, 158);
            this->trackbar_speed->Maximum = 200;
            this->trackbar_speed->Minimum = 30;
            this->trackbar_speed->Name = L"trackbar_speed";
            this->trackbar_speed->Size = System::Drawing::Size(151, 28);
            this->trackbar_speed->TabIndex = 2;
            this->trackbar_speed->TickStyle = System::Windows::Forms::TickStyle::None;
            this->trackbar_speed->Value = 30;
            this->trackbar_speed->Scroll += gcnew System::EventHandler(this, &Main::trackbar_speed_Scroll);
            // 
            // cb_invisibility
            // 
            this->cb_invisibility->AutoSize = true;
            this->cb_invisibility->Location = System::Drawing::Point(6, 42);
            this->cb_invisibility->Name = L"cb_invisibility";
            this->cb_invisibility->Size = System::Drawing::Size(70, 17);
            this->cb_invisibility->TabIndex = 1;
            this->cb_invisibility->Text = L"Invisibility";
            this->cb_invisibility->UseVisualStyleBackColor = true;
            this->cb_invisibility->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_invisibility_CheckedChanged);
            // 
            // cb_gm
            // 
            this->cb_gm->AutoSize = true;
            this->cb_gm->Location = System::Drawing::Point(6, 19);
            this->cb_gm->Name = L"cb_gm";
            this->cb_gm->Size = System::Drawing::Size(194, 17);
            this->cb_gm->TabIndex = 0;
            this->cb_gm->Text = L"Become gamemaster (Administrator)";
            this->cb_gm->UseVisualStyleBackColor = true;
            this->cb_gm->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_gm_CheckedChanged);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->label15);
            this->groupBox1->Controls->Add(this->numeric_maxlvl);
            this->groupBox1->Controls->Add(this->cb_autobuff);
            this->groupBox1->Controls->Add(this->cb_bot_collision);
            this->groupBox1->Controls->Add(this->combobox_bot_dca);
            this->groupBox1->Controls->Add(this->label_bot_dca);
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
            this->groupBox1->Size = System::Drawing::Size(294, 303);
            this->groupBox1->TabIndex = 13;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Bot";
            // 
            // cb_autobuff
            // 
            this->cb_autobuff->AutoSize = true;
            this->cb_autobuff->Location = System::Drawing::Point(164, 19);
            this->cb_autobuff->Name = L"cb_autobuff";
            this->cb_autobuff->Size = System::Drawing::Size(81, 17);
            this->cb_autobuff->TabIndex = 48;
            this->cb_autobuff->Text = L"Autobuff 15";
            this->cb_autobuff->UseVisualStyleBackColor = true;
            // 
            // cb_bot_collision
            // 
            this->cb_bot_collision->AutoSize = true;
            this->cb_bot_collision->Location = System::Drawing::Point(9, 123);
            this->cb_bot_collision->Name = L"cb_bot_collision";
            this->cb_bot_collision->Size = System::Drawing::Size(122, 17);
            this->cb_bot_collision->TabIndex = 47;
            this->cb_bot_collision->Text = L"Try to avoid collision";
            this->cb_bot_collision->UseVisualStyleBackColor = true;
            // 
            // combobox_bot_dca
            // 
            this->combobox_bot_dca->FormattingEnabled = true;
            this->combobox_bot_dca->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"2D Plain", L"FDA", L"Pythagoras", L"No distance algorithm" });
            this->combobox_bot_dca->Location = System::Drawing::Point(157, 267);
            this->combobox_bot_dca->Name = L"combobox_bot_dca";
            this->combobox_bot_dca->Size = System::Drawing::Size(80, 21);
            this->combobox_bot_dca->TabIndex = 46;
            // 
            // label_bot_dca
            // 
            this->label_bot_dca->AutoSize = true;
            this->label_bot_dca->Location = System::Drawing::Point(6, 270);
            this->label_bot_dca->Name = L"label_bot_dca";
            this->label_bot_dca->Size = System::Drawing::Size(154, 13);
            this->label_bot_dca->TabIndex = 45;
            this->label_bot_dca->Text = L"Distance calculation algorithm: ";
            // 
            // tb_bot_ignore
            // 
            this->tb_bot_ignore->Location = System::Drawing::Point(137, 237);
            this->tb_bot_ignore->Name = L"tb_bot_ignore";
            this->tb_bot_ignore->ReadOnly = true;
            this->tb_bot_ignore->Size = System::Drawing::Size(100, 20);
            this->tb_bot_ignore->TabIndex = 43;
            this->tb_bot_ignore->Text = L"5000";
            // 
            // cb_bot_ignore
            // 
            this->cb_bot_ignore->AutoSize = true;
            this->cb_bot_ignore->Location = System::Drawing::Point(9, 237);
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
            this->combobox_bot_pet->Location = System::Drawing::Point(116, 196);
            this->combobox_bot_pet->Name = L"combobox_bot_pet";
            this->combobox_bot_pet->Size = System::Drawing::Size(80, 21);
            this->combobox_bot_pet->TabIndex = 42;
            // 
            // cb_bot_restartpet
            // 
            this->cb_bot_restartpet->AutoSize = true;
            this->cb_bot_restartpet->Location = System::Drawing::Point(9, 196);
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
            this->combobox_bot_eatmp->Location = System::Drawing::Point(202, 174);
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
            this->combobox_bot_eathp->Location = System::Drawing::Point(202, 152);
            this->combobox_bot_eathp->Name = L"combobox_bot_eathp";
            this->combobox_bot_eathp->Size = System::Drawing::Size(80, 21);
            this->combobox_bot_eathp->TabIndex = 38;
            // 
            // tb_bot_eatmana
            // 
            this->tb_bot_eatmana->Location = System::Drawing::Point(116, 175);
            this->tb_bot_eatmana->Name = L"tb_bot_eatmana";
            this->tb_bot_eatmana->ReadOnly = true;
            this->tb_bot_eatmana->Size = System::Drawing::Size(80, 20);
            this->tb_bot_eatmana->TabIndex = 36;
            this->tb_bot_eatmana->Text = L"50";
            // 
            // cb_bot_eatmp
            // 
            this->cb_bot_eatmp->AutoSize = true;
            this->cb_bot_eatmp->Location = System::Drawing::Point(9, 175);
            this->cb_bot_eatmp->Name = L"cb_bot_eatmp";
            this->cb_bot_eatmp->Size = System::Drawing::Size(105, 17);
            this->cb_bot_eatmp->TabIndex = 37;
            this->cb_bot_eatmp->Text = L"Eat food if MP < ";
            this->cb_bot_eatmp->UseVisualStyleBackColor = true;
            this->cb_bot_eatmp->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_bot_eatmp_CheckedChanged);
            // 
            // tb_bot_eatfood
            // 
            this->tb_bot_eatfood->Location = System::Drawing::Point(116, 152);
            this->tb_bot_eatfood->Name = L"tb_bot_eatfood";
            this->tb_bot_eatfood->ReadOnly = true;
            this->tb_bot_eatfood->Size = System::Drawing::Size(80, 20);
            this->tb_bot_eatfood->TabIndex = 14;
            this->tb_bot_eatfood->Text = L"5000";
            // 
            // cb_bot_eathp
            // 
            this->cb_bot_eathp->AutoSize = true;
            this->cb_bot_eathp->Location = System::Drawing::Point(9, 152);
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
            this->cb_bot_targettp->Location = System::Drawing::Point(9, 100);
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
            this->cb_bot_rotatecamera->Location = System::Drawing::Point(9, 71);
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
            this->gb_teleport->Controls->Add(this->btn_figuredelta);
            this->gb_teleport->Controls->Add(this->btn_getcoordinates);
            this->gb_teleport->Controls->Add(this->btn_teleport);
            this->gb_teleport->Controls->Add(this->numeric_tpdelta);
            this->gb_teleport->Controls->Add(this->label_teleportdelta);
            this->gb_teleport->Controls->Add(this->cb_teleport_a);
            this->gb_teleport->Controls->Add(this->label_a_readonly);
            this->gb_teleport->Controls->Add(this->tb_a_readonly);
            this->gb_teleport->Controls->Add(this->label_a);
            this->gb_teleport->Controls->Add(this->tb_a);
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
            this->cb_teleport_mark->Location = System::Drawing::Point(7, 206);
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
            this->listView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
                this->column_name, this->column_x,
                    this->column_y, this->column_z, this->column_a
            });
            this->listView->FullRowSelect = true;
            this->listView->Location = System::Drawing::Point(7, 281);
            this->listView->Name = L"listView";
            this->listView->Size = System::Drawing::Size(261, 179);
            this->listView->TabIndex = 25;
            this->listView->UseCompatibleStateImageBehavior = false;
            this->listView->View = System::Windows::Forms::View::Details;
            this->listView->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::listView_SelectedIndexChanged);
            // 
            // column_name
            // 
            this->column_name->Text = L"Name";
            this->column_name->Width = 73;
            // 
            // column_x
            // 
            this->column_x->Text = L"X";
            this->column_x->Width = 39;
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
            // column_a
            // 
            this->column_a->Text = L"A";
            this->column_a->Width = 64;
            // 
            // btn_figuredelta
            // 
            this->btn_figuredelta->Location = System::Drawing::Point(9, 252);
            this->btn_figuredelta->Name = L"btn_figuredelta";
            this->btn_figuredelta->Size = System::Drawing::Size(100, 23);
            this->btn_figuredelta->TabIndex = 24;
            this->btn_figuredelta->Text = L"Figure out delta";
            this->btn_figuredelta->UseVisualStyleBackColor = true;
            this->btn_figuredelta->Click += gcnew System::EventHandler(this, &Main::btn_figuredelta_Click);
            // 
            // btn_getcoordinates
            // 
            this->btn_getcoordinates->Location = System::Drawing::Point(165, 123);
            this->btn_getcoordinates->Name = L"btn_getcoordinates";
            this->btn_getcoordinates->Size = System::Drawing::Size(103, 23);
            this->btn_getcoordinates->TabIndex = 23;
            this->btn_getcoordinates->Text = L"Get coordinates";
            this->btn_getcoordinates->UseVisualStyleBackColor = true;
            this->btn_getcoordinates->Click += gcnew System::EventHandler(this, &Main::btn_getcoordinates_Click);
            // 
            // btn_teleport
            // 
            this->btn_teleport->Location = System::Drawing::Point(31, 123);
            this->btn_teleport->Name = L"btn_teleport";
            this->btn_teleport->Size = System::Drawing::Size(100, 23);
            this->btn_teleport->TabIndex = 22;
            this->btn_teleport->Text = L"Manual teleport";
            this->btn_teleport->UseVisualStyleBackColor = true;
            this->btn_teleport->Click += gcnew System::EventHandler(this, &Main::btn_teleport_Click);
            // 
            // numeric_tpdelta
            // 
            this->numeric_tpdelta->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
            this->numeric_tpdelta->Location = System::Drawing::Point(201, 258);
            this->numeric_tpdelta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
            this->numeric_tpdelta->Name = L"numeric_tpdelta";
            this->numeric_tpdelta->Size = System::Drawing::Size(67, 20);
            this->numeric_tpdelta->TabIndex = 21;
            this->numeric_tpdelta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 139, 0, 0, 0 });
            // 
            // label_teleportdelta
            // 
            this->label_teleportdelta->AutoSize = true;
            this->label_teleportdelta->Location = System::Drawing::Point(122, 260);
            this->label_teleportdelta->Name = L"label_teleportdelta";
            this->label_teleportdelta->Size = System::Drawing::Size(73, 13);
            this->label_teleportdelta->TabIndex = 20;
            this->label_teleportdelta->Text = L"Click TP delta";
            // 
            // cb_teleport_a
            // 
            this->cb_teleport_a->AutoSize = true;
            this->cb_teleport_a->Location = System::Drawing::Point(7, 152);
            this->cb_teleport_a->Name = L"cb_teleport_a";
            this->cb_teleport_a->Size = System::Drawing::Size(187, 17);
            this->cb_teleport_a->TabIndex = 18;
            this->cb_teleport_a->Text = L"Teleport to ALL instead of specific";
            this->cb_teleport_a->UseVisualStyleBackColor = true;
            // 
            // label_a_readonly
            // 
            this->label_a_readonly->AutoSize = true;
            this->label_a_readonly->Location = System::Drawing::Point(147, 100);
            this->label_a_readonly->Name = L"label_a_readonly";
            this->label_a_readonly->Size = System::Drawing::Size(14, 13);
            this->label_a_readonly->TabIndex = 17;
            this->label_a_readonly->Text = L"A";
            // 
            // tb_a_readonly
            // 
            this->tb_a_readonly->Location = System::Drawing::Point(167, 97);
            this->tb_a_readonly->Name = L"tb_a_readonly";
            this->tb_a_readonly->ReadOnly = true;
            this->tb_a_readonly->Size = System::Drawing::Size(101, 20);
            this->tb_a_readonly->TabIndex = 16;
            this->tb_a_readonly->Text = L"\?\?";
            // 
            // label_a
            // 
            this->label_a->AutoSize = true;
            this->label_a->Location = System::Drawing::Point(11, 100);
            this->label_a->Name = L"label_a";
            this->label_a->Size = System::Drawing::Size(14, 13);
            this->label_a->TabIndex = 15;
            this->label_a->Text = L"A";
            // 
            // tb_a
            // 
            this->tb_a->Location = System::Drawing::Point(31, 97);
            this->tb_a->Name = L"tb_a";
            this->tb_a->Size = System::Drawing::Size(100, 20);
            this->tb_a->TabIndex = 14;
            // 
            // cb_teleport_click
            // 
            this->cb_teleport_click->AutoSize = true;
            this->cb_teleport_click->Location = System::Drawing::Point(7, 229);
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
            // tabPage2
            // 
            this->tabPage2->Location = System::Drawing::Point(4, 22);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(1032, 518);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"F-Key";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this->tabPage3->Controls->Add(this->gb_debug);
            this->tabPage3->Location = System::Drawing::Point(4, 22);
            this->tabPage3->Name = L"tabPage3";
            this->tabPage3->Size = System::Drawing::Size(1032, 518);
            this->tabPage3->TabIndex = 2;
            this->tabPage3->Text = L"Logger";
            this->tabPage3->UseVisualStyleBackColor = true;
            // 
            // gb_debug
            // 
            this->gb_debug->Controls->Add(this->richtb_debug);
            this->gb_debug->Location = System::Drawing::Point(3, 3);
            this->gb_debug->Name = L"gb_debug";
            this->gb_debug->Size = System::Drawing::Size(447, 479);
            this->gb_debug->TabIndex = 4;
            this->gb_debug->TabStop = false;
            this->gb_debug->Text = L"DEBUG";
            // 
            // richtb_debug
            // 
            this->richtb_debug->Location = System::Drawing::Point(9, 19);
            this->richtb_debug->Name = L"richtb_debug";
            this->richtb_debug->Size = System::Drawing::Size(427, 454);
            this->richtb_debug->TabIndex = 0;
            this->richtb_debug->Text = L"";
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
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Location = System::Drawing::Point(138, 48);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(55, 13);
            this->label15->TabIndex = 50;
            this->label15->Text = L"Max level:";
            // 
            // numeric_maxlvl
            // 
            this->numeric_maxlvl->Location = System::Drawing::Point(197, 46);
            this->numeric_maxlvl->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
            this->numeric_maxlvl->Name = L"numeric_maxlvl";
            this->numeric_maxlvl->Size = System::Drawing::Size(48, 20);
            this->numeric_maxlvl->TabIndex = 49;
            // 
            // timerBuff
            // 
            this->timerBuff->Enabled = true;
            this->timerBuff->Tick += gcnew System::EventHandler(this, &Main::tickBuff);
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
            this->Text = L"E Loœ [eLosh]";
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->Character->ResumeLayout(false);
            this->Character->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_scroll))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_speed))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bot_delay))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->gb_misc->ResumeLayout(false);
            this->gb_misc->PerformLayout();
            this->gb_teleport->ResumeLayout(false);
            this->gb_teleport->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_tpdelta))->EndInit();
            this->tabPage3->ResumeLayout(false);
            this->gb_debug->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_maxlvl))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion    
    private: System::Void btn_getcoordinates_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_teleport_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void richtb_debug_TextChanged(System::Object^  sender, System::EventArgs^  e) {
        richtb_debug->SelectionStart = richtb_debug->Text->Length;
        // scroll it automatically
        richtb_debug->ScrollToCaret();
    }
    private: System::Void cb_invisibility_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_add_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_remove_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void listView_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
    private: System::Void btn_figuredelta_Click(System::Object^  sender, System::EventArgs^  e);
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
};
}