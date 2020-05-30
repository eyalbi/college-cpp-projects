#include "LinkList.h"

Stack::Node::Node(const Node & Other):value(Other.value)
{
	if (Other.next != NULL) {
		next = new Node(*Other.next);
	}
	else {
		next = NULL;
	}
}

void Stack::Node::PrintNode()
{
	cout << this->value;
	cout << endl;
}

Stack::~Stack()
{
	if (!IsEmpty())
	{
		Node* temp;
		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
		size = ZERO;
	}
	
}

Stack & Stack::operator+=(int value)
{
	if (IsEmpty()) {
		this->head = new Node(value);
		size++;
	}
	else {
		Node*current = head;
		head = new Node(value);
		head->next = current;
		size++;
	}
	return *this;
}

Stack & Stack::operator-=(int removalAmount)
{
	if (removalAmount > size) {
		cout << "invalid removal amount" << endl;
		return *this;
	}
	else if (removalAmount == size) {
		Node* temp;
			while (head != NULL) {
				temp = head;
				head = head->next;
				delete temp;
				size--;
			}
			return *this;
	}
	else if (removalAmount < size && removalAmount > ZERO) {
		Node*temp;
		while (removalAmount > ZERO)
		{
			temp = head;
			head = head->next;
			removalAmount--;
		}
		
		return *this;
	}
}	

bool Stack::operator==(const Stack &Rstack) const
{
	if (size != Rstack.size) {
		return false;
	}
	else {
		Node* current = head;
		Node* Rcurrent = Rstack.head;
		while (current->next != NULL)
		{
			if (current->value != Rcurrent->value) {
				return false;
			}
			else {
				current = current->next;
				Rcurrent = Rcurrent->next;
			}
		}
		if (current->value != Rcurrent->value) {
			return false;
		}
		else {
			return true;
		}
	}
}

bool Stack::operator!=(const Stack &Rstack) const
{
	if (*this == Rstack) {
		return false;
	}
	return true;
}

Stack & Stack::operator!()
{
	Node*current = head;
	Node* prev = NULL;
	Node *next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return *this;
}

void Stack::PrintStack()
{
	Node*temp = head;
	while (temp->next != NULL) {
		temp->PrintNode();
		temp = temp->next;
	}
	temp->PrintNode();
}
ostream & operator<<(ostream & out, Stack & RStack)
{
	RStack.PrintStack();
	return out;
}
