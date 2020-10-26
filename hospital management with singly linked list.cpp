#include<iostream>
#include<ctime>
using namespace std;
const int max_rooms = 20;
class node
{
public:
	string name, cnic, disease;
	char time1[26];
	int room;
	node* next;
	node(string n = NULL, string c = NULL, string d = NULL,int r=0)
	{
		{
			time_t now = time(NULL);
			tm t;
			localtime_s(&t, &now);
			asctime_s(time1, sizeof time1, &t);
		}
		name = n; cnic = c; disease = d;
		room = r;
		next = NULL;
	}
};
class linklist
{
	node* start;

	bool patientExist(string cnic)
	{
		node* temp = start;
		while (temp != NULL)
		{
			if (temp->cnic == cnic)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	int roomAvailable()
	{
		node* temp = start;
		if (isEmpty() || temp->room != 1)
		{
			return 1;
		}
		while (temp->next != NULL)
		{
			if (temp->room != temp->next->room - 1)
			{
				break;
			}
			temp = temp->next;
		}
		if (temp->room == max_rooms)
			return -1;
		else
			return temp->room + 1;
	}
public:
	linklist()
	{
		start = NULL;
	}
	bool isEmpty()
	{
		if (start == NULL)
		{
			return true;
		}
		return false;
	}
	void admitPatient(string name,string cnic,string disease)
	{
			int x = roomAvailable();
			if (x == -1)
			{
				cout << "\nsorry!!no rooms available\n";
			}
			else {
				node* n = new node(name, cnic, disease,x);
				if (isEmpty())
				{
					start = n;
					cout << "\npatient is admitted in room no." << x << endl;
				}
				else if (patientExist(cnic))
				{
					cout << "\npatient already exist\n";
				}
				else
				{
					if (x == 1)
					{
						n->next = start;
						start = n;
					}
					else {
						node* temp = start;
						while (!(temp->next == NULL|| temp->room == x - 1))
						{
							/*if (temp->room == x - 1)
							{
								break;
							}*/
							temp = temp->next;
						}
						if (temp->next == NULL)
							temp->next = n;
						else
						{
							n->next = temp->next;
							temp->next = n;
						}
					}
					cout << "\npatient is admitted in room no." << x << endl;
				}
				
			}
	}
	void searchByRoom(int room)
	{
		node* temp = start;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->room == room)
			{
				check = true;
				break;
			}
			temp = temp->next;
		}
		if (check == true)
		{
			cout << "name = " << temp->name << endl;
			cout << "cnic = " << temp->cnic << endl;
			cout << "disease = " << temp->disease << endl;
			cout << "room = " << temp->room << endl;
			cout << "admit date and time = " << temp->time1 << endl;
		}
		else
			cout << "\n no result found in room no." << room << endl;
	}
	void searchByCnic(string cnic)
	{
		node* temp = start;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->cnic == cnic)
			{
				check = true;
				break;
			}
			temp = temp->next;
		}
		if (check == true)
		{
			cout << "name = " << temp->name << endl;
			cout << "cnic = " << temp->cnic << endl;
			cout << "disease = " << temp->disease << endl;
			cout << "room = " << temp->room << endl;
			cout << "admit date and time = " << temp->time1 << endl;
		}
		else
			cout << "\n no result found in cnic no." << cnic << endl;
	}
	void searchByDisease(string disease)
	{
		node* temp = start;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->disease == disease)
			{
				check = true;
				cout << "name = " << temp->name << endl;
				cout << "cnic = " << temp->cnic << endl;
				cout << "disease = " << temp->disease << endl;
				cout << "room = " << temp->room << endl;
				cout << "admit date and time = " << temp->time1 << endl;
				cout << "**********************************\n";
			}
			temp = temp->next;
		}
		if (check == false)
		{
			cout << "\n no result found in room no." << disease << endl;
		}	
	}
	void dischargePatient(string cnic)
	{
		if (isEmpty())
		{
			cout << "\nno patient is admitted yet\n";
		}
		else if (patientExist(cnic))
		{
			node* temp = start, * previos = NULL;
			while (temp->cnic != cnic)
			{
				previos = temp;
				temp = temp->next;
			}
			if (temp == start)
			{
				start = start->next;
			}
			else if (temp->next == NULL)
			{
				previos->next = NULL;
			}
			else
			{
				previos->next = temp->next;
			}
			cout << "\npatient is discharged from room no." << temp->room << endl;
		}
		else
			cout << "\npatient not found\n";
	}
	void displayAll()
	{
		node* temp = start;
		while (temp != NULL)
		{
			cout << "name = " << temp->name << endl;
			cout << "cnic = " << temp->cnic << endl;
			cout << "disease = " << temp->disease << endl;
			cout << "room = " << temp->room << endl;
			cout << "admit date and time = " << temp->time1 << endl;
			cout << "**********************************\n";
			temp = temp->next;
		}
	}
};
int main()
{
	linklist l;
	int opt, room; string name, cnic, disease;
	do
	{
		cout << "press 1 to admit\npress 2 to discharge\npress 3 to search by room\npress 4 to search by cnic\npress 5 to search by disease\npress 6 to display all patient\npress 7 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "enter patient name to admit = ";
			cin >> name;
			cout << "enter patient cnic to admit = ";
			cin >> cnic;
			cout << "enter patient disease to admit = ";
			cin >> disease;
			system("cls");
			l.admitPatient(name, cnic, disease);
			cout << "\n\n*************************************\n";
			break;
		case 2:
			cout << "enter patient cnic to discharge = ";
			cin >> cnic;
			system("cls");
			l.dischargePatient(cnic);
			cout << "\n\n*************************************\n";
			break;
		case 3:
			cout << "room to be searched = ";
			cin >> room;
			system("cls");
			l.searchByRoom(room);
			system("pause");
			cout << "\n\n*************************************\n";
			break;
		case 4:
			cout << "cnic to be searched = ";
			cin >> cnic;
			system("cls");
			l.searchByCnic(cnic);
			system("pause");
			cout << "\n\n*************************************\n";
			break;
		case 5:
			cout << "disease to be searched = ";
			cin >> disease;
			system("cls");
			l.searchByDisease(disease);
			system("pause");
			cout << "\n\n*************************************\n";
			break;
		case 6:
			system("cls");
			l.displayAll();
			system("pause");
			break;
		case 7:
			break;
		default:
			cout << "\ninvalid input\n";
		}
	} while (opt != 7);
}