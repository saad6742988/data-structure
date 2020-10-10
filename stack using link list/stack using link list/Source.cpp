#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d=0)
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
	node * makeNode(int x)
	{
		node* n = new node(x);
		return n;
	}
	//this push function can be called if we make node in int main()
	void push_by_node(node* n)
	{
		if (isEmpty())
		{
			head = n;
			cout << "\npushed\n";
		}
		else
		{
			node* temp = head;
			head = n;
			head->next = temp;
			cout << "\npushed\n";
		}
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
			cout << "\npushed\n";
		}
		else
		{
			node* temp = head;
			head = n;
			head->next = temp;
			cout << "\npushed\n";
		}
	}

	//pop function
	node* pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node * temp = head;
			head = head->next;
			return temp;
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
	//funtion to count elements in stack
	int count()
	{
		node* temp = head;
		int counter=0;
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
		node* temp = head;
		if (count() % 2 == 0)
		{
			
			return NULL;
		}
		else
		{
			for (int i = 0; i < count()/2; i++)
			{
				temp = temp->next;
			}
		}
		return temp;
	}
};
int main()
{
	stack s;
	node* n;
	int opt, x;
	do {
		cout << "press 1 to push by value\npress 2 to push by node\npress 3 to pop \n"
			<< "press 4 to count elements\npress 5 to display all elements\npress 6 to check stack is empty or not\n"
			"press 7 to check middle element\npress 8 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "\nenter number to push by value = ";
			cin >> x;
			s.push_by_value(x);
			cout << endl << endl;
			break;
		case 2:
			system("cls");
			cout << "\nenter number to push by node = ";
			cin >> x;
			 n = new node(x);
			s.push_by_node(n);
			cout << endl << endl;
			break;
		case 3:
			system("cls");
		  n = s.pop();
			try {
				if (n == NULL)
				{
					throw n;
				}
				else
					cout<<endl<< n->data<<" is popped\n";
			}
			catch (node* m)
			{
				cout << "\nstack is empty";
			}
			cout <<endl<< "*****************************" << endl;
			break;
		case 4:
			system("cls");
			cout << "number of elements in stack = " << s.count();
			cout << endl << "*****************************" << endl;
			break;
		case 5:
			system("cls");
			cout << "stack: ";
			s.display();
			cout << endl << "*****************************" << endl;
			break;
		case 6:
			system("cls");
			if (s.isEmpty())
			{
				cout << "\nstack is empty\n";
			}
			else
				cout << "\nstack is not empty\n";
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
			cout << "\nsize of stack is even so there will be no middle value\n";
			cout << endl << "*****************************" << endl;
		}
			break;
		default:
			cout << "\ninvalid choice\n";
		}

	} while (opt != 8);
	
}



