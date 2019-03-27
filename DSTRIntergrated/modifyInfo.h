#pragma once
#include<iostream>
#include<string>
#include "sqlite3.h"
#include "linkedQueueType.h"
#include <msclr\marshal_cppstd.h>
bool checkIfAccountNumberIsFound(std::string accountNumber);
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for modifyInfo
	/// </summary>
	public ref class modifyInfo : public System::Windows::Forms::Form
	{
	public:
		modifyInfo(void)
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
		~modifyInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  accountNumber;
	private: System::Windows::Forms::Label^  verificationLabel;
	private: System::Windows::Forms::Label^  expiryLabel;
	private: System::Windows::Forms::Label^  firstLabel;
	private: System::Windows::Forms::Label^  lastLabel;
	private: System::Windows::Forms::Label^  dateLabel;
	private: System::Windows::Forms::Label^  addressLabel;
	private: System::Windows::Forms::Label^  balanceLabel;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  cardVerCodeBox;
	private: System::Windows::Forms::TextBox^  firstBox;
	private: System::Windows::Forms::TextBox^  addressBox;
	private: System::Windows::Forms::TextBox^  balanceBox;
	private: System::Windows::Forms::TextBox^  lastBox;
	private: System::Windows::Forms::ComboBox^  dateBirth;
	private: System::Windows::Forms::ComboBox^  monthBirth;
	private: System::Windows::Forms::ComboBox^  yearBirth;
	private: System::Windows::Forms::ComboBox^  monthExpiry;
	private: System::Windows::Forms::ComboBox^  yearExpiry;
	private: System::Windows::Forms::TextBox^  accountBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
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
			this->accountNumber = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->verificationLabel = (gcnew System::Windows::Forms::Label());
			this->expiryLabel = (gcnew System::Windows::Forms::Label());
			this->firstLabel = (gcnew System::Windows::Forms::Label());
			this->lastLabel = (gcnew System::Windows::Forms::Label());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->balanceLabel = (gcnew System::Windows::Forms::Label());
			this->cardVerCodeBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->firstBox = (gcnew System::Windows::Forms::TextBox());
			this->lastBox = (gcnew System::Windows::Forms::TextBox());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->balanceBox = (gcnew System::Windows::Forms::TextBox());
			this->dateBirth = (gcnew System::Windows::Forms::ComboBox());
			this->monthBirth = (gcnew System::Windows::Forms::ComboBox());
			this->yearBirth = (gcnew System::Windows::Forms::ComboBox());
			this->monthExpiry = (gcnew System::Windows::Forms::ComboBox());
			this->yearExpiry = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->accountBox = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// accountNumber
			// 
			this->accountNumber->AutoSize = true;
			this->accountNumber->Location = System::Drawing::Point(22, 25);
			this->accountNumber->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->accountNumber->Name = L"accountNumber";
			this->accountNumber->Size = System::Drawing::Size(194, 26);
			this->accountNumber->TabIndex = 0;
			this->accountNumber->Text = L"Account Number";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(717, 78);
			this->button1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 61);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &modifyInfo::button1_Click);
			// 
			// verificationLabel
			// 
			this->verificationLabel->AutoSize = true;
			this->verificationLabel->Location = System::Drawing::Point(22, 167);
			this->verificationLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->verificationLabel->Name = L"verificationLabel";
			this->verificationLabel->Size = System::Drawing::Size(256, 26);
			this->verificationLabel->TabIndex = 3;
			this->verificationLabel->Tag = L"allLabels";
			this->verificationLabel->Text = L"Card Verification Code";
			this->verificationLabel->Visible = false;
			// 
			// expiryLabel
			// 
			this->expiryLabel->AutoSize = true;
			this->expiryLabel->Location = System::Drawing::Point(22, 281);
			this->expiryLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->expiryLabel->Name = L"expiryLabel";
			this->expiryLabel->Size = System::Drawing::Size(141, 26);
			this->expiryLabel->TabIndex = 4;
			this->expiryLabel->Tag = L"allLabels";
			this->expiryLabel->Text = L"Expiry Date";
			this->expiryLabel->Visible = false;
			// 
			// firstLabel
			// 
			this->firstLabel->AutoSize = true;
			this->firstLabel->Location = System::Drawing::Point(22, 328);
			this->firstLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->firstLabel->Name = L"firstLabel";
			this->firstLabel->Size = System::Drawing::Size(131, 26);
			this->firstLabel->TabIndex = 5;
			this->firstLabel->Tag = L"allLabels";
			this->firstLabel->Text = L"First Name";
			this->firstLabel->Visible = false;
			// 
			// lastLabel
			// 
			this->lastLabel->AutoSize = true;
			this->lastLabel->Location = System::Drawing::Point(22, 373);
			this->lastLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->lastLabel->Name = L"lastLabel";
			this->lastLabel->Size = System::Drawing::Size(128, 26);
			this->lastLabel->TabIndex = 6;
			this->lastLabel->Tag = L"allLabels";
			this->lastLabel->Text = L"Last Name";
			this->lastLabel->Visible = false;
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Location = System::Drawing::Point(22, 418);
			this->dateLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(154, 26);
			this->dateLabel->TabIndex = 7;
			this->dateLabel->Tag = L"allLabels";
			this->dateLabel->Text = L"Date of Birth";
			this->dateLabel->Visible = false;
			// 
			// addressLabel
			// 
			this->addressLabel->AutoSize = true;
			this->addressLabel->Location = System::Drawing::Point(22, 463);
			this->addressLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->addressLabel->Name = L"addressLabel";
			this->addressLabel->Size = System::Drawing::Size(99, 26);
			this->addressLabel->TabIndex = 8;
			this->addressLabel->Tag = L"allLabels";
			this->addressLabel->Text = L"Address";
			this->addressLabel->Visible = false;
			// 
			// balanceLabel
			// 
			this->balanceLabel->AutoSize = true;
			this->balanceLabel->Location = System::Drawing::Point(22, 508);
			this->balanceLabel->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->balanceLabel->Name = L"balanceLabel";
			this->balanceLabel->Size = System::Drawing::Size(97, 26);
			this->balanceLabel->TabIndex = 9;
			this->balanceLabel->Tag = L"allLabels";
			this->balanceLabel->Text = L"Balance";
			this->balanceLabel->Visible = false;
			// 
			// cardVerCodeBox
			// 
			this->cardVerCodeBox->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cardVerCodeBox->Location = System::Drawing::Point(280, 162);
			this->cardVerCodeBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->cardVerCodeBox->MaxLength = 3;
			this->cardVerCodeBox->Name = L"cardVerCodeBox";
			this->cardVerCodeBox->ReadOnly = true;
			this->cardVerCodeBox->Size = System::Drawing::Size(182, 33);
			this->cardVerCodeBox->TabIndex = 10;
			this->cardVerCodeBox->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(264, 281);
			this->label8->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(81, 26);
			this->label8->TabIndex = 23;
			this->label8->Tag = L"allLabels";
			this->label8->Text = L"Month";
			this->label8->Visible = false;
			// 
			// firstBox
			// 
			this->firstBox->Location = System::Drawing::Point(271, 321);
			this->firstBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->firstBox->Name = L"firstBox";
			this->firstBox->Size = System::Drawing::Size(658, 33);
			this->firstBox->TabIndex = 11;
			this->firstBox->Visible = false;
			// 
			// lastBox
			// 
			this->lastBox->Location = System::Drawing::Point(269, 370);
			this->lastBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->lastBox->Name = L"lastBox";
			this->lastBox->Size = System::Drawing::Size(658, 33);
			this->lastBox->TabIndex = 12;
			this->lastBox->Visible = false;
			// 
			// addressBox
			// 
			this->addressBox->Location = System::Drawing::Point(269, 460);
			this->addressBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(658, 33);
			this->addressBox->TabIndex = 14;
			this->addressBox->Visible = false;
			// 
			// balanceBox
			// 
			this->balanceBox->Location = System::Drawing::Point(269, 505);
			this->balanceBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->balanceBox->Name = L"balanceBox";
			this->balanceBox->Size = System::Drawing::Size(658, 33);
			this->balanceBox->TabIndex = 15;
			this->balanceBox->Visible = false;
			// 
			// dateBirth
			// 
			this->dateBirth->DropDownWidth = 60;
			this->dateBirth->FormattingEnabled = true;
			this->dateBirth->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31"
			});
			this->dateBirth->Location = System::Drawing::Point(349, 415);
			this->dateBirth->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->dateBirth->Name = L"dateBirth";
			this->dateBirth->Size = System::Drawing::Size(121, 33);
			this->dateBirth->TabIndex = 18;
			this->dateBirth->Visible = false;
			// 
			// monthBirth
			// 
			this->monthBirth->DropDownWidth = 60;
			this->monthBirth->FormattingEnabled = true;
			this->monthBirth->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12"
			});
			this->monthBirth->Location = System::Drawing::Point(587, 415);
			this->monthBirth->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->monthBirth->Name = L"monthBirth";
			this->monthBirth->Size = System::Drawing::Size(119, 33);
			this->monthBirth->TabIndex = 19;
			this->monthBirth->Visible = false;
			// 
			// yearBirth
			// 
			this->yearBirth->FormattingEnabled = true;
			this->yearBirth->Items->AddRange(gcnew cli::array< System::Object^  >(113) {
				L"2012", L"2011", L"2010", L"2009", L"2008", L"2007",
					L"2006", L"2005", L"2004", L"2003", L"2002", L"2001", L"2000", L"1999", L"1998", L"1997", L"1996", L"1995", L"1994", L"1993",
					L"1992", L"1991", L"1990", L"1989", L"1988", L"1987", L"1986", L"1985", L"1984", L"1983", L"1982", L"1981", L"1980", L"1979",
					L"1978", L"1977", L"1976", L"1975", L"1974", L"1973", L"1972", L"1971", L"1970", L"1969", L"1968", L"1967", L"1966", L"1965",
					L"1964", L"1963", L"1962", L"1961", L"1960", L"1959", L"1958", L"1957", L"1956", L"1955", L"1954", L"1953", L"1952", L"1951",
					L"1950", L"1949", L"1948", L"1947", L"1946", L"1945", L"1944", L"1943", L"1942", L"1941", L"1940", L"1939", L"1938", L"1937",
					L"1936", L"1935", L"1934", L"1933", L"1932", L"1931", L"1930", L"1929", L"1928", L"1927", L"1926", L"1925", L"1924", L"1923",
					L"1922", L"1921", L"1920", L"1919", L"1918", L"1917", L"1916", L"1915", L"1914", L"1913", L"1912", L"1911", L"1910", L"1909",
					L"1908", L"1907", L"1906", L"1905", L"1904", L"1903", L"1902", L"1901", L"1900"
			});
			this->yearBirth->Location = System::Drawing::Point(804, 415);
			this->yearBirth->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->yearBirth->Name = L"yearBirth";
			this->yearBirth->Size = System::Drawing::Size(125, 33);
			this->yearBirth->TabIndex = 20;
			this->yearBirth->Visible = false;
			// 
			// monthExpiry
			// 
			this->monthExpiry->DropDownWidth = 60;
			this->monthExpiry->FormattingEnabled = true;
			this->monthExpiry->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->monthExpiry->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12"
			});
			this->monthExpiry->Location = System::Drawing::Point(375, 276);
			this->monthExpiry->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->monthExpiry->Name = L"monthExpiry";
			this->monthExpiry->Size = System::Drawing::Size(119, 33);
			this->monthExpiry->TabIndex = 21;
			this->monthExpiry->Visible = false;
			// 
			// yearExpiry
			// 
			this->yearExpiry->FormattingEnabled = true;
			this->yearExpiry->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"2017", L"2018", L"2019", L"2020", L"2021", L"2022",
					L"2023", L"2024", L"2025", L"2026", L"2027", L"2028"
			});
			this->yearExpiry->Location = System::Drawing::Point(631, 276);
			this->yearExpiry->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->yearExpiry->Name = L"yearExpiry";
			this->yearExpiry->Size = System::Drawing::Size(119, 33);
			this->yearExpiry->TabIndex = 22;
			this->yearExpiry->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(535, 281);
			this->label9->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(60, 26);
			this->label9->TabIndex = 24;
			this->label9->Tag = L"allLabels";
			this->label9->Text = L"Year";
			this->label9->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(264, 418);
			this->label10->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(64, 26);
			this->label10->TabIndex = 25;
			this->label10->Tag = L"allLabels";
			this->label10->Text = L"Date";
			this->label10->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(492, 418);
			this->label11->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 26);
			this->label11->TabIndex = 26;
			this->label11->Tag = L"allLabels";
			this->label11->Text = L"Month";
			this->label11->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(730, 418);
			this->label12->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 26);
			this->label12->TabIndex = 27;
			this->label12->Tag = L"allLabels";
			this->label12->Text = L"Year";
			this->label12->Visible = false;
			// 
			// accountBox
			// 
			this->accountBox->Location = System::Drawing::Point(271, 19);
			this->accountBox->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->accountBox->MaxLength = 20;
			this->accountBox->Name = L"accountBox";
			this->accountBox->Size = System::Drawing::Size(658, 33);
			this->accountBox->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button2->ForeColor = System::Drawing::Color::Cyan;
			this->button2->Location = System::Drawing::Point(280, 78);
			this->button2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 61);
			this->button2->TabIndex = 28;
			this->button2->Text = L"Reset";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &modifyInfo::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button3->Location = System::Drawing::Point(269, 565);
			this->button3->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(148, 61);
			this->button3->TabIndex = 29;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &modifyInfo::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->button4->Location = System::Drawing::Point(631, 565);
			this->button4->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(148, 61);
			this->button4->TabIndex = 30;
			this->button4->Text = L"Modify";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &modifyInfo::button4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(665, 146);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 31;
			this->pictureBox1->TabStop = false;
			// 
			// modifyInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 641);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->cardVerCodeBox);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->balanceLabel);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->addressLabel);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->yearExpiry);
			this->Controls->Add(this->lastLabel);
			this->Controls->Add(this->accountBox);
			this->Controls->Add(this->monthExpiry);
			this->Controls->Add(this->firstLabel);
			this->Controls->Add(this->yearBirth);
			this->Controls->Add(this->expiryLabel);
			this->Controls->Add(this->monthBirth);
			this->Controls->Add(this->verificationLabel);
			this->Controls->Add(this->dateBirth);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->accountNumber);
			this->Controls->Add(this->balanceBox);
			this->Controls->Add(this->firstBox);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->lastBox);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->ForeColor = System::Drawing::Color::Cyan;
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"modifyInfo";
			this->Text = L"Modify Info";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {\
	String^ x = accountBox->Text->ToString();
	std::string account = msclr::interop::marshal_as<std::string>(x);
	//Used to check if the box is empty or not
	
	bool has_only_digits = (account.find_first_not_of("0123456789 ") == string::npos);
	if (has_only_digits == false)
	{
		MessageBox::Show("Account must be digit only");
		return;
	}

	if (checkIfAccountNumberIsFound(account) == true) {
		sqlite3 *db;
		int rc;
		rc = sqlite3_open("main.db", &db);
		if (rc) {
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
		}
		sqlite3_stmt *stmt = NULL;
		std::string x = "SELECT * FROM customerList WHERE account_number = '" + account + "'";
		rc = sqlite3_prepare_v2(db, x.c_str(), -1, &stmt, NULL);
		int colCount = sqlite3_column_count(stmt);
		rc = sqlite3_step(stmt);
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
				String^ step3 = cardVerificationCode.ToString();
				this->cardVerCodeBox->Text = step3;
			}
			else if (colIndex == 7) {
				balance = float(sqlite3_column_double(stmt, colIndex));
				String^ step3 = balance.ToString();
				this->balanceBox->Text = step3;
			}
			else {
				const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
				switch (colIndex) {
				case 0:
				{
					accountNumber = const_cast<unsigned char *>(valChar);
					char * step1 = (char*)accountNumber;
					String^ step3 = gcnew String(step1);
					this->accountBox->Text = step3;
					break;
				}
				case 2:
				{
					expiryDate = const_cast<unsigned char *>(valChar);
					char * step1 = (char*)expiryDate;
					String^ step3 = gcnew String(step1);
					this->monthExpiry->SelectedItem = "" + step3[0] + step3[1];
					this->yearExpiry->SelectedItem = "20" + step3[3] + step3[4];
					break;
				}
				case 3:
				{
					firstName = const_cast<unsigned char *>(valChar);
					char * step1 = (char*)firstName;
					String^ step3 = gcnew String(step1);
					this->firstBox->Text = step3;
					break;
				}
				case 4:
				{
					lastName = const_cast<unsigned char *>(valChar);
					char * step1 = (char*)lastName;
					String^ step3 = gcnew String(step1);
					this->lastBox->Text = step3;
					break;
				}
				case 5:
				{
					dateOfBirth = const_cast<unsigned char *>(valChar);
					char * step1 = (char*)dateOfBirth;
					String^ step3 = gcnew String(step1);
					this->dateBirth->SelectedItem = "" + step3[0] + step3[1];
					this->monthBirth->SelectedItem = "" + step3[3] + step3[4];
					this->yearBirth->SelectedItem = "" + step3[6] + step3[7] + step3[8] + step3[9];

					break;
				}
				case 6:
				{
					address = const_cast<unsigned char *>(valChar);
					char * step1 = (char*)address;
					String^ step3 = gcnew String(step1);
					this->addressBox->Text = step3;
					break;
				}
				default:
					std::cout << "SOMETHING WRONG" << std::endl;
					break;
				}
			}
		}

		rc = sqlite3_finalize(stmt);
		sqlite3_close(db);

		verificationLabel->Visible = true;
		expiryLabel->Visible = true;
		firstLabel->Visible = true;
		lastLabel->Visible = true;
		dateLabel->Visible = true;
		addressLabel->Visible = true;
		balanceLabel->Visible = true;
		label8->Visible = true;
		label9->Visible = true;
		label10->Visible = true;
		label11->Visible = true;
		label12->Visible = true;
		cardVerCodeBox->Visible = true;

		firstBox->Visible = true;
		lastBox->Visible = true;
		addressBox->Visible = true;
		balanceBox->Visible = true;
		dateBirth->Visible = true;
		monthBirth->Visible = true;
		yearBirth->Visible = true;
		monthExpiry->Visible = true;
		yearExpiry->Visible = true;
		button4->Visible = true;
		accountBox->ReadOnly = true;
	}
	else
		MessageBox::Show("Account number is invalid");

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	verificationLabel->Visible = false;
	expiryLabel->Visible = false;
	firstLabel->Visible = false;
	lastLabel->Visible = false;
	dateLabel->Visible = false;
	addressLabel->Visible = false;
	balanceLabel->Visible = false;
	label8->Visible = false;
	label9->Visible = false;
	label10->Visible = false;
	label11->Visible = false;
	label12->Visible = false;
	cardVerCodeBox->Visible = false;
	firstBox->Visible = false;
	lastBox->Visible = false;
	addressBox->Visible = false;
	balanceBox->Visible = false;
	dateBirth->Visible = false;
	monthBirth->Visible = false;
	yearBirth->Visible = false;
	monthExpiry->Visible = false;
	yearExpiry->Visible = false;
	button4->Visible = false;

	this->cardVerCodeBox->Text = nullptr;
	this->accountBox->Text = nullptr;
	this->addressBox->Text = nullptr;
	this->balanceBox->Text = nullptr;
	this->firstBox->Text = nullptr;
	this->lastBox->Text = nullptr;
	this->dateBirth->SelectedItem = nullptr;
	this->yearBirth->SelectedItem = nullptr;
	this->monthBirth->SelectedItem = nullptr;
	this->monthExpiry->SelectedItem = nullptr;
	this->yearExpiry->SelectedItem = nullptr;
	accountBox->ReadOnly = false;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//1. open connection with database
	//2. Declare variables for each book information
	//3. Store modified variable for each book
	//4. Create a linked stack and enqueue all exisiting information into the stack
	//5. Replace the old information with the new one that has same book ID
	//6. Store into the database (either using ALTER TABLE or DROP the table, CREATE the table, and re-insert all information in the stack.zti



	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *stmt = NULL;

	std::string updatedInformation[8];
	std::string dateBirth, monthBirth, yearBirth, monthExpire, yearExpire;
	std::string birthDate, expiryCard;

	String^ x = accountBox->Text->ToString();
	updatedInformation[0] = msclr::interop::marshal_as<std::string>(x);

	x = this->cardVerCodeBox->Text->ToString();
	updatedInformation[1] = msclr::interop::marshal_as<std::string>(x);

	x = this->monthExpiry->SelectedItem->ToString();
	monthExpire = msclr::interop::marshal_as<std::string>(x);
	x = this->yearExpiry->SelectedItem->ToString();
	yearExpire = msclr::interop::marshal_as<std::string>(x);
	updatedInformation[2] = monthExpire + "/" + yearExpire[2] + yearExpire[3];

	x = firstBox->Text->ToString();
	updatedInformation[3] = msclr::interop::marshal_as<std::string>(x);
	x = lastBox->Text->ToString();
	updatedInformation[4] = msclr::interop::marshal_as<std::string>(x);

	x = this->dateBirth->SelectedItem->ToString();
	dateBirth = msclr::interop::marshal_as<std::string>(x);
	x = this->monthBirth->SelectedItem->ToString();
	monthBirth = msclr::interop::marshal_as<std::string>(x);
	x = this->yearBirth->SelectedItem->ToString();
	yearBirth = msclr::interop::marshal_as<std::string>(x);
	updatedInformation[5] = dateBirth + "/" + monthBirth + "/" + yearBirth;

	x = addressBox->Text->ToString();
	updatedInformation[6] = msclr::interop::marshal_as<std::string>(x);

	x = balanceBox->Text->ToString();
	updatedInformation[7] = msclr::interop::marshal_as<std::string>(x);

	//2. create the queue
	stmt = NULL;
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

	rc = sqlite3_finalize(stmt);

	customerInfo modifiedCustomer(updatedInformation[0].c_str(), atoi(updatedInformation[1].c_str()), updatedInformation[2].c_str(), updatedInformation[3].c_str(), updatedInformation[4].c_str(), updatedInformation[5].c_str(), updatedInformation[6].c_str(),float(atof(updatedInformation[7].c_str())));

	queue.modifyInformation(modifiedCustomer);

	//delete the table
	rc = sqlite3_prepare_v2(db, "DROP TABLE customerList;", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);

	//create the same table
	rc = sqlite3_prepare_v2(db, "CREATE TABLE customerList (account_number VARCHAR[20] PRIMARY KEY, card_ver_code INT NOT NULL, expiry_date VARCHAR[5] NOT NULL, first_name VARCHAR[255] NOT NULL, last_name VARCHAR[255] NOT NULL, date_of_birth VARCHAR[9] NOT NULL, address VARCHAR[255] NOT NULL, balance FLOAT NOT NULL); ", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);


	//insert the data from linked list to the database
	node * curr;
	for (curr = queue.getQueue(); curr; curr = curr->link)
	{
		char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
		int cardVerificationCode;
		float balance;
		//we can use << on data object because we overload << in the data class
		curr->info.getAccountNumber(accountNumber);
		curr->info.getExpiryDate(expiryDate);
		curr->info.getFirstName(firstName);
		curr->info.getLastName(lastName);
		curr->info.getDateOfBirth(dateOfBirth);
		curr->info.getAddress(address);
		balance = curr->info.getBalance();
		cardVerificationCode = curr->info.getCardVerificationCode();
		cout << "Card number: " << accountNumber << endl
			<< "Card verification code: " << cardVerificationCode << endl
			<< "Expiry date: " << expiryDate << endl
			<< "First name: " << firstName << endl
			<< "Last name: " << lastName << endl
			<< "Date of birth: " << dateOfBirth << endl
			<< "Address: " << address << endl
			<< "Balance: " << balance << endl;
		cout << "=============================" << endl;

		System::String^ convertToString = balance.ToString();
		string balanceInString = msclr::interop::marshal_as<std::string>(convertToString);
		convertToString = cardVerificationCode.ToString();
		string newCardVerificationCode = msclr::interop::marshal_as<std::string>(convertToString);

		string statement = "INSERT INTO customerList VALUES('" + string(accountNumber) + "'," + newCardVerificationCode + ",'" + string(expiryDate) + "','" + string(firstName) + "','" + string(lastName) + "','" + string(dateOfBirth) + "','" + string(address) + "'," + balanceInString + ");";
		rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "%s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
		}
		rc = sqlite3_step(stmt);
		rc = sqlite3_finalize(stmt);
	}
	queue.~linkedQueueType();
	//DB VERSION
	/*std::string statement = "UPDATE customerList SET "
		" expiry_date = '" + updatedInformation[2] + 
		"', first_name = '" + updatedInformation[3] +
		"', last_name = '" + updatedInformation[4] +
		"', date_of_birth = '" + updatedInformation[5] +
		"', address = '" + updatedInformation[6] +
		"', balance = " + updatedInformation[7] + " WHERE account_number = '" + updatedInformation[0] +  "';";
	rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);*/

	sqlite3_close(db);

}
};
}
