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
class linkedList
{
	node* head;
public:
	linkedList()
	{
		head = NULL;
	}
	void insert_node(int value)
	{
		node* n = new node(value);
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
	}
	node* getHead()
	{
		return head;
	}
};
node* merge(node* n, node* n1)
{
	linkedList temp;
	while (!(n == NULL && n1 == NULL))
	{
		if (n1==NULL || (n!=NULL&&n->data <= n1->data))
		{
			temp.insert_node(n->data);
			n = n->next;
		}
		else
		{
			temp.insert_node(n1->data);
			n1 = n1->next;
		}
	}
	return temp.getHead();
}
int main()
{
	linkedList l, l1;
	int x, value;
	cout << "values you want to enter in list 1 = ";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter value no." << i+1 << " = ";
		cin >> value;
		l.insert_node(value);
	}
	cout << "values you want to enter in list 2 = ";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter value no." << i+1 << " = ";
		cin >> value;
		l1.insert_node(value);
	}
	node* merged_list = merge(l.getHead(), l1.getHead());
	node* temp = merged_list;
	cout << "list 1 and list 2 after merging : ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	delete temp;
}