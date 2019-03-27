#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "transactionRecord.h"
#include "linkedStack.h"
#include "sqlite3.h"
#include <string>

using namespace std;
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for ModifyTransaction
	/// </summary>
	public ref class ModifyTransaction : public System::Windows::Forms::Form
	{
	public:
		ModifyTransaction(void)
		{
			InitializeComponent();
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
			rc = sqlite3_prepare_v2(db, "SELECT account_number, first_name, last_name FROM customerList", -1, &stmt, NULL);
			if (rc != SQLITE_OK) {
				fprintf(stderr, "%s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
				return;
			}
			rc = sqlite3_step(stmt);
			while (rc != SQLITE_DONE && rc != SQLITE_OK)
			{
				unsigned char * accountNumber = new unsigned char[255];
				unsigned char * firstName = new unsigned char[255];
				unsigned char * lastName = new unsigned char[255];
				const unsigned char * valChar = sqlite3_column_text(stmt, 0);
				accountNumber = const_cast<unsigned char *>(valChar);
				valChar = sqlite3_column_text(stmt, 1);
				firstName = const_cast<unsigned char *>(valChar);
				valChar = sqlite3_column_text(stmt, 2);
				lastName = const_cast<unsigned char *>(valChar);
				char * resultConvert = (char *)accountNumber;
				String^ resultAccount = gcnew String(resultConvert);
				resultConvert = (char *)firstName;
				String^ resultFirst = gcnew String(resultConvert);
				resultConvert = (char *)lastName;
				String^ resultLast = gcnew String(resultConvert);
				String^ result = resultAccount + " (" + resultFirst + " " + resultLast + ")";
				this->accountRecepientBox->Items->Add(result);
				this->accountBox->Items->Add(result);
				rc = sqlite3_step(stmt);
			}
			rc = sqlite3_finalize(stmt);
			sqlite3_close(db);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModifyTransaction()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  amountLabel;
	private: System::Windows::Forms::Label^  recepientAccountNumberLabel;
	private: System::Windows::Forms::Label^  accountNumberLabel;
	private: System::Windows::Forms::Label^  dateLabel;
	private: System::Windows::Forms::Label^  yearOfTransacationLabel;
	private: System::Windows::Forms::Label^  monthOfTransacationLabel;
	private: System::Windows::Forms::Label^  dateOfTransacationLabel;
	private: System::Windows::Forms::Label^  typeOfTransactionLabel;
	private: System::Windows::Forms::ComboBox^  yearOfTransaction;
	private: System::Windows::Forms::ComboBox^  monthOfTransaction;
	private: System::Windows::Forms::ComboBox^  dateOfTransaction;
	private: System::Windows::Forms::ComboBox^  typeOfTransactionBox;

	private: System::Windows::Forms::ComboBox^  accountBox;
	private: System::Windows::Forms::ComboBox^  accountRecepientBox;
	private: System::Windows::Forms::Button^  resetButton;
	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  modifyButton;
	private: System::Windows::Forms::TextBox^  amountBox;
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
			this->amountLabel = (gcnew System::Windows::Forms::Label());
			this->amountBox = (gcnew System::Windows::Forms::TextBox());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->yearOfTransacationLabel = (gcnew System::Windows::Forms::Label());
			this->monthOfTransacationLabel = (gcnew System::Windows::Forms::Label());
			this->dateOfTransacationLabel = (gcnew System::Windows::Forms::Label());
			this->yearOfTransaction = (gcnew System::Windows::Forms::ComboBox());
			this->monthOfTransaction = (gcnew System::Windows::Forms::ComboBox());
			this->dateOfTransaction = (gcnew System::Windows::Forms::ComboBox());
			this->typeOfTransactionLabel = (gcnew System::Windows::Forms::Label());
			this->typeOfTransactionBox = (gcnew System::Windows::Forms::ComboBox());
			this->accountBox = (gcnew System::Windows::Forms::ComboBox());
			this->accountNumberLabel = (gcnew System::Windows::Forms::Label());
			this->accountRecepientBox = (gcnew System::Windows::Forms::ComboBox());
			this->recepientAccountNumberLabel = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->modifyButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// amountLabel
			// 
			this->amountLabel->AutoSize = true;
			this->amountLabel->Location = System::Drawing::Point(16, 334);
			this->amountLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->amountLabel->Name = L"amountLabel";
			this->amountLabel->Size = System::Drawing::Size(98, 26);
			this->amountLabel->TabIndex = 7;
			this->amountLabel->Text = L"Amount";
			this->amountLabel->Visible = false;
			// 
			// amountBox
			// 
			this->amountBox->Location = System::Drawing::Point(299, 331);
			this->amountBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->amountBox->Name = L"amountBox";
			this->amountBox->Size = System::Drawing::Size(386, 33);
			this->amountBox->TabIndex = 6;
			this->amountBox->Visible = false;
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Location = System::Drawing::Point(16, 191);
			this->dateLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(213, 26);
			this->dateLabel->TabIndex = 41;
			this->dateLabel->Text = L"Date of Transction";
			// 
			// yearOfTransacationLabel
			// 
			this->yearOfTransacationLabel->AutoSize = true;
			this->yearOfTransacationLabel->Location = System::Drawing::Point(744, 191);
			this->yearOfTransacationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->yearOfTransacationLabel->Name = L"yearOfTransacationLabel";
			this->yearOfTransacationLabel->Size = System::Drawing::Size(60, 26);
			this->yearOfTransacationLabel->TabIndex = 40;
			this->yearOfTransacationLabel->Text = L"Year";
			// 
			// monthOfTransacationLabel
			// 
			this->monthOfTransacationLabel->AutoSize = true;
			this->monthOfTransacationLabel->Location = System::Drawing::Point(516, 191);
			this->monthOfTransacationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->monthOfTransacationLabel->Name = L"monthOfTransacationLabel";
			this->monthOfTransacationLabel->Size = System::Drawing::Size(81, 26);
			this->monthOfTransacationLabel->TabIndex = 39;
			this->monthOfTransacationLabel->Text = L"Month";
			// 
			// dateOfTransacationLabel
			// 
			this->dateOfTransacationLabel->AutoSize = true;
			this->dateOfTransacationLabel->Location = System::Drawing::Point(294, 191);
			this->dateOfTransacationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->dateOfTransacationLabel->Name = L"dateOfTransacationLabel";
			this->dateOfTransacationLabel->Size = System::Drawing::Size(64, 26);
			this->dateOfTransacationLabel->TabIndex = 38;
			this->dateOfTransacationLabel->Text = L"Date";
			// 
			// yearOfTransaction
			// 
			this->yearOfTransaction->FormattingEnabled = true;
			this->yearOfTransaction->Items->AddRange(gcnew cli::array< System::Object^  >(118) {
				L"2017", L"2016", L"2015", L"2014", L"2013",
					L"2012", L"2011", L"2010", L"2009", L"2008", L"2007", L"2006", L"2005", L"2004", L"2003", L"2002", L"2001", L"2000", L"1999",
					L"1998", L"1997", L"1996", L"1995", L"1994", L"1993", L"1992", L"1991", L"1990", L"1989", L"1988", L"1987", L"1986", L"1985",
					L"1984", L"1983", L"1982", L"1981", L"1980", L"1979", L"1978", L"1977", L"1976", L"1975", L"1974", L"1973", L"1972", L"1971",
					L"1970", L"1969", L"1968", L"1967", L"1966", L"1965", L"1964", L"1963", L"1962", L"1961", L"1960", L"1959", L"1958", L"1957",
					L"1956", L"1955", L"1954", L"1953", L"1952", L"1951", L"1950", L"1949", L"1948", L"1947", L"1946", L"1945", L"1944", L"1943",
					L"1942", L"1941", L"1940", L"1939", L"1938", L"1937", L"1936", L"1935", L"1934", L"1933", L"1932", L"1931", L"1930", L"1929",
					L"1928", L"1927", L"1926", L"1925", L"1924", L"1923", L"1922", L"1921", L"1920", L"1919", L"1918", L"1917", L"1916", L"1915",
					L"1914", L"1913", L"1912", L"1911", L"1910", L"1909", L"1908", L"1907", L"1906", L"1905", L"1904", L"1903", L"1902", L"1901",
					L"1900"
			});
			this->yearOfTransaction->Location = System::Drawing::Point(818, 188);
			this->yearOfTransaction->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->yearOfTransaction->Name = L"yearOfTransaction";
			this->yearOfTransaction->Size = System::Drawing::Size(125, 33);
			this->yearOfTransaction->TabIndex = 37;
			// 
			// monthOfTransaction
			// 
			this->monthOfTransaction->DropDownWidth = 60;
			this->monthOfTransaction->FormattingEnabled = true;
			this->monthOfTransaction->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06",
					L"07", L"08", L"09", L"10", L"11", L"12"
			});
			this->monthOfTransaction->Location = System::Drawing::Point(611, 188);
			this->monthOfTransaction->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->monthOfTransaction->Name = L"monthOfTransaction";
			this->monthOfTransaction->Size = System::Drawing::Size(119, 33);
			this->monthOfTransaction->TabIndex = 36;
			// 
			// dateOfTransaction
			// 
			this->dateOfTransaction->DropDownWidth = 60;
			this->dateOfTransaction->FormattingEnabled = true;
			this->dateOfTransaction->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"01", L"02", L"03", L"04", L"05", L"06",
					L"07", L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24",
					L"25", L"26", L"27", L"28", L"29", L"30", L"31"
			});
			this->dateOfTransaction->Location = System::Drawing::Point(381, 188);
			this->dateOfTransaction->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dateOfTransaction->Name = L"dateOfTransaction";
			this->dateOfTransaction->Size = System::Drawing::Size(121, 33);
			this->dateOfTransaction->TabIndex = 35;
			// 
			// typeOfTransactionLabel
			// 
			this->typeOfTransactionLabel->AutoSize = true;
			this->typeOfTransactionLabel->Location = System::Drawing::Point(16, 80);
			this->typeOfTransactionLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->typeOfTransactionLabel->Name = L"typeOfTransactionLabel";
			this->typeOfTransactionLabel->Size = System::Drawing::Size(226, 26);
			this->typeOfTransactionLabel->TabIndex = 7;
			this->typeOfTransactionLabel->Text = L"Type of Transaction";
			// 
			// typeOfTransactionBox
			// 
			this->typeOfTransactionBox->FormattingEnabled = true;
			this->typeOfTransactionBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"DEPOSIT", L"TRANSFER", L"WITHDRAWAL" });
			this->typeOfTransactionBox->Location = System::Drawing::Point(381, 80);
			this->typeOfTransactionBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->typeOfTransactionBox->Name = L"typeOfTransactionBox";
			this->typeOfTransactionBox->Size = System::Drawing::Size(393, 33);
			this->typeOfTransactionBox->TabIndex = 6;
			this->typeOfTransactionBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ModifyTransaction::comboBox1_SelectedIndexChanged);
			// 
			// accountBox
			// 
			this->accountBox->FormattingEnabled = true;
			this->accountBox->Location = System::Drawing::Point(381, 28);
			this->accountBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountBox->Name = L"accountBox";
			this->accountBox->Size = System::Drawing::Size(393, 33);
			this->accountBox->TabIndex = 43;
			// 
			// accountNumberLabel
			// 
			this->accountNumberLabel->AutoSize = true;
			this->accountNumberLabel->Location = System::Drawing::Point(16, 31);
			this->accountNumberLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->accountNumberLabel->Name = L"accountNumberLabel";
			this->accountNumberLabel->Size = System::Drawing::Size(194, 26);
			this->accountNumberLabel->TabIndex = 42;
			this->accountNumberLabel->Text = L"Account Number";
			// 
			// accountRecepientBox
			// 
			this->accountRecepientBox->FormattingEnabled = true;
			this->accountRecepientBox->Location = System::Drawing::Point(381, 133);
			this->accountRecepientBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountRecepientBox->Name = L"accountRecepientBox";
			this->accountRecepientBox->Size = System::Drawing::Size(393, 33);
			this->accountRecepientBox->TabIndex = 45;
			this->accountRecepientBox->Visible = false;
			// 
			// recepientAccountNumberLabel
			// 
			this->recepientAccountNumberLabel->AutoSize = true;
			this->recepientAccountNumberLabel->Location = System::Drawing::Point(16, 133);
			this->recepientAccountNumberLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->recepientAccountNumberLabel->Name = L"recepientAccountNumberLabel";
			this->recepientAccountNumberLabel->Size = System::Drawing::Size(309, 26);
			this->recepientAccountNumberLabel->TabIndex = 44;
			this->recepientAccountNumberLabel->Text = L"Recepient Account Number";
			this->recepientAccountNumberLabel->Visible = false;
			// 
			// resetButton
			// 
			this->resetButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->resetButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->resetButton->ForeColor = System::Drawing::Color::Cyan;
			this->resetButton->Location = System::Drawing::Point(299, 253);
			this->resetButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(164, 58);
			this->resetButton->TabIndex = 47;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = false;
			this->resetButton->Click += gcnew System::EventHandler(this, &ModifyTransaction::button2_Click);
			// 
			// searchButton
			// 
			this->searchButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->searchButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searchButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->searchButton->ForeColor = System::Drawing::Color::Cyan;
			this->searchButton->Location = System::Drawing::Point(521, 253);
			this->searchButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(164, 58);
			this->searchButton->TabIndex = 46;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = false;
			this->searchButton->Click += gcnew System::EventHandler(this, &ModifyTransaction::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->Location = System::Drawing::Point(299, 380);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(164, 58);
			this->exitButton->TabIndex = 48;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &ModifyTransaction::button3_Click);
			// 
			// modifyButton
			// 
			this->modifyButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->modifyButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->modifyButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->modifyButton->Location = System::Drawing::Point(521, 380);
			this->modifyButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->modifyButton->Name = L"modifyButton";
			this->modifyButton->Size = System::Drawing::Size(164, 58);
			this->modifyButton->TabIndex = 49;
			this->modifyButton->Text = L"Modify";
			this->modifyButton->UseVisualStyleBackColor = false;
			this->modifyButton->Visible = false;
			this->modifyButton->Click += gcnew System::EventHandler(this, &ModifyTransaction::button4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(710, 256);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 50;
			this->pictureBox1->TabStop = false;
			// 
			// ModifyTransaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->modifyButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->accountRecepientBox);
			this->Controls->Add(this->recepientAccountNumberLabel);
			this->Controls->Add(this->accountBox);
			this->Controls->Add(this->accountNumberLabel);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->yearOfTransacationLabel);
			this->Controls->Add(this->monthOfTransacationLabel);
			this->Controls->Add(this->dateOfTransacationLabel);
			this->Controls->Add(this->yearOfTransaction);
			this->Controls->Add(this->monthOfTransaction);
			this->Controls->Add(this->dateOfTransaction);
			this->Controls->Add(this->amountLabel);
			this->Controls->Add(this->amountBox);
			this->Controls->Add(this->typeOfTransactionLabel);
			this->Controls->Add(this->typeOfTransactionBox);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"ModifyTransaction";
			this->Text = L"ModifyTransaction";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Close();
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	String^ selectedItem = this->typeOfTransactionBox->SelectedItem->ToString();
	std::string convertedItem = msclr::interop::marshal_as<std::string>(selectedItem);
	if (convertedItem.compare("TRANSFER") == 0) {
		this->recepientAccountNumberLabel->Visible = true;
		this->accountRecepientBox->Visible = true;
	}
	else
	{
		this->recepientAccountNumberLabel->Visible = false;
		this->accountRecepientBox->Visible = false;
	}

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ queryRetrieved = accountBox->Text->ToString();
	std::string account = msclr::interop::marshal_as<std::string>(queryRetrieved);
	account = account.substr(0, 19);
	queryRetrieved = typeOfTransactionBox->SelectedItem->ToString();

	std::string dateTransaction, monthTransaction, yearTransaction;
	queryRetrieved = this->dateOfTransaction->SelectedItem->ToString();
	dateTransaction = msclr::interop::marshal_as<std::string>(queryRetrieved);
	queryRetrieved = this->monthOfTransaction->SelectedItem->ToString();
	monthTransaction = msclr::interop::marshal_as<std::string>(queryRetrieved);
	queryRetrieved = this->yearOfTransaction->SelectedItem->ToString();
	yearTransaction = msclr::interop::marshal_as<std::string>(queryRetrieved);
	std::string transactionDate = dateTransaction + "/" + monthTransaction + "/" + yearTransaction;

	queryRetrieved = this->typeOfTransactionBox->SelectedItem->ToString();
	std::string convertedItem = msclr::interop::marshal_as<std::string>(queryRetrieved);
	bool isTransfer = false;
	std::string recepient;
	if (convertedItem.compare("TRANSFER") == 0) {
		queryRetrieved = accountRecepientBox->Text->ToString();
		recepient = msclr::interop::marshal_as<std::string>(queryRetrieved);
		recepient = recepient.substr(0, 19);
		isTransfer = true;
	}
	//SELECT amount FROM transactionList WHERE account_number = ' account ', type_of_transaction = 'convertedItem', date_of_transaction = 'transactionDate', target_account = ' recepient ' 
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *stmt = NULL;
	string statement;
	if (convertedItem.compare("TRANSFER") == 0) {
		statement = "SELECT amount FROM transactionList WHERE account_number = '" + account + "' AND type_of_transaction = '" + convertedItem + "' AND date_of_transaction = '" + transactionDate + "' AND target_account = '" + recepient + "'";
	}
	else
		statement = "SELECT amount FROM transactionList WHERE account_number = '" + account + "' AND type_of_transaction = '" + convertedItem + "' AND date_of_transaction = '" + transactionDate + "'";
	rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	float amount = float(sqlite3_column_double(stmt, 0));
	String^ step3 = amount.ToString();
	if (amount > 0) {
		this->amountBox->Text = step3;
		this->amountBox->Visible = true;
		this->amountLabel->Visible = true;
		this->modifyButton->Visible = true;
		this->typeOfTransactionBox->Enabled = false;
		this->accountRecepientBox->Enabled = false;
		this->accountBox->Enabled = false;
		this->typeOfTransactionBox->Enabled = false;
		this->dateOfTransaction->Enabled = false;
		this->monthOfTransaction->Enabled = false;
		this->yearOfTransaction->Enabled = false;
	}
	else
	{
		MessageBox::Show("No information found");
	}
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);


}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ queryRetrieved = accountBox->Text->ToString();
	std::string account = msclr::interop::marshal_as<std::string>(queryRetrieved);
	account = account.substr(0, 19);
	queryRetrieved = typeOfTransactionBox->SelectedItem->ToString();

	std::string dateTransaction, monthTransaction, yearTransaction;
	queryRetrieved = this->dateOfTransaction->SelectedItem->ToString();
	dateTransaction = msclr::interop::marshal_as<std::string>(queryRetrieved);
	queryRetrieved = this->monthOfTransaction->SelectedItem->ToString();
	monthTransaction = msclr::interop::marshal_as<std::string>(queryRetrieved);
	queryRetrieved = this->yearOfTransaction->SelectedItem->ToString();
	yearTransaction = msclr::interop::marshal_as<std::string>(queryRetrieved);
	std::string transactionDate = dateTransaction + "/" + monthTransaction + "/" + yearTransaction;

	queryRetrieved = this->amountBox->Text->ToString();
	std::string newAmount = msclr::interop::marshal_as<std::string>(queryRetrieved);

	queryRetrieved = this->typeOfTransactionBox->SelectedItem->ToString();
	std::string convertedItem = msclr::interop::marshal_as<std::string>(queryRetrieved);
	bool isTransfer = false;
	std::string recepient = "N/A";
	if (convertedItem.compare("TRANSFER") == 0) {
		queryRetrieved = accountRecepientBox->Text->ToString();
		recepient = msclr::interop::marshal_as<std::string>(queryRetrieved);
		recepient = recepient.substr(0, 19);
		isTransfer = true;
	}
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	//if (rc) {
	//	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	//	sqlite3_close(db);
	//}
	sqlite3_stmt *stmt = NULL;
	rc = sqlite3_prepare_v2(db, "SELECT * FROM transactionList", -1, &stmt, NULL);
	linkedStack stack;
	int rowCount = 0;
	int colCount = sqlite3_column_count(stmt);
	rc = sqlite3_step(stmt);
	float amountDifference = 0;
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		int colCount = sqlite3_column_count(stmt);
		unsigned char * accountNumber = new unsigned char[1500];
		unsigned char * typeOfTransaction = new unsigned char[1500];
		unsigned char * targetAccount = new unsigned char[1500];
		unsigned char * dateOfTransaction = new unsigned char[1500];
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
		if (strcmp((char*)accountNumber, account.c_str()) == 0 &&
			strcmp((char*)typeOfTransaction, convertedItem.c_str()) == 0 &&
			strcmp((char*)targetAccount, recepient.c_str()) == 0 &&
			strcmp((char*)dateOfTransaction, transactionDate.c_str()) == 0
			)
			amountDifference = float(atof(newAmount.c_str())) - amount;

		transactionRecord newTransaction((char*)accountNumber, (char*)typeOfTransaction, amount, (char *)targetAccount, (char *)dateOfTransaction);
		stack.push(newTransaction);
		rc = sqlite3_step(stmt);
		rowCount++;
	}
	rc = sqlite3_finalize(stmt);
	rc = sqlite3_close(db);
	rc = sqlite3_open("main.db", &db);

	transactionRecord modifiedTransaction(account.c_str(), convertedItem.c_str(), float(atof(newAmount.c_str())), recepient.c_str(), transactionDate.c_str());

	stack.modifyInformation(modifiedTransaction);

	//Update the changed amount to the system
	if(convertedItem.compare("DEPOSIT") == 0)
	addAccount(amountDifference, account);

	if (convertedItem.compare("WITHDRAWAL") == 0)
		deductBalance(amountDifference, account);

	if (convertedItem.compare("TRANSFER") == 0) {
		deductBalance(amountDifference, account);
		addAccount(amountDifference, recepient);
	}

	rc = sqlite3_prepare_v2(db, "PRAGMA foreign_keys = OFF;", -1, &stmt, NULL);
	//if (rc != SQLITE_OK) {
	//	fprintf(stderr, "%s\n", sqlite3_errmsg(db));
	//	sqlite3_close(db);
	//}
	rc = sqlite3_step(stmt);
	rc = sqlite3_reset(stmt);

	rc = sqlite3_prepare_v2(db, "DROP TABLE transactionList;", -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	rc = sqlite3_reset(stmt);

	//create the same table
	rc = sqlite3_prepare_v2(db, "CREATE TABLE transactionList (account_number VARCHAR[16], type_of_transaction VARCHAR[10] NOT NULL, amount FLOAT NOT NULL, target_account VARCHAR[16], date_of_transaction VARCHAR[9] NOT NULL,FOREIGN KEY (account_number) REFERENCES customerList(account_number)); ", -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_OK) {
		fprintf(stderr, " %s\n", sqlite3_errmsg(db));
	}
	rc = sqlite3_reset(stmt);

	nodeStack * curr;
	transactionRecord recorded[100];
	int putIntoRecord = 0;
	for (curr = stack.getStack(); curr != NULL; curr = curr->link) {
		char accountNumber[255], typeOfTransaction[255], targetCard[255], dateOftransction[255];
		float amount = curr->info.getAmount();
		curr->info.getAccountNumber(accountNumber);
		curr->info.getTypeOfTransaction(typeOfTransaction);
		curr->info.getTargetCard(targetCard);
		curr->info.getDateOfTransaction(dateOftransction);
		cout << "=============================" << endl;
		recorded[putIntoRecord] = curr->info;
		char testResult[255];
		recorded[putIntoRecord].getAccountNumber(testResult);
		cout << "Test accountNumber : " << testResult << endl;
		cout << "=============================" << endl;
		putIntoRecord++;
	}
	putIntoRecord--;
	cout << "RECORDED INFORMATION " << endl;
	for (; putIntoRecord >= 0; putIntoRecord--)
	{
		char accountNumber[255], typeOfTransaction[255], targetCard[255], dateOftransction[255];
		float amount = recorded[putIntoRecord].getAmount();
		recorded[putIntoRecord].getAccountNumber(accountNumber);
		recorded[putIntoRecord].getTypeOfTransaction(typeOfTransaction);
		recorded[putIntoRecord].getTargetCard(targetCard);
		recorded[putIntoRecord].getDateOfTransaction(dateOftransction);
		cout << "Account number: " << accountNumber << endl
			<< "Type of transaction: " << typeOfTransaction << endl
			<< "Amount: " << amount << endl;
		if (strcmp(typeOfTransaction, "TRANSFER") == 0)
			cout << "Targeted card: " << targetCard << endl;
		cout << "Date of transcation: " << dateOftransction << endl;
		cout << "=============================" << endl;

		System::String^ convertToString = amount.ToString();
		string amountInString = msclr::interop::marshal_as<std::string>(convertToString);

		string statement = "INSERT INTO transactionList VALUES('" + string(accountNumber) + "','" + string(typeOfTransaction) + "'," + amountInString + ",'" + string(targetCard) + "', '" + string(dateOftransction) + "');";
		rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, NULL);
		rc = sqlite3_step(stmt);
		rc = sqlite3_reset(stmt);
	}

	stack.~linkedStack();
	rc = sqlite3_close(db);
	
	MessageBox::Show("Transaction has been modified");
	Hide();
	Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	float amount = 0;
	String^ step3 = amount.ToString();
	this->amountBox->Text = step3;
	this->amountBox->Visible = false;
	this->amountLabel->Visible = false;
	this->modifyButton->Visible = false;
	this->yearOfTransaction->SelectedItem = "";
	this->monthOfTransaction->SelectedItem = "";
	this->dateOfTransaction->SelectedItem = "";
	this->typeOfTransactionBox->Enabled = true;
	this->accountRecepientBox->Enabled = true;
	this->accountBox->Enabled = true;
	this->typeOfTransactionBox->Enabled = true;
	this->dateOfTransaction->Enabled = true;
	this->monthOfTransaction->Enabled = true;
	this->yearOfTransaction->Enabled = true;

}
};
}
