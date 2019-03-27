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
	/// Summary for SearchCustomer
	/// </summary>
	public ref class SearchCustomer : public System::Windows::Forms::Form
	{
	public:
		SearchCustomer(void)
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
		~SearchCustomer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  accountRadio;
	private: System::Windows::Forms::RadioButton^  cardVerificationRadio;
	private: System::Windows::Forms::RadioButton^  addressRadio;
	private: System::Windows::Forms::RadioButton^  dateOfBirthRadio;
	private: System::Windows::Forms::RadioButton^  lastNameRadio;
	private: System::Windows::Forms::RadioButton^  firstNameRadio;
	private: System::Windows::Forms::RadioButton^  expiryRadio;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::TextBox^  searchBox;
	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  accountNumberColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cardVerificationCodeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  expiryColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lastColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dateOfBirthColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  addressColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  balanceColumn;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label2;

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
			this->accountRadio = (gcnew System::Windows::Forms::RadioButton());
			this->cardVerificationRadio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->addressRadio = (gcnew System::Windows::Forms::RadioButton());
			this->dateOfBirthRadio = (gcnew System::Windows::Forms::RadioButton());
			this->lastNameRadio = (gcnew System::Windows::Forms::RadioButton());
			this->firstNameRadio = (gcnew System::Windows::Forms::RadioButton());
			this->expiryRadio = (gcnew System::Windows::Forms::RadioButton());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->accountNumberColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cardVerificationCodeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->expiryColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateOfBirthColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addressColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->balanceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
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
			// cardVerificationRadio
			// 
			this->cardVerificationRadio->AutoSize = true;
			this->cardVerificationRadio->Location = System::Drawing::Point(249, 37);
			this->cardVerificationRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->cardVerificationRadio->Name = L"cardVerificationRadio";
			this->cardVerificationRadio->Size = System::Drawing::Size(274, 30);
			this->cardVerificationRadio->TabIndex = 1;
			this->cardVerificationRadio->TabStop = true;
			this->cardVerificationRadio->Text = L"Card Verification Code";
			this->cardVerificationRadio->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->addressRadio);
			this->groupBox1->Controls->Add(this->dateOfBirthRadio);
			this->groupBox1->Controls->Add(this->lastNameRadio);
			this->groupBox1->Controls->Add(this->firstNameRadio);
			this->groupBox1->Controls->Add(this->expiryRadio);
			this->groupBox1->Controls->Add(this->cardVerificationRadio);
			this->groupBox1->Controls->Add(this->accountRadio);
			this->groupBox1->Location = System::Drawing::Point(26, 132);
			this->groupBox1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Size = System::Drawing::Size(530, 242);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			// 
			// addressRadio
			// 
			this->addressRadio->AutoSize = true;
			this->addressRadio->Location = System::Drawing::Point(13, 175);
			this->addressRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->addressRadio->Name = L"addressRadio";
			this->addressRadio->Size = System::Drawing::Size(117, 30);
			this->addressRadio->TabIndex = 6;
			this->addressRadio->TabStop = true;
			this->addressRadio->Text = L"Address";
			this->addressRadio->UseVisualStyleBackColor = true;
			// 
			// dateOfBirthRadio
			// 
			this->dateOfBirthRadio->AutoSize = true;
			this->dateOfBirthRadio->Location = System::Drawing::Point(249, 129);
			this->dateOfBirthRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dateOfBirthRadio->Name = L"dateOfBirthRadio";
			this->dateOfBirthRadio->Size = System::Drawing::Size(172, 30);
			this->dateOfBirthRadio->TabIndex = 5;
			this->dateOfBirthRadio->TabStop = true;
			this->dateOfBirthRadio->Text = L"Date of Birth";
			this->dateOfBirthRadio->UseVisualStyleBackColor = true;
			// 
			// lastNameRadio
			// 
			this->lastNameRadio->AutoSize = true;
			this->lastNameRadio->Location = System::Drawing::Point(249, 81);
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
			this->firstNameRadio->Location = System::Drawing::Point(13, 81);
			this->firstNameRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->firstNameRadio->Name = L"firstNameRadio";
			this->firstNameRadio->Size = System::Drawing::Size(149, 30);
			this->firstNameRadio->TabIndex = 3;
			this->firstNameRadio->TabStop = true;
			this->firstNameRadio->Text = L"First Name";
			this->firstNameRadio->UseVisualStyleBackColor = true;
			// 
			// expiryRadio
			// 
			this->expiryRadio->AutoSize = true;
			this->expiryRadio->Location = System::Drawing::Point(11, 129);
			this->expiryRadio->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->expiryRadio->Name = L"expiryRadio";
			this->expiryRadio->Size = System::Drawing::Size(218, 30);
			this->expiryRadio->TabIndex = 2;
			this->expiryRadio->TabStop = true;
			this->expiryRadio->Text = L"Card Expiry Date";
			this->expiryRadio->UseVisualStyleBackColor = true;
			// 
			// searchBox
			// 
			this->searchBox->Location = System::Drawing::Point(26, 87);
			this->searchBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(530, 33);
			this->searchBox->TabIndex = 3;
			// 
			// searchButton
			// 
			this->searchButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->searchButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->searchButton->ForeColor = System::Drawing::Color::Cyan;
			this->searchButton->Location = System::Drawing::Point(366, 419);
			this->searchButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(164, 58);
			this->searchButton->TabIndex = 4;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &SearchCustomer::searchButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->ForeColor = System::Drawing::Color::Cyan;
			this->exitButton->Location = System::Drawing::Point(366, 483);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(164, 58);
			this->exitButton->TabIndex = 5;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &SearchCustomer::exitButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(394, 383);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 26);
			this->label1->TabIndex = 6;
			this->label1->Text = L"No result";
			this->label1->Visible = false;
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
			this->dataGridView1->Location = System::Drawing::Point(570, 23);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(959, 518);
			this->dataGridView1->TabIndex = 8;
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
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(26, 383);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(244, 118);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label2->Location = System::Drawing::Point(20, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(263, 32);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Search Customers";
			// 
			// SearchCustomer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(1545, 556);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->searchBox);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"SearchCustomer";
			this->Text = L"Search Customer";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Close();
	}
private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ query = searchBox->Text;
	int test = query->IsNullOrWhiteSpace(searchBox->Text);
	if ( test == 1)
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

	String^ x = searchBox->Text->ToString();
	std::string boxInput = msclr::interop::marshal_as<std::string>(x);
	char * targetedQuery;
	if (this->accountRadio->Checked == true)
		targetedQuery = "account_number";
	else if (this->cardVerificationRadio->Checked == true)
		targetedQuery = "card_ver_code";
	else if (this->expiryRadio->Checked == true)
		targetedQuery = "expiry_date";
	else if (this->firstNameRadio->Checked == true)
		targetedQuery = "first_name";
	else if (this->lastNameRadio->Checked == true)
		targetedQuery = "last_name";
	else if (this->dateOfBirthRadio->Checked == true)
		targetedQuery = "date_of_birth";
	else if (this->addressRadio->Checked == true)
		targetedQuery = "address";
	else {
		MessageBox::Show("Must pick any of the radio box as a criteria to search.");
		return;
	}
		


	node * results = queue.findRelevantInformation(boxInput.c_str(), targetedQuery);
	node * curr;
	for (curr = results; curr; curr = curr->link) {
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
	rc = sqlite3_finalize(stmt);
	queue.~linkedQueueType();
	sqlite3_close(db);
}
};
}
