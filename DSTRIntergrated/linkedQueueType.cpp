#include "linkedQueueType.h"
#include <cassert>

using namespace std;

linkedQueueType::linkedQueueType()
{
	queueFront = NULL; //set front to null
	queueRear = NULL; //set rear to null
} //end default constructor
linkedQueueType::~linkedQueueType()
{
	node * curr = queueFront;
	while (queueFront)
	{
		curr = queueFront->link;
		delete queueFront;
		queueFront = curr;

	}
	queueFront = queueRear = NULL;
} //end default deconstructor

bool linkedQueueType::isEmptyQueue() const {
	return (queueFront == NULL);
}


void linkedQueueType::addQueue(customerInfo& newElement)
{
	node *newNode;
	newNode = new node; //create the node
	/*char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";

	int cardVerificationCode;
	newElement.getAddress(address);
	newNode->info.setAddress(address);
	float bal = 0;
	bal = newElement.getBalance();
	newNode->info.setBalance(bal);

	cardVerificationCode = newElement.getCardVerificationCode();
	newNode->info.setCardVerificationCode(cardVerificationCode);

	newElement.getAccountNumber(accountNumber);
	newNode->info.setAccountNumber(accountNumber);
	newElement.getDateOfBirth(dateOfBirth);
	newNode->info.setDateOfBirth(dateOfBirth);

	newElement.getExpiryDate(expiryDate);
	newNode->info.setExpiryDate(expiryDate);

	newElement.getFirstName(firstName);
	newNode->info.setFirstName(firstName);

	newElement.getLastName(lastName);
	newNode->info.setLastName(lastName);*/
	newNode->info = newElement;
	newNode->link = NULL; //initialize the link field to NULL

	if (queueFront == NULL) //if initially the queue is empty
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else //add newNode at the end
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}

} //end addQueue
customerInfo linkedQueueType::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
} //end front

customerInfo linkedQueueType::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
} //end front

void linkedQueueType::deQueue()
{
	node *temp;
	if (!isEmptyQueue())
	{
		temp = queueFront; //make temp point to the
						   //first node
		queueFront = queueFront->link; //advance queueFront
		delete temp; //delete the first node
		if (queueFront == NULL) //if after deletion the
			queueRear = NULL; //set queueRear to NULL
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
} //end deQueue

bool linkedQueueType::checkDuplicateAccountNumber(const char * recepient) const{
	/*node* tempFrontNode = NULL;
	node* tempBackNode = NULL;*/
	node * tempFrontNode = queueFront;
	cout << "Data in the queue: " << endl << endl;
	if (isEmptyQueue())
		cout << "NOTHING INSIDE";
	else {
		for (tempFrontNode; tempFrontNode; tempFrontNode = tempFrontNode->link)
		{
			char accountNumber[255];
			//we can use << on data object because we overload << in the data class
			tempFrontNode->info.getAccountNumber(accountNumber);
			if (strcmp(accountNumber, recepient) == 0) {
				return true;
			}
			//if (tempFrontNode == NULL) //if initially the queue is empty
			//{
			//	tempFrontNode = queueFront;
			//	tempBackNode = queueFront;
			//}
			//else //add newNode at the end
			//{
			//	tempBackNode->link = queueFront;
			//	tempBackNode = tempBackNode->link;
			//}

		}
		//queueFront = tempFrontNode;
		//queueRear = tempBackNode;
	}
	return false;
}

node * linkedQueueType::getQueue() {
	return queueFront;
}

node * linkedQueueType::getBackQueue() {
	return queueRear;
}

node * linkedQueueType::findRelevantInformation(const char * keyword, const char * targetType) const {
	node * results = NULL;
	node *tempFront = queueFront;
	if (isEmptyQueue()) {
		cout << "NOTHING INSIDE";
		return results;
	}
	else {
		for (tempFront; tempFront != NULL; tempFront = tempFront->link)
		{
			bool verdict = false;
			char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
			int cardVerificationCode;
			float balance;
			//we can use << on data object because we overload << in the data class
			tempFront->info.getAccountNumber(accountNumber);
			tempFront->info.getExpiryDate(expiryDate);
			tempFront->info.getFirstName(firstName);
			tempFront->info.getLastName(lastName);
			tempFront->info.getDateOfBirth(dateOfBirth);
			tempFront->info.getAddress(address);
			balance = tempFront->info.getBalance();
			cardVerificationCode = tempFront->info.getCardVerificationCode();

			if (strcmp(accountNumber, keyword) == 0 && strcmp(targetType, "account_number") == 0)
				verdict = true;
			else if (strcmp(expiryDate, keyword) == 0 && strcmp(targetType, "expiry_date") == 0)
				verdict = true;
			else if (strcmp(firstName, keyword) == 0 && strcmp(targetType, "first_name") == 0)
				verdict = true;
			else if (strcmp(lastName, keyword) == 0 && strcmp(targetType, "last_name") == 0)
				verdict = true;
			else if (strcmp(dateOfBirth, keyword) == 0 && strcmp(targetType, "date_of_birth") == 0)
				verdict = true;
			else if (strcmp(address, keyword) == 0 && strcmp(targetType, "address") == 0)
				verdict = true;
			else if (cardVerificationCode == atoi(keyword) && strcmp(targetType, "card_ver_code") == 0)
				verdict = true;
			node * curr;
			curr = new node;
			if (verdict) {
				
				curr->info = tempFront->info;
				curr->link = NULL;
				if (results == NULL) //if initially the queue is empty
				{
					results = curr;
				}
				else //add newNode at the end
				{
					results->link = curr;
				}
			}
			//insert balance in here (OPTIONAL)-

		}
		return results;
	}
}

void linkedQueueType::modifyInformation(customerInfo& newInfo) {
	if (isEmptyQueue())
		std::cout << "NOTHING INSIDE";
	else {

		char targetedInfo[255];
		newInfo.getAccountNumber(targetedInfo);
		node* tempNode;
		for (tempNode = queueFront; tempNode != NULL; tempNode = tempNode->link)
		{
			bool verdict = false;
			char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
			int cardVerificationCode;
			float balance;
			//we can use << on data object because we overload << in the data class
			tempNode->info.getAccountNumber(accountNumber);
			tempNode->info.getExpiryDate(expiryDate);
			tempNode->info.getFirstName(firstName);
			tempNode->info.getLastName(lastName);
			tempNode->info.getDateOfBirth(dateOfBirth);
			tempNode->info.getAddress(address);
			balance = tempNode->info.getBalance();
			cardVerificationCode = tempNode->info.getCardVerificationCode();

			if (strcmp(targetedInfo, accountNumber) == 0) {
				tempNode->info = newInfo;
				break;
				
			}
		}
	}
}

bool linkedQueueType::checkForSufficientBalance(const char * sender, float amount) const{

	node* tempFrontNode = queueFront;
	std::cout << "Data in the queue: " << endl << endl;
	if (isEmptyQueue())
		std::cout << "NOTHING INSIDE";
	else {
		for (tempFrontNode; tempFrontNode; tempFrontNode = tempFrontNode->link)
		{
			char accountNumber[255];
			float balance;
			//we can use << on data object because we overload << in the data class
			queueFront->info.getAccountNumber(accountNumber);
			balance = queueFront->info.getBalance();
			if (strcmp(accountNumber, sender) == 0 && balance > amount) {
				return true;
			}
			if (strcmp(accountNumber, sender) == 0 && balance < amount) {
				return false;
			}
			//if (tempFrontNode == NULL) //if initially the queue is empty
			//{
			//	tempFrontNode = queueFront;
			//	tempBackNode = queueFront;
			//}
			//else //add newNode at the end
			//{
			//	tempBackNode->link = queueFront;
			//	tempBackNode = tempBackNode->link;
			//}

		}
		//queueFront = tempFrontNode;
		//queueRear = tempBackNode;
	}
}

void linkedQueueType::display() const
{
	node * curr;

	std::cout << "Data in the queue: " << endl << endl;
	if (isEmptyQueue())
		System::Windows::Forms::MessageBox::Show("Queue is empty");
	else {
		for (curr = queueFront; curr; curr = curr->link)
		{
			char accountNumber[255], expiryDate[255], firstName[255], lastName[255], dateOfBirth[255], address[255] = "";
			int cardVerificationCode;
			float balance;
			//we can use << on data object because we overload << in the data class
			curr->info.getAccountNumber(accountNumber);
			curr->info.getExpiryDate(expiryDate);
			curr->info.getFirstName(firstName);
			curr->info.getLastName(lastName);
			curr->info.getDateOfBirth(dateOfBirth);
			curr->info.getAddress(address);
			balance = curr->info.getBalance();
			cardVerificationCode = curr->info.getCardVerificationCode();
			std::cout << "Card number: " << accountNumber << endl
				<< "Card verification code: " << cardVerificationCode << endl
				<< "Expiry date: " << expiryDate << endl
				<< "First name: " << firstName << endl
				<< "Last name: " << lastName << endl
				<< "Date of birth: " << dateOfBirth << endl
				<< "Address: " << address << endl
				<< "Balance: " << balance << endl;
			std::cout << "=============================" << endl;
		}
	}
}
