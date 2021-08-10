#include <iostream>
using namespace std;

template <class T>
class SingleList
{
public:
	SingleList()
	{

	}
	SingleList(T num, SingleList<T> *p1)
	{
		value = num;
		next = p1;
	}
	T value;
	SingleList<T> *next;
};

template <class T>
class SingleLinkedList                        //a list of SingleLists
{                   
public:
	SingleList<T> *head;//pointer to first SingleList

	SingleLinkedList()                      //no-argument constructor
	{
		head = NULL;
	}            //no first SingleList
	void addAtHead(T d);            //add data item (one SingleList)
	void addAtTail(T d);
	void addAtSpecificLocation(T d);
	void deleteAtHead();
	void deleteAtTail();
	void deleteAtSpecificLocation();
	void Search(T d);
	void SingleListedListOptions();
	void display();                 //display all SingleLists
	int countlist(void)
	{
		SingleList<T> *count;
		count = head;
		int i = 1;
		while (head->next)
		{
			i++;
			count = count->next;
		}
		return i;
	}
};
template <class T>
void SingleLinkedList<T>::addAtTail(T d)         //add data item
{
	SingleList<T>* nodePtr;
	SingleList<T> *newNode = new SingleList < T >;
	newNode->value = d;
	newNode->next = NULL;
	//insert at head of SingleList list
	if (!head)
	{
		head = newNode;
	}
	else {
		nodePtr = head;
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}
	//newNode->next = NULL;
}

template <class T>
void SingleLinkedList<T>::addAtHead(T d)         //add data item
{
	SingleList<T> *newNode = new SingleList<T>;
	newNode->value = d;
	//insert at head of SingleList list
	newNode->next = head;
	head = newNode;
}
template <class T>
void SingleLinkedList<T>::addAtSpecificLocation(T d)         //add data item
{
	int i = 0, pos = 0;
	SingleList<T>* cur = new SingleList<T>;
	SingleList<T>* pre = new SingleList<T>;
	SingleList<T> *temp = new SingleList < T >;
	cur = head;
	cout << "Enter the position where node has to be inserted: ";
	cin >> pos;
	if (pos == 0)
	{
		cout << "Invalid Location entered." << endl;
	}
	else if (pos == 1)
	{
		addAtHead(d);
	}
	else
	{
		for(int i = 0; i < (pos - 1); i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->value = d;
		pre->next = temp;
		temp->next = cur;
	}
}

template <class T>
void SingleLinkedList<T>::deleteAtSpecificLocation()         //add data item
{
	
	if (!head) {
		cout << "Link list is empty.\n";
	}
	else {
		int location;
		cout << "Enter the location where you want to delete: ";
		cin >> location;
		cout << "Before Deletion: ";
		display();
		SingleList<T> *pr1 = new SingleList < T >;
		SingleList<T> *pr2 = new SingleList < T >;
		SingleList<T> *temp = new SingleList < T >;
		if (!head) {
			return;
		}
		
		if (location == 0)
		{
			cout << "List is Empty." << endl;
		}
		if (location == 1) {
			if (head->next == NULL) {
				delete head;
				return;
			}
			pr1 = head->next;
			delete head;
			head = pr1;
		}
		else {
			pr1 = head;
			pr2 = NULL;
			temp = NULL;
			int i = 0;
			while ((pr1 != NULL) && (i < location)) {
				temp = pr2;
				pr2 = pr1;
				pr1 = pr1->next;
				i++;
			}
			if (pr1 == NULL) {
				temp->next = NULL;
				delete pr2;
			}
			else {
				temp->next = pr1;
				delete pr2;
			}
			cout << "After Deletion: ";
			display();
			cout << endl;
		}
	}
}

template <class T>
void SingleLinkedList<T>::display()              //display all SingleLists
{
	if (head == NULL)
	{
		cout << "The List is empty." << endl;
		return;
	}
	else {
		SingleList<T>* ptrNext = head;             //set ptr to first SingleList
		while (ptrNext != NULL)          //traverse until last ptr is reached
		{
			cout << ptrNext->value << " ";  //print data
			ptrNext = ptrNext->next;        //move to next SingleList
		}
		cout << endl;
	}
}
template <class T>
void SingleLinkedList<T>::deleteAtHead()
{
	cout << "Before Deletion: ";
	display();
	SingleList<T>* nodePtr;
	// If the list is empty, do nothing.
	if (!head)
	{
		cout << "List is Empty.\n";
		return;
	}
	// Determine if the first node is the one.
	if (head->value) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		cout << "After Deletion: ";
		display();
		cout << endl;
	}
}

template <class T>
void SingleLinkedList<T>::deleteAtTail()
{
	
	if (!head)
	{
		cout << "Link list is empty.\n";
		return;
	}
	else {
		cout << "Before Deletion: ";
		display();
		SingleList<T>  *temp = new SingleList < T >;
		SingleList<T> *previousNode = new SingleList < T >;
		SingleList<T> *nodePtr = new SingleList < T >;
		nodePtr = head;
		temp = NULL;
		previousNode = NULL;
		while (nodePtr != NULL)
		{
			temp = previousNode;
			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}
		temp->next = NULL;
		delete nodePtr;

		cout << "After Deletion: ";
		display();
		cout << endl;
		// SingleList the previous node to the node after nodePtr, then delete nodePtr.
	}
}
template <class T>
void SingleLinkedList<T>::Search(T x)
{
	SingleList<T>* temp = new SingleList<T>;
	temp = head;
	int count = 1, flag = 0;

	if (temp == NULL)
	{
		cout << "Link list is empty." << endl;
	}
	else
	{
		cout << "\nThe location of " << x << " : ";
		while (temp != NULL)
		{
			if (temp->value == x)
			{
				cout << count << " ";
				flag = 1;
			}
			temp = temp->next;
			count++;
		}
	}
	if (flag == 0 && head != NULL)
	{
		cout << "Value not found." << endl;
	}
	cout << endl;
}
template <class T>
void SingleLinkedList<T>::SingleListedListOptions()
{
	int choice, choice2;
	T value;
	char ch, b = '0';
	SingleLinkedList<T> lint;       //make SingleListed list
	while (1) {
		choice = InsertionAndDeletion();

		while (1) {
			if (choice == 4)
			{
				lint.deleteAtHead();
				break;
			}
			else if (choice == 5)
			{
				lint.deleteAtTail();
				break;
			}
			else if (choice == 6)
			{
				lint.deleteAtSpecificLocation();
				break;
			}
			else if (choice == 8)
			{
				cout << " The list is:";
				lint.display();
				break;
			}

			else if (choice == 1)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.addAtHead(value);
				break;
			}
			else if (choice == 2)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.addAtTail(value);
				break;
			}
			else if (choice == 3)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.addAtSpecificLocation(value);
				break;
			}
			else if (choice == 7)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.Search(value);
				break;
			}
		}
		cout << "1-Exit\n2-Return to previous Menu\n";
		cin >> choice2;
		if (choice2 == 1)
		{
			cout << "Thank you for having our service :)\n";
			break;
		}
		else
			continue;
	}
}
//Main screen for singly list
void mainScreen()
{
	int choice, choice2;
	cout << "Enter the type of SingleListed list:\n1-Integer        2-Float        3-Long        4-Char\n ";
	cin >> choice;
	if (choice == 1)
	{
		SingleLinkedList<int> lint;
		lint.SingleListedListOptions();
	}
	else if (choice == 2)
	{
		SingleLinkedList<float> list;
		list.SingleListedListOptions();
	}
	else if (choice == 3)
	{
		SingleLinkedList<long> list;
		list.SingleListedListOptions();
	}
	else if (choice == 4)
	{
		SingleLinkedList<char> list;
		list.SingleListedListOptions();
	}
}
int InsertionAndDeletion()
{
	int choice2;
	cout << "Select the function you want to perform: \n";
	cout << "1-Insert at Head   2-Insert at tail  3-Insert at specific Location  \n4-Delete at start  5-Delete at end   6-Delete at specific location  7-Search  8-Display List\n";
	cin >> choice2;
	return choice2;
}
template <typename T>
class DListNode {
public:
	DListNode() {
		next = NULL;
	}
	DListNode(int n, DListNode *ptr1, DListNode *ptr2) {
		value = n;
		next = ptr1;
		prev = ptr2;
	}
	int value;
	DListNode *next, *prev;
};
//Doubly Linked List
template <class T>
class DoubleLinkedList                        //a list of SingleLists
{
private:
	DListNode<T>* head;                    //pointer to first DoubleList
	DListNode<T>* tail;
public:
	DoubleLinkedList()                      //no-argument constructor
	{
		head = NULL;
	}            //no first SingleList
	void addAtHead(T d);            //add data item (one SingleList)
	void addAtTail(T d);
	void addAtSpecificLocation(T d);
	void deleteAtHead();
	void deleteAtTail();
	void deleteAtSpecificLocation();
	void Search(T d);
	void DoubleLinkedListOptions();
	void display();                 //display all SingleLists


};
template <class T>
void DoubleLinkedList<T>::addAtHead(T d)         //add data item
{
	DListNode<T> *newNode = new DListNode < T >;
	newNode->value = d;
	if (!head)
	{
		head = newNode;
	}
	else {

		newNode->next = head;
		head = newNode;
		head->prev = newNode;
	}
}

template <class T>
void DoubleLinkedList<T>::Search(T d)
{
	DListNode<T>* temp = new DListNode<T>;
	temp = head;
	int count = 1, flag = 0;

	if (temp == NULL)
	{
		cout << "Link list is empty." << endl;
	}
	else
	{
		cout << "\nThe location of " << d << " : ";
		while (temp != NULL)
		{
			if (temp->value == d)
			{
				cout << count << " ";
				flag = 1;
			}
			temp = temp->next;
			count++;
		}
	}
	if (flag == 0 && head != NULL)
	{
		cout << "Value not found." << endl;
	}
	cout << endl;
}
template <class T>
void DoubleLinkedList<T>::display()
{
	if (head == NULL)
	{
		cout << "The List is empty." << endl;
		return;
	}
	else {
		
		DListNode<T>* ptrNext = head;             //set ptr to first SingleList
		while (ptrNext != NULL)          //traverse until last ptr is reached
		{
			cout << ptrNext->value << " ";  //print data
			ptrNext = ptrNext->next;        //move to next SingleList
		}
		cout << endl;
	}
}
template <class T>
void DoubleLinkedList<T>::addAtTail(T d)
{
	DListNode<T> *nodePtr1 = new DListNode < T >;
	DListNode<T> *nodePtr2 = new DListNode < T >;
	nodePtr1 = head;
	if (head == NULL) {
		addAtHead(d);
	}
	else {
		while (nodePtr1->next != NULL) {
			nodePtr1 = nodePtr1->next;
		}
		nodePtr2->value = d;
		nodePtr1->next = nodePtr2;
		nodePtr2->next = NULL;
		nodePtr2->prev = nodePtr1;
		tail = nodePtr2;
	}

}
template <class T>
void DoubleLinkedList<T>::addAtSpecificLocation(T d)
{
	int l;
	DListNode<T> *ptr1 = new DListNode < T >;
	DListNode<T> *ptr2 = new DListNode < T >;
	DListNode<T> *ptr = new DListNode < T >;
	cout << "Enter the position where node has to be inserted: ";
	cin >> l;
	ptr1 = head;
	if (l == 0) {
		return;
	}
	else if (l == 1) {
		addAtHead(d);
	}
	else {
		int i = 0;
		while (i < (l - 1)) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
			i++;
		}
		ptr->value = d;
		ptr2->next = ptr;
		ptr->prev = ptr2;
		if (ptr1 == NULL) {
			ptr->next = NULL;
			tail = ptr;
		}
		else {
			ptr->next = ptr1;
			ptr1->prev = ptr;
		}
	}
}
template <class T>
void DoubleLinkedList<T>::deleteAtHead()
{
	if (!head) {
		cout << "List is empty.\n";
	}
	else {
		cout << "Before Deletion: ";
		display();
		if (head->next == NULL) {
			delete head;
			return;
		}
		head = head->next;
		delete head->prev;
		cout << "After Deletion: ";
		display();
		cout << endl;
	}

}
template <class T>
void DoubleLinkedList<T>::deleteAtTail()
{
	if (!head) {
		cout << "List is empty.\n";
	}
	else {
		cout << "Before Deletion: ";
		display();
		DListNode<T> *ptr1 = new DListNode < T >;
		DListNode<T> *ptr2 = new DListNode < T >;
		DListNode<T> *temp = new DListNode < T >;
		ptr1 = head;
		ptr2 = NULL;
		while (ptr1->next != NULL) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
		delete ptr1;
		tail = ptr2;
		cout << "After Deletion: ";
		display();
		cout << endl;
	}
}
template <class T>
void DoubleLinkedList<T>::deleteAtSpecificLocation()
{
	int l;
	if (!head) {
		cout << "No element in the list.\n";
	}
	else {
		cout << "Please enter the location where you want to delete: ";
		cin >> l;
		cout << "Before Deletion: ";
		display();
		DListNode<T> *ptr1 = new DListNode < T >;
		DListNode<T> *ptr2 = new DListNode < T >;
		DListNode<T> *temp = new DListNode < T >;
		
		if (l == 1) {
			if (head->next == NULL) {
				delete head;
				return;
			}
			head = head->next;
			delete head->prev;
		}
		else 
		{
			ptr1 = head;
			ptr2 = NULL;
			temp = NULL;
			int i = 0;
			while ((ptr1 != NULL) && (i < l)) {
				temp = ptr2;
				ptr2 = ptr1;
				ptr1 = ptr1->next;
				i++;
			}
			if (ptr1 == NULL) {
				temp->next = NULL;
				delete ptr2;
			}
			else {
				temp->next = ptr1;
				ptr1->prev = temp;
				delete ptr2;
			}
			cout << "After Deletion: ";
			display();
			cout << endl;
		}
	}
}
template <class T>
void DoubleLinkedList<T>::DoubleLinkedListOptions()
{
	int choice, choice2;
	T value;
	char ch, b = '0';
	DoubleLinkedList<T> lint;       //make SingleListed list
	while (1) {
		choice = InsertionAndDeletion();

		while (1) {
			if (choice == 4)
			{
				lint.deleteAtHead();
				break;
			}
			else if (choice == 5)
			{
				lint.deleteAtTail();
				break;
			}
			else if (choice == 6)
			{
				lint.deleteAtSpecificLocation();
				break;
			}
			else if (choice == 8)
			{
				cout << "The list is: " << endl;
				lint.display();
				break;
			}
			else if (choice == 1)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.addAtHead(value);
				break;
			}
			else if (choice == 2)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.addAtTail(value);
				break;
			}
			else if (choice == 3)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.addAtSpecificLocation(value);
				break;
			}
			else if (choice == 7)
			{
				cout << "Please enter the number:";
				cin >> value;
				lint.Search(value);
				break;
			}
		    else if (choice == 8)
			{
				cout << "The list is:\n";
				lint.display();
				break;
			}
		}
		cout << "1-Exit\n2-Return to previous Menu\n";
		cin >> choice2;
		if (choice2 == 1)
		{
			cout << "Thank you for having our service :)\n";
			break;
		}
		else
			continue;
	}
}
void DoublyMainScreen()
{
	int choice, choice2;
	cout << "Enter the type of SingleListed list:\n1- Integer        2-Float        3-Long        4-Char\n ";
	cin >> choice;
	if (choice == 1)
	{
		DoubleLinkedList<int> lint;
		lint.DoubleLinkedListOptions();
	}
	else if (choice == 2)
	{
		DoubleLinkedList<int> lint;
		lint.DoubleLinkedListOptions();
	}
	else if (choice == 3)
	{
		DoubleLinkedList<int> lint;
		lint.DoubleLinkedListOptions();
	}
	else if (choice == 4)
	{
		DoubleLinkedList<int> lint;
		lint.DoubleLinkedListOptions();
	}
}
//--------------------------------------------------------------------//
//Singly Circular----------------------------------------------------//

template <typename T>
class SCnode {
public:
	SCnode() {
		next = NULL;
	}
	SCnode(T n, SCnode *nodePtr) {
		value = n;
		next = nodePtr;
	}
	T value;
	SCnode *next;
};

template <class T>
class SingleCircularList {
public:
	SCnode<T> *tail;
	SingleCircularList() {
		tail = NULL;
	}
	void displayCircularList() {
		SCnode<T> *nodePtr = new SCnode < T >;
		nodePtr = tail->next;
		if (tail->next == NULL)
		{
			cout << "The List is empty." << endl;
			return;
		}
			do {
				cout << nodePtr->value << " ";
				nodePtr = nodePtr->next;
			} while (nodePtr != tail->next);
			cout << endl;
	}
	void insertAtHead(T n) {
		SCnode<T> *newNode = new SCnode < T >;
		newNode->value = n;
		if (!tail) {
			tail = newNode;
			newNode->next = newNode;
			return;
		}
		else {
			newNode->next = tail->next;
			tail->next = newNode;
		}
	}

	void insertAtLocation(int l, T n) {
		SCnode<T> *ptr1 = new SCnode < T >;
		SCnode<T> *ptr2 = new SCnode < T >;
		SCnode<T> *ptr3 = new SCnode < T >;
		if (l == 0) {
			return;
		}
		else if (l == 1) {
			insertAtHead(n);
		}
		else {
			ptr1 = tail->next;
			int i = 0;
			while (i < (l - 1)) {
				ptr2 = ptr1;
				ptr1 = ptr1->next;
				i++;
			}
			ptr3->value = n;
			ptr2->next = ptr3;
			ptr3->next = ptr1;
			if (tail == ptr2) {
				tail = ptr3;
			}
		}

	}

	void insertAtEnd(T n) {
		SCnode<T> *nodePtr = new SCnode < T >;
		if (!tail)
			insertAtHead(n);
		else {
			nodePtr->value = n;
			nodePtr->next = tail->next;
			tail->next = nodePtr;
			tail = nodePtr;
		}
	}

	void deleteFromHead() {
		SCnode<T> *nodePtr = new SCnode < T >;
		SCnode<T> *ptr2 = new SCnode < T >;
		nodePtr = tail;
		if (!tail) {
			cout << "No element in the list.\n";
		}
		else if (nodePtr == nodePtr->next) {
			delete tail;
			tail = NULL;
		}
		else if (tail == tail->next->next) {
			nodePtr = tail->next;
			delete nodePtr;
			tail->next = tail;
		}
		else {
			ptr2 = nodePtr->next;
			nodePtr->next = ptr2->next;
			delete ptr2;
		}
	}

	void deleteFromLocation(int l) {
		if (!tail) {
			cout << "No element in the list.\n";
		}
		else {
			SCnode<T> *ptr1 = new SCnode < T >;
			SCnode<T> *ptr2 = new SCnode < T >;
			SCnode<T> *temp = new SCnode < T >;
			int i = 0;
			ptr1 = tail->next;
			if (!tail) {
				cout << "No element in the list\n";
			}
			else if ((tail == tail->next) && (l == 1)) {
				delete tail;
			}
			else if (tail == tail->next->next) {
				if (l == 1)
					deleteFromHead();
				else if (l == 2) {
					ptr1->next = ptr1;
					delete tail;
					tail = ptr1;
				}
			}
			else {
				cout << "Before Deletion: ";
				displayCircularList();
				cout << endl;
				while (i < l) {
					temp = ptr2;
					ptr2 = ptr1;
					ptr1 = ptr2->next;
					i++;
				}
				temp->next = ptr1;
				delete ptr2;
				cout << "After Deletion: ";
				displayCircularList();
				cout << endl;
			}
		}
	}

	void deleteFromEnd() {
		if (!tail) {
			cout << "No element in the list\n";
		}
		else {
			cout << "Before Deletion: ";
			displayCircularList();
			cout << endl;
			SCnode<T> *ptr1 = new SCnode < T >;
			SCnode<T> *ptr2 = new SCnode < T >;
			ptr1 = ptr2 = tail->next;

			if (tail->next == tail) {
				deleteFromHead();
			}
			else {
				while (ptr1->next != tail) {
					ptr1 = ptr1->next;
				}
				ptr1->next = ptr2;
				delete tail;
				tail = ptr1;
				cout << "After Deletion: ";
				displayCircularList();
				cout << endl;
			}
		}
	}
	void Search(T d)
	{
		SCnode<T>* temp = new SCnode<T>;
		temp = tail->next;
		int count = 1, flag = 0;

		if (temp == NULL)
		{
			cout << "Link list is empty." << endl;
		}
		else
		{
			cout << "\nThe location of " << d << " : ";
			do 
			{
				if (temp->value == d)
				{
					cout << count << " ";
					flag = 1;
				}
				temp = temp->next;
				count++;
			} while (temp != tail->next);
			
		}
		if (flag == 0 && tail->next != NULL)
		{
			cout << "Value not found." << endl;
		}
		cout << endl;
	}
	void SinglyCircularOptions()
	{
		int choice, choice2, pos;
		T value;
		char ch, b = '0';
		SingleCircularList<T> lint;       //make SingleListed list
		while (1) {
			choice = InsertionAndDeletion();

			while (1) {
				if (choice == 4)
				{
					lint.deleteFromHead();
				}
				else if (choice == 5)
				{
					lint.deleteFromEnd();
				}
				else if (choice == 6)
				{
					cout << "Please enter the location where you want to delete: ";
					cin >> pos;
					lint.deleteFromLocation(pos);
					break;
				}
				else if (choice == 8)
				{
					cout << "The list is: ";
					lint.displayCircularList();
					break;
				}
				else if (choice == 1)
				{
					cout << "Please enter the number:";
					cin >> value;
					lint.insertAtHead(value);
					break;
				}
				else if (choice == 2)
				{
					cout << "Please enter the number:";
					cin >> value;
					lint.insertAtEnd(value);
					break;
				}
				else if (choice == 3)
				{
					cout << "Enter the position where node has to be inserted: ";
					cin >> pos;
					cout << "Please enter the number:";
					cin >> value;
					lint.insertAtLocation(pos, value);
					break;
				}
				else if (choice == 7)
				{
					cout << "Please enter the number:";
					cin >> value;
					lint.Search(value);
					break;
				}
				else if (choice == 8)
				{
					cout << "The list is:\n";
					lint.displayCircularList();
					break;
				}
			}
			cout << "1-Exit\n2-Return to previous Menu\n";
			cin >> choice2;
			if (choice2 == 1)
			{
				cout << "Thank you for having our service :)\n";
				break;
			}
			else
				continue;
		}
	}


};
//Main Screen for SingleCircular List
void SCmainScreen()
{
	int choice, choice2;
	cout << "Enter the type of SingleListed list:\n1- Integer        2-Float        3-Long        4-Char\n ";
	cin >> choice;
	if (choice == 1)
	{
		SingleCircularList<int> list;
		list.SinglyCircularOptions();
	}
	else if (choice == 2)
	{
		SingleCircularList<float> list;
		list.SinglyCircularOptions();
	}
	else if (choice == 3)
	{
		SingleCircularList<long> list;
		list.SinglyCircularOptions();
	}
	else if (choice == 4)
	{
		SingleCircularList<char> list;
		list.SinglyCircularOptions();
	}
}


//-----------------//
//Doubly Circular  //
//-----------------//
template <typename T>
class Node
{
public:
	Node()
	{
	
	}
	Node(T num, Node<T> *p1 = 0, Node<T> *p2 = 0)
	{
		value = num;
		next = p1;
		prev = p2;
	}
	T value;
	Node<T> *next, *prev;
};
template <typename T>
class DoublyCircularll
{
public:
	Node<T> *start, *last;

	DoublyCircularll()
	{
		start = NULL;
		last = NULL;
	}
	~DoublyCircularll()
	{

	}
	int countlist(void)
	{
		Node<T> *count;
		count = start;
		int i = 1;
		while (1)
		{
			i++;
			count = count->next;
			if (count == last)
			{
				break;
			}
		}
		return i;
	}
	void displayList(void)
	{
		Node<T> *nodeptr = new Node<T>;
		nodeptr = start;
		if (start == NULL)
		{
			cout << "The List is empty." << endl;
			return;
		}
		
		while (1) {
			cout << nodeptr->value << " ";
			if (nodeptr == last)
				break;
			nodeptr = nodeptr->next;
		}
		cout << endl;
	}
	void insertAtHead(T num)
	{
		Node<T> *newnode = new Node<T>(num);
		if (start == NULL)
		{
			last = start = newnode;
			last->next = start;
			last->prev = start;
		}
		else
		{
			newnode->next = start;
			newnode->prev = last;
			last->next = start->prev = newnode;
			start = newnode;
		}
	}
	void insertatend(T num)
	{
		Node<T> *newnode = new Node<T>(num);
		if (start == NULL)
		{
			last = start = newnode;
			last->next = start;
			last->prev = start;
		}
		else
		{
			newnode->next = start;
			newnode->prev = last;
			last->next = newnode;
			start->prev = newnode;
			last = newnode;
		}
	}
	void insertAtLocation(int location, T new_value)
	{
		Node<T> value = new_value;
		Node<T> *current = new Node<T>;
		Node<T> *previous = NULL;
		Node<T> *newnode = new Node<T>(new_value, start, last);
		current = start;

		if (location == 0)
		{
			cout << "Invalid Location entered." << endl;
		}
		else if (location == 1)
		{
			insertAtHead(new_value);
		}
		else
		{
			for (int x = 0; x < (location - 1); x++)
			{
				previous = current;
				current = current->next;
			}
			current->prev = newnode;
			previous->next = newnode;
			newnode->next = current;
			newnode->prev = previous;
		}
	}
	void Deleteatstart()
	{
		cout << "Before Deletion:";
		displayList();
		Node<T> *nodeptr = new Node<T>();
		if ((start == NULL) && (last == NULL))
		{
			cout << "List is Empty!" << endl;
		}
		else
		{
			if (start == last)
			{
				delete start;
				start = last = NULL;
			}
			else
			{
				nodeptr = start;
				start = start->next;
				start->prev = last;
				last->next = start;
				delete nodeptr;
				cout << "After Deletion:";
				displayList();
			}
		}
	}
	void Deleteatlast()
	{
		cout << "Before Deletion:";
		displayList();
		Node<T> *nodeptr = new Node<T>();
		if (start == NULL && last == NULL)
		{
			cout << "List is Empty!" << endl;
		}
		else
		{
			if (start == last)
			{
				delete start;
				start = last = NULL;
			}
			else
			{
				nodeptr = last;
				last = last->prev;
				delete last;
				last->next = start;
				start->prev = last;
				
			}
		}
		cout << "After Deletion:";
		displayList();
		cout << endl;
	}
	void Deleteatspecificlocation(int pos)
	{
		Node<T> *nodeptr = new Node<T>;
		Node<T> *newnode = NULL;
		nodeptr = start;
		int x = 0;
		if (pos == 0)
		{
			cout << "Invalid position." << endl;
		}
		else if (last == start->next)
		{
			if (pos == 1)
			{
				if (start == last)
				{
					delete start;
					start = last = NULL;
				}
				else
				{
					Deleteatstart();
				}
			}
			else if (pos == 2)
			{
				nodeptr->next = nodeptr;
				nodeptr->prev = nodeptr;
				delete last;
				last = nodeptr;
			}
		}
		else if (pos == countlist())
		{
			Deleteatlast();
		}
		else
		{
			cout << "Before Deletion:";
			displayList();
			nodeptr = start;
			for (int x = 0; x < (pos - 1); x++)
			{
				newnode = nodeptr;
				nodeptr = nodeptr->next;
			}
			newnode->next = nodeptr->next;
			nodeptr->next->prev = newnode;
			delete nodeptr;
			cout << "After Deletion:";
			displayList();
			cout << endl;
		}
	}
	void Search(T d)
	{
		Node<T>* temp = new Node<T>;
		temp = start;
		int count = 1, flag = 0;

		if (temp == NULL)
		{
			cout << "Link list is empty." << endl;
		}
		else
		{
			cout << "\nThe location of " << d << " : ";
			do
			{
				if (temp->value == d)
				{
					cout << count << " ";
					flag = 1;
				}
				temp = temp->next;
				count++;
			} while (temp != start);
		}
		if (flag == 0 && start != NULL)
		{
			cout << "Value not found." << endl;
		}
		cout << endl;

	}
	void DoubleCircularOptions()
	{
		int choice, choice2, pos;
		T value;
		char ch, b = '0';
		DoublyCircularll<T> lint;
		while (1) {
			choice = InsertionAndDeletion();

			while (1) {
				if (choice == 4)
				{
					lint.Deleteatstart();
					break;
				}
				else if (choice == 5)
				{
					lint.Deleteatlast();
					break;
				}
				else if (choice == 6)
				{
					cout << "Please enter the location where you want to delete: ";
					cin >> pos;
					lint.Deleteatspecificlocation(pos);
					break;
				}
				else if (choice == 8)
				{
					cout << "The list is:";
					lint.displayList();
					break;
				}
				else if (choice == 1)
				{
					cout << "Please enter the number:";
					cin >> value;
					lint.insertAtHead(value);
					break;
				}
				else if (choice == 2)
				{
					cout << "Please enter the number:";
					cin >> value;
					lint.insertatend(value);
					break;
				}
				else if (choice == 3)
				{
					cout << "Enter the position where node has to be inserted: ";
					cin >> pos;
					cout << "Please enter the number:";
					cin >> value;
					lint.insertAtLocation(pos, value);
					break;
				}
				else if (choice == 7)
				{
					cout << "Please enter the number:";
					cin >> value;
					lint.Search(value);
					break;
				}
				else if (choice == 8)
				{
					cout << "The list is:\n";
					lint.displayList();
					break;
				}
			}
			cout << "1-Exit\n2-Return to previous Menu\n";
			cin >> choice2;
			if (choice2 == 1)
			{
				cout << "Thank you for having our service :)\n";
				break;
			}
			else
			{
				continue;
			}
		}
	}
};
void DCmainScreen()
{
	int choice, choice2;
	cout << "Enter the type of SingleListed list:\n1- Integer        2-Float        3-Long        4-Char\n ";
	cin >> choice;
	if (choice == 1)
	{

		DoublyCircularll<int> list;
		list.DoubleCircularOptions();
	}
	else if (choice == 2)
	{
		DoublyCircularll<float> list;
		list.DoubleCircularOptions();
	}
	else if (choice == 3)
	{
		DoublyCircularll<long> list;
		list.DoubleCircularOptions();
	}
	else if (choice == 4)
	{
		DoublyCircularll<char> list;
		list.DoubleCircularOptions();
	}
}


int main()  //Main begins execution
{
	int choice = 0;
	cout << "Enter the type of linked list:\n1-Singular    2-Doubly    3-SinglyCircular    4-DoublyCircular\n";
	cin >> choice;
	if (choice == 1)
		mainScreen();   //Single Linked list
	else if (choice == 2)
		DoublyMainScreen();   //Double Linked List
	else if (choice == 3)
		SCmainScreen();  //Single Circular List
	else if (choice == 4)
		DCmainScreen();    //Double Circular List
	system("pause");
	return 0;
}
//End main

