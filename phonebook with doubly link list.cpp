#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class node
{
public:
	string name,number;
	int age;
	node* pre;
	node* next;
	node(string n=NULL,string num=NULL,int a = 0)
	{
		name = n; number = num; age = a;
		pre = NULL;
		next = NULL;
	}
};
class stackNode:public node
{
public:
	bool check;
	stackNode* next;
	stackNode(string n = NULL, string num = NULL, int a = 0,bool c=false):node(n, num, a)
	{
		check = c;
		next = NULL;
	}
};
class stack {
	stackNode* head;
public:
	stack()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	void push(string name, string number, int age, bool check)
	{
		stackNode* n = new stackNode(name, number, age, check);
		if (isEmpty())
		{
			head = n;
		}
		else
		{
			stackNode* temp = head;
			head = n;
			head->next = temp;
		}
	}
	stackNode* pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			stackNode* temp = head;
			head = head->next;
			return temp;
		}
	}

};
class linkedList
{
	node* head;
	stack undo;
	//to change console colours
	void green()
	{
		HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(t, 2);
	}
	void blue()
	{
		HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(t, 1);
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	//converting first letter to upper case
	void upperCase(string& name)
	{
		if (name[0] >= 97 && name[0] <= 122)
		{
			name[0] = name[0] - 32;
		}
	}
	bool numberExist(string number)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->number == number)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	//i make these functions if we add two numbers with same 
	//then there will be a problem while searching by name
	bool nameExist(string name)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->name == name)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
public:
	linkedList()
	{
		head = NULL;
	}
	void insert(string name,string number,int age,bool push=true)
	{
		upperCase(name);
		if (numberExist(number))
		{
			cout << "\nnumber already exist in your contact\n";
		}
		else if (nameExist(name))
		{
			cout << "\nname already exist in your contact\n";
		}
		else
		{
			
			node* n = new node(name, number, age);
			if (push)
			{
				undo.push(name, number, age, true);
			}
			if (isEmpty())
			{
				head = n;
			}
			else
			{
				//if first letter is of new name is smaller than head,s first letter
				//then new contact will be inserted at head
				if (name[0] < head->name[0])
				{
					head->pre = n;
					n->next = head;
					head = n;
				}
				else
				{
					node* temp = head;
					while (!(temp->next == NULL|| name[0] < temp->next->name[0]))
					{
						temp = temp->next;
					}
					if (temp->next == NULL)
					{
						temp->next = n;
						n->pre = temp;
					}
					else
					{
						n->pre = temp;
						n->next = temp->next;
						temp->next->pre = n;
						temp->next = n;
					}
				}

			}
			cout << name << " is added in contact\n";
		}
	}
	int count()
	{
		node* temp = head;
		int c = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			c++;
		}
		return c;
	}
	void display()
	{
		if (isEmpty())
		{
			cout << "\nno contacts are saved\n";
		}
		else {
			node* temp = head;
			int i = 0;
			while (temp != NULL)
			{
				if (temp == head || temp->name[0] != temp->pre->name[0])
				{
					if (i % 2 == 0)
					{
						green();
					}
					else
					{
						blue();
					}
					cout << endl << endl << temp->name[0] << ":" << endl;
					i++;
				}
				cout << temp->name << endl << temp->number << endl << temp->age << endl << endl;
				temp = temp->next;
			}
		}
	}
	void deleteContact(string name,bool push=true)
	{
		upperCase(name);
		if (isEmpty())
		{
			cout << "\nno contacts are saved\n";
		}
		else if (nameExist(name))
		{
			node* temp = head;
			while (temp->name != name)
			{
				temp = temp->next;
			}
			if (temp == head)
			{
				head = head->next;
				if (head != NULL)
					head->pre = NULL;
			}
			else if (temp->next == NULL)
			{
				temp->pre->next = NULL;
				temp->pre = NULL;
			}
			else
			{
				temp->pre->next = temp->next;
				temp->next->pre = temp->pre;
			}
			cout << temp->name << " is deleted" << endl;
			if (push) {
				undo.push(temp->name, temp->number, temp->age, false);
			}
		}
		else
			cout << "\nno contact found with name:" << name << endl;
	}
	void reverse()
	{
	/*	node* tail = head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		node* temp = head;*/
		do
		{
			swap(head->next, head->pre);
			if (head->pre != NULL)
				head = head->pre;
		} while (head->pre != NULL);

		//head = tail;
	}
	void _undo()
	{
		if (!isEmpty())
		{
			stackNode* n = undo.pop();
			if (n->check == true)
			{
				deleteContact(n->name, false);
			}
			else
				insert(n->name, n->number, n->age, false);
		}
		else
			cout << "\nnothing to undo\n";
	}
	void search(string name)
	{
		node* temp = head;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->name == name)
			{
				check = true;
				break;
			}
			temp = temp->next;
		}
		if (check == true)
		{
			cout << temp->name << endl;
			cout << temp->number << endl;
			cout << temp->age << endl;
		}
		else
			cout << "\n no contact found with " << name << endl;
	}
};
void white()
{
	HANDLE t = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(t, 7);
}
int main()
{
	linkedList l;
	string name, number; int age, opt;
	bool reversed = false;
	do {
		cout << "press 1 to insert\npress 2 to delete contact\npress 3 to undo function\n"
			"press 4 to reverse phone book\npress 5 to search contact\npress 6 to display all contacts"
			"\npress 7 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			if (reversed == false)
			{
				cout << "enter name = ";
				cin.ignore();
				getline(cin, name);
				cout << "enter number = ";
				cin >> number;
				cout << "enter age = ";
				cin >> age;
				system("cls");
				l.insert(name, number, age);
				cout << "\n*******************************\n";
				system("pause");
			}
			else
			{
				cout << "\nyour phonebook is reversed please bring it in orginal condition to add new contact properly\n";
				cout << "\n*******************************\n";
				system("pause");
			}
			break;
		case 2:
			
			cout << "enter name to delete = ";
			cin.ignore();
			getline(cin, name);
			system("cls");
			l.deleteContact(name);
			cout << "\n*******************************\n";
			system("pause");
			break;
		case 3:
			system("cls");
			if (reversed == false)
			{
				l._undo();
				cout << "\n*******************************\n";
				system("pause");
			}
			else
			{
				cout << "\nyour phonebook is reversed please bring it in orginal condition to undo changes properly\n";
				cout << "\n*******************************\n";
				system("pause");
			}
			break;
		case 4:
			system("cls");
			l.reverse();
			reversed++;
			cout << "your phonebook is reversed please bring it to its orignal position\n"
				"before adding new contact \n";
			break;
		case 5:
			cout << "enter name to search = ";
			cin.ignore();
			getline(cin, name);
			system("cls");
			l.search(name);
			cout << "\n*******************************\n";
			system("pause");
			break;
		case 6:
			system("cls");
			l.display();
			white();
			cout << "\n*******************************\n";
			system("pause");
			break;
		case 7:
			break;
		default:
			cout << "\ninvalid input!!!!\n";
		}
	} while (opt != 7);
}