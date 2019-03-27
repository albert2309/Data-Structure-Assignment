#include "linkedStack.h"


using namespace std;

linkedStack::linkedStack()
{
	stack = NULL;
}

linkedStack::~linkedStack() {
	nodeStack * curr = stack;
	while (stack)
	{
		curr = stack->link;
		delete stack;
		stack = curr;
	}
}

void linkedStack::push(transactionRecord& newElement) {
	nodeStack *newNode;
	newNode = new nodeStack; //create the node
	newNode->info = newElement;
	newNode->link = NULL; //initialize the link field to NULL
	if (stack == NULL) {
		stack = newNode;
	}
	else {
		newNode->link = stack;
		stack = newNode;
	}

}

void linkedStack::pop() {
	nodeStack*temp; //pointer to deallocate memory
	if (stack != NULL)
	{
		{
			temp = stack; //set temp to point to the top node
			stack = stack->link; //advance stackTop to the
									   //next node
			delete temp; //delete the top node
		}
	}
	else
		System::Windows::Forms::MessageBox::Show("Stack is empty");
}

bool linkedStack::isEmptyStack() const {
	if (stack == NULL)
		return true;
	else
		return false;

}

nodeStack * linkedStack::getStack() const {
	return stack;
}

void linkedStack::display() const {
	nodeStack * curr;

	cout << "Data in the stack: " << endl << endl;
	if (isEmptyStack())
		System::Windows::Forms::MessageBox::Show("Stack is empty");
	else {
		for (curr = stack; curr; curr = curr->link)
		{
			char accountNumber[255], dateOfTransaction[255], targetCard[255], typeOfTransaction[255];
			float amount = 0;
			//we can use << on data object because we overload << in the data class
			curr->info.getAccountNumber(accountNumber);
			curr->info.getDateOfTransaction(dateOfTransaction);
			curr->info.getTargetCard(targetCard);
			curr->info.getTypeOfTransaction(typeOfTransaction);
			amount = curr->info.getAmount();

			cout << "Card number: " << accountNumber << endl
				<< "Type of transction: " << typeOfTransaction << endl
				<< "Amount: " << amount << endl
				<< "Target card: " << targetCard << endl
				<< "Date of transaction: " << dateOfTransaction << endl;
			cout << "=============================" << endl;
		}
	}
}

nodeStack * linkedStack::findRelevantInformation(const char * keyword, const char * targetType) const {
	nodeStack * results = NULL;
	nodeStack * tempFront = stack;
	if (isEmptyStack()) {
		cout << "NOTHING INSIDE";
		return results;
	}
	else {
		for (tempFront; tempFront != NULL; tempFront = tempFront->link)
		{
			bool verdict = false;
			char accountNumber[255], dateOfTransaction[255], targetAccount[255], typeOfTranscation[255] = "";
			float amount;
			//we can use << on data object because we overload << in the data class
			tempFront->info.getAccountNumber(accountNumber);
			amount = tempFront->info.getAmount();
			tempFront->info.getDateOfTransaction(dateOfTransaction);
			tempFront->info.getTargetCard(targetAccount);
			tempFront->info.getTypeOfTransaction(typeOfTranscation);

			if (strcmp(accountNumber, keyword) == 0 && strcmp(targetType, "account_number") == 0)
				verdict = true;
			else if (strcmp(dateOfTransaction, keyword) == 0 && strcmp(targetType, "date_of_transaction") == 0)
				verdict = true;
			else if (strcmp(targetAccount, keyword) == 0 && strcmp(targetType, "target_account") == 0)
				verdict = true;
			else if (strcmp(typeOfTranscation, keyword) == 0 && strcmp(targetType, "type_of_transaction") == 0)
				verdict = true;
			nodeStack * curr;
			curr = new nodeStack;
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

void linkedStack::modifyInformation(transactionRecord& newInfo) {
	if (isEmptyStack())
		std::cout << "NOTHING INSIDE";
	else {
		char targetedInfo[255], targetedDateOfTransaction[255], targetedTypeOfTransaction[255], targetedAccount[255];
		newInfo.getAccountNumber(targetedInfo);
		newInfo.getDateOfTransaction(targetedDateOfTransaction);
		newInfo.getTypeOfTransaction(targetedTypeOfTransaction);
		newInfo.getTargetCard(targetedAccount);
		nodeStack * tempNode;
		for (tempNode = stack; tempNode != NULL; tempNode = tempNode->link)
		{
			bool verdict = false;
			char accountNumber[255], dateOfTransaction[255], typeOfTransaction[255], targetCard[255];
			float balance;
			//we can use << on data object because we overload << in the data class
			tempNode->info.getAccountNumber(accountNumber);
			tempNode->info.getDateOfTransaction(dateOfTransaction);
			tempNode->info.getTypeOfTransaction(typeOfTransaction);
			tempNode->info.getTargetCard(targetCard);

			if (strcmp(targetedInfo, accountNumber) == 0 && strcmp(targetedDateOfTransaction,dateOfTransaction) == 0 && strcmp(targetedTypeOfTransaction,typeOfTransaction) == 0 && strcmp(targetCard, targetedAccount) == 0){
				tempNode->info.~transactionRecord();
				tempNode->info = newInfo;
				break;

			}
		}
	}
}