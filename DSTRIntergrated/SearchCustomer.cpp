#include "SearchCustomer.h"

//String^ x = searchBox->Text->ToString();
//std::string boxInput = msclr::interop::marshal_as<std::string>(x);
//std::string targetedQuery = "SELECT * FROM customerList WHERE ";
//if (this->accountRadio->Checked == true)
//targetedQuery += "account_number = '" + boxInput + "';";
//else if (this->cardVerificationRadio->Checked == true)
//targetedQuery += "card_ver_code = '" + boxInput + "';";
//else if (this->expiryRadio->Checked == true)
//targetedQuery += "expiry_date = '" + boxInput + "';";
//else if (this->firstNameRadio->Checked == true)
//targetedQuery += "first_name = '" + boxInput + "';";
//else if (this->lastNameRadio->Checked == true)
//targetedQuery += "last_name = '" + boxInput + "';";
//else if (this->dateOfBirthRadio->Checked == true)
//targetedQuery += "date_of_birth = '" + boxInput + "';";
//else if (this->addressRadio->Checked == true)
//targetedQuery += "address = '" + boxInput + "';";
//
//
//sqlite3 *db;
//int rc;
//rc = sqlite3_open("main.db", &db);
//if (rc) {
//	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//	sqlite3_close(db);
//}
//sqlite3_stmt *stmt = NULL;
//
//rc = sqlite3_prepare_v2(db, targetedQuery.c_str(), -1, &stmt, NULL);
//int colCount = sqlite3_column_count(stmt);
//rc = sqlite3_step(stmt);
//unsigned char * accountNumber = new unsigned char[1500];
//int cardVerificationCode = 0;
//unsigned char * expiryDate = new unsigned char[1500];
//unsigned char * firstName = new unsigned char[1500];
//unsigned char * lastName = new unsigned char[1500];
//unsigned char * dateOfBirth = new unsigned char[1500];
//unsigned char * address = new unsigned char[1500];
//String^ convertedCardVerification;
//String^ convertedAccountNumber;
//String^ convertedExpiryDate;
//String^ convertedFirstName;
//String^ convertedLastName;
//String^ convertedDateOfBirth;
//String^ convertedAddress;
//String^ convertedBalance;
//while (rc != SQLITE_DONE && rc != SQLITE_OK)
//{
//	float balance = 0;
//	for (int colIndex = 0; colIndex < colCount; colIndex++)
//	{
//		if (colIndex == 1) {
//			cardVerificationCode = sqlite3_column_int(stmt, colIndex);
//			convertedCardVerification = cardVerificationCode.ToString();
//		}
//		else if (colIndex == 7) {
//			balance = float(sqlite3_column_double(stmt, colIndex));
//			convertedBalance = balance.ToString();
//		}
//		else {
//			const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
//			switch (colIndex) {
//			case 0:
//			{
//				accountNumber = const_cast<unsigned char *>(valChar);
//				char * step1 = (char*)accountNumber;
//				convertedAccountNumber = gcnew String(step1);
//				break;
//			}
//			case 2:
//			{
//				expiryDate = const_cast<unsigned char *>(valChar);
//				char * step1 = (char*)expiryDate;
//				convertedExpiryDate = gcnew String(step1);
//				break;
//			}
//			case 3:
//			{
//				firstName = const_cast<unsigned char *>(valChar);
//				char * step1 = (char*)firstName;
//				convertedFirstName = gcnew String(step1);
//				break;
//			}
//			case 4:
//			{
//				lastName = const_cast<unsigned char *>(valChar);
//				char * step1 = (char*)lastName;
//				convertedLastName = gcnew String(step1);
//				break;
//			}
//			case 5:
//			{
//				dateOfBirth = const_cast<unsigned char *>(valChar);
//				char * step1 = (char*)dateOfBirth;
//				convertedDateOfBirth = gcnew String(step1);
//				break;
//			}
//			case 6:
//			{
//				address = const_cast<unsigned char *>(valChar);
//				char * step1 = (char*)address;
//				convertedAddress = gcnew String(step1);
//				break;
//			}
//			default:
//				std::cout << "SOMETHING WRONG" << std::endl;
//				break;
//			}
//		}
//	}
//	this->dataGridView1->Rows->Add(convertedAccountNumber, convertedCardVerification, convertedExpiryDate, convertedFirstName, convertedLastName, convertedDateOfBirth, convertedAddress, convertedBalance);
//	rc = sqlite3_step(stmt);
//}
//
//rc = sqlite3_finalize(stmt);
//sqlite3_close(db);