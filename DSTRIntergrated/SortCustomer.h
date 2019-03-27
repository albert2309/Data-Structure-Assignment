#pragma once
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "sqlite3.h"
#include "linkedQueueType.h"
#include <list>
#include <iostream>
namespace Project2 {
	list<string> sortByFirstName();
	list<string> sortByLastName();
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SortCustomer
	/// </summary>
	public ref class SortCustomer : public System::Windows::Forms::Form
	{
	public:
		SortCustomer(void)
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
		~SortCustomer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  accountNumberColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cardVerificationCodeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  expiryColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lastColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dateOfBirthColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  addressColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  balanceColumn;
	private: System::Windows::Forms::GroupBox^  groupBox1;


	private: System::Windows::Forms::RadioButton^  lastNameRadio;
	private: System::Windows::Forms::RadioButton^  firstNameRadio;


	private: System::Windows::Forms::RadioButton^  accountRadio;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::Label^  label2;


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
			this->expiryColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateOfBirthColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addressColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->balanceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lastNameRadio = (gcnew System::Windows::Forms::RadioButton());
			this->firstNameRadio = (gcnew System::Windows::Forms::RadioButton());
			this->accountRadio = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->accountNumberColumn,
					this->cardVerificationCodeColumn, this->expiryColumn, this->firstColumn, this->lastColumn, this->dateOfBirthColumn, this->addressColumn,
					this->balanceColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(516, 30);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(1002, 511);
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
			// expiryColumn
			// 
			this->expiryColumn->HeaderText = L"Expiry Date";
			this->expiryColumn->Name = L"expiryColumn";
			this->expiryColumn->ReadOnly = true;
			// 
			// firstColumn
			// 
			this->firstColumn->HeaderText = L"First Name";
			this->firstColumn->Name = L"firstColumn";
			this->firstColumn->ReadOnly = true;
			// 
			// lastColumn
			// 
			this->lastColumn->HeaderText = L"Last Name";
			this->lastColumn->Name = L"lastColumn";
			this->lastColumn->ReadOnly = true;
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lastNameRadio);
			this->groupBox1->Controls->Add(this->firstNameRadio);
			this->groupBox1->Controls->Add(this->accountRadio);
			this->groupBox1->Location = System::Drawing::Point(16, 134);
			this->groupBox1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Size = System::Drawing::Size(440, 131);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			// 
			// lastNameRadio
			// 
			this->lastNameRadio->AutoSize = true;
			this->lastNameRadio->ForeColor = System::Drawing::Color::Cyan;
			this->lastNameRadio->Location = System::Drawing::Point(249, 80);
			this->lastNameRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->lastNameRadio->Name = L"lastNameRadio";
			this->lastNameRadio->Size = System::Drawing::Size(146, 30);
			this->lastNameRadio->TabIndex = 4;
			this->lastNameRadio->TabStop = true;
			this->lastNameRadio->Text = L"Last Name";
			this->lastNameRadio->UseVisualStyleBackColor = true;
			// 
			// firstNameRadio
			// 
			this->firstNameRadio->AutoSize = true;
			this->firstNameRadio->ForeColor = System::Drawing::Color::Cyan;
			this->firstNameRadio->Location = System::Drawing::Point(13, 81);
			this->firstNameRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->firstNameRadio->Name = L"firstNameRadio";
			this->firstNameRadio->Size = System::Drawing::Size(149, 30);
			this->firstNameRadio->TabIndex = 3;
			this->firstNameRadio->TabStop = true;
			this->firstNameRadio->Text = L"First Name";
			this->firstNameRadio->UseVisualStyleBackColor = true;
			// 
			// accountRadio
			// 
			this->accountRadio->AutoSize = true;
			this->accountRadio->ForeColor = System::Drawing::Color::Cyan;
			this->accountRadio->Location = System::Drawing::Point(13, 37);
			this->accountRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountRadio->Name = L"accountRadio";
			this->accountRadio->Size = System::Drawing::Size(210, 30);
			this->accountRadio->TabIndex = 0;
			this->accountRadio->TabStop = true;
			this->accountRadio->Text = L"Account number";
			this->accountRadio->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(16, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(244, 118);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->ForeColor = System::Drawing::Color::Cyan;
			this->exitButton->Location = System::Drawing::Point(29, 295);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(164, 58);
			this->exitButton->TabIndex = 12;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &SortCustomer::exitButton_Click);
			// 
			// searchButton
			// 
			this->searchButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->searchButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->searchButton->ForeColor = System::Drawing::Color::Cyan;
			this->searchButton->Location = System::Drawing::Point(292, 295);
			this->searchButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(164, 58);
			this->searchButton->TabIndex = 11;
			this->searchButton->Text = L"Sort";
			this->searchButton->UseVisualStyleBackColor = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &SortCustomer::searchButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(279, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 32);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Sort Customers";
			// 
			// SortCustomer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(1545, 556);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Black;
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"SortCustomer";
			this->Text = L"SortCustomer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		char * targetedQuery;
		list<string> sortedName;
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
		if (this->firstNameRadio->Checked == true){
			rc = sqlite3_step(stmt);
			while (rc != SQLITE_DONE && rc != SQLITE_OK)
			{
				unsigned char * firstName = new unsigned char[1500];
				unsigned char * lastName = new unsigned char[1500];
				const unsigned char * valChar = sqlite3_column_text(stmt, 3);
				firstName = const_cast<unsigned char *>(valChar);
				valChar = sqlite3_column_text(stmt, 4);
				lastName = const_cast<unsigned char *>(valChar);
				char fullName[200] = "";
				strcat(fullName, (char*)firstName);
				strcat(fullName, " ");
				strcat(fullName, (char*)lastName);
				string fullNameString = string(fullName);
				sortedName.push_front(fullNameString);

				rc = sqlite3_step(stmt);
			}
			sortedName.sort();
			targetedQuery = "first_name";

		}
		else if (this->lastNameRadio->Checked == true) {
			targetedQuery = "last_name";
			rc = sqlite3_step(stmt);
			while (rc != SQLITE_DONE && rc != SQLITE_OK)
			{
				unsigned char * firstName = new unsigned char[1500];
				unsigned char * lastName = new unsigned char[1500];
				const unsigned char * valChar = sqlite3_column_text(stmt, 3);
				firstName = const_cast<unsigned char *>(valChar);
				valChar = sqlite3_column_text(stmt, 4);
				lastName = const_cast<unsigned char *>(valChar);
				char fullName[200] = "";
				strcat(fullName, (char*)lastName);
				strcat(fullName, " ");
				strcat(fullName, (char*)firstName);
				string fullNameString = string(fullName);
				sortedName.push_front(fullNameString);

				rc = sqlite3_step(stmt);
			}
			sortedName.sort();
		}
		else if (this->accountRadio->Checked == true)
			targetedQuery = "account_number";
		else {
			MessageBox::Show("Must pick any of the radio box as a criteria to sort.");
			return;
		}


		
		//node * results = queue.findRelevantInformation(boxInput.c_str(), targetedQuery);
		sqlite3_reset(stmt);
		if (strcmp(targetedQuery, "account_number") == 0)
			rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList ORDER BY account_number", -1, &stmt, NULL);
		else
			rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList", -1, &stmt, NULL);
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
		if (strcmp(targetedQuery, "account_number") == 0) {
			node * curr;
			for (curr = queue.getQueue(); curr; curr = curr->link) {
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

				curr->info.getAccountNumber(accountNumber);
				curr->info.getAddress(address);
				balance = curr->info.getBalance();
				cardVerificationCode = curr->info.getCardVerificationCode();
				curr->info.getDateOfBirth(dateOfBirth);
				curr->info.getExpiryDate(expiryDate);
				curr->info.getFirstName(firstName);
				curr->info.getLastName(lastName);
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
		}
		else {
			while (sortedName.empty() == false) {
				node * curr;
				char fullName[200];
				for (curr = queue.getQueue(); curr; curr = curr->link) {
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
					
					if (sortedName.empty() || curr == NULL)
						break;
					curr->info.getAccountNumber(accountNumber);
					curr->info.getAddress(address);
					balance = curr->info.getBalance();
					cardVerificationCode = curr->info.getCardVerificationCode();
					curr->info.getDateOfBirth(dateOfBirth);
					curr->info.getExpiryDate(expiryDate);
					curr->info.getFirstName(firstName);
					curr->info.getLastName(lastName);
					if (strcmp(targetedQuery, "first_name") == 0) {
						strcpy(fullName, firstName);
						strcat(fullName, " ");
						strcat(fullName, lastName);
					}
					else if (strcmp(targetedQuery, "last_name") == 0) {
						strcpy(fullName, lastName);
						strcat(fullName, " ");
						strcat(fullName, firstName);
					}
					if (strcmp(fullName, const_cast<char *>(sortedName.front().c_str())) == 0) {
						convertedCardVerification = cardVerificationCode.ToString();
						convertedAccountNumber = gcnew String(accountNumber);
						convertedExpiryDate = gcnew String(expiryDate);
						convertedFirstName = gcnew String(firstName);
						convertedLastName = gcnew String(lastName);
						convertedDateOfBirth = gcnew String(dateOfBirth);
						convertedAddress = gcnew String(address);
						convertedBalance = balance.ToString();
						this->dataGridView1->Rows->Add(convertedAccountNumber, convertedCardVerification, convertedExpiryDate, convertedFirstName, convertedLastName, convertedDateOfBirth, convertedAddress, convertedBalance);
						sortedName.pop_front();
					}
					if (sortedName.empty() || curr->link == NULL)
						break;
				}
				delete curr;
			}
		}
	
		
	
	}
private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
};
}
