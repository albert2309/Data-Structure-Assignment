
#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
#include <iostream>
#include <string>
using namespace std;
class customerInfo
{
public:

	customerInfo();
	customerInfo(const char * accountNumber,int verificationCode,const char * expiryDate, const char * firstName, const char * lastName, const char * dateOfBirth, const char * address, float balance);
	customerInfo(customerInfo& account);		//copy constructor: make current object a copy of "student"
	~customerInfo();						//destructor: release the dynamically allocated memory	

	void getAccountNumber(char * accountNumber) const;
	int  getCardVerificationCode();
	void getExpiryDate(char * expiryDate) const;
	void getFirstName(char * firstName) const;
	void getLastName(char * lastName) const;
	void getDateOfBirth(char * dateOfBirth) const;
	void getAddress(char * address) const;
	float getBalance();

	void setAccountNumber(const char * newaccountNumber);
	void setCardVerificationCode(int newCode);
	void setDateOfBirth(const char * newDateOfBirth);
	void setFirstName( const char * newFirstName);
	void setLastName(const char * newLastName);
	void setAddress(const char * address);
	void setBalance(float newBalance);
	void setExpiryDate(const char *newExpiry);
	const customerInfo& operator=(customerInfo& student);
private:
	char * accountNumber;
	int cardVerificationCode;
	char * expiryDate;
	char * firstName;
	char * lastName;
	char * dateOfBirth;
	char * address;
	float balance;
};

#endif