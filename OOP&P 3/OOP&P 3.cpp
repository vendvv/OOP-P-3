#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

fstream file;

void vector_menu();
void list_menu();
void array_menu();

class app  //все сортируется по выручке
{
private:
	string name;
	int users;
	string date;
	int revenue;

	friend bool operator<(app& app1, app& app2);
	friend bool operator==(app& app1, app& app2);
	friend bool operator==(int& key, app& app2);
	friend bool operator>(app& app1, app& app2);
	friend bool operator!=(app& app1, app& app2);
	friend ostream& operator<<(ostream& stream, app& app2);
	friend istream& operator>>(istream& stream, app& app1);


	void caseOutput(int num)
	{
		switch (num)
		{
		case 1:
		{
			cout << "date = " << this->date << endl;
			break;
		}
		case 2:
		{
			cout << "amount of users = " << this->users << endl;
			break;
		}
		case 3:
		{
			cout << "revenue = " << this->revenue << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	}
public:
	void filteredView(int num)
	{
		cout << this->name << endl;
		cout << "**************************************\n";
		caseOutput(num / 100);
		caseOutput((num - (num / 100) * 100) / 10);
		caseOutput((num - (num / 100) * 100 - ((num - (num / 100) * 100) / 10) * 10));
		cout << "**************************************\n";
	}
	void fileInput()
	{
		string buff_2, buff = ":    ";
		buff_2 = this->name + buff;
		file.write(buff_2.c_str(), strlen(buff_2.c_str()));
		file.write(this->date.c_str(), strlen(this->date.c_str()));
		buff = "\namount of users = ";
		buff_2 = buff + to_string(this->users);
		file.write(buff_2.c_str(), strlen(buff_2.c_str()));
		buff = "\nrevenue = ";
		buff_2 = buff + to_string(this->revenue);
		file.write(buff_2.c_str(), strlen(buff_2.c_str()));
		buff = "\n**************************************\n";
		file.write(buff.c_str(), sizeof(buff));
	}

};

bool operator<(app& app1, app& app2)
{
	return app1.revenue < app2.revenue;
}
bool operator==(app& app1, app& app2)
{
	return app1.revenue == app2.revenue;
}
bool operator==(int& key, app& app2)
{
	return key == app2.revenue;
}
bool operator>(app& app1, app& app2)
{
	//cout << app1.revenue << ">" << app2.revenue << endl;
	return app1.revenue > app2.revenue;
}
bool operator!=(app& app1, app& app2)
{
	return app1.revenue != app2.revenue;
}
ostream& operator<<(ostream& stream, app& app1)
{
	stream << app1.name << ": ";
	stream << app1.date << "\n";
	stream << "**************************************\n";
	stream << "amount of users: " << app1.users << "\n";
	stream << "revenue: " << app1.revenue << "\n";
	stream << "**************************************\n";
	return stream;
}
istream& operator>>(istream& stream, app& app1) // проверки в задании не требуются
{
	cout << "Enter the name of th app: ";
	stream.ignore();
	getline(stream, app1.name);
	cout << "Enter the date of launch: ";
	getline(stream,app1.date);
	cout << "Enter the amount of users: ";
	stream >> app1.users;
	cout << "Enter the revenue: ";
	stream >> app1.revenue;
	return stream;
}

vector <app> appVect;
vector <app>::iterator vectIter;
list <app> appList;
list <app>::iterator listIter;
array <app, 20> appArr;
array <app, 20>::iterator arrIter;
int max_index = -1; //индекс последнего существующего элемента массива
map <string, app> appMap;

int main()
{
	int contChoice;
	while (true)
	{
		cout << "Enter the container you'd like to work with:\n1 - vector\n2 - list\n3 - array\n";
		cin >> contChoice;
		switch (contChoice)
		{
		case 1: // vector
		{
			vector_menu();
			break;
		}
		case 2:
		{
			list_menu();
			break;
		}
		case 3:
		{
			array_menu();
			break;
		}
		default:
		{
			cout << "Input error. Try again.\n";
			break;
		}
		}
	}

}

void vector_menu()
{
	while (true)
	{
		cout << "             vector menu \n";
		cout << "**************************************\n";
		cout << "1 - add\n2 - delete\n3 - edit\n4 - save to file\n5 - view\n6 - sort\n7 - search\n0 - back";
		int vectChoice;
		cin.ignore();
		cin >> vectChoice;
		switch (vectChoice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			app newApp;
			cin >> newApp;
			appVect.push_back(newApp);
			break;
		}
		case 2:
		{
			if (appVect.empty())
			{
				cout << "vector is empty\n";
				break;
			}
			vectIter = appVect.begin();
			cout << "enter the number of the element you want to delete:\n";
			int numToDel = -1;                                                  //number
			while (numToDel > appVect.size() || numToDel <= 0)
				cin >> numToDel;
			for (int i = 0; i < (numToDel - 1);i++)                                // i - index
			{
				cout << "iteration\n";
				vectIter++;
			}
			cout << "deleting " << *vectIter << endl;
			appVect.erase(vectIter);
			break;
		}
		case 3:  //edit
		{
			if (appVect.empty())
			{
				cout << "vector is empty\n";
				break;
			}
			vectIter = appVect.begin();
			cout << "enter the number of the element you want to edit:\n";
			int numToDel = -1;                                                  //number
			size_t size = appVect.size();
			while (numToDel > size || numToDel <= 0)
			{cin >> numToDel;}
			for (int i = 0; i < (numToDel - 1);i++)  //    т.к. он уже стоит на первом элементе                          // i - index
			{
				cout << "iteration\n";
				vectIter++;
			}
			cout << "deleting " << *vectIter << endl;
			appVect.erase(vectIter);
			if (numToDel == size)
			{
				vectIter = appVect.end();
				cout << "numToDel == size";
			}
			else if (numToDel == 1)
			{
				vectIter = appVect.begin();
			}
			app newApp;
			cin >> newApp;
			appVect.insert(vectIter, newApp);
			break;
		}
		case 4:
		{
			cout << "enter the name of the file, where you want to output information: \n";
			string FileName;
			cin.ignore();
			getline(cin, FileName);
			file.open(FileName.c_str(), ios::out);
			while (!file.is_open())
			{
				cout << "something went wrong try again\n";
				getline(cin, FileName);
				file.open(FileName.c_str(), ios::out);
			}
			size_t size = appVect.size();
			for (int i = 0; i < size; i++)
			{
				appVect[i].fileInput();
			}
			file.close();
			break;
		}
		case 5:
		{
			if (appVect.empty())
			{
				cout << "vector is empty\n";
				break;
			}
			vectIter = appVect.begin();
			for (int i = 0; i < appVect.size(); i++)                 // i - index
			{
				cout << *vectIter;
				vectIter++;
			}
			break;
		}
		case 6:   //sort
		{
			if (appVect.empty())
			{
				cout << "vector is empty\n";
				break;
			}
			sort(appVect.begin(), appVect.end());
			break;
		}
		case 7:
		{
			int key;
			cout << "Enter the search query (revenue):\n";
			cin >> key;
			size_t size = appVect.size();
			for (int i = 0; i < size; i++)
			{
				if (key == appVect[i])
				{
					key = -1;
					cout << appVect[i] << endl;
					break;
				}
			}
			if (key != -1)
				cout << "Haven't found matching results\n";
			break;
		}
		}
	}
}

void list_menu()
{
	while (true)
	{
		cout << "             list menu \n";
		cout << "**************************************\n";
		cout << "1 - add\n2 - delete\n3 - edit\n4 - save to file\n5 - view\n6 - sort\n7 - search\n0 - back";
		int listChoice;
		cin.ignore();
		cin >> listChoice;
		switch (listChoice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			app newApp;
			cin >> newApp;
			appList.push_back(newApp);
			break;
		}
		case 2:
		{
			if (appList.empty())
			{
				cout << "list is empty\n";
				break;
			}
			listIter = appList.begin();
			cout << "enter the number of the element you want to delete:\n";
			int numToDel = -1;                                                  //number
			while (numToDel > appList.size() || numToDel <= 0)
			{
				cin >> numToDel;
			}
			for (int i = 0; i < (numToDel - 1);i++)                                // i - index
			{
				cout << "iteration\n";
				listIter++;
			}
			cout << "deleting " << *listIter << endl;
			appList.erase(listIter);
			break;
		}
		case 3:  //edit
		{
			if (appList.empty())
			{
				cout << "list is empty\n";
				break;
			}
			listIter = appList.begin();
			cout << "enter the number of the element you want to edit:\n";
			int numToDel = -1;                                                  //number
			size_t size = appList.size();
			while (numToDel > size || numToDel <= 0)
			{
				cin >> numToDel;
			}
			for (int i = 0; i < (numToDel - 1);i++)  //    т.к. он уже стоит на первом элементе                          // i - index
			{
				cout << "iteration\n";
				listIter++;
			}
			cout << "deleting " << *listIter << endl;
			appList.erase(listIter);
			if (numToDel == size)
			{
				listIter = appList.end();
				cout << "numToDel == size";
			}
			else if (numToDel == 1)
			{
				listIter = appList.begin();
			}
			app newApp;
			cin >> newApp;
			appList.insert(listIter, newApp);
			break;
		}
		case 4:
		{
			cout << "enter the name of the file, where you want to output information: \n";
			string FileName;
			cin.ignore();
			getline(cin, FileName);
			file.open(FileName.c_str(), ios::out);
			while (!file.is_open())
			{
				cout << "something went wrong try again\n";
				getline(cin, FileName);
				file.open(FileName.c_str(), ios::out);
			}
			size_t size = appList.size();
			listIter = appList.begin();
			(*listIter).fileInput();
			cout << "size = " << size << endl;
			for (int i = 0; i < size - 1; i++)
			{
				listIter++;
				(*listIter).fileInput();
			}
			file.close();
			break;
		}
		case 5:
		{
			if (appList.empty())
			{
				cout << "list is empty\n";
				break;
			}
			listIter = appList.begin();
			for (int i = 0; i < appList.size(); i++)                 // i - index
			{
				cout << *listIter;
				listIter++;
			}
			break;
		}
		case 6:   //sort
		{
			if (appList.empty())
			{
				cout << "list is empty\n";
				break;
			}
			appList.sort();
			break;
		}
		case 7:
		{
			int key;
			cout << "Enter the search query (revenue):\n";
			cin >> key;
			size_t size = appList.size();
			for (int i = 0; i < size; i++)
			{
				if (i == 0)
					listIter = appList.begin();
				else
					listIter++;
				if (key == *listIter)
				{
					key = -1;
					cout << *listIter << endl;
					break;
				}
			}
			if (key != -1)
				cout << "Haven't found matching results\n";
			break;
		}
		}
	}
}

void array_menu()
{
	while (true)
	{
		cout << "             array menu \n";
		cout << "**************************************\n";
		cout << "1 - add\n2 - delete\n3 - edit\n4 - save to file\n5 - view\n51 - filtered view\n6 - sort\n7 - search\n0 - back";
		int arrChoice;
		cin.ignore();
		cin >> arrChoice;
		switch (arrChoice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			app newApp;
			cin >> newApp;
			appArr[max_index+1] = newApp;
			max_index++;
			break;
		}
		case 2:
		{
			if (max_index == -1)
			{
				cout << "array is empty\n";
				break;
			}
			cout << "enter the number of the element you want to delete:\n";
			int numToDel = -1;                                                  //number
			while (numToDel > max_index+1 || numToDel <= 0)
				cin >> numToDel;
			for (int i = numToDel - 1; i < max_index; i++)
			{
				appArr[i] = appArr[i + 1];

			}
			cout << "deleting " << appArr[max_index] << endl;
			max_index--;
			
			break;
		}
		case 3:  //edit
		{
			if (max_index == -1)
			{
				cout << "array is empty\n";
				break;
			}
			vectIter = appVect.begin();
			cout << "enter the number of the element you want to edit:\n";
			int numToDel = -1;                                                  //number
			while (numToDel > max_index+1 || numToDel <= 0)
			{
				cin >> numToDel;
			}
			cin >> appArr[numToDel - 1];
			break;
		}
		case 4:
		{
			cout << "enter the name of the file, where you want to output information: \n";
			string FileName;
			cin.ignore();
			getline(cin, FileName);
			file.open(FileName.c_str(), ios::out);
			while (!file.is_open())
			{
				cout << "something went wrong try again\n";
				getline(cin, FileName);
				file.open(FileName.c_str(), ios::out);
			}
			for (int i = 0; i < max_index+1; i++)
			{
				appArr[i].fileInput();
			}
			file.close();
			break;
		}
		case 5:
		{
			if (max_index == -1)
			{
				cout << "array is empty\n";
				break;
			}
			for (int i = 0; i < max_index+1; i++)                 // i - index
			{
				cout << appArr[i];
			}
			break;
		}
		case 51:
		{
			if (max_index == -1)
			{
				cout << "array is empty\n";
				break;
			}
			int num;
			cout << "Enter numbers of elements you want to view (for exmp.:12 - if you want 1 and 2):\n";
			cout << "1 - date\n2 - amt of users\n3 - revenue\n";
			cin >> num;
			for (int i = 0; i < max_index + 1; i++)                 // i - index
			{
				appArr[i].filteredView(num);
			}
			break;
		}
		case 6:   //sort
		{
			if (max_index == -1)
			{
				cout << "array is empty\n";
				break;
			}
			for (int i = 0; i < max_index; i++)
			{
				for (int j = 0; j < max_index - i; j++)
				{
					if (appArr[j] > appArr[j + 1])
					{
						//cout << "swapping " << appArr[j] << " > " << appArr[j + 1] << endl;
						swap(appArr[j], appArr[j + 1]);
					}
				}
			}
			break;
		}
		case 7:
		{
			int key;
			cout << "Enter the search query (revenue):\n";
			cin >> key;
			for (int i = 0; i < max_index+1; i++)
			{
				if (key == appArr[i])
				{
					key = -1;
					cout << appArr[i] << endl;
					break;
				}
			}
			if (key != -1)
				cout << "Haven't found matching results\n";
			break;
		}
		}
	}
}

