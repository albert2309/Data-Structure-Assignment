#include "RemoveTransaction.h"
#include<vector>
void Project2::commitPop() {
	//1. Open the database
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	//2. create the pop
	sqlite3_stmt *stmt = NULL;
	rc = sqlite3_prepare_v2(db, "SELECT * FROM transactionList", -1, &stmt, NULL);
	linkedStack stack;
	int rowCount = 0;
	rc = sqlite3_step(stmt);
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		rowCount++;
		unsigned char * accountNumber = new unsigned char[1500];
		unsigned char * typeOfTransaction = new unsigned char[1500];
		float amount;
		unsigned char * targetCard = new unsigned char[1500];
		unsigned char * dateOfTransaction = new unsigned char[1500];
		int colCount = sqlite3_column_count(stmt);
		for (int colIndex = 0; colIndex < colCount; colIndex++)
		{
			if (colIndex == 2) {
				amount = float(sqlite3_column_double(stmt, colIndex));
			}
			else {
				const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
				switch (colIndex) {
				case 0: {
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
					targetCard = const_cast<unsigned char *>(valChar);
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
		transactionRecord newTransaction((char*)accountNumber, (char *)typeOfTransaction, amount, (char*)targetCard, (char *)dateOfTransaction);
		stack.push(newTransaction);
		rc = sqlite3_step(stmt);
	}
	rc = sqlite3_finalize(stmt);
	stack.pop();
	rc = sqlite3_prepare_v2(db, "DROP TABLE transactionList;", -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	rc = sqlite3_reset(stmt);
	rc = sqlite3_prepare_v2(db, "CREATE TABLE transactionList( account_number VARCHAR[16], type_of_transaction VARCHAR[10] NOT NULL, amount FLOAT NOT NULL, target_account VARCHAR[16], date_of_transaction VARCHAR[9] NOT NULL, FOREIGN KEY (account_number) REFERENCES customerList(account_number) );", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);

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
		//cout << "Account number: " << accountNumber << endl
		//	<< "Type of transaction: " << typeOfTransaction << endl
		//	<< "Amount: " << amount << endl;
		//if (strcmp(typeOfTransaction, "TRANSFER") == 0)
		//	cout << "Targeted card: " << targetCard << endl;
		//cout << "Date of transcation: " << dateOftransction << endl;
		cout << "=============================" << endl;
		recorded[putIntoRecord] = curr->info;
		char testResult[255];
		recorded[putIntoRecord].getAccountNumber(testResult);
		cout << "Test accountNumber : " << testResult << endl;
		cout << "=============================" << endl;
		putIntoRecord++;
	}
	putIntoRecord = rowCount - 2;
	cout << "RECORDED INFORMATION " << endl;
	for (;putIntoRecord >= 0;putIntoRecord--)
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
			if (rc != SQLITE_OK) {
				fprintf(stderr, "%s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
			}
		rc = sqlite3_step(stmt);
		rc = sqlite3_reset(stmt);
	}
	stack.~linkedStack();
	rc = sqlite3_close(db);
}

void Project2::cancelWithdrawalOrDeposit(string accountNumber, float amount, string typeOfTransaction) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *stmt = NULL;
	string query = "SELECT balance FROM customerList WHERE account_number ='" + accountNumber + "'";
	rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	float existingBalance = 0;
	existingBalance = float(sqlite3_column_double(stmt, 0));
	rc = sqlite3_reset(stmt);
	stmt = NULL;

	float changedBalance;
	if(typeOfTransaction.compare("WITHDRAWAL") == 0)
		changedBalance = existingBalance + amount;
	else
		changedBalance = existingBalance - amount;
		String^ convertToString = changedBalance.ToString();
		string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
		string query2 = "UPDATE customerList SET balance = " + amountInString + " WHERE account_number ='" + accountNumber + "'";
		rc = sqlite3_prepare_v2(db, query2.c_str(), -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "%s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
		}
		rc = sqlite3_step(stmt);
		rc = sqlite3_finalize(stmt);
		sqlite3_close(db);

}
void Project2::revokeTransfer(string accountNumber, string recepientNumber, float amount) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *stmt = NULL;
	string query = "SELECT balance FROM customerList WHERE account_number ='" + accountNumber + "'";
	rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	float existingBalance = 0;
	existingBalance = float(sqlite3_column_double(stmt, 0));
	rc = sqlite3_reset(stmt);
	stmt = NULL;

	float newBalanceForSender;


	newBalanceForSender = existingBalance + amount;

	//newBalanceForRecepient = existingBalance - amount;
	String^ convertToString = newBalanceForSender.ToString();
	string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
	string query2 = "UPDATE customerList SET balance = " + amountInString + " WHERE account_number ='" + accountNumber + "'";
	rc = sqlite3_prepare_v2(db, query2.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_reset(stmt);

	string query3 = "SELECT balance FROM customerList WHERE account_number ='" + recepientNumber + "'";
	rc = sqlite3_prepare_v2(db, query3.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	existingBalance = float(sqlite3_column_double(stmt, 0));
	rc = sqlite3_reset(stmt);
	stmt = NULL;

	float newBalanceForRecepient;
	newBalanceForRecepient = existingBalance - amount;
	convertToString = newBalanceForRecepient.ToString();
	amountInString = msclr::interop::marshal_as<std::string>(convertToString);
	string query4 = "UPDATE customerList SET balance = " + amountInString + " WHERE account_number ='" + recepientNumber + "'";
	rc = sqlite3_prepare_v2(db, query4.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);	
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
}