#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d = 0)
	{
		data = d;
		next = NULL;
	}
};
class stack
{
	node* head;
public:
	stack()
	{
		head = NULL;
	}
	node* makeNode(int x)
	{
		node* n = new node(x);
		return n;
	}

	//this push function is called when we dont want to create node in 
	//int main() and we want to just pass the value from main
	// and node will be created by the makenode() funtion itself
	void push_by_value(int x)
	{
		node* n = makeNode(x);
		if (isEmpty())
		{
			head = n;
		}
		else
		{
			node* temp = head;
			head = n;
			head->next = temp;
		}
	}

	//pop function
	int pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = head;
			head = head->next;
			return temp->data;
		}
	}

	//check empty
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};
void displayPoles(stack p,stack p1,stack p2)
{
	cout << "1st pole: ";
	p.display();
	cout << "\n2nd pole: ";
	p1.display();
	cout << "\n3rd pole: ";
	p2.display();
	cout << endl;
}
bool checkValid(stack pop,stack push)
{
	int pop1, pop2;
	pop1 = pop.pop();
	pop2 = push.pop();
	if ((pop1 == NULL && pop2 == NULL)||pop1==NULL)
	{
		return false;
	}
	else if (pop2==NULL)
	{
		return true;
	}
	else if (pop1 > pop2)
	{
		return false;
	}
	else
		return true;
}
int main()
{
	stack pole[3];
	int toPop,toPush,moves=0,disk;
	cout << "enter the number of disks = ";
	cin >> disk;
	for (int i = disk; i >0; i--)
	{
		pole[0].push_by_value(i);
	}
	while (1)
	{
		if (pole[0].isEmpty() && pole[1].isEmpty())
		{
			break;
		}
		displayPoles(pole[0], pole[1], pole[2]);
		cout << "\nenter pole number to pop value = ";
		do {
			cin >> toPop;
			if (toPop > 3 || toPop <= 0)
				cout << "invalid input!!!!\n";
		} while (toPop > 3||toPop<=0);
		cout << "enter pole number to push value = ";
		do {
			cin >> toPush;
			if (toPush > 3 || toPush <= 0)
				cout << "invalid input!!!!\n";
		} while (toPush > 3 || toPush <= 0);
		if (checkValid(pole[toPop - 1], pole[toPush - 1]))
		{
			pole[toPush - 1].push_by_value(pole[toPop - 1].pop());
			moves++;
		}
		else
			cout << "invalid move\n\n";

	}
	displayPoles(pole[0], pole[1], pole[2]);
	cout << "number of moves = " << moves;
}