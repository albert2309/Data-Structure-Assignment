#include "AddCustomer.h"

void Project2::enqueue(const char * newCard, int newCardVerCode, const char * newExpiryDate, const char * newFirstName, const char * newLastName, const char * newDateOfBirth, const char * newAddress, float newBalance) {
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
	bool check = queue.checkDuplicateAccountNumber(newCard);
	if (check) {
		MessageBox::Show("Account number is a duplicate");
		rc = sqlite3_finalize(stmt);
		queue.~linkedQueueType();
		sqlite3_close(db);
		return;
	}
	else
	{
		customerInfo newCustomer(newCard, newCardVerCode, newExpiryDate, newFirstName, newLastName, newDateOfBirth, newAddress, newBalance);
		queue.addQueue(newCustomer);
	}
	//Is it okay if I use CMD to display the result?
	queue.display();

	/*rc = sqlite3_prepare_v2(db, "DROP TABLE customerList", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);
	rc = sqlite3_prepare_v2(db, "CREATE TABLE customerList (account_number VARCHAR[20] PRIMARY KEY, card_ver_code INT NOT NULL, expiry_date VARCHAR[5] NOT NULL, first_name VARCHAR[255] NOT NULL, last_name VARCHAR[255] NOT NULL, date_of_birth VARCHAR[9] NOT NULL, address VARCHAR[255] NOT NULL, balance FLOAT NOT NULL); ", -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
	rc = sqlite3_step(stmt);
	rc = sqlite3_finalize(stmt);*/

	//I decided to do for loop to do input new ones and also to double check the table
	node * curr = queue.getBackQueue();
//	for (curr = queue.getQueue(); curr; curr = curr->link)
//	{
		char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
		int cardVerificationCode;
		float balance;

		curr->info.getAccountNumber(accountNumber);
		curr->info.getExpiryDate(expiryDate);
		curr->info.getFirstName(firstName);
		curr->info.getLastName(lastName);
		curr->info.getDateOfBirth(dateOfBirth);
		curr->info.getAddress(address);
		balance = curr->info.getBalance();
		cardVerificationCode = curr->info.getCardVerificationCode();
		String^ convertToString = balance.ToString();
		string balanceInString = msclr::interop::marshal_as<std::string>(convertToString);
		 convertToString = cardVerificationCode.ToString();
		string newCardVerificationCode = msclr::interop::marshal_as<std::string>(convertToString);
		string statement = "INSERT INTO customerList VALUES('" + string(accountNumber) + "'," + newCardVerificationCode + ",'" + string(expiryDate) + "','" + string(firstName) + "','" + string(lastName) + "','" + string(dateOfBirth) + "','" + string(address) + "'," + balanceInString +");";
		rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "%s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
		}
		rc = sqlite3_step(stmt);
		rc = sqlite3_finalize(stmt);

//	}

	queue.~linkedQueueType();
	MessageBox::Show("New customer added");
	sqlite3_close(db);

}

