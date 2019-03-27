#pragma once
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "sqlite3.h"
#include "linkedStack.h"
#include "transactionRecord.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SearchTransaction
	/// </summary>
	public ref class SearchTransaction : public System::Windows::Forms::Form
	{
	public:
		SearchTransaction(void)
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
		~SearchTransaction()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::TextBox^  searchBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  targetRadio;
	private: System::Windows::Forms::RadioButton^  amountRadio;
	private: System::Windows::Forms::RadioButton^  dateRadio;
	private: System::Windows::Forms::RadioButton^  transactionTypeRadio;
	private: System::Windows::Forms::RadioButton^  accountRadio;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  accountNumberColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  typeOfTransactionColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  amountColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  targetedAccountColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dateOfTransactionColumn;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;






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
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->targetRadio = (gcnew System::Windows::Forms::RadioButton());
			this->amountRadio = (gcnew System::Windows::Forms::RadioButton());
			this->dateRadio = (gcnew System::Windows::Forms::RadioButton());
			this->transactionTypeRadio = (gcnew System::Windows::Forms::RadioButton());
			this->accountRadio = (gcnew System::Windows::Forms::RadioButton());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->accountNumberColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->typeOfTransactionColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amountColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->targetedAccountColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateOfTransactionColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->Location = System::Drawing::Point(26, 351);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(164, 58);
			this->exitButton->TabIndex = 9;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &SearchTransaction::exitButton_Click);
			// 
			// searchButton
			// 
			this->searchButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->searchButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->searchButton->Location = System::Drawing::Point(408, 351);
			this->searchButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(164, 58);
			this->searchButton->TabIndex = 8;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &SearchTransaction::searchButton_Click);
			// 
			// searchBox
			// 
			this->searchBox->Location = System::Drawing::Point(26, 76);
			this->searchBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(546, 33);
			this->searchBox->TabIndex = 7;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->targetRadio);
			this->groupBox1->Controls->Add(this->amountRadio);
			this->groupBox1->Controls->Add(this->dateRadio);
			this->groupBox1->Controls->Add(this->transactionTypeRadio);
			this->groupBox1->Controls->Add(this->accountRadio);
			this->groupBox1->Location = System::Drawing::Point(26, 121);
			this->groupBox1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Size = System::Drawing::Size(546, 191);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			// 
			// targetRadio
			// 
			this->targetRadio->AutoSize = true;
			this->targetRadio->Location = System::Drawing::Point(249, 81);
			this->targetRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->targetRadio->Name = L"targetRadio";
			this->targetRadio->Size = System::Drawing::Size(221, 30);
			this->targetRadio->TabIndex = 4;
			this->targetRadio->TabStop = true;
			this->targetRadio->Text = L"Targeted Account";
			this->targetRadio->UseVisualStyleBackColor = true;
			// 
			// amountRadio
			// 
			this->amountRadio->AutoSize = true;
			this->amountRadio->Location = System::Drawing::Point(13, 81);
			this->amountRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->amountRadio->Name = L"amountRadio";
			this->amountRadio->Size = System::Drawing::Size(116, 30);
			this->amountRadio->TabIndex = 3;
			this->amountRadio->TabStop = true;
			this->amountRadio->Text = L"Amount";
			this->amountRadio->UseVisualStyleBackColor = true;
			// 
			// dateRadio
			// 
			this->dateRadio->AutoSize = true;
			this->dateRadio->Location = System::Drawing::Point(11, 129);
			this->dateRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dateRadio->Name = L"dateRadio";
			this->dateRadio->Size = System::Drawing::Size(244, 30);
			this->dateRadio->TabIndex = 2;
			this->dateRadio->TabStop = true;
			this->dateRadio->Text = L"Date of Transaction";
			this->dateRadio->UseVisualStyleBackColor = true;
			// 
			// transactionTypeRadio
			// 
			this->transactionTypeRadio->AutoSize = true;
			this->transactionTypeRadio->Location = System::Drawing::Point(249, 37);
			this->transactionTypeRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->transactionTypeRadio->Name = L"transactionTypeRadio";
			this->transactionTypeRadio->Size = System::Drawing::Size(244, 30);
			this->transactionTypeRadio->TabIndex = 1;
			this->transactionTypeRadio->TabStop = true;
			this->transactionTypeRadio->Text = L"Type of Transaction";
			this->transactionTypeRadio->UseVisualStyleBackColor = true;
			// 
			// accountRadio
			// 
			this->accountRadio->AutoSize = true;
			this->accountRadio->Location = System::Drawing::Point(13, 37);
			this->accountRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountRadio->Name = L"accountRadio";
			this->accountRadio->Size = System::Drawing::Size(210, 30);
			this->accountRadio->TabIndex = 0;
			this->accountRadio->TabStop = true;
			this->accountRadio->Text = L"Account number";
			this->accountRadio->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->accountNumberColumn,
					this->typeOfTransactionColumn, this->amountColumn, this->targetedAccountColumn, this->dateOfTransactionColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(609, 43);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(681, 269);
			this->dataGridView1->TabIndex = 10;
			// 
			// accountNumberColumn
			// 
			this->accountNumberColumn->HeaderText = L"Account Number";
			this->accountNumberColumn->Name = L"accountNumberColumn";
			this->accountNumberColumn->ReadOnly = true;
			// 
			// typeOfTransactionColumn
			// 
			this->typeOfTransactionColumn->HeaderText = L"Type of Transaction";
			this->typeOfTransactionColumn->Name = L"typeOfTransactionColumn";
			this->typeOfTransactionColumn->ReadOnly = true;
			// 
			// amountColumn
			// 
			this->amountColumn->HeaderText = L"Amount";
			this->amountColumn->Name = L"amountColumn";
			this->amountColumn->ReadOnly = true;
			// 
			// targetedAccountColumn
			// 
			this->targetedAccountColumn->HeaderText = L"Targeted Account";
			this->targetedAccountColumn->Name = L"targetedAccountColumn";
			this->targetedAccountColumn->ReadOnly = true;
			// 
			// dateOfTransactionColumn
			// 
			this->dateOfTransactionColumn->HeaderText = L"Date of Transaction";
			this->dateOfTransactionColumn->Name = L"dateOfTransactionColumn";
			this->dateOfTransactionColumn->ReadOnly = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(632, 321);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 29;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label1->Location = System::Drawing::Point(20, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(286, 32);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Search Transactions";
			// 
			// SearchTransaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(1331, 453);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->searchBox);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"SearchTransaction";
			this->Text = L"SearchTransaction";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ query = searchBox->Text;
	int test = query->IsNullOrWhiteSpace(searchBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Search query must not be empty");
		return;
	}
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();
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
	rc = sqlite3_prepare_v2(db, "SELECT * FROM transactionList", -1, &stmt, NULL);
	linkedStack stack;
	int rowCount = 0;
	rc = sqlite3_step(stmt);
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		rowCount++;
		int colCount = sqlite3_column_count(stmt);
		unsigned char * accountNumber = new unsigned char[1500];
		unsigned char * transactionType = new unsigned char[1500];
		unsigned char * dateOfTransaction = new unsigned char[1500];
		unsigned char * targetAccount = new unsigned char[1500];
		float amount = 0;
		for (int colIndex = 0; colIndex < colCount; colIndex++)
		{
			if (colIndex == 2) {
				amount = float(sqlite3_column_double(stmt, colIndex));
			}
			else {
				const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
				switch (colIndex) {
				case 0:
				{
					accountNumber = const_cast<unsigned char *>(valChar);
					break;
				}
				case 1:
				{
					transactionType = const_cast<unsigned char *>(valChar);
					break;
				}
				case 3:
				{
					targetAccount = const_cast<unsigned char *>(valChar);
					break;
				}
				case 4:
				{
					dateOfTransaction = const_cast<unsigned char *>(valChar);
					break;
				}
				default:
					std::cout << "SOMETHING WRONG" << std::endl;
					break;
				}
			}
		}

		transactionRecord newTransaction((char*)accountNumber, (char*)transactionType, amount, (char *) targetAccount, (char *) dateOfTransaction);

		stack.push(newTransaction);
		rc = sqlite3_step(stmt);
	}

	String^ x = searchBox->Text->ToString();
	std::string boxInput = msclr::interop::marshal_as<std::string>(x);
	char * targetedQuery;
	if (this->accountRadio->Checked == true)
		targetedQuery = "account_number";
	else if (this->transactionTypeRadio->Checked == true)
		targetedQuery = "type_of_transaction";
	else if (this->targetRadio->Checked == true)
		targetedQuery = "target_account";
	else if (this->dateRadio->Checked == true)
		targetedQuery = "date_of_transaction";
	else {
		MessageBox::Show("Must pick any of the radio box as a criteria to search.");
		return;
	}

	nodeStack * results = stack.findRelevantInformation(boxInput.c_str(), targetedQuery);
	nodeStack * curr;
	for (curr = results; curr; curr = curr->link) {
		char * accountNumber = new  char[1500];
		char * dateOfTransaction = new  char[1500];
		char * targetAccount = new  char[1500];
		char * typeOfTranscation = new  char[1500];
		float amount = 0;
		String^ c0onvertedDateOfTransaction;
		String^ convertedAccountNumber;
		String^ convertedTargetAccount;
		String^ convertedTypeOfTransaction;
		String^ convertedAmount;

		curr->info.getAccountNumber(accountNumber);
		amount = curr->info.getAmount();
		curr->info.getDateOfTransaction(dateOfTransaction);
		curr->info.getTargetCard(targetAccount);
		curr->info.getTypeOfTransaction(typeOfTranscation);

		convertedAmount = amount.ToString();
		convertedAccountNumber = gcnew String(accountNumber);
		c0onvertedDateOfTransaction = gcnew String(dateOfTransaction);
		convertedTargetAccount = gcnew String(targetAccount);
		convertedTypeOfTransaction = gcnew String(typeOfTranscation);


		this->dataGridView1->Rows->Add(convertedAccountNumber, convertedTypeOfTransaction, convertedAmount, convertedTargetAccount, c0onvertedDateOfTransaction);
	}
	sqlite3_close(db);
}
private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
};
}
