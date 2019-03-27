#pragma once
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
//SOURCE CODE TAKEN FROM A BOOK CALLED C++ PROGRAMMING (6TH EDITION) D.S MALIK PAGE 1211
#include "transactionRecord.h"
#include "sqlite3.h"
#include <cstdlib>
struct nodeStack
{
	transactionRecord info;
	nodeStack * link;
};

class linkedStack
{
public:
	bool isEmptyStack() const;
	//Function to determine whether the stack is empty.
	//Postcondition: Returns true if the stack is empty,
	// otherwise returns false.

	void push(transactionRecord& newElement);
	//Function to add newItem to the stack.
	//Precondition: The stack exists and is not full.
	//Postcondition: The stack is changed and newItem
	// is added to the top of the stack.
	void pop();
	//Function to remove the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: The stack is changed and the top
	// element is removed from the stack

	void display() const;
	nodeStack * getStack() const;
	nodeStack * findRelevantInformation(const char * keyword, const char * targetType) const;
	bool checkIfTheRecepientIsExist(const char * recepient);
	bool checkForEnoughAmountToWithdraw(const char * ownerAccount, float amount);
	//node * findRelevantInformation(const char * keyword, const char * targetType) const;
	void modifyInformation(transactionRecord& newInfo);
	linkedStack();
	//Default constructor
	~linkedStack();
	//Destructor
private:
	nodeStack * stack; //pointer to the top of the queue
};
#endif