#include<iostream>
using namespace std;
class node {
public:
	string name;
	int age, id;
	node* next;
	node* pre;
	node(string n=NULL,int a=0,int i=0)
	{
		name = n;
		age = a; id = i;
		next = NULL;
		pre = NULL;
	}
};
class linkedList
{
	node* head;
public:
	linkedList()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	void insert(string name,int age,int id)
	{
		node* n = new node(name,age,id);
		if (isEmpty())
		{
			head = n;
			head->next = head;
			head->pre = head;
		}
		else
		{
			node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			n->next = temp->next;
			n->pre = temp;
			temp->next = n;
			n->next->pre = n;
		}
	}
	void display()
	{
		node* temp = head;
		do
		{
			cout <<"name : "<< temp->name << " ";
			cout << "age : " << temp->age << " ";
			cout << "id : " << temp->id << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl << endl;
	}
	int count()
	{
		node* temp = head;
		int c = 0;
		do
		{
			c++;
			temp = temp->next;
		} while (temp != head);
		return c;
	}
	void deleteByIndex(int index)
	{
		if (isEmpty())
		{
			cout << "\nlist is empty\n";
		}
		else
		{
			node* temp = head;
			for (int i = 1; i < index; i++)
			{
				temp = temp->next;
			}
			temp->pre->next = temp->next;
			temp->next->pre = temp->pre;
			if (temp == head)
			{
				head = head->next;
			}
		}
	}
};
int main()
{
	linkedList l;
	string name; int age, id,n;
	cout << "number of members you want to enter = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter the name of member no." << i + 1 << " : ";
		cin >> name;
		cout << "enter the age of member no." << i + 1 << " : ";
		cin >> age;
		cout << "enter the id of member no." << i + 1 << " : ";
		cin >> id;
		l.insert(name,age,id);
	}
	while (l.count() != 1)
	{
		cout << "enter the member number you want to delete = ";
		cin >> n;
		l.deleteByIndex(n+1);
	}
	cout << "\n\nyour leader is :\n";
	l.display();

}