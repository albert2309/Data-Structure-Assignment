#include "RecordTransaction.h"
#include "sqlite3.h"
#include "linkedQueueType.h"


bool Project2::checkAndDeductBalance(float amount, string accountNumber) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
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

	if (existingBalance < amount)
	{
		rc = sqlite3_finalize(stmt);
		stmt = NULL;
		sqlite3_close(db);
		return false;
	}
	else
	{
		rc = sqlite3_reset(stmt);
		stmt = NULL;
		float deductedBalance = existingBalance - amount;
		String^ convertToString = deductedBalance.ToString();
		string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
		string query2 = "UPDATE customerList SET balance = " + amountInString + " WHERE account_number ='" + accountNumber + "'";
		rc = sqlite3_prepare_v2(db, query2.c_str(), -1, &stmt, NULL);
		rc = sqlite3_step(stmt);
		rc = sqlite3_finalize(stmt);
		sqlite3_close(db);
		return true;
	}

	//this->accountRecepientBox->Items->AddRange(
}

void Project2::addAccount(float amount, string recepientNumber) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *stmt = NULL;
	string query = "SELECT balance FROM customerList WHERE account_number = '" + recepientNumber + "';";
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
	float addedBalance = existingBalance + amount;
	String^ convertToString = addedBalance.ToString();
	string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
	string query2 = "UPDATE customerList SET balance = " + amountInString + " WHERE account_number = '" + recepientNumber + "';";
	const char * final2 = query2.c_str();
	rc = sqlite3_open("main.db", &db);
	rc = sqlite3_prepare_v2(db, final2, -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
		if (rc != SQLITE_DONE)
		{
			fprintf(stderr, "2 %s\n", sqlite3_errmsg(db));
		}
		rc = sqlite3_finalize(stmt);

		sqlite3_close(db);
}

void Project2::deductBalance(float amount, string accountNumber) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	sqlite3_stmt *stmt = NULL;
	string query = "SELECT balance FROM customerList WHERE account_number = '" + accountNumber + "';";
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
	float deductedBalance = existingBalance - amount;
	String^ convertToString = deductedBalance.ToString();
	string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
	string query2 = "UPDATE customerList SET balance = " + amountInString + " WHERE account_number = '" + accountNumber + "';";
	const char * final2 = query2.c_str();
	rc = sqlite3_open("main.db", &db);
	rc = sqlite3_prepare_v2(db, final2, -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE)
	{
		fprintf(stderr, "2 %s\n", sqlite3_errmsg(db));
	}
	rc = sqlite3_finalize(stmt);

	sqlite3_close(db);
}



void Project2::push(const char * newAccount, const char * newTypeOfTranscation, float newAmount, const char * newTargetCard, const char * newDateOfTransacation) {
	//int result = validation(newAccount, newAmount, newTargetCard);
	//if (result != 0) {
	//	if(result == 3)
	//		MessageBox::Show("Sender account is not found");
	//	if (result == 2)
	//		MessageBox::Show("Recepient account is not found");
	//	if (result == 1)
	//		MessageBox::Show("Balance of the sender is insufficient");
	//	if (result == 4){
	//		MessageBox::Show("Sender account is not found");
	//		MessageBox::Show("Recepient account is not found");
	//	}
	//	return;
	//}
	//	
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}

	sqlite3_stmt *stmt = NULL;
	string query = "SELECT * FROM transactionList";
	rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
	linkedStack stack;
	rc = sqlite3_step(stmt);
	unsigned char * accountNumber = new unsigned char[255];
	float amount = 0;
	unsigned char * typeOfTransaction = new unsigned char[255];
	unsigned char * targetCard = new unsigned char[255];
	unsigned char * dateOfTranscation = new unsigned char[255];
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		int colCount = sqlite3_column_count(stmt);

		//account_number VARCHAR[16],
		//	type_of_transaction VARCHAR[10] NOT NULL,
		//	amount FLOAT NOT NULL,
		//	target_account VARCHAR[16],
		//	date_of_transaction VARCHAR[9] NOT NULL,
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
					targetCard = const_cast<unsigned char *>(valChar);
					break;
				}
				case 4:
				{
					dateOfTranscation = const_cast<unsigned char *>(valChar);
					break;
				}
				default:
					std::cout << "SOMETHING WRONG" << std::endl;
					break;
				}
			}
		}
		transactionRecord newTransaction( (char*)accountNumber,  (char*)typeOfTransaction, amount, (char *)targetCard, (char *)dateOfTranscation);
		stack.push(newTransaction);
		rc = sqlite3_step(stmt);
	}

	transactionRecord newTransaction((char*)newAccount, (char*)newTypeOfTranscation, newAmount, (char *)newTargetCard, (char *)newDateOfTransacation);
	stack.push(newTransaction);
	
	stack.display();

	nodeStack * curr = stack.getStack();
	//	for (curr = queue.getQueue(); curr; curr = curr->link)
	//	{
	char finalAccountNumber[255], finalDateOfTransaction[255], finalTargetCard[255], finalTypeOfTransaction[255];
	curr->info.getAccountNumber(finalAccountNumber);
	curr->info.getDateOfTransaction(finalDateOfTransaction);
	curr->info.getTargetCard(finalTargetCard);
	curr->info.getTypeOfTransaction(finalTypeOfTransaction);
	amount = curr->info.getAmount();
	String^ convertToString = amount.ToString();
	string amountInString = msclr::interop::marshal_as<std::string>(convertToString);
	string statement = "INSERT INTO transactionList VALUES('" + string(finalAccountNumber) + "' , '" + string(finalTypeOfTransaction) + "' , " + amountInString + " , '" + string(finalTargetCard) + "' , '" + string(finalDateOfTransaction) + "')";
	rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, NULL);
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
	stack.~linkedStack();

}




//int validation(const char * sender, float amountDesired, const char * recepient) {
//	sqlite3 *db;
//	int rc;
//	rc = sqlite3_open("main.db", &db);
//	if (rc) {
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		sqlite3_close(db);
//	}
//	sqlite3_stmt *res = NULL;
//	rc = sqlite3_step(res);
//	sqlite3_stmt *stmt = NULL;
//	rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList where ", -1, &stmt, NULL);
//	linkedQueueType queue;
//	int rowCount = 0;
//	rc = sqlite3_step(stmt);
//	while (rc != SQLITE_DONE && rc != SQLITE_OK)
//	{
//		rowCount++;
//		int colCount = sqlite3_column_count(stmt);
//		unsigned char * accountNumber = new unsigned char[1500];
//		int cardVerificationCode = 0;
//		unsigned char * expiryDate = new unsigned char[1500];
//		unsigned char * firstName = new unsigned char[1500];
//		unsigned char * lastName = new unsigned char[1500];
//		unsigned char * dateOfBirth = new unsigned char[1500];
//		unsigned char * address = new unsigned char[1500];
//		float balance = 0;
//		for (int colIndex = 0; colIndex < colCount; colIndex++)
//		{
//			if (colIndex == 1) {
//				cardVerificationCode = sqlite3_column_int(stmt, colIndex);
//			}
//			else if (colIndex == 7) {
//				balance = float(sqlite3_column_double(stmt, colIndex));
//			}
//			else {
//				const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
//				switch (colIndex) {
//				case 0:
//				{
//					accountNumber = const_cast<unsigned char *>(valChar);
//					break;
//				}
//				case 2:
//				{
//					expiryDate = const_cast<unsigned char *>(valChar);
//					break;
//				}
//				case 3:
//				{
//					firstName = const_cast<unsigned char *>(valChar);
//					break;
//				}
//				case 4:
//				{
//					lastName = const_cast<unsigned char *>(valChar);
//					break;
//				}
//				case 5:
//				{
//					dateOfBirth = const_cast<unsigned char *>(valChar);
//					break;
//				}
//				case 6:
//				{
//					address = const_cast<unsigned char *>(valChar);
//					break;
//				}
//				default:
//					std::cout << "SOMETHING WRONG" << std::endl;
//					break;
//				}
//			}
//		}
//
//		customerInfo newCustomer((char*)accountNumber, cardVerificationCode, (char*)expiryDate, (char *)firstName, (char *)lastName, (char *)dateOfBirth, (char *)address, balance);
//
//		queue.addQueue(newCustomer);
//		rc = sqlite3_step(stmt);
//	}
//	//WRITE AN ERROR FOR EACH FALSE 
//	bool check = queue.checkDuplicateAccountNumber(sender);
//	if (check) {
//		if (strcmp(recepient, "N/A") != 0) {
//			check = queue.checkDuplicateAccountNumber(recepient);
//			if (check == false)
//				return 2;
//		}
//
//		if (check) {
//			check = queue.checkForSufficientBalance(sender, amountDesired);
//			if (check)
//				return 0;
//			else
//				return 1;
//		}
//	}
//	if (strcmp(recepient, "N/A") != 0) {
//		bool checkRecepient = check = queue.checkDuplicateAccountNumber(recepient);
//		if (checkRecepient == false)
//			return 4;
//	}
//	else
//		return 3;
//}

//if return 3 = sender accout number is not found
//if return 2 = recepient accnount number is not found
//if return 1 = balance of the sender is not enough