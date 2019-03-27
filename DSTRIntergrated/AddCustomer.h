#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "customerInfo.h"
#include "linkedQueueType.h"
#include "sqlite3.h"
namespace Project2 {
	void enqueue(const char * newCard, int newCardVerCode, const char * newExpiryDate, const char * newFirstName, const char * newLastName, const char * newDateOfBirth, const char * newAddress, float newBalance);
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddCustomer
	/// </summary>
	public ref class AddCustomer : public System::Windows::Forms::Form
	{
	public:

		AddCustomer(void)
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
		~AddCustomer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  accountBox;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  cardVerCodeBox;
	private: System::Windows::Forms::TextBox^  firstBox;
	private: System::Windows::Forms::TextBox^  lastBox;
	private: System::Windows::Forms::TextBox^  addressBox;
	private: System::Windows::Forms::TextBox^  balanceBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  dateOfBirth;
	private: System::Windows::Forms::ComboBox^  monthOfBirth;
	private: System::Windows::Forms::ComboBox^  yearOfBirth;
	private: System::Windows::Forms::ComboBox^  monthOfExpire;
	private: System::Windows::Forms::ComboBox^  yearOfExpire;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
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
			this->accountBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cardVerCodeBox = (gcnew System::Windows::Forms::TextBox());
			this->firstBox = (gcnew System::Windows::Forms::TextBox());
			this->lastBox = (gcnew System::Windows::Forms::TextBox());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->balanceBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dateOfBirth = (gcnew System::Windows::Forms::ComboBox());
			this->monthOfBirth = (gcnew System::Windows::Forms::ComboBox());
			this->yearOfBirth = (gcnew System::Windows::Forms::ComboBox());
			this->monthOfExpire = (gcnew System::Windows::Forms::ComboBox());
			this->yearOfExpire = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// accountBox
			// 
			this->accountBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->accountBox->Location = System::Drawing::Point(243, 29);
			this->accountBox->Margin = System::Windows::Forms::Padding(4);
			this->accountBox->MaxLength = 20;
			this->accountBox->Name = L"accountBox";
			this->accountBox->Size = System::Drawing::Size(566, 33);
			this->accountBox->TabIndex = 0;
			this->accountBox->TextChanged += gcnew System::EventHandler(this, &AddCustomer::accountBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(22, 33);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Account Number";
			this->label1->Click += gcnew System::EventHandler(this, &AddCustomer::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(20, 78);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(256, 26);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Card Verification Code";
			this->label2->Click += gcnew System::EventHandler(this, &AddCustomer::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label3->ForeColor = System::Drawing::Color::Cyan;
			this->label3->Location = System::Drawing::Point(20, 119);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Expiry Date";
			this->label3->Click += gcnew System::EventHandler(this, &AddCustomer::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label4->ForeColor = System::Drawing::Color::Cyan;
			this->label4->Location = System::Drawing::Point(23, 161);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 26);
			this->label4->TabIndex = 4;
			this->label4->Text = L"First name";
			this->label4->Click += gcnew System::EventHandler(this, &AddCustomer::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label5->ForeColor = System::Drawing::Color::Cyan;
			this->label5->Location = System::Drawing::Point(23, 205);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 26);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Last Name";
			this->label5->Click += gcnew System::EventHandler(this, &AddCustomer::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label6->ForeColor = System::Drawing::Color::Cyan;
			this->label6->Location = System::Drawing::Point(22, 244);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 26);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Date of Birth";
			this->label6->Click += gcnew System::EventHandler(this, &AddCustomer::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label7->ForeColor = System::Drawing::Color::Cyan;
			this->label7->Location = System::Drawing::Point(22, 287);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(99, 26);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Address";
			this->label7->Click += gcnew System::EventHandler(this, &AddCustomer::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label8->ForeColor = System::Drawing::Color::Cyan;
			this->label8->Location = System::Drawing::Point(22, 335);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(97, 26);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Balance";
			this->label8->Click += gcnew System::EventHandler(this, &AddCustomer::label8_Click);
			// 
			// cardVerCodeBox
			// 
			this->cardVerCodeBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->cardVerCodeBox->Location = System::Drawing::Point(331, 75);
			this->cardVerCodeBox->Margin = System::Windows::Forms::Padding(4);
			this->cardVerCodeBox->MaxLength = 3;
			this->cardVerCodeBox->Name = L"cardVerCodeBox";
			this->cardVerCodeBox->Size = System::Drawing::Size(141, 33);
			this->cardVerCodeBox->TabIndex = 9;
			this->cardVerCodeBox->TextChanged += gcnew System::EventHandler(this, &AddCustomer::cardVerCodeBox_TextChanged);
			// 
			// firstBox
			// 
			this->firstBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->firstBox->Location = System::Drawing::Point(243, 158);
			this->firstBox->Margin = System::Windows::Forms::Padding(4);
			this->firstBox->Name = L"firstBox";
			this->firstBox->Size = System::Drawing::Size(566, 33);
			this->firstBox->TabIndex = 11;
			this->firstBox->TextChanged += gcnew System::EventHandler(this, &AddCustomer::firstBox_TextChanged);
			// 
			// lastBox
			// 
			this->lastBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->lastBox->Location = System::Drawing::Point(243, 202);
			this->lastBox->Margin = System::Windows::Forms::Padding(4);
			this->lastBox->Name = L"lastBox";
			this->lastBox->Size = System::Drawing::Size(566, 33);
			this->lastBox->TabIndex = 12;
			this->lastBox->TextChanged += gcnew System::EventHandler(this, &AddCustomer::lastBox_TextChanged);
			// 
			// addressBox
			// 
			this->addressBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->addressBox->Location = System::Drawing::Point(243, 285);
			this->addressBox->Margin = System::Windows::Forms::Padding(4);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(566, 33);
			this->addressBox->TabIndex = 14;
			this->addressBox->TextChanged += gcnew System::EventHandler(this, &AddCustomer::addressBox_TextChanged);
			// 
			// balanceBox
			// 
			this->balanceBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->balanceBox->Location = System::Drawing::Point(243, 331);
			this->balanceBox->Margin = System::Windows::Forms::Padding(4);
			this->balanceBox->Name = L"balanceBox";
			this->balanceBox->Size = System::Drawing::Size(566, 33);
			this->balanceBox->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button1->Location = System::Drawing::Point(646, 367);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 58);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AddCustomer::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button2->Location = System::Drawing::Point(243, 367);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 58);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AddCustomer::button2_Click);
			// 
			// dateOfBirth
			// 
			this->dateOfBirth->DropDownWidth = 60;
			this->dateOfBirth->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->dateOfBirth->FormattingEnabled = true;
			this->dateOfBirth->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31"
			});
			this->dateOfBirth->Location = System::Drawing::Point(332, 242);
			this->dateOfBirth->Margin = System::Windows::Forms::Padding(4);
			this->dateOfBirth->Name = L"dateOfBirth";
			this->dateOfBirth->Size = System::Drawing::Size(94, 33);
			this->dateOfBirth->TabIndex = 18;
			this->dateOfBirth->SelectedIndexChanged += gcnew System::EventHandler(this, &AddCustomer::dateOfBirth_SelectedIndexChanged);
			// 
			// monthOfBirth
			// 
			this->monthOfBirth->DropDownWidth = 60;
			this->monthOfBirth->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->monthOfBirth->FormattingEnabled = true;
			this->monthOfBirth->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12"
			});
			this->monthOfBirth->Location = System::Drawing::Point(540, 242);
			this->monthOfBirth->Margin = System::Windows::Forms::Padding(4);
			this->monthOfBirth->Name = L"monthOfBirth";
			this->monthOfBirth->Size = System::Drawing::Size(93, 33);
			this->monthOfBirth->TabIndex = 19;
			this->monthOfBirth->SelectedIndexChanged += gcnew System::EventHandler(this, &AddCustomer::monthOfBirth_SelectedIndexChanged);
			// 
			// yearOfBirth
			// 
			this->yearOfBirth->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->yearOfBirth->FormattingEnabled = true;
			this->yearOfBirth->Items->AddRange(gcnew cli::array< System::Object^  >(113) {
				L"2012", L"2011", L"2010", L"2009", L"2008",
					L"2007", L"2006", L"2005", L"2004", L"2003", L"2002", L"2001", L"2000", L"1999", L"1998", L"1997", L"1996", L"1995", L"1994",
					L"1993", L"1992", L"1991", L"1990", L"1989", L"1988", L"1987", L"1986", L"1985", L"1984", L"1983", L"1982", L"1981", L"1980",
					L"1979", L"1978", L"1977", L"1976", L"1975", L"1974", L"1973", L"1972", L"1971", L"1970", L"1969", L"1968", L"1967", L"1966",
					L"1965", L"1964", L"1963", L"1962", L"1961", L"1960", L"1959", L"1958", L"1957", L"1956", L"1955", L"1954", L"1953", L"1952",
					L"1951", L"1950", L"1949", L"1948", L"1947", L"1946", L"1945", L"1944", L"1943", L"1942", L"1941", L"1940", L"1939", L"1938",
					L"1937", L"1936", L"1935", L"1934", L"1933", L"1932", L"1931", L"1930", L"1929", L"1928", L"1927", L"1926", L"1925", L"1924",
					L"1923", L"1922", L"1921", L"1920", L"1919", L"1918", L"1917", L"1916", L"1915", L"1914", L"1913", L"1912", L"1911", L"1910",
					L"1909", L"1908", L"1907", L"1906", L"1905", L"1904", L"1903", L"1902", L"1901", L"1900"
			});
			this->yearOfBirth->Location = System::Drawing::Point(712, 243);
			this->yearOfBirth->Margin = System::Windows::Forms::Padding(4);
			this->yearOfBirth->Name = L"yearOfBirth";
			this->yearOfBirth->Size = System::Drawing::Size(97, 33);
			this->yearOfBirth->TabIndex = 20;
			this->yearOfBirth->SelectedIndexChanged += gcnew System::EventHandler(this, &AddCustomer::yearOfBirth_SelectedIndexChanged);
			// 
			// monthOfExpire
			// 
			this->monthOfExpire->DropDownWidth = 60;
			this->monthOfExpire->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->monthOfExpire->FormattingEnabled = true;
			this->monthOfExpire->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12"
			});
			this->monthOfExpire->Location = System::Drawing::Point(331, 119);
			this->monthOfExpire->Margin = System::Windows::Forms::Padding(4);
			this->monthOfExpire->Name = L"monthOfExpire";
			this->monthOfExpire->Size = System::Drawing::Size(93, 33);
			this->monthOfExpire->TabIndex = 21;
			this->monthOfExpire->SelectedIndexChanged += gcnew System::EventHandler(this, &AddCustomer::monthOfExpire_SelectedIndexChanged);
			// 
			// yearOfExpire
			// 
			this->yearOfExpire->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->yearOfExpire->FormattingEnabled = true;
			this->yearOfExpire->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"2017", L"2018", L"2019", L"2020", L"2021",
					L"2022", L"2023", L"2024", L"2025", L"2026", L"2027", L"2028"
			});
			this->yearOfExpire->Location = System::Drawing::Point(534, 119);
			this->yearOfExpire->Margin = System::Windows::Forms::Padding(4);
			this->yearOfExpire->Name = L"yearOfExpire";
			this->yearOfExpire->Size = System::Drawing::Size(93, 33);
			this->yearOfExpire->TabIndex = 22;
			this->yearOfExpire->SelectedIndexChanged += gcnew System::EventHandler(this, &AddCustomer::yearOfExpire_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label9->ForeColor = System::Drawing::Color::Cyan;
			this->label9->Location = System::Drawing::Point(238, 119);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 26);
			this->label9->TabIndex = 23;
			this->label9->Text = L"Month";
			this->label9->Click += gcnew System::EventHandler(this, &AddCustomer::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label10->ForeColor = System::Drawing::Color::Cyan;
			this->label10->Location = System::Drawing::Point(447, 119);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 26);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Year";
			this->label10->Click += gcnew System::EventHandler(this, &AddCustomer::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label11->ForeColor = System::Drawing::Color::Cyan;
			this->label11->Location = System::Drawing::Point(238, 244);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(64, 26);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Date";
			this->label11->Click += gcnew System::EventHandler(this, &AddCustomer::label11_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label12->ForeColor = System::Drawing::Color::Cyan;
			this->label12->Location = System::Drawing::Point(447, 245);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(81, 26);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Month";
			this->label12->Click += gcnew System::EventHandler(this, &AddCustomer::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->label13->ForeColor = System::Drawing::Color::Cyan;
			this->label13->Location = System::Drawing::Point(642, 244);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(60, 26);
			this->label13->TabIndex = 27;
			this->label13->Text = L"Year";
			this->label13->Click += gcnew System::EventHandler(this, &AddCustomer::label13_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(818, 121);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 28;
			this->pictureBox1->TabStop = false;
			// 
			// AddCustomer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(1073, 429);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->yearOfExpire);
			this->Controls->Add(this->monthOfExpire);
			this->Controls->Add(this->yearOfBirth);
			this->Controls->Add(this->monthOfBirth);
			this->Controls->Add(this->dateOfBirth);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->balanceBox);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->lastBox);
			this->Controls->Add(this->firstBox);
			this->Controls->Add(this->cardVerCodeBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->accountBox);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 12));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddCustomer";
			this->Text = L"Add Customer";
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
	//TextBox^  cardVerCodeBox;
	//TextBox^  firstBox;
	//TextBox^  lastBox;
	//TextBox^  addressBox;
	//TextBox^  balanceBox;
	//ComboBox^  dateOfBirth;
	//ComboBox^  monthOfBirth;
	//ComboBox^  yearOfBirth;
	//ComboBox^  monthYear;
	//ComboBox^  expiryYear;
	bool isMissing = false;
	String^ query = accountBox->Text;
	int test = query->IsNullOrWhiteSpace(accountBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Account Number must not be empty");
		isMissing = true;
	}

	query = cardVerCodeBox->Text;
	test = query->IsNullOrWhiteSpace(cardVerCodeBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Card Verification Number must not be empty");
		isMissing = true;
	}

	query = firstBox->Text;
	test = query->IsNullOrWhiteSpace(firstBox->Text);
	if (test == 1)
	{
		MessageBox::Show("First Name must not be empty");
		isMissing = true;
	}

	query = lastBox->Text;
	test = query->IsNullOrWhiteSpace(lastBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Last Name must not be empty");
		isMissing = true;
	}

	query = addressBox->Text;
	test = query->IsNullOrWhiteSpace(addressBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Address must not be empty");
		isMissing = true;
	}

	query = balanceBox->Text;
	test = query->IsNullOrWhiteSpace(balanceBox->Text);
	if (test == 1)
	{
		MessageBox::Show("Balance must not be empty");
		isMissing = true;
	}

	query = dateOfBirth->Text;
	test = query->IsNullOrWhiteSpace(dateOfBirth->Text);
	if (test == 1)
	{
		MessageBox::Show("Date of birth must not be empty");
		isMissing = true;
	}

	query = monthOfBirth->Text;
	test = query->IsNullOrWhiteSpace(monthOfBirth->Text);
	if (test == 1)
	{
		MessageBox::Show("Month of birth must not be empty");
		isMissing = true;
	}

	query = yearOfBirth->Text;
	test = query->IsNullOrWhiteSpace(yearOfBirth->Text);
	if (test == 1)
	{
		MessageBox::Show("Year of birth must not be empty");
		isMissing = true;
	}

	query = monthOfExpire->Text;
	test = query->IsNullOrWhiteSpace(monthOfExpire->Text);
	if (test == 1)
	{
		MessageBox::Show("Month of card expiry must not be empty");
		isMissing = true;
	}

	query = yearOfExpire->Text;
	test = query->IsNullOrWhiteSpace(yearOfExpire->Text);
	if (test == 1)
	{
		MessageBox::Show("Year of card expiry must not be empty");
		isMissing = true;
	}

	if (isMissing) return;

	String^ x = accountBox->Text->ToString();
	std::string account = msclr::interop::marshal_as<std::string>(x);
	x = balanceBox->Text->ToString();
	std::string balance = msclr::interop::marshal_as<std::string>(x);
	x = cardVerCodeBox->Text->ToString();
	std::string cardVerCode = msclr::interop::marshal_as<std::string>(x);
	x = firstBox->Text->ToString();
	std::string firstName = msclr::interop::marshal_as<std::string>(x);
	x = lastBox->Text->ToString();
	std::string lastName = msclr::interop::marshal_as<std::string>(x);
	x = addressBox->Text->ToString();
	std::string address = msclr::interop::marshal_as<std::string>(x);

	std::string dateBirth, monthBirth, yearBirth, monthExpire, yearExpire;
	x = dateOfBirth->Text->ToString();
	dateBirth = msclr::interop::marshal_as<std::string>(x);
	x = monthOfBirth->Text->ToString();
	monthBirth = msclr::interop::marshal_as<std::string>(x);
	x = yearOfBirth->Text->ToString();
	yearBirth = msclr::interop::marshal_as<std::string>(x);
	x = monthOfExpire->Text->ToString();
	monthExpire = msclr::interop::marshal_as<std::string>(x);
	x = yearOfExpire->Text->ToString();
	yearExpire = msclr::interop::marshal_as<std::string>(x);

	std::string birthDate, expiryCard;
	birthDate = dateBirth+ "/" + monthBirth + "/" + yearBirth;
	expiryCard = monthExpire +"/" + yearExpire[2] + yearExpire[3];

	bool has_only_digits = (cardVerCode.find_first_not_of("0123456789") == string::npos);
	if(has_only_digits == false)
	{
		MessageBox::Show("Card Verification Code must be digit only");
		return;
	}
	has_only_digits = (balance.find_first_not_of("0123456789.") == string::npos);
	if (has_only_digits == false)
	{
		MessageBox::Show("Balance must be digit only and not negative");
		return;
	}
	has_only_digits = (account.find_first_not_of("0123456789 ") == string::npos);
	if (has_only_digits == false)
	{
		MessageBox::Show("Account number must be digit and space only");
		return;
	}
	//accountInformation (account.c_str(),stoi(cardVerCode),expiryCard.c_str(),firstName.c_str(), lastName.c_str(), birthDate.c_str(),address.c_str(),stof(balance));
	//enqueue(x);
	enqueue(account.c_str(),stoi(cardVerCode),expiryCard.c_str(),firstName.c_str(), lastName.c_str(), birthDate.c_str(),address.c_str(),stof(balance));
}
private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void accountBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void cardVerCodeBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void firstBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lastBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void addressBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dateOfBirth_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void monthOfBirth_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void yearOfBirth_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void monthOfExpire_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void yearOfExpire_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}