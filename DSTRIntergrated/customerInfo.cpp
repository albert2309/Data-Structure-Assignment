
#include "customerInfo.h"
#include <iostream>
#include <iomanip>
using namespace std;
/*************************
private:
char * name;
char * accountNumber;
char * dateOfBirth;
*************************/
customerInfo::customerInfo() : accountNumber(NULL), expiryDate(NULL), firstName(NULL), lastName(NULL), dateOfBirth(NULL), address(NULL)
{
	cardVerificationCode = 0;
	balance = 0;
}

customerInfo::customerInfo(const char * accountNumber, int verificationCode, const char * expiryDate, const char * firstName, const char * lastName, const char * dateOfBirth, const char * address, float balance): accountNumber(NULL), expiryDate(NULL),firstName(NULL), lastName(NULL), dateOfBirth(NULL), address(NULL)
{
	setAccountNumber(accountNumber);
	setExpiryDate(expiryDate);
	setFirstName(firstName);
	setLastName(lastName);
	setDateOfBirth(dateOfBirth);
	setAddress(address);
	setCardVerificationCode(verificationCode);
	setBalance(balance);
}

customerInfo::customerInfo(customerInfo& customer):accountNumber(NULL), expiryDate(NULL), firstName(NULL), lastName(NULL), dateOfBirth(NULL), address(NULL)
{
	char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
	int cardVerificationCode;
	float balance;
	//we can use << on data object because we overload << in the data class
	customer.getAccountNumber(accountNumber);
	customer.getExpiryDate(expiryDate);
	customer.getFirstName(firstName);
	customer.getLastName(lastName);
	customer.getDateOfBirth(dateOfBirth);
	customer.getAddress(address);
	balance = customer.getBalance();
	cardVerificationCode = customer.getCardVerificationCode();

	this->accountNumber = accountNumber;
	this->expiryDate = expiryDate;
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	this->cardVerificationCode = cardVerificationCode;
	this->balance = balance;

}


customerInfo::~customerInfo()
{
	if (accountNumber)
		delete[] accountNumber;
	if (dateOfBirth)
		delete[] dateOfBirth;
	if (firstName)
		delete[] firstName;
	if (lastName)
		delete[] lastName;
	if (expiryDate)
		delete[] expiryDate;
	if (address)
		delete[] address;
	}

void customerInfo::getAddress(char * address)const
{
	strcpy(address, this->address);
}

float customerInfo::getBalance()
{
	return this->balance;
}

int customerInfo::getCardVerificationCode()
{
	return this->cardVerificationCode;
}

void customerInfo::getAccountNumber(char * accountNumber)const
{
	strcpy(accountNumber, this->accountNumber);
}

void customerInfo::getDateOfBirth(char * dateOfBirth) const
{
	strcpy(dateOfBirth, this->dateOfBirth);
}

void customerInfo::getExpiryDate(char * expiryDate)const
{
	strcpy(expiryDate, this->expiryDate);
}

void customerInfo::getFirstName(char * firstName)const
{
	strcpy(firstName, this->firstName);
}

void customerInfo::getLastName(char * lastName)const
{
	strcpy(lastName, this->lastName);
}


void customerInfo::setFirstName(const char * newFirstName)
{
	firstName = new char[strlen(newFirstName) + 1];
	strcpy(firstName, newFirstName);
}

void customerInfo::setLastName(const char * newLastName)
{
	lastName = new char[strlen(newLastName) + 1];
	strcpy(lastName, newLastName);
}

void customerInfo::setExpiryDate(const char * newExpiry)
{
	expiryDate = new char[strlen(newExpiry) + 1];
	strcpy(expiryDate, newExpiry);
}

void customerInfo::setAddress(const char * newAddress)
{
	address = new char[strlen(newAddress) + 1];
	strcpy(address, newAddress);
}

void customerInfo::setAccountNumber(const char * newaccountNumber)
{
	//release the exisisting memory if there is any
	//if (this->accountNumber)
	//	delete[] this->accountNumber;

	//set new Id
	this->accountNumber = new char[strlen(newaccountNumber) + 1];
	strcpy(this->accountNumber, newaccountNumber);
}

void customerInfo::setDateOfBirth(const char * newDateOfBirth)
{
	//release the exisisting memory if there is any
	//if (this->dateOfBirth)
	//delete[] this->dateOfBirth;

	//set new Id
	this->dateOfBirth = new char[strlen(newDateOfBirth) + 1];
	strcpy(this->dateOfBirth, newDateOfBirth);
}

void customerInfo::setCardVerificationCode(int newCode) {
	cardVerificationCode = newCode;
}

void customerInfo::setBalance(float newBalance) {
	balance = newBalance;
}

//ostream& operator<< (ostream& out, const customerInfo& customer)
//{
//	out << setw(20) << customer.name << setw(15) << customer.accountNumber << setw(5) << customer.dateOfBirth;
//	return out;
//}

const customerInfo& customerInfo::operator=(customerInfo& customer)
{
	//if it is a self copy, don't do anything
	if (this == &customer)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
		int cardVerificationCode = 0;
		float balance = 0;
		//we can use << on data object because we overload << in the data class
		customer.getAccountNumber(accountNumber);
		customer.getExpiryDate(expiryDate);
		customer.getFirstName(firstName);
		customer.getLastName(lastName);
		customer.getDateOfBirth(dateOfBirth);
		customer.getAddress(address);
		balance = customer.getBalance();
		cardVerificationCode = customer.getCardVerificationCode();
		setAccountNumber(accountNumber);
		setCardVerificationCode(cardVerificationCode);
		setExpiryDate(expiryDate);
		setFirstName(firstName);
		setLastName(lastName);
		setDateOfBirth(dateOfBirth);
		setAddress(address);
		setBalance(balance);
		return *this;
	}
}
