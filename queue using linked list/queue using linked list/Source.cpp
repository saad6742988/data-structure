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
class queue
{
	node* front,*rare;
public:
	queue()
	{
		front = rare = NULL;
	}
	node* makeNode(int x)
	{
		node* n = new node(x);
		return n;
	}
	//this enqueue function can be called if we make node in int main()
	void enqueue_by_node(node* n)
	{
		if (isEmpty())
		{
			front=rare = n;
			cout << "\nenqueued\n";
		}
		else
		{
			rare->next=n;
			rare = n;
			cout << "\nenqueued\n";
		}
	}
	//this enqueue function is called when we dont want to create node in 
	//int main() and we want to just pass the value from main
	// and node will be created by the makenode() funtion itself
	void enqueue_by_value(int x)
	{
		node* n = makeNode(x);
		if (isEmpty())
		{
			front=rare = n;
			cout << "\nenqueued\n";
		}
		else
		{
			rare->next = n;
			rare = n;
			cout << "\nenqueued\n";
		}
	}
	//dequeue function
	node* dequeue()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = front;
			front = front->next;
			return temp;
		}
	}
	//check empty
	bool isEmpty()
	{
		if (front == NULL&&rare==NULL)
		{
			return true;
		}
		return false;
	}

	void display()
	{
		node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	//funtion to count elements in queue
	int count()
	{
		node* temp = front;
		int counter = 0;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;

	}
	//function to return middle
	node* returnMiddle()
	{
		node* temp = front;
		if (count() % 2 == 0)
		{

			return NULL;
		}
		else
		{
			for (int i = 0; i < count() / 2; i++)
			{
				temp = temp->next;
			}
		}
		return temp;
	}
};
int main()
{
	queue s;
	node* n;
	int opt, x;
	do {
		cout << "press 1 to enqueue by value\npress 2 to enqueue by node\npress 3 to dequeue \n"
			<< "press 4 to count elements\npress 5 to display all elements\npress 6 to check queue is empty or not\n"
			"press 7 to check middle element\npress 8 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "\nenter number to enqueue by value = ";
			cin >> x;
			s.enqueue_by_value(x);
			cout << endl << endl;
			break;
		case 2:
			system("cls");
			cout << "\nenter number to enqueue by node = ";
			cin >> x;
			n = new node(x);
			s.enqueue_by_node(n);
			cout << endl << endl;
			break;
		case 3:
			system("cls");
			n = s.dequeue();
			try {
				if (n == NULL)
				{
					throw n;
				}
				else
					cout << endl << n->data<<" is dequeued\n";
			}
			catch (node* m)
			{
				cout << "\nqueue is empty";
			}
			cout << endl << "*****************************" << endl;
			break;
		case 4:
			system("cls");
			cout << "number of elements in queue = " << s.count();
			cout << endl << "*****************************" << endl;
			break;
		case 5:
			system("cls");
			cout << "queue: ";
			s.display();
			cout << endl << "*****************************" << endl;
			break;
		case 6:
			system("cls");
			if (s.isEmpty())
			{
				cout << "\nqueue is empty\n";
			}
			else
				cout << "\nqueue is not empty\n";
			cout << endl << "*****************************" << endl;
			break;
		case 7:
			system("cls");
			n = s.returnMiddle();
			try {
				if (n == NULL)
				{
					throw n;
				}
				else
				{
					cout << "\n middle element = " << n->data;
					cout << endl << "*****************************" << endl;
				}
			}
			catch (node* n)
			{
				cout << "\nsize of queue is even so there will be no middle value\n";
				cout << endl << "*****************************" << endl;
			}
			break;
		default:
			cout << "\ninvalid choice\n";
		}

	} while (opt != 8);
}