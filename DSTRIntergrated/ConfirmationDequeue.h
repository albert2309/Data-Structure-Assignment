#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "customerInfo.h"
#include "linkedQueueType.h"
#include "sqlite3.h"
#include<string>
using namespace std;

void commitDequeue();
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ConfirmationDequeue
	/// </summary>
	public ref class ConfirmationDequeue : public System::Windows::Forms::Form
	{
	public:
		ConfirmationDequeue(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
			rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList", -1, &stmt, NULL);
			unsigned char * accountNumber = new unsigned char[1500];
			int cardVerificationCode = 0;
			unsigned char * expiryDate = new unsigned char[1500];
			unsigned char * firstName = new unsigned char[1500];
			unsigned char * lastName = new unsigned char[1500];
			unsigned char * dateOfBirth = new unsigned char[1500];
			unsigned char * address = new unsigned char[1500];
			float balance = 0;
			if (rc != SQLITE_OK) {
				fprintf(stderr, "%s\n", sqlite3_errmsg(db));
			}
			else {
				rc = sqlite3_step(stmt);
				int colCount = sqlite3_column_count(stmt);
				for (int colIndex = 0; colIndex < colCount; colIndex++)
				{
					if (colIndex == 1) {
						cardVerificationCode = sqlite3_column_int(stmt, colIndex);
						String^ step3 = cardVerificationCode.ToString();
						this->cardFill->Text = step3;
					}
					else if (colIndex == 7) {
						balance = float(sqlite3_column_double(stmt, colIndex));
						String^ step3 = balance.ToString();
						this->balanceFill->Text = step3;
					}
					else {
						const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
						switch (colIndex) {
						case 0:
						{
							accountNumber = const_cast<unsigned char *>(valChar);
							char * step1 = (char*)accountNumber;
							String^ step3 = gcnew String(step1);
							this->accountFill->Text = step3;
							break;
						}
						case 2:
						{
							expiryDate = const_cast<unsigned char *>(valChar);
							char * step1 = (char*)expiryDate;
							String^ step3 = gcnew String(step1);
							this->expiryFill->Text = step3;
							break;
						}
						case 3:
						{
							firstName = const_cast<unsigned char *>(valChar);
							char * step1 = (char*)firstName;
							String^ step3 = gcnew String(step1);
							this->firstFill->Text = step3;
							break;
						}
						case 4:
						{
							lastName = const_cast<unsigned char *>(valChar);
							char * step1 = (char*)lastName;
							String^ step3 = gcnew String(step1);
							this->lastFill->Text = step3;
							break;
						}
						case 5:
						{
							dateOfBirth = const_cast<unsigned char *>(valChar);
							char * step1 = (char*)dateOfBirth;
							String^ step3 = gcnew String(step1);
							this->dobFill->Text = step3;
							break;
						}
						case 6:
						{
							address = const_cast<unsigned char *>(valChar);
							char * step1 = (char*)address;
							String^ step3 = gcnew String(step1);
							this->addressFill->Text = step3;
							break;
						}
						default:
							std::cout << "SOMETHING WRONG" << std::endl;
							break;
						}
					}
				}
				rc = sqlite3_finalize(stmt);
			}
			//all additional label is taken from https://stackoverflow.com/questions/30950244/changing-the-text-of-a-c-cli-label

			sqlite3_close(db);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConfirmationDequeue()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  accountFill;
	private: System::Windows::Forms::Label^  cardFill;
	private: System::Windows::Forms::Label^  expiryFill;
	private: System::Windows::Forms::Label^  firstFill;
	private: System::Windows::Forms::Label^  lastFill;
	private: System::Windows::Forms::Label^  dobFill;
	private: System::Windows::Forms::Label^  addressFill;
	private: System::Windows::Forms::Label^  balanceFill;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->accountFill = (gcnew System::Windows::Forms::Label());
			this->cardFill = (gcnew System::Windows::Forms::Label());
			this->expiryFill = (gcnew System::Windows::Forms::Label());
			this->firstFill = (gcnew System::Windows::Forms::Label());
			this->lastFill = (gcnew System::Windows::Forms::Label());
			this->dobFill = (gcnew System::Windows::Forms::Label());
			this->addressFill = (gcnew System::Windows::Forms::Label());
			this->balanceFill = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button1->Location = System::Drawing::Point(487, 359);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 61);
			this->button1->TabIndex = 0;
			this->button1->Text = L"DELETE";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ConfirmationDequeue::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button2->Location = System::Drawing::Point(188, 359);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 61);
			this->button2->TabIndex = 1;
			this->button2->Text = L"CANCEL";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ConfirmationDequeue::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label1->Location = System::Drawing::Point(182, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 26);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Account Number";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label2->Location = System::Drawing::Point(182, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(256, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Card Verification Code";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label3->Location = System::Drawing::Point(182, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 26);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Expiry Date";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label4->Location = System::Drawing::Point(182, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 26);
			this->label4->TabIndex = 5;
			this->label4->Text = L"First Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label5->Location = System::Drawing::Point(182, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 26);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Last Name";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label6->Location = System::Drawing::Point(182, 217);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 26);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Date of Birth";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label7->Location = System::Drawing::Point(182, 251);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(99, 26);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Address";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label8->Location = System::Drawing::Point(182, 289);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(97, 26);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Balance";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->label9->Location = System::Drawing::Point(183, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(544, 29);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Are you sure you want to delete this record\?";
			// 
			// accountFill
			// 
			this->accountFill->AutoSize = true;
			this->accountFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->accountFill->Location = System::Drawing::Point(482, 66);
			this->accountFill->Name = L"accountFill";
			this->accountFill->Size = System::Drawing::Size(224, 26);
			this->accountFill->TabIndex = 11;
			this->accountFill->Text = L"account number fill";
			// 
			// cardFill
			// 
			this->cardFill->AutoSize = true;
			this->cardFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->cardFill->Location = System::Drawing::Point(480, 96);
			this->cardFill->Name = L"cardFill";
			this->cardFill->Size = System::Drawing::Size(152, 26);
			this->cardFill->TabIndex = 12;
			this->cardFill->Text = L"card number";
			// 
			// expiryFill
			// 
			this->expiryFill->AutoSize = true;
			this->expiryFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->expiryFill->Location = System::Drawing::Point(482, 127);
			this->expiryFill->Name = L"expiryFill";
			this->expiryFill->Size = System::Drawing::Size(114, 26);
			this->expiryFill->TabIndex = 13;
			this->expiryFill->Text = L"expiry fill";
			// 
			// firstFill
			// 
			this->firstFill->AutoSize = true;
			this->firstFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->firstFill->Location = System::Drawing::Point(482, 158);
			this->firstFill->Name = L"firstFill";
			this->firstFill->Size = System::Drawing::Size(158, 26);
			this->firstFill->TabIndex = 14;
			this->firstFill->Text = L"first name fill";
			// 
			// lastFill
			// 
			this->lastFill->AutoSize = true;
			this->lastFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->lastFill->Location = System::Drawing::Point(482, 186);
			this->lastFill->Name = L"lastFill";
			this->lastFill->Size = System::Drawing::Size(154, 26);
			this->lastFill->TabIndex = 15;
			this->lastFill->Text = L"last name fill";
			// 
			// dobFill
			// 
			this->dobFill->AutoSize = true;
			this->dobFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->dobFill->Location = System::Drawing::Point(482, 217);
			this->dobFill->Name = L"dobFill";
			this->dobFill->Size = System::Drawing::Size(184, 26);
			this->dobFill->TabIndex = 16;
			this->dobFill->Text = L"date of birth fill";
			// 
			// addressFill
			// 
			this->addressFill->AutoSize = true;
			this->addressFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->addressFill->Location = System::Drawing::Point(482, 251);
			this->addressFill->Name = L"addressFill";
			this->addressFill->Size = System::Drawing::Size(131, 26);
			this->addressFill->TabIndex = 17;
			this->addressFill->Text = L"address fill";
			// 
			// balanceFill
			// 
			this->balanceFill->AutoSize = true;
			this->balanceFill->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->balanceFill->Location = System::Drawing::Point(482, 289);
			this->balanceFill->Name = L"balanceFill";
			this->balanceFill->Size = System::Drawing::Size(130, 26);
			this->balanceFill->TabIndex = 18;
			this->balanceFill->Text = L"balance fill";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(711, 127);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 118);
			this->pictureBox1->TabIndex = 30;
			this->pictureBox1->TabStop = false;
			// 
			// ConfirmationDequeue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->balanceFill);
			this->Controls->Add(this->addressFill);
			this->Controls->Add(this->dobFill);
			this->Controls->Add(this->lastFill);
			this->Controls->Add(this->firstFill);
			this->Controls->Add(this->expiryFill);
			this->Controls->Add(this->cardFill);
			this->Controls->Add(this->accountFill);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Name = L"ConfirmationDequeue";
			this->Text = L"Confirm Remove";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		commitDequeue();
		MessageBox::Show("Oldest customer removed");
		Hide();
		Close();
	}
};
}
