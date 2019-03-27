#pragma once
#include"AdminMenu.h"
#include "TransactionMenu.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TypeMenu
	/// </summary>
	public ref class TypeMenu : public System::Windows::Forms::Form
	{
	public:
		TypeMenu(void)
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
		~TypeMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  customerButton;
	private: System::Windows::Forms::Button^  transactionButton;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->customerButton = (gcnew System::Windows::Forms::Button());
			this->transactionButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(192, 136);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(597, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Which type of system do you want to use\?";
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->exitButton->ForeColor = System::Drawing::Color::Cyan;
			this->exitButton->Location = System::Drawing::Point(198, 394);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(591, 61);
			this->exitButton->TabIndex = 8;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &TypeMenu::button2_Click);
			// 
			// customerButton
			// 
			this->customerButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->customerButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->customerButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->customerButton->ForeColor = System::Drawing::Color::Cyan;
			this->customerButton->Location = System::Drawing::Point(198, 197);
			this->customerButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->customerButton->Name = L"customerButton";
			this->customerButton->Size = System::Drawing::Size(591, 61);
			this->customerButton->TabIndex = 7;
			this->customerButton->Text = L"Customer List (queue)";
			this->customerButton->UseVisualStyleBackColor = false;
			this->customerButton->Click += gcnew System::EventHandler(this, &TypeMenu::button1_Click);
			// 
			// transactionButton
			// 
			this->transactionButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->transactionButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->transactionButton->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->transactionButton->ForeColor = System::Drawing::Color::Cyan;
			this->transactionButton->Location = System::Drawing::Point(198, 298);
			this->transactionButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->transactionButton->Name = L"transactionButton";
			this->transactionButton->Size = System::Drawing::Size(591, 61);
			this->transactionButton->TabIndex = 9;
			this->transactionButton->Text = L"Transaction List (stack)";
			this->transactionButton->UseVisualStyleBackColor = false;
			this->transactionButton->Click += gcnew System::EventHandler(this, &TypeMenu::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(348, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 51;
			this->pictureBox1->TabStop = false;
			// 
			// TypeMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 514);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->transactionButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->customerButton);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"TypeMenu";
			this->Text = L"Type Menu";
			this->Load += gcnew System::EventHandler(this, &TypeMenu::TypeMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ rgForm = gcnew AdminMenu();
		rgForm->Show();
	}
	private: System::Void TypeMenu_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew TransactionMenu();
	rgForm->Show();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
};
}
