#pragma once
#include "engine.h"
#include <iostream>

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

		    Main(Engine *pEngine) {
                this->objEngine = pEngine;
			    InitializeComponent();
		    }

	    protected:
		    /// <summary>
		    /// Clean up any resources being used.
		    /// </summary>
		    ~Main(){
			    if (components) {
				    delete components;
			    }
                //delete objEngine;
		    }

    private: System::Void tick(System::Object^  sender, System::EventArgs^  e);
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
    private: System::Windows::Forms::GroupBox^  gb_debug;

    private: System::Windows::Forms::RichTextBox^  richtb_debug;

    private: System::Windows::Forms::GroupBox^  gb_misc;
    private: System::Windows::Forms::CheckBox^  cb_invisibility;


    private: System::Windows::Forms::CheckBox^  checkBox6;




    private: System::Windows::Forms::NumericUpDown^  numeric_tpdelta;
    private: System::Windows::Forms::Label^  label_teleportdelta;

    private: System::Windows::Forms::Label^  label9;
    public: System::Windows::Forms::Label^  label_version;
    private:

    private: System::Windows::Forms::Label^  label_x_readonly;
    private: System::Windows::Forms::Button^  btn_teleport;
    public: System::Windows::Forms::Timer^  timer;
    private: System::Windows::Forms::Button^  btn_getcoordinates;

    private: System::Windows::Forms::Button^  button1;
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
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->gb_debug = (gcnew System::Windows::Forms::GroupBox());
            this->richtb_debug = (gcnew System::Windows::Forms::RichTextBox());
            this->gb_misc = (gcnew System::Windows::Forms::GroupBox());
            this->cb_invisibility = (gcnew System::Windows::Forms::CheckBox());
            this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
            this->gb_teleport = (gcnew System::Windows::Forms::GroupBox());
            this->tb_posname = (gcnew System::Windows::Forms::TextBox());
            this->btn_remove = (gcnew System::Windows::Forms::Button());
            this->btn_add = (gcnew System::Windows::Forms::Button());
            this->listView = (gcnew System::Windows::Forms::ListView());
            this->column_name = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_x = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_y = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_z = (gcnew System::Windows::Forms::ColumnHeader());
            this->column_a = (gcnew System::Windows::Forms::ColumnHeader());
            this->button1 = (gcnew System::Windows::Forms::Button());
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
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label_version = (gcnew System::Windows::Forms::Label());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->gb_debug->SuspendLayout();
            this->gb_misc->SuspendLayout();
            this->gb_teleport->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_tpdelta))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
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
            this->tabControl1->Size = System::Drawing::Size(915, 511);
            this->tabControl1->TabIndex = 0;
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->pictureBox1);
            this->tabPage1->Controls->Add(this->gb_debug);
            this->tabPage1->Controls->Add(this->gb_misc);
            this->tabPage1->Controls->Add(this->gb_teleport);
            this->tabPage1->Location = System::Drawing::Point(4, 22);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(907, 485);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Main";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(598, 366);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(303, 113);
            this->pictureBox1->TabIndex = 12;
            this->pictureBox1->TabStop = false;
            // 
            // gb_debug
            // 
            this->gb_debug->Controls->Add(this->richtb_debug);
            this->gb_debug->Location = System::Drawing::Point(327, 138);
            this->gb_debug->Name = L"gb_debug";
            this->gb_debug->Size = System::Drawing::Size(472, 192);
            this->gb_debug->TabIndex = 2;
            this->gb_debug->TabStop = false;
            this->gb_debug->Text = L"DEBUG";
            // 
            // richtb_debug
            // 
            this->richtb_debug->Location = System::Drawing::Point(9, 19);
            this->richtb_debug->Name = L"richtb_debug";
            this->richtb_debug->Size = System::Drawing::Size(427, 153);
            this->richtb_debug->TabIndex = 0;
            this->richtb_debug->Text = L"";
            this->richtb_debug->TextChanged += gcnew System::EventHandler(this, &Main::richtb_debug_TextChanged);
            // 
            // gb_misc
            // 
            this->gb_misc->Controls->Add(this->cb_invisibility);
            this->gb_misc->Controls->Add(this->checkBox6);
            this->gb_misc->Location = System::Drawing::Point(668, 6);
            this->gb_misc->Name = L"gb_misc";
            this->gb_misc->Size = System::Drawing::Size(233, 220);
            this->gb_misc->TabIndex = 11;
            this->gb_misc->TabStop = false;
            this->gb_misc->Text = L"Miscellaneous";
            // 
            // cb_invisibility
            // 
            this->cb_invisibility->AutoSize = true;
            this->cb_invisibility->Location = System::Drawing::Point(6, 45);
            this->cb_invisibility->Name = L"cb_invisibility";
            this->cb_invisibility->Size = System::Drawing::Size(70, 17);
            this->cb_invisibility->TabIndex = 1;
            this->cb_invisibility->Text = L"Invisibility";
            this->cb_invisibility->UseVisualStyleBackColor = true;
            this->cb_invisibility->CheckedChanged += gcnew System::EventHandler(this, &Main::cb_invisibility_CheckedChanged);
            // 
            // checkBox6
            // 
            this->checkBox6->AutoSize = true;
            this->checkBox6->Location = System::Drawing::Point(6, 22);
            this->checkBox6->Name = L"checkBox6";
            this->checkBox6->Size = System::Drawing::Size(125, 17);
            this->checkBox6->TabIndex = 0;
            this->checkBox6->Text = L"Become gamemaster";
            this->checkBox6->UseVisualStyleBackColor = true;
            // 
            // gb_teleport
            // 
            this->gb_teleport->Controls->Add(this->tb_posname);
            this->gb_teleport->Controls->Add(this->btn_remove);
            this->gb_teleport->Controls->Add(this->btn_add);
            this->gb_teleport->Controls->Add(this->listView);
            this->gb_teleport->Controls->Add(this->button1);
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
            this->gb_teleport->Size = System::Drawing::Size(281, 473);
            this->gb_teleport->TabIndex = 7;
            this->gb_teleport->TabStop = false;
            this->gb_teleport->Text = L"Teleport";
            // 
            // tb_posname
            // 
            this->tb_posname->Location = System::Drawing::Point(7, 446);
            this->tb_posname->Name = L"tb_posname";
            this->tb_posname->Size = System::Drawing::Size(103, 20);
            this->tb_posname->TabIndex = 28;
            // 
            // btn_remove
            // 
            this->btn_remove->Location = System::Drawing::Point(192, 445);
            this->btn_remove->Name = L"btn_remove";
            this->btn_remove->Size = System::Drawing::Size(78, 23);
            this->btn_remove->TabIndex = 27;
            this->btn_remove->Text = L"Remove";
            this->btn_remove->UseVisualStyleBackColor = true;
            this->btn_remove->Click += gcnew System::EventHandler(this, &Main::btn_remove_Click);
            // 
            // btn_add
            // 
            this->btn_add->Location = System::Drawing::Point(116, 444);
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
            this->listView->Location = System::Drawing::Point(7, 260);
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
            // button1
            // 
            this->button1->Location = System::Drawing::Point(9, 231);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 23);
            this->button1->TabIndex = 24;
            this->button1->Text = L"Figure out delta";
            this->button1->UseVisualStyleBackColor = true;
            // 
            // btn_getcoordinates
            // 
            this->btn_getcoordinates->Location = System::Drawing::Point(165, 123);
            this->btn_getcoordinates->Name = L"btn_getcoordinates";
            this->btn_getcoordinates->Size = System::Drawing::Size(103, 23);
            this->btn_getcoordinates->TabIndex = 23;
            this->btn_getcoordinates->Text = L"Get coordinates";
            this->btn_getcoordinates->UseVisualStyleBackColor = true;
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
            this->numeric_tpdelta->Location = System::Drawing::Point(150, 211);
            this->numeric_tpdelta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
            this->numeric_tpdelta->Name = L"numeric_tpdelta";
            this->numeric_tpdelta->Size = System::Drawing::Size(120, 20);
            this->numeric_tpdelta->TabIndex = 21;
            this->numeric_tpdelta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 139, 0, 0, 0 });
            // 
            // label_teleportdelta
            // 
            this->label_teleportdelta->AutoSize = true;
            this->label_teleportdelta->Location = System::Drawing::Point(6, 211);
            this->label_teleportdelta->Name = L"label_teleportdelta";
            this->label_teleportdelta->Size = System::Drawing::Size(136, 13);
            this->label_teleportdelta->TabIndex = 20;
            this->label_teleportdelta->Text = L"Teleport on click delta error";
            // 
            // cb_teleport_a
            // 
            this->cb_teleport_a->AutoSize = true;
            this->cb_teleport_a->Location = System::Drawing::Point(5, 152);
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
            this->cb_teleport_click->Location = System::Drawing::Point(150, 237);
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
            this->tabPage2->Size = System::Drawing::Size(907, 485);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"F-Key";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this->tabPage3->Location = System::Drawing::Point(4, 22);
            this->tabPage3->Name = L"tabPage3";
            this->tabPage3->Size = System::Drawing::Size(907, 485);
            this->tabPage3->TabIndex = 2;
            this->tabPage3->Text = L"Logger";
            this->tabPage3->UseVisualStyleBackColor = true;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(12, 528);
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
            // Main
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(939, 544);
            this->Controls->Add(this->label_version);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->tabControl1);
            this->Name = L"Main";
            this->Text = L"E Loœ [eLosh]";
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->gb_debug->ResumeLayout(false);
            this->gb_misc->ResumeLayout(false);
            this->gb_misc->PerformLayout();
            this->gb_teleport->ResumeLayout(false);
            this->gb_teleport->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_tpdelta))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
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
};
}