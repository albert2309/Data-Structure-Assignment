#include "modifyInfo.h"

bool checkIfAccountNumberIsFound(std::string accountNumber) {
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("main.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}

	sqlite3_stmt *stmt = NULL;
	std::string x = "SELECT account_number FROM customerList WHERE account_number = '" + accountNumber + "';";
	rc = sqlite3_prepare_v2(db, x.c_str() , -1, &stmt, NULL);
	int colCount = sqlite3_column_count(stmt);
	rc = sqlite3_step(stmt); 
	const unsigned char * valChar = sqlite3_column_text(stmt, 0);
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
	if (valChar == NULL)
		return false;
	else
		return true;
}
