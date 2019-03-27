#pragma once
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "sqlite3.h"
#include "linkedQueueType.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DisplayAll
	/// </summary>
	public ref class DisplayAll : public System::Windows::Forms::Form
	{
	public:
		DisplayAll(void)
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
		~DisplayAll()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:








	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  accountNumberColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cardVerificationCodeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  expiryDateColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lastNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dateOfBirthColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  addressColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  balanceColumn;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->accountNumberColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cardVerificationCodeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->expiryDateColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateOfBirthColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addressColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->balanceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->exitButton = (gcnew System::Windows::Forms::Button());
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->accountNumberColumn,
					this->cardVerificationCodeColumn, this->expiryDateColumn, this->firstNameColumn, this->lastNameColumn, this->dateOfBirthColumn,
					this->addressColumn, this->balanceColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(14, 45);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(941, 271);
			this->dataGridView1->TabIndex = 9;
			// 
			// accountNumberColumn
			// 
			this->accountNumberColumn->HeaderText = L"Account Number";
			this->accountNumberColumn->Name = L"accountNumberColumn";
			this->accountNumberColumn->ReadOnly = true;
			// 
			// cardVerificationCodeColumn
			// 
			this->cardVerificationCodeColumn->HeaderText = L"Card Verification Code";
			this->cardVerificationCodeColumn->Name = L"cardVerificationCodeColumn";
			this->cardVerificationCodeColumn->ReadOnly = true;
			// 
			// expiryDateColumn
			// 
			this->expiryDateColumn->HeaderText = L"Expiry Date";
			this->expiryDateColumn->Name = L"expiryDateColumn";
			this->expiryDateColumn->ReadOnly = true;
			// 
			// firstNameColumn
			// 
			this->firstNameColumn->HeaderText = L"First Name";
			this->firstNameColumn->Name = L"firstNameColumn";
			this->firstNameColumn->ReadOnly = true;
			// 
			// lastNameColumn
			// 
			this->lastNameColumn->HeaderText = L"Last Name";
			this->lastNameColumn->Name = L"lastNameColumn";
			this->lastNameColumn->ReadOnly = true;
			// 
			// dateOfBirthColumn
			// 
			this->dateOfBirthColumn->HeaderText = L"Date of Birth";
			this->dateOfBirthColumn->Name = L"dateOfBirthColumn";
			this->dateOfBirthColumn->ReadOnly = true;
			// 
			// addressColumn
			// 
			this->addressColumn->HeaderText = L"Address";
			this->addressColumn->Name = L"addressColumn";
			this->addressColumn->ReadOnly = true;
			// 
			// balanceColumn
			// 
			this->balanceColumn->HeaderText = L"Balance";
			this->balanceColumn->Name = L"balanceColumn";
			this->balanceColumn->ReadOnly = true;
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->ForeColor = System::Drawing::Color::Aqua;
			this->exitButton->Location = System::Drawing::Point(368, 357);
			this->exitButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(148, 61);
			this->exitButton->TabIndex = 10;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &DisplayAll::exitButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(635, 323);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 118);
			this->pictureBox1->TabIndex = 29;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(327, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 32);
			this->label1->TabIndex = 30;
			this->label1->Text = L"List of All Customer";
			// 
			// DisplayAll
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 12));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"DisplayAll";
			this->Text = L"Display All";
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
			rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList;", -1, &stmt, NULL);
			linkedQueueType queue;
			int rowCount = 0;
			rc = sqlite3_step(stmt);
			while (rc != SQLITE_DONE && rc != SQLITE_OK)
			{
				rowCount++;
				int colCount = sqlite3_column_count(stmt);
				unsigned char * accountNumber = new unsigned char[1500];
				int cardVerificationCode = 0;
				unsigned char * expiryDate = new unsigned char[1500];
				unsigned char * firstName = new unsigned char[1500];
				unsigned char * lastName = new unsigned char[1500];
				unsigned char * dateOfBirth = new unsigned char[1500];
				unsigned char * address = new unsigned char[1500];
				float balance = 0;
				for (int colIndex = 0; colIndex < colCount; colIndex++)
				{
					if (colIndex == 1) {
						cardVerificationCode = sqlite3_column_int(stmt, colIndex);
					}
					else if (colIndex == 7) {
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
						case 2:
						{
							expiryDate = const_cast<unsigned char *>(valChar);
							break;
						}
						case 3:
						{
							firstName = const_cast<unsigned char *>(valChar);
							break;
						}
						case 4:
						{
							lastName = const_cast<unsigned char *>(valChar);
							break;
						}
						case 5:
						{
							dateOfBirth = const_cast<unsigned char *>(valChar);
							break;
						}
						case 6:
						{
							address = const_cast<unsigned char *>(valChar);
							break;
						}
						default:
							std::cout << "SOMETHING WRONG" << std::endl;
							break;
						}
					}
				}

				customerInfo newCustomer((char*)accountNumber, cardVerificationCode, (char*)expiryDate, (char *)firstName, (char *)lastName, (char *)dateOfBirth, (char *)address, balance);

				queue.addQueue(newCustomer);
				rc = sqlite3_step(stmt);
			}

			for (node * displayNode = queue.getQueue(); displayNode != NULL ; displayNode = displayNode->link) {
				char * accountNumber = new  char[1500];
				int cardVerificationCode = 0;
				char * expiryDate = new  char[1500];
				char * firstName = new  char[1500];
				char * lastName = new  char[1500];
				char * dateOfBirth = new  char[1500];
				char * address = new  char[1500];
				float balance = 0;
				String^ convertedCardVerification;
				String^ convertedAccountNumber;
				String^ convertedExpiryDate;
				String^ convertedFirstName;
				String^ convertedLastName;
				String^ convertedDateOfBirth;
				String^ convertedAddress;
				String^ convertedBalance;

				displayNode->info.getAccountNumber(accountNumber);
				displayNode->info.getAddress(address);
				balance = displayNode->info.getBalance();
				cardVerificationCode = displayNode->info.getCardVerificationCode();
				displayNode->info.getDateOfBirth(dateOfBirth);
				displayNode->info.getExpiryDate(expiryDate);
				displayNode->info.getFirstName(firstName);
				displayNode->info.getLastName(lastName);

				convertedCardVerification = cardVerificationCode.ToString();
				convertedAccountNumber = gcnew String(accountNumber);
				convertedExpiryDate = gcnew String(expiryDate);
				convertedFirstName = gcnew String(firstName);
				convertedLastName = gcnew String(lastName);
				convertedDateOfBirth = gcnew String(dateOfBirth);
				convertedAddress = gcnew String(address);
				convertedBalance = balance.ToString();

				this->dataGridView1->Rows->Add(convertedAccountNumber, convertedCardVerification, convertedExpiryDate, convertedFirstName, convertedLastName, convertedDateOfBirth, convertedAddress, convertedBalance);
			}
			rc = sqlite3_finalize(stmt);
			queue.~linkedQueueType();
			sqlite3_close(db);
		}


#pragma endregion
	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Close();
	}
};
}
