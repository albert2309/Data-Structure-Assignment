#include "transactionRecord.h"

transactionRecord::transactionRecord() : accountNumber(NULL), typeOfTransaction(NULL), targetCard(NULL), dateOfTransaction(NULL){
	amount = 0;
}

transactionRecord::transactionRecord(const char * accountNumber, const char * typeOfTransaction, float amount, const char * targetCard, const char * dateOfTransaction) : accountNumber(NULL), typeOfTransaction(NULL), targetCard(NULL), dateOfTransaction(NULL) {
	setAmount(amount);
	setAccountNumber(accountNumber);
	setTypeOfTransaction(typeOfTransaction);
	setTargetCard(targetCard);
	setDateOfTransaction(dateOfTransaction);
}

transactionRecord::~transactionRecord()
{
	if (accountNumber)
		delete[] accountNumber;
	if (typeOfTransaction)
		delete[] typeOfTransaction;
	if (targetCard)
		delete[] targetCard;
	if (dateOfTransaction)
		delete[] dateOfTransaction;
}


void transactionRecord::getAccountNumber(char * accountNumber)const
{
	strcpy(accountNumber, this->accountNumber);
}

void transactionRecord::getTypeOfTransaction(char * typeOfTransaction)const
{
	strcpy(typeOfTransaction, this->typeOfTransaction);
}

float transactionRecord::getAmount()
{
	return amount;
}

void transactionRecord::getTargetCard(char * targetCard)const
{
	strcpy(targetCard, this->targetCard);
}

void transactionRecord::getDateOfTransaction(char * dateOfTransaction)const
{
	strcpy(dateOfTransaction, this->dateOfTransaction);
}

void transactionRecord::setAccountNumber(const char * accountNumber) {
	this->accountNumber = new char[strlen(accountNumber) + 1];
	strcpy(this->accountNumber, accountNumber);
}

void transactionRecord::setTypeOfTransaction(const char * typeOfTransaction) {
	this->typeOfTransaction = new char[strlen(typeOfTransaction) + 1];
	strcpy(this->typeOfTransaction, typeOfTransaction);
}

void transactionRecord::setAmount(float amount) {	
	this->amount = amount;
}

void transactionRecord::setTargetCard(const char * targetCard) {
	this->targetCard = new char[strlen(targetCard) + 1];
	strcpy(this->targetCard, targetCard);
}

void transactionRecord::setDateOfTransaction(const char * dateOfTransaction) {
	this->dateOfTransaction = new char[strlen(dateOfTransaction) + 1];
	strcpy(this->dateOfTransaction, dateOfTransaction);
}

const transactionRecord& transactionRecord::operator=(transactionRecord& record)
{
	//if it is a self copy, don't do anything
	if (this == &record)
		return *this;
	//make current object *this a copy of the passed in student
	else
	{
		char accountNumber[255], dateOfTransaction[255], targetCard[255], typeOfTransaction[255];
		float amount = 0;
		record.getAccountNumber(accountNumber);
		record.getDateOfTransaction(dateOfTransaction);
		record.getTargetCard(targetCard);
		record.getTypeOfTransaction(typeOfTransaction);
		amount = record.getAmount();

		setAccountNumber(accountNumber);
		setDateOfTransaction(dateOfTransaction);
		setTargetCard(targetCard);
		setTypeOfTransaction(typeOfTransaction);
		setAmount(amount);
		return *this;
	}
}