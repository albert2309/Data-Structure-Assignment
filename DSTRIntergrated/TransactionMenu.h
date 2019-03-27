#pragma once
#include "Search Transaction.h"
#include "RecordTransaction.h"
#include "RemoveTransaction.h"
#include "DisplayAllStack.h"
#include "ModifyTransaction.h"
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TransactionMenu
	/// </summary>
	public ref class TransactionMenu : public System::Windows::Forms::Form
	{
	public:
		TransactionMenu(void)
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
		~TransactionMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  sortTranscationButton;
	private: System::Windows::Forms::Button^  modifyTransactionButton;
	private: System::Windows::Forms::Button^  displayAllButton;
	private: System::Windows::Forms::Button^  purgeTransactionButton;
	private: System::Windows::Forms::Button^  searchTransactionButton;
	private: System::Windows::Forms::Button^  removeTransactionButton;
	private: System::Windows::Forms::Button^  recordTransactionButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Label^  label1;
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
			this->sortTranscationButton = (gcnew System::Windows::Forms::Button());
			this->modifyTransactionButton = (gcnew System::Windows::Forms::Button());
			this->displayAllButton = (gcnew System::Windows::Forms::Button());
			this->purgeTransactionButton = (gcnew System::Windows::Forms::Button());
			this->searchTransactionButton = (gcnew System::Windows::Forms::Button());
			this->removeTransactionButton = (gcnew System::Windows::Forms::Button());
			this->recordTransactionButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// sortTranscationButton
			// 
			this->sortTranscationButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->sortTranscationButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sortTranscationButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->sortTranscationButton->ForeColor = System::Drawing::Color::Cyan;
			this->sortTranscationButton->Location = System::Drawing::Point(331, 332);
			this->sortTranscationButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->sortTranscationButton->Name = L"sortTranscationButton";
			this->sortTranscationButton->Size = System::Drawing::Size(279, 113);
			this->sortTranscationButton->TabIndex = 22;
			this->sortTranscationButton->Text = L"Sort transaction records";
			this->sortTranscationButton->UseVisualStyleBackColor = false;
			this->sortTranscationButton->Click += gcnew System::EventHandler(this, &TransactionMenu::sortTransactionButton_Click);
			// 
			// modifyTransactionButton
			// 
			this->modifyTransactionButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->modifyTransactionButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->modifyTransactionButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->modifyTransactionButton->ForeColor = System::Drawing::Color::Cyan;
			this->modifyTransactionButton->Location = System::Drawing::Point(331, 207);
			this->modifyTransactionButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->modifyTransactionButton->Name = L"modifyTransactionButton";
			this->modifyTransactionButton->Size = System::Drawing::Size(279, 113);
			this->modifyTransactionButton->TabIndex = 21;
			this->modifyTransactionButton->Text = L"Modify a transaction\'s record";
			this->modifyTransactionButton->UseVisualStyleBackColor = false;
			this->modifyTransactionButton->Click += gcnew System::EventHandler(this, &TransactionMenu::modifyTransactionButton_Click);
			// 
			// displayAllButton
			// 
			this->displayAllButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->displayAllButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->displayAllButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->displayAllButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->displayAllButton->ForeColor = System::Drawing::Color::Cyan;
			this->displayAllButton->Location = System::Drawing::Point(26, 332);
			this->displayAllButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->displayAllButton->Name = L"displayAllButton";
			this->displayAllButton->Size = System::Drawing::Size(279, 113);
			this->displayAllButton->TabIndex = 20;
			this->displayAllButton->Text = L"Display all transaction record";
			this->displayAllButton->UseVisualStyleBackColor = false;
			this->displayAllButton->Click += gcnew System::EventHandler(this, &TransactionMenu::displayAllButton_Click);
			// 
			// purgeTransactionButton
			// 
			this->purgeTransactionButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->purgeTransactionButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->purgeTransactionButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->purgeTransactionButton->ForeColor = System::Drawing::Color::Cyan;
			this->purgeTransactionButton->Location = System::Drawing::Point(630, 207);
			this->purgeTransactionButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->purgeTransactionButton->Name = L"purgeTransactionButton";
			this->purgeTransactionButton->Size = System::Drawing::Size(279, 113);
			this->purgeTransactionButton->TabIndex = 19;
			this->purgeTransactionButton->Text = L"Purge all transaction record";
			this->purgeTransactionButton->UseVisualStyleBackColor = false;
			this->purgeTransactionButton->Click += gcnew System::EventHandler(this, &TransactionMenu::purgeTransactionButton_Click);
			// 
			// searchTransactionButton
			// 
			this->searchTransactionButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->searchTransactionButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searchTransactionButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->searchTransactionButton->ForeColor = System::Drawing::Color::Cyan;
			this->searchTransactionButton->Location = System::Drawing::Point(26, 207);
			this->searchTransactionButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->searchTransactionButton->Name = L"searchTransactionButton";
			this->searchTransactionButton->Size = System::Drawing::Size(279, 113);
			this->searchTransactionButton->TabIndex = 18;
			this->searchTransactionButton->Text = L"Search transactions";
			this->searchTransactionButton->UseVisualStyleBackColor = false;
			this->searchTransactionButton->Click += gcnew System::EventHandler(this, &TransactionMenu::searchTransactionButton_Click);
			// 
			// removeTransactionButton
			// 
			this->removeTransactionButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->removeTransactionButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->removeTransactionButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->removeTransactionButton->ForeColor = System::Drawing::Color::Cyan;
			this->removeTransactionButton->Location = System::Drawing::Point(331, 82);
			this->removeTransactionButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->removeTransactionButton->Name = L"removeTransactionButton";
			this->removeTransactionButton->Size = System::Drawing::Size(279, 113);
			this->removeTransactionButton->TabIndex = 17;
			this->removeTransactionButton->Text = L"Remove a recent transaction";
			this->removeTransactionButton->UseVisualStyleBackColor = false;
			this->removeTransactionButton->Click += gcnew System::EventHandler(this, &TransactionMenu::removeTransactionButton_Click);
			// 
			// recordTransactionButton
			// 
			this->recordTransactionButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->recordTransactionButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recordTransactionButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->recordTransactionButton->ForeColor = System::Drawing::Color::Cyan;
			this->recordTransactionButton->Location = System::Drawing::Point(26, 82);
			this->recordTransactionButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->recordTransactionButton->Name = L"recordTransactionButton";
			this->recordTransactionButton->Size = System::Drawing::Size(279, 113);
			this->recordTransactionButton->TabIndex = 16;
			this->recordTransactionButton->Text = L"Record a transaction";
			this->recordTransactionButton->UseVisualStyleBackColor = false;
			this->recordTransactionButton->Click += gcnew System::EventHandler(this, &TransactionMenu::recordTransactionButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 18));
			this->exitButton->ForeColor = System::Drawing::Color::Cyan;
			this->exitButton->Location = System::Drawing::Point(630, 332);
			this->exitButton->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(279, 113);
			this->exitButton->TabIndex = 23;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &TransactionMenu::exitButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 20));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(174, 9);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(551, 64);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Welcome to Transaction Record System\r\nHow may I help you\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Albert\\Documents\\Visual Studio 2017\\Projects\\DSTRIntergrated\\DSTRIntergr"
				L"ated\\resized.png";
			this->pictureBox1->Location = System::Drawing::Point(630, 83);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 112);
			this->pictureBox1->TabIndex = 30;
			this->pictureBox1->TabStop = false;
			// 
			// TransactionMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Navy;
			this->ClientSize = System::Drawing::Size(969, 453);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->sortTranscationButton);
			this->Controls->Add(this->modifyTransactionButton);
			this->Controls->Add(this->displayAllButton);
			this->Controls->Add(this->purgeTransactionButton);
			this->Controls->Add(this->searchTransactionButton);
			this->Controls->Add(this->removeTransactionButton);
			this->Controls->Add(this->recordTransactionButton);
			this->Font = (gcnew System::Drawing::Font(L"Verdana", 16));
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"TransactionMenu";
			this->Text = L"Transaction Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void recordTransactionButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Form^ rgForm = gcnew RecordTransaction();
		rgForm->Show();
	}
private: System::Void modifyTransactionButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew ModifyTransaction();
	rgForm->Show();
	}
private: System::Void displayAllButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew DisplayAllStack();
	rgForm->Show();
}
private: System::Void purgeTransactionButton_Click(System::Object^  sender, System::EventArgs^  e) {
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
	rc = sqlite3_prepare_v2(db, "DROP TABLE transactionList", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_reset(stmt);


	rc = sqlite3_prepare_v2(db, "CREATE TABLE transactionList( account_number VARCHAR[16], type_of_transaction VARCHAR[10] NOT NULL, amount FLOAT NOT NULL, target_account VARCHAR[16], date_of_transaction VARCHAR[9] NOT NULL, FOREIGN KEY (account_number) REFERENCES customerList(account_number) );", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);

	MessageBox::Show("DATA HAS BEEN PURGED");
}
private: System::Void searchTransactionButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew SearchTransaction();
	rgForm->Show();
}
private: System::Void removeTransactionButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Form^ rgForm = gcnew RemoveTransaction();
	rgForm->Show();
}
private: System::Void sortTransactionButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Hide();
	Close();
}
};
}
