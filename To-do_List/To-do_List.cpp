#include "Header.h"


struct TodoItem
{
	int id;
	string name;
	string description;
	int day;
	int month;
	int year;
	string deadline;

};

struct TodoList
{
	int size = 5;
	int counter = 0;

	int id;
	string name;
	TodoItem* todoitems = new TodoItem[size];


	void updateItem(TodoItem item)
	{
		int choose;

		cout << "Choose what u want to change: ";
			"\n1. id",
			"\n2. name",
			"\n3. description",
			"\n4. day",
			"\n5. month",
			"\n6. year",
			"\n7. deadline";
		cin >> choose;

		switch (choose)
		{
		case 1:
			cin >> item.id;
		case 2:
			cin >> item.name;
		case 3:
			cin >> item.description;
		case 4:
			cin >> item.day;
		case 5:
			cin >> item.month;
		case 6:
			cin >> item.year;
		case 7:
			cin >> item.deadline;
		default:
			cout << "Incorrect input!";
			break;
		}
	}
	void clean();

	void addNewItem(TodoItem item)
	{
		if (counter > size - 1)
		{
			extendArr();
		}
		
		todoitems[counter++] = item;

	}

	void extendArr()
	{
		TodoItem* temp = todoitems;
		size *= 1.5;
		TodoItem* todoitems = new TodoItem[size];

		for (int i = 0; i < counter; i++)
		{
			todoitems[i].id = temp[i].id;
			todoitems[i].name = temp[i].name;
			todoitems[i].description = temp[i].description;
			todoitems[i].day = temp[i].day;
			todoitems[i].month = temp[i].month;
			todoitems[i].year = temp[i].year;
			todoitems[i].deadline = temp[i].deadline;
		}

		delete temp;
	}

	void deleteItem(int id)
	{
		TodoItem* newTodoitems = new TodoItem[size];
		for (int i= 0, k = 0; i < size - 1; i++, k++)
		{
			if (i == id)
			{
				continue;
			}
			newTodoitems[k] = todoitems[i];
			
		}
	}
};


int main()
{
	TodoItem todoitem;
	TodoList list;

	cout << "Enter id: ";
	cin >> todoitem.id;
	cout << "Enter name: ";
	cin >> todoitem.name;
	cout << "Enter description: ";
	cin >> todoitem.description;
	cout << "Enter day: ";
	cin >> todoitem.day;
	cout << "Enter month: ";
	cin >> todoitem.month;
	cout << "Enter year: ";
	cin >> todoitem.year;
	cout << "Enter deadline: ";
	cin >> todoitem.deadline;

	
	list.addNewItem(todoitem);
	

}

