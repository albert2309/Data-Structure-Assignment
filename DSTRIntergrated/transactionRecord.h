#pragma once
#ifndef TRANSACTIONRECORD_H
#define TRANSACTIONRECORD_H
#include <iostream>

class transactionRecord {
public:
	transactionRecord();
	transactionRecord(const char * accountNumber, const char * typeOfTransaction, float amount, const char * targetCard, const char * dateOfTransaction);
	transactionRecord(transactionRecord& record);
	~transactionRecord();

	void getAccountNumber(char * accountNumber) const;
	void getTypeOfTransaction(char * typeOfTransaction) const;
	float getAmount();
	void getTargetCard(char * targetCard) const;
	void getDateOfTransaction(char * dateOfTransaction) const;

	void setAccountNumber(const char * accountNumber);
	void setTypeOfTransaction(const char * typeOfTransaction);
	void setAmount(float amount);
	void setTargetCard(const char * tarsetCard);
	void setDateOfTransaction(const char * dateOfTransaction);

	const transactionRecord& operator=(transactionRecord& student);
private:
	char * accountNumber;
	char * typeOfTransaction;
	float amount;
	char * targetCard;
	char * dateOfTransaction;
};

#endif