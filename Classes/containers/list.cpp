#include <iostream>
#include "conio.h"

using namespace std;

struct link
{
	int data;
	link* next;
};

class linklist
{
private:
	link* first;
public:
	linklist();
	~linklist();
public:
	void additem(int d);
	void display();
};

linklist::linklist()
{
	first = NULL;
}

linklist::~linklist()
{
	link* current = first;
	link* tmp = NULL;
	while (current)
	{
		tmp = current;
		current = current->next;
		delete tmp;
	}
}

void linklist::additem(int d)
{
	link* newlink = new link;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}

void linklist::display()
{
	link* current = first;
	while(current)
	{
		cout<<current->data<<endl;
		current = current->next;
	}
}

void main()
{

	linklist li;

	li.additem(25);
	li.additem(36);
	li.additem(49);
	li.additem(64);

	li.display();

	getch();
}