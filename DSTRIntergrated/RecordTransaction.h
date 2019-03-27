#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "transactionRecord.h"
#include "linkedStack.h"
#include "sqlite3.h"
#include <string>
using namespace std;
namespace Project2 {
	bool checkAndDeductBalance(float amount, string accountNumber);
	void addAccount(float amount, string recepientNumber);
	void push(const char * newAccount, const char * newTypeOfTranscation, float newAmount, const char * newTargetCard, const char * newDateOfTransacation);
	void deductBalance(float amount, string accountNumber);
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RecordTransaction
	/// </summary>
	public ref class RecordTransaction : public System::Windows::Forms::Form
	{
	public:
		RecordTransaction(void)
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
		~RecordTransaction()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::Button^  recordButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::TextBox^  amountBox;
	private: System::Windows::Forms::Label^  accountNumberLabel;
	private: System::Windows::Forms::Label^  amountLabel;
	private: System::Windows::Forms::Label^  typeOfTransactionLabel;
	private: System::Windows::Forms::Label^  dateLabel;
	private: System::Windows::Forms::Label^  yearOfTransacationLabel;
	private: System::Windows::Forms::Label^  monthOfTransacationLabel;
	private: System::Windows::Forms::Label^  dateOfTransacationLabel;
	private: System::Windows::Forms::Label^  recepientAccountNumberLabel;
	private: System::Windows::Forms::ComboBox^  yearOfTransaction;
	private: System::Windows::Forms::ComboBox^  monthOfTransaction;
	private: System::Windows::Forms::ComboBox^  dateOfTransaction;
	private: System::Windows::Forms::ComboBox^  accountBox;
	private: System::Windows::Forms::ComboBox^  typeOfTransactionBox;

	private: System::Windows::Forms::ComboBox^  accountRecepientBox;
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
			this->recordButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->accountNumberLabel = (gcnew System::Windows::Forms::Label());
			this->amountBox = (gcnew System::Windows::Forms::TextBox());
			this->amountLabel = (gcnew System::Windows::Forms::Label());
			this->yearOfTransacationLabel = (gcnew System::Windows::Forms::Label());
			this->monthOfTransacationLabel = (gcnew System::Windows::Forms::Label());
			this->dateOfTransacationLabel = (gcnew System::Windows::Forms::Label());
			this->yearOfTransaction = (gcnew System::Windows::Forms::ComboBox());
			this->monthOfTransaction = (gcnew System::Windows::Forms::ComboBox());
			this->dateOfTransaction = (gcnew System::Windows::Forms::ComboBox());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->accountBox = (gcnew System::Windows::Forms::ComboBox());
			this->typeOfTransactionBox = (gcnew System::Windows::Forms::ComboBox());
			this->typeOfTransactionLabel = (gcnew System::Windows::Forms::Label());
			this->accountRecepientBox = (gcnew System::Windows::Forms::ComboBox());
			this->recepientAccountNumberLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// recordButton
			// 
			this->recordButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->recordButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recordButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->recordButton->Location = System::Drawing::Point(446, 282);
			this->recordButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->recordButton->Name = L"recordButton";
			this->recordButton->Size = System::Drawing::Size(164, 58);
			this->recordButton->TabIndex = 0;
			this->recordButton->Text = L"Record";
			this->recordButton->UseVisualStyleBackColor = false;
			this->recordButton->Click += gcnew System::EventHandler(this, &RecordTransaction::button1_Click);
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->Location = System::Drawing::Point(230, 282);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(164, 58);
			this->exitButton->TabIndex = 1;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &RecordTransaction::button2_Click);
			// 
			// accountNumberLabel
			// 
			this->accountNumberLabel->AutoSize = true;
			this->accountNumberLabel->Location = System::Drawing::Point(16, 25);
			this->accountNumberLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->accountNumberLabel->Name = L"accountNumberLabel";
			this->accountNumberLabel->Size = System::Drawing::Size(194, 26);
			this->accountNumberLabel->TabIndex = 2;
			this->accountNumberLabel->Text = L"Account Number";
			// 
			// amountBox
			// 
			this->amountBox->Location = System::Drawing::Point(381, 76);
			this->amountBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->amountBox->Name = L"amountBox";
			this->amountBox->Size = System::Drawing::Size(571, 33);
			this->amountBox->TabIndex = 4;
			// 
			// amountLabel
			// 
			this->amountLabel->AutoSize = true;
			this->amountLabel->Location = System::Drawing::Point(16, 76);
			this->amountLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->amountLabel->Name = L"amountLabel";
			this->amountLabel->Size = System::Drawing::Size(98, 26);
			this->amountLabel->TabIndex = 5;
			this->amountLabel->Text = L"Amount";
			// 
			// yearOfTransacationLabel
			// 
			this->yearOfTransacationLabel->AutoSize = true;
			this->yearOfTransacationLabel->Location = System::Drawing::Point(757, 125);
			this->yearOfTransacationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->yearOfTransacationLabel->Name = L"yearOfTransacationLabel";
			this->yearOfTransacationLabel->Size = System::Drawing::Size(60, 26);
			this->yearOfTransacationLabel->TabIndex = 33;
			this->yearOfTransacationLabel->Text = L"Year";
			// 
			// monthOfTransacationLabel
			// 
			this->monthOfTransacationLabel->AutoSize = true;
			this->monthOfTransacationLabel->Location = System::Drawing::Point(529, 126);
			this->monthOfTransacationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->monthOfTransacationLabel->Name = L"monthOfTransacationLabel";
			this->monthOfTransacationLabel->Size = System::Drawing::Size(81, 26);
			this->monthOfTransacationLabel->TabIndex = 32;
			this->monthOfTransacationLabel->Text = L"Month";
			// 
			// dateOfTransacationLabel
			// 
			this->dateOfTransacationLabel->AutoSize = true;
			this->dateOfTransacationLabel->Location = System::Drawing::Point(308, 126);
			this->dateOfTransacationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->dateOfTransacationLabel->Name = L"dateOfTransacationLabel";
			this->dateOfTransacationLabel->Size = System::Drawing::Size(64, 26);
			this->dateOfTransacationLabel->TabIndex = 31;
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
			this->yearOfTransaction->Location = System::Drawing::Point(828, 123);
			this->yearOfTransaction->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->yearOfTransaction->Name = L"yearOfTransaction";
			this->yearOfTransaction->Size = System::Drawing::Size(125, 33);
			this->yearOfTransaction->TabIndex = 30;
			// 
			// monthOfTransaction
			// 
			this->monthOfTransaction->DropDownWidth = 60;
			this->monthOfTransaction->FormattingEnabled = true;
			this->monthOfTransaction->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06",
					L"07", L"08", L"09", L"10", L"11", L"12"
			});
			this->monthOfTransaction->Location = System::Drawing::Point(624, 122);
			this->monthOfTransaction->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->monthOfTransaction->Name = L"monthOfTransaction";
			this->monthOfTransaction->Size = System::Drawing::Size(119, 33);
			this->monthOfTransaction->TabIndex = 29;
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
			this->dateOfTransaction->Location = System::Drawing::Point(381, 122);
			this->dateOfTransaction->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dateOfTransaction->Name = L"dateOfTransaction";
			this->dateOfTransaction->Size = System::Drawing::Size(121, 33);
			this->dateOfTransaction->TabIndex = 28;
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Location = System::Drawing::Point(16, 126);
			this->dateLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(213, 26);
			this->dateLabel->TabIndex = 34;
			this->dateLabel->Text = L"Date of Transction";
			// 
			// accountBox
			// 
			this->accountBox->FormattingEnabled = true;
			this->accountBox->Location = System::Drawing::Point(381, 22);
			this->accountBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountBox->Name = L"accountBox";
			this->accountBox->Size = System::Drawing::Size(571, 33);
			this->accountBox->TabIndex = 35;
			// 
			// typeOfTransactionBox
			// 
			this->typeOfTransactionBox->FormattingEnabled = true;
			this->typeOfTransactionBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"DEPOSIT", L"TRANSFER", L"WITHDRAWAL" });
			this->typeOfTransactionBox->Location = System::Drawing::Point(381, 168);
			this->typeOfTransactionBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->typeOfTransactionBox->Name = L"typeOfTransactionBox";
			this->typeOfTransactionBox->Size = System::Drawing::Size(258, 33);
			this->typeOfTransactionBox->TabIndex = 6;
			this->typeOfTransactionBox->SelectedIndexChanged += gcnew System::EventHandler(this, &RecordTransaction::comboBox1_SelectedIndexChanged);
			// 
			// typeOfTransactionLabel
			// 
			this->typeOfTransactionLabel->AutoSize = true;
			this->typeOfTransactionLabel->Location = System::Drawing::Point(16, 167);
			this->typeOfTransactionLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->typeOfTransactionLabel->Name = L"typeOfTransactionLabel";
			this->typeOfTransactionLabel->Size = System::Drawing::Size(226, 26);
			this->typeOfTransactionLabel->TabIndex = 7;
			this->typeOfTransactionLabel->Text = L"Type of Transaction";
			// 
			// accountRecepientBox
			// 
			this->accountRecepientBox->FormattingEnabled = true;
			this->accountRecepientBox->Location = System::Drawing::Point(381, 213);
			this->accountRecepientBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountRecepientBox->Name = L"accountRecepientBox";
			this->accountRecepientBox->Size = System::Drawing::Size(572, 33);
			this->accountRecepientBox->TabIndex = 36;
			this->accountRecepientBox->Visible = false;
			// 
			// recepientAccountNumberLabel
			// 
			this->recepientAccountNumberLabel->AutoSize = true;
			this->recepientAccountNumberLabel->Location = System::Drawing::Point(16, 213);
			this->recepientAccountNumberLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->recepientAccountNumberLabel->Name = L"recepientAccountNumberLabel";
			this->recepientAccountNumberLabel->Size = System::Drawing::Size(309, 26);
			this->recepientAccountNumberLabel->TabIndex = 9;
			this->recepientAccountNumberLabel->Text = L"Recepient Account Number";
			this->recepientAccountNumberLabel->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(696, 268);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 37;
			this->pictureBox1->TabStop = false;
			// 
			// RecordTransaction
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->accountRecepientBox);
			this->Controls->Add(this->accountBox);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->yearOfTransacationLabel);
			this->Controls->Add(this->monthOfTransacationLabel);
			this->Controls->Add(this->dateOfTransacationLabel);
			this->Controls->Add(this->yearOfTransaction);
			this->Controls->Add(this->monthOfTransaction);
			this->Controls->Add(this->dateOfTransaction);
			this->Controls->Add(this->recepientAccountNumberLabel);
			this->Controls->Add(this->typeOfTransactionLabel);
			this->Controls->Add(this->typeOfTransactionBox);
			this->Controls->Add(this->amountLabel);
			this->Controls->Add(this->amountBox);
			this->Controls->Add(this->accountNumberLabel);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->recordButton);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"RecordTransaction";
			this->Text = L"Record Transaction";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		String^ x = typeOfTransactionBox->Text->ToString();
		std::string typeOfTransaction = msclr::interop::marshal_as<std::string>(x);

		if (strcmp(typeOfTransaction.c_str(),"TRANSFER") == 0) {
			recepientAccountNumberLabel->Visible = true;
			accountRecepientBox->Visible = true;
		}
		else {
			recepientAccountNumberLabel->Visible = false;
			accountRecepientBox->Visible = false;
		}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	bool isMissing = false;
	int test;
	String^ query;
	query = dateOfTransaction->Text;
	test = query->IsNullOrWhiteSpace(dateOfTransaction->Text);
	if (test == 1)
	{
		MessageBox::Show("Date of Transaction must not be empty");
		isMissing = true;
	}

	query = monthOfTransaction->Text;
	test = query->IsNullOrWhiteSpace(monthOfTransaction->Text);
	if (test == 1)
	{
		MessageBox::Show("Month of Transaction must not be empty");
		isMissing = true;
	}

	query = yearOfTransaction->Text;
	test = query->IsNullOrWhiteSpace(yearOfTransaction->Text);
	if (test == 1)
	{
		MessageBox::Show("Year of Transaction must not be empty");
		isMissing = true;
	}

	query = typeOfTransactionBox->Text;
	test = query->IsNullOrWhiteSpace(typeOfTransactionBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Type of transction must be picked");
		isMissing = true;
	}
	if (isMissing) return;
		


	String^ x = accountBox->Text->ToString();
	std::string account = msclr::interop::marshal_as<std::string>(x);
	account = account.substr(0, 19);
	x = amountBox->Text->ToString();
	std::string amount = msclr::interop::marshal_as<std::string>(x);

	bool has_only_digits = (amount.find_first_not_of("0123456789.") == string::npos);
	if (has_only_digits == false)
	{
		MessageBox::Show("Balance must be digit only and not negative");
		return;
	}

	x = typeOfTransactionBox->Text->ToString();
	std::string transactionType = msclr::interop::marshal_as<std::string>(x);

	std::string accountRecepient;
	if (accountRecepientBox->Visible == false && strcmp(transactionType.c_str(), "TRANSFER") != 0)
		accountRecepient = "N/A";
	else {
		String^ recepient = accountRecepientBox->Text->ToString();
		accountRecepient = msclr::interop::marshal_as<std::string>(recepient);
		accountRecepient = accountRecepient.substr(0, 19);
		if (strcmp(accountRecepient.c_str(), account.c_str()) == 0)
		{
			MessageBox::Show("You are sending yourselves");
			return;
		}
	}

	
		if (strcmp(transactionType.c_str(), "WITHDRAWAL") == 0) {
			if (checkAndDeductBalance(stof(amount.c_str()), account) == false) {
				MessageBox::Show("Insufficient balance to withdraw money");
				return;
			}
			else {
				MessageBox::Show("Withdrawal has been made");
			}

		}
		if (strcmp(transactionType.c_str(), "TRANSFER") == 0) {
			if (checkAndDeductBalance(stof(amount.c_str()), account) == false) {
				MessageBox::Show("Insufficient balance to transfer money");
				return;
			}
			else {
				addAccount(stof(amount.c_str()), accountRecepient);
				MessageBox::Show("Transfer has been made");
			}
		}
	if (strcmp(transactionType.c_str(), "DEPOSIT") == 0) {
		addAccount(stof(amount.c_str()), account);
		MessageBox::Show("Deposit has been made");
	}


	std::string dateTransaction, monthTransaction, yearTransaction, monthExpire, yearExpire;
	x = dateOfTransaction->Text->ToString();
	dateTransaction = msclr::interop::marshal_as<std::string>(x);
	x = monthOfTransaction->Text->ToString();
	monthTransaction = msclr::interop::marshal_as<std::string>(x);
	x = yearOfTransaction->Text->ToString();
	yearTransaction = msclr::interop::marshal_as<std::string>(x);

	std::string transactionDate;
	transactionDate = dateTransaction + "/" + monthTransaction + "/" + yearTransaction;


	//has_only_digits = (account.find_first_not_of("0123456789 ") == string::npos);
	//if (has_only_digits == false)
	//{
	//	MessageBox::Show("Account number must be digit and space only");
	//	return;
	//}

	push(account.c_str(), transactionType.c_str(), stof(amount), accountRecepient.c_str(), transactionDate.c_str());
	Hide();
	Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
};
}
