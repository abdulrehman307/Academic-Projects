#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contact
{
    string name;
    string phone;
};

Contact list[50];
int total = 0;

void sortList()
{
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (list[i].name > list[j].name)
            {
                Contact temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int searchBinary(string key)
{
    int start = 0;
    int end = total - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (list[mid].name == key)
            return mid;
        else if (list[mid].name < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

void saveFile()
{
    ofstream file("contacts.txt");
    for (int i = 0; i < total; i++)
    {
        file << list[i].name << "\t" << list[i].phone << endl;
    }
    file.close();
}

void loadFile()
{
    ifstream file("contacts.txt");
    total = 0;

    while (file >> list[total].name >> list[total].phone)
    {
        total++;
    }
    file.close();
    sortList();
}

void addContact()
{
    cout << "Enter name: ";
    cin >> list[total].name;

    cout << "Enter phone: ";
    cin >> list[total].phone;

    total++;
    sortList();
    saveFile();

    cout << "Contact added.\n";
}

void findContact()
{
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    int pos = searchBinary(name);
    if (pos != -1)
    {
        cout << "Name: " << list[pos].name << endl;
        cout << "Phone: " << list[pos].phone << endl;
    }
    else
    {
        cout << "Contact not found.\n";
    }
}

void removeContact()
{
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    int pos = searchBinary(name);
    if (pos != -1)
    {
        for (int i = pos; i < total - 1; i++)
        {
            list[i] = list[i + 1];
        }
        total--;
        saveFile();
        cout << "Contact deleted.\n";
    }
    else
    {
        cout << "Contact not found.\n";
    }
}
void Display_Contact_List()
{
	
	string line;
    int count=0;
	cout<<"The list of All Contacts is as Follows :"<<endl;
	ifstream infile("contacts.txt");
	cout<<"Sr.No"<< "\t"<<"Name"<<"\t"<<"contact"<<endl;

	while(getline(infile,line))
	{
        count++;
		cout<<count<<"\t"<<line<<endl;
	}
	infile.close();
}

int main()
{
    int choice;
    loadFile();

    do
    {
        cout << "\n1. Add Contact";
        cout << "\n2. Search Contact";
        cout << "\n3. Delete Contact";
         cout << "\n4. Sort Contact By Name";
        cout << "\n5. Displays All Contacts";

        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            addContact();
        else if (choice == 2)
            findContact();
        else if (choice == 3)
            removeContact();
        else if (choice == 4)
           {
              sortList();
              cout<<"\n Contact List Sorted By Name";
            }
        else if (choice == 5)
            Display_Contact_List();
        else if (choice == 0)
            cout << "Program ended.\n";
        else
            cout << "Wrong choice.\n";

    } while (choice != 0);

    return 0;
}
