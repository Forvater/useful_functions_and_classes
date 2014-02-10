#include <iostream>
#include "conio.h"

using namespace std;

struct StackElement
{
	int data;
	StackElement* next;
};

class Stack
{
private:
	StackElement* first;
public:
	Stack();
	~Stack();
public:
	void push(int d);
	int pop();
	void display();
};

Stack::Stack()
{
	first = NULL;
}

Stack::~Stack()
{
	StackElement* current = first;
	StackElement* tmp = NULL;
	while (current)
	{
		tmp = current;
		current = current->next;
		delete tmp;
	}
}

void Stack::push(int d)
{
	StackElement* newlink = new StackElement;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}

int Stack::pop()
{
	int res = first->data;
	StackElement* tmp = first;
	first = first->next;
	delete tmp;
	return res;
}

void Stack::display()
{
	StackElement* current = first;
	while(current)
	{
		cout<<current->data<<endl;
		current = current->next;
	}
	cout<<endl<<endl;
}

void main()
{

	Stack st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	st.display();

	int re = st.pop(); 
	cout<<re<<endl<<endl;

	st.display();

	st.push(4);
	st.push(5);

	st.display();

	getch();
}