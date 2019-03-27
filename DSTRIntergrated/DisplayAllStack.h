#pragma once
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "sqlite3.h"
#include "linkedStack.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DisplayAllStack
	/// </summary>
	public ref class DisplayAllStack : public System::Windows::Forms::Form
	{
	public:
		DisplayAllStack(void)
		{
			InitializeComponent();
			renderTheTable();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DisplayAllStack()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;





	private: System::Windows::Forms::Button^  button1;





	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  accountNumberColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  typeOfTransactionColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  amountColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  targetColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dateOfTransactionColumn;
	private: System::Windows::Forms::Label^  label1;










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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->accountNumberColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->typeOfTransactionColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amountColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->targetColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateOfTransactionColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->accountNumberColumn,
					this->typeOfTransactionColumn, this->amountColumn, this->targetColumn, this->dateOfTransactionColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(41, 47);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(875, 269);
			this->dataGridView1->TabIndex = 10;
			// 
			// accountNumberColumn
			// 
			this->accountNumberColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->accountNumberColumn->Frozen = true;
			this->accountNumberColumn->HeaderText = L"Account Number";
			this->accountNumberColumn->Name = L"accountNumberColumn";
			this->accountNumberColumn->ReadOnly = true;
			this->accountNumberColumn->Width = 151;
			// 
			// typeOfTransactionColumn
			// 
			this->typeOfTransactionColumn->HeaderText = L"Type of Transaction";
			this->typeOfTransactionColumn->Name = L"typeOfTransactionColumn";
			this->typeOfTransactionColumn->ReadOnly = true;
			this->typeOfTransactionColumn->Width = 150;
			// 
			// amountColumn
			// 
			this->amountColumn->HeaderText = L"Amount";
			this->amountColumn->Name = L"amountColumn";
			this->amountColumn->ReadOnly = true;
			// 
			// targetColumn
			// 
			this->targetColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->targetColumn->HeaderText = L"Target Account";
			this->targetColumn->Name = L"targetColumn";
			this->targetColumn->ReadOnly = true;
			this->targetColumn->Width = 141;
			// 
			// dateOfTransactionColumn
			// 
			this->dateOfTransactionColumn->HeaderText = L"Date of Transaction";
			this->dateOfTransactionColumn->Name = L"dateOfTransactionColumn";
			this->dateOfTransactionColumn->ReadOnly = true;
			this->dateOfTransactionColumn->Width = 120;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(383, 350);
			this->button1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 61);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &DisplayAllStack::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(639, 323);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 118);
			this->pictureBox1->TabIndex = 30;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(336, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(304, 32);
			this->label1->TabIndex = 31;
			this->label1->Text = L"List of All Transaction";
			// 
			// DisplayAllStack
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 12));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"DisplayAllStack";
			this->Text = L"DisplayAllStack";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void renderTheTable() {
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
				unsigned char * typeOfTransaction = new unsigned char[1500];
				unsigned char * targetAccount = new unsigned char[1500];
				unsigned char * dateOfTransaction = new unsigned char[1500];
				float balance = 0;
				for (int colIndex = 0; colIndex < colCount; colIndex++)
				{
					if (colIndex == 2) {
						balance = float(sqlite3_column_double(stmt, colIndex));
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
							typeOfTransaction = const_cast<unsigned char *>(valChar);
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

				transactionRecord newRecord((char*)accountNumber, (char*)typeOfTransaction, balance, (char*)targetAccount, (char*)dateOfTransaction);

				stack.push(newRecord);
				rc = sqlite3_step(stmt);
			}
			
			for (nodeStack * displayNode = stack.getStack(); displayNode != NULL; displayNode = displayNode->link) {
				char * accountNumber = new  char[1500];
				char * typeOfTransaction = new  char[1500];
				char * targetAccount = new  char[1500];
				char * dateOfTransaction = new  char[1500];
				float amount = 0;
				String^ convertedTypeOfTransaction;
				String^ convertedAccountNumber;
				String^ convertedTargetAccount;
				String^ convertedDateOfTransaction;
				String^ convertedAmount;

				displayNode->info.getAccountNumber(accountNumber);
				displayNode->info.getDateOfTransaction(dateOfTransaction);
				amount = displayNode->info.getAmount();
				displayNode->info.getTargetCard(targetAccount);
				displayNode->info.getTypeOfTransaction(typeOfTransaction);

				convertedAccountNumber = gcnew String(accountNumber);
				convertedTypeOfTransaction = gcnew String(typeOfTransaction);
				convertedTargetAccount = gcnew String(targetAccount);
				convertedDateOfTransaction = gcnew String(dateOfTransaction);
				convertedAmount = amount.ToString();

				this->dataGridView1->Rows->Add(convertedAccountNumber, convertedTypeOfTransaction, convertedAmount, convertedTargetAccount, convertedDateOfTransaction);
			}
			rc = sqlite3_finalize(stmt);
			stack.~linkedStack();
			sqlite3_close(db);
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Close();
	}
};
}
