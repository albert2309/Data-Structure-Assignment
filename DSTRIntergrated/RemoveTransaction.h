#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "transactionRecord.h"
#include "linkedStack.h"
#include "sqlite3.h"
#include <string>

using namespace std;

namespace Project2 {
	void commitPop();
	void cancelWithdrawalOrDeposit(string accountNumber, float amount, string typeOfTransaction);
	void revokeTransfer(string accountNumber, string recepientNumber, float amount);
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RemoveTransaction
	/// </summary>
	public ref class RemoveTransaction : public System::Windows::Forms::Form
	{
	public:
		RemoveTransaction(void)
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
			sqlite3_stmt *stmt = NULL;
			rc = sqlite3_prepare_v2(db, "SELECT COUNT(*) FROM transactionList", -1, &stmt, NULL);
			rc = sqlite3_step(stmt);
			int maxRow = sqlite3_column_int(stmt, 0);
			rc = sqlite3_reset(stmt);
			stmt = NULL;

			rc = sqlite3_prepare_v2(db, "SELECT * FROM transactionList", -1, &stmt, NULL);
			unsigned char * accountNumber = new unsigned char[1500];
			unsigned char * typeOfTransaction = new unsigned char[1500];
			float amount;
			unsigned char * targetCard = new unsigned char[1500];
			unsigned char * dateOfTransaction = new unsigned char[1500];
			if (rc != SQLITE_OK) {
				fprintf(stderr, "%s\n", sqlite3_errmsg(db));
			}
			else {
				rc = sqlite3_step(stmt);
				int colCount = sqlite3_column_count(stmt);
			for(int rowCount = 0; rowCount < maxRow;rowCount++){
				if (rowCount == (maxRow - 1)) {
					for (int colIndex = 0; colIndex < colCount; colIndex++)
					{
						if (colIndex == 2) {
							amount = float(sqlite3_column_double(stmt, colIndex));
							String^ step3 = amount.ToString();
							this->amountFill->Text = step3;
						}
						else {
							const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
							switch (colIndex) {
							case 0: {
								accountNumber = const_cast<unsigned char *>(valChar);
								char * step1 = (char*)accountNumber;
								String^ step3 = gcnew String(step1);
								this->accountFill->Text = step3;
								break;
							}

							case 1:
							{
								typeOfTransaction = const_cast<unsigned char *>(valChar);
								char * step1 = (char*)typeOfTransaction;
								String^ step3 = gcnew String(step1);
								this->typeFill->Text = step3;
								break;
							}
							case 3:
							{
								targetCard = const_cast<unsigned char *>(valChar);
								char * step1 = (char*)targetCard;
								String^ step3 = gcnew String(step1);
								this->targetFill->Text = step3;
								break;
							}
							case 4:
							{
								dateOfTransaction = const_cast<unsigned char *>(valChar);
								char * step1 = (char*)dateOfTransaction;
								String^ step3 = gcnew String(step1);
								this->dateFill->Text = step3;
								break;
							}
							}
						}
					}
				}
				rc = sqlite3_step(stmt);
			}
			rc = sqlite3_reset(stmt);
			String^ step1 = this->accountFill->Text;
			string accountQuery = msclr::interop::marshal_as<std::string>(step1);
			string accountNum = "SELECT first_name, last_name FROM customerList WHERE account_number = '" + accountQuery + "'";
			rc = sqlite3_prepare_v2(db, accountNum.c_str(), -1, &stmt, NULL);
			rc = sqlite3_step(stmt);
			unsigned char * firstName = new unsigned char[1500];
			unsigned char * lastName = new unsigned char[1500];
			const unsigned char * valChar = sqlite3_column_text(stmt, 0);
			firstName = const_cast<unsigned char *>(valChar);
			valChar = sqlite3_column_text(stmt, 1);
			lastName = const_cast<unsigned char *>(valChar);
			char * firstNew = (char*)firstName;
			char * lastNew = (char*)lastName;
			string x = (string) firstNew + " " + (string)lastNew;
			String^ firstFinal = gcnew String(x.c_str());
			this->nameFill->Text = firstFinal;
			//MAKE A IF CONDITION TO SHOW THAT THE TARGETED CARD NAME IS VISIBLE 
			String^ seeRecepient = this->targetFill->Text;
			std::string recepientString = msclr::interop::marshal_as<std::string>(seeRecepient);
			if (recepientString.compare("N/A") != 0) {
				rc = sqlite3_reset(stmt);
				step1 = this->targetFill->Text;
				accountQuery = msclr::interop::marshal_as<std::string>(step1);
				accountNum = "SELECT first_name, last_name FROM customerList WHERE account_number = '" + accountQuery + "'";
				rc = sqlite3_prepare_v2(db, accountNum.c_str(), -1, &stmt, NULL);
				rc = sqlite3_step(stmt);
				firstName = new unsigned char[1500];
				lastName = new unsigned char[1500];
				valChar = sqlite3_column_text(stmt, 0);
				firstName = const_cast<unsigned char *>(valChar);
				valChar = sqlite3_column_text(stmt, 1);
				lastName = const_cast<unsigned char *>(valChar);
				firstNew = (char*)firstName;
				lastNew = (char*)lastName;
				x = (string)firstNew + " " + (string)lastNew;
				firstFinal = gcnew String(x.c_str());
				this->targetNameFill->Text = firstFinal;
			}
			else {
				this->targetNameFill->Text = gcnew String("N/A");
			}
			rc = sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RemoveTransaction()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  targetFill;
	private: System::Windows::Forms::Label^  dateFill;
	private: System::Windows::Forms::Label^  nameFill;
	private: System::Windows::Forms::Label^  amountFill;
	private: System::Windows::Forms::Label^  typeFill;
	private: System::Windows::Forms::Label^  accountFill;
	private: System::Windows::Forms::Label^  targetNameFill;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			this->amountFill = (gcnew System::Windows::Forms::Label());
			this->typeFill = (gcnew System::Windows::Forms::Label());
			this->accountFill = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->targetFill = (gcnew System::Windows::Forms::Label());
			this->dateFill = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nameFill = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->targetNameFill = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// amountFill
			// 
			this->amountFill->AutoSize = true;
			this->amountFill->Location = System::Drawing::Point(519, 210);
			this->amountFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->amountFill->Name = L"amountFill";
			this->amountFill->Size = System::Drawing::Size(130, 26);
			this->amountFill->TabIndex = 19;
			this->amountFill->Text = L"amount fill";
			// 
			// typeFill
			// 
			this->typeFill->AutoSize = true;
			this->typeFill->Location = System::Drawing::Point(519, 162);
			this->typeFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->typeFill->Name = L"typeFill";
			this->typeFill->Size = System::Drawing::Size(95, 26);
			this->typeFill->TabIndex = 18;
			this->typeFill->Text = L"type fill";
			// 
			// accountFill
			// 
			this->accountFill->AutoSize = true;
			this->accountFill->Location = System::Drawing::Point(519, 66);
			this->accountFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->accountFill->Name = L"accountFill";
			this->accountFill->Size = System::Drawing::Size(224, 26);
			this->accountFill->TabIndex = 17;
			this->accountFill->Text = L"account number fill";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(132, 210);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 26);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Amount";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(132, 162);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 26);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Type of Transaction";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(132, 66);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 26);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Account Number";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->label9->Location = System::Drawing::Point(157, 17);
			this->label9->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(544, 29);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Are you sure you want to delete this record\?";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Location = System::Drawing::Point(207, 377);
			this->button2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 61);
			this->button2->TabIndex = 21;
			this->button2->Text = L"CANCEL";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &RemoveTransaction::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(524, 377);
			this->button1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 61);
			this->button1->TabIndex = 22;
			this->button1->Text = L"DELETE";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &RemoveTransaction::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(132, 255);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 26);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Target Card";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(132, 345);
			this->label5->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(226, 26);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Date of Transaction";
			// 
			// targetFill
			// 
			this->targetFill->AutoSize = true;
			this->targetFill->Location = System::Drawing::Point(519, 255);
			this->targetFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->targetFill->Name = L"targetFill";
			this->targetFill->Size = System::Drawing::Size(113, 26);
			this->targetFill->TabIndex = 25;
			this->targetFill->Text = L"target fill";
			// 
			// dateFill
			// 
			this->dateFill->AutoSize = true;
			this->dateFill->Location = System::Drawing::Point(519, 345);
			this->dateFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->dateFill->Name = L"dateFill";
			this->dateFill->Size = System::Drawing::Size(95, 26);
			this->dateFill->TabIndex = 26;
			this->dateFill->Text = L"date fill";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(132, 114);
			this->label6->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(122, 26);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Full Name";
			// 
			// nameFill
			// 
			this->nameFill->AutoSize = true;
			this->nameFill->Location = System::Drawing::Point(519, 114);
			this->nameFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->nameFill->Name = L"nameFill";
			this->nameFill->Size = System::Drawing::Size(112, 26);
			this->nameFill->TabIndex = 28;
			this->nameFill->Text = L"name Fill";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(132, 296);
			this->label7->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(199, 26);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Target Full Name";
			// 
			// targetNameFill
			// 
			this->targetNameFill->AutoSize = true;
			this->targetNameFill->Location = System::Drawing::Point(519, 296);
			this->targetNameFill->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->targetNameFill->Name = L"targetNameFill";
			this->targetNameFill->Size = System::Drawing::Size(182, 26);
			this->targetNameFill->TabIndex = 30;
			this->targetNameFill->Text = L"target name fill";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(711, 140);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 118);
			this->pictureBox1->TabIndex = 31;
			this->pictureBox1->TabStop = false;
			// 
			// RemoveTransaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->targetNameFill);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->nameFill);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->dateFill);
			this->Controls->Add(this->targetFill);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->amountFill);
			this->Controls->Add(this->typeFill);
			this->Controls->Add(this->accountFill);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"RemoveTransaction";
			this->Text = L"RemoveTransaction";
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
			commitPop();
			String^ convertToString = this->typeFill->Text;
			std::string typeTransactionInString = msclr::interop::marshal_as<std::string>(convertToString);
			convertToString = this->accountFill->Text;
			std::string accountString = msclr::interop::marshal_as<std::string>(convertToString);
			convertToString = this->targetFill->Text;
			std::string recepientString = msclr::interop::marshal_as<std::string>(convertToString);
			convertToString = this->amountFill->Text;
			std::string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
			if (typeTransactionInString.compare("TRANSFER") == 0) {
				revokeTransfer(accountString, recepientString, stof(amountInString));
				MessageBox::Show("Transfer has been cancelled");
			}
			else {
				cancelWithdrawalOrDeposit(accountString, stof(amountInString), typeTransactionInString);
				if (typeTransactionInString.compare("DEPOSIT") == 0)
					MessageBox::Show("Deposit has been cancelled");
				else
					MessageBox::Show("Withdraw has been cancelled");

			}
			Hide();
			Close();
	}
};
}
