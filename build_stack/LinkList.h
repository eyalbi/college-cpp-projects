#include <iostream>
#define ZERO 0
using namespace std;

class Stack {
private:
	class Node {
	private:
		int value;
		Node* next;
	public:
		Node(int num) :value(num), next(NULL) {}
		Node(const Node &);
		void PrintNode();
		friend class Stack;
		};
	Node *head;
	int size;
public:
	Stack() :head(NULL), size(ZERO) {};
	~Stack();
	Stack & operator += (int value);
	Stack & operator -= (int removalAmount);
	bool operator ==(const Stack&)const;
	bool operator !=(const Stack&)const;
	Stack & operator !();
	void PrintStack();
	friend ostream& operator <<(ostream & out,Stack&);
	bool IsEmpty()const { return head == NULL; };
	
	
	friend class Node;


};








