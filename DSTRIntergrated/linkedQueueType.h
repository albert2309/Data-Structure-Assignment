#pragma once
#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H
//SOURCE CODE TAKEN FROM A BOOK CALLED C++ PROGRAMMING (6TH EDITION) D.S MALIK PAGE 1211
#include "customerInfo.h"
#include "sqlite3.h"
#include <cstdlib>
struct node
{
	customerInfo info;
	node * link;
};
class linkedQueueType
{
public:
	//Overload the assignment operator.
	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.
	customerInfo front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the first
	// element of the queue is returned.
	customerInfo back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the last
	// element of the queue is returned.
	void addQueue(customerInfo& newElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement
	// is added to the queue.
	void deQueue();
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first
	// element is removed from the queue.
	void display() const;
	node * getQueue();
	node * getBackQueue();
	bool checkForSufficientBalance(const char * sender, float amount) const;
	bool checkDuplicateAccountNumber(const char * recepient) const;
	node * findRelevantInformation(const char * keyword, const char * targetType) const;
	void modifyInformation(customerInfo& newInfo);
	linkedQueueType();
	//Default constructor

	~linkedQueueType();
	//Destructor
private:
	node * queueFront; //pointer to the front of						  //the queue
	node * queueRear; //pointer to the rear of
					  //the queued
};
#endif