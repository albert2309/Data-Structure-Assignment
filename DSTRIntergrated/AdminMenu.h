#pragma once
#include <iostream>
#include "AddCustomer.h"
#include "ConfirmationDequeue.h"
#include "modifyInfo.h"
#include "SearchCustomer.h"
#include "DisplayAll.h"
#include "SortCustomer.h"
#include "RecordTransaction.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminMenu
	/// </summary>
	public ref class AdminMenu : public System::Windows::Forms::Form
	{
	public:
		AdminMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(27, 84);
			this->button1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(279, 113);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add new customer";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AdminMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button2->ForeColor = System::Drawing::Color::Cyan;
			this->button2->Location = System::Drawing::Point(337, 84);
			this->button2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(279, 113);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Remove oldest customer data";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button3->ForeColor = System::Drawing::Color::Cyan;
			this->button3->Location = System::Drawing::Point(27, 209);
			this->button3->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(279, 113);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Search Customers";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &AdminMenu::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button4->ForeColor = System::Drawing::Color::Cyan;
			this->button4->Location = System::Drawing::Point(639, 334);
			this->button4->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(279, 113);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Exit";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &AdminMenu::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button5->ForeColor = System::Drawing::Color::Cyan;
			this->button5->Location = System::Drawing::Point(639, 209);
			this->button5->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(279, 113);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Purge all customers data";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &AdminMenu::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button6->ForeColor = System::Drawing::Color::Cyan;
			this->button6->Location = System::Drawing::Point(27, 334);
			this->button6->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(279, 113);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Display all customers data";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &AdminMenu::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button7->ForeColor = System::Drawing::Color::Cyan;
			this->button7->Location = System::Drawing::Point(337, 209);
			this->button7->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(279, 113);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Modify a customer\'s data";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &AdminMenu::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->button8->ForeColor = System::Drawing::Color::Cyan;
			this->button8->Location = System::Drawing::Point(337, 334);
			this->button8->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(279, 113);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Sort customer data";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &AdminMenu::button8_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(163, 9);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(594, 64);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Welcome to Customer Information System\r\nHow may I help you\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(639, 84);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 31;
			this->pictureBox1->TabStop = false;
			// 
			// AdminMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"AdminMenu";
			this->Text = L"Customer Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Close();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ rgForm = gcnew AddCustomer();
		rgForm->Show();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ rgForm = gcnew ConfirmationDequeue();
		rgForm->Show();
	}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *res = NULL;
	rc = sqlite3_step(res);
	sqlite3_stmt *stmt = NULL;
	rc = sqlite3_prepare_v2(db, "DROP TABLE customerList;", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);


	rc = sqlite3_prepare_v2(db, "CREATE TABLE customerList (account_number VARCHAR[20] PRIMARY KEY, card_ver_code INT NOT NULL, expiry_date VARCHAR[5] NOT NULL, first_name VARCHAR[255] NOT NULL, last_name VARCHAR[255] NOT NULL, date_of_birth VARCHAR[9] NOT NULL, address VARCHAR[255] NOT NULL, balance FLOAT NOT NULL); ", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);

	MessageBox::Show("DATA HAS BEEN PURGED");
}


private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew modifyInfo();
	rgForm->Show();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew SearchCustomer();
	rgForm->Show();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew DisplayAll();
	rgForm->Show();
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew RecordTransaction();
	rgForm->Show();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew SortCustomer();
	rgForm->Show();
}
};
}
