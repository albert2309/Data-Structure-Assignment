#include "SortCustomer.h"

using namespace std;
list<string> Project2::sortByFirstName() {
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
	rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList;", -1, &stmt, NULL);

	rc = sqlite3_step(stmt);
	list<string> unsortedFirstName;
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		unsigned char * firstName = new unsigned char[1500];
		unsigned char * lastName = new unsigned char[1500];
		const unsigned char * valChar = sqlite3_column_text(stmt, 3);
		firstName = const_cast<unsigned char *>(valChar);
		valChar = sqlite3_column_text(stmt, 4);
		lastName = const_cast<unsigned char *>(valChar);
		char fullName[200] = "";
		strcat(fullName, (char*)firstName);
		strcat(fullName, " ");
		strcat(fullName, (char*)lastName);
		string fullNameString = string(fullName);
		unsortedFirstName.push_front(fullNameString);

		rc = sqlite3_step(stmt);
	}
	unsortedFirstName.sort();
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
	return unsortedFirstName;
}

list<string> Project2::sortByLastName() {
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
	rc = sqlite3_prepare_v2(db, "SELECT * FROM customerList;", -1, &stmt, NULL);

	rc = sqlite3_step(stmt);
	list<string> unsortedFirstName;
	while (rc != SQLITE_DONE && rc != SQLITE_OK)
	{
		unsigned char * firstName = new unsigned char[1500];
		unsigned char * lastName = new unsigned char[1500];
		const unsigned char * valChar = sqlite3_column_text(stmt, 3);
		firstName = const_cast<unsigned char *>(valChar);
		valChar = sqlite3_column_text(stmt, 4);
		lastName = const_cast<unsigned char *>(valChar);
		char fullName[200] = "";
		strcat(fullName, (char*)lastName);
		strcat(fullName, " ");
		strcat(fullName, (char*)firstName);
		string fullNameString = string(fullName);
		unsortedFirstName.push_front(fullNameString);

		rc = sqlite3_step(stmt);
	}
	unsortedFirstName.sort();
	rc = sqlite3_finalize(stmt);
	sqlite3_close(db);
	return unsortedFirstName;
}