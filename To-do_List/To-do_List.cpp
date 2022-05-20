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


	void updateItem(TodoItem item,int chooseItem)
	{
		todoitems[chooseItem].id = item.id;
		todoitems[chooseItem].name = item.name;
		todoitems[chooseItem].description = item.description;
		todoitems[chooseItem].day = item.day;
		todoitems[chooseItem].month = item.month;
		todoitems[chooseItem].year = item.year;
		todoitems[chooseItem].deadline = item.deadline;
	}
	void clean()
	{
		delete todoitems;
	}

	void addNewItem(TodoItem item)
	{
		if (counter > size - 1)
		{
			extendArr();
		}
		
		todoitems[counter].id = item.id;
		todoitems[counter].name = item.name;
		todoitems[counter].description = item.description;
		todoitems[counter].day = item.day;
		todoitems[counter].month = item.month;
		todoitems[counter].year = item.year;
		todoitems[counter].deadline = item.deadline;

		counter++;

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
		for (int i= 0, k = 0; i < size - 1; i++)
		{
			if (i == id)
			{
				continue;
			}
			
			newTodoitems[k] = todoitems[i];
			k++;
		}
		delete todoitems;
		todoitems = newTodoitems;
		
		
	}
};


int main()
{
	TodoItem todoitem;
	TodoList list;

	
	int chooseMenuItem;

	cout << "Choose action: "
		"\n1. Add new item"
		"\n2. delete item"
		"\n3. Update item"
		"\n4. Clean list\n";
	cin >> chooseMenuItem;

	switch (chooseMenuItem)
	{
	case 1:
	{
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
		break;
	}
	case 2:
	{
		int chooseId;

		cout << "Enter item id which u want to delete: ";
		cin >> chooseId;
		list.deleteItem(chooseId);
		break;
	}
	case 3:
	{
		int chooseItem;
		cout << "Choose item which u want to change: ";
		cin >> chooseItem;

		int changePos = -1;

		while (changePos != 0)
		{
			TodoItem tempitem;

			cout << "Choose what u want to change: ";
			"\n1. id",
				"\n2. name",
				"\n3. description",
				"\n4. day",
				"\n5. month",
				"\n6. year",
				"\n7. deadline"
				"\n0.if	 Exit";
			cin >> changePos;

			switch (changePos)
			{
			case 1:
				cin >> tempitem.id;
				break;
			case 2:
				cin >> tempitem.name;
				break;
			case 3:
				cin >> tempitem.description;
				break;
			case 4:
				cin >> tempitem.day;
				break;
			case 5:
				cin >> tempitem.month;
				break;
			case 6:
				cin >> tempitem.year;
				break;
			case 7:
				cin >> tempitem.deadline;
				break;
			case 0:
				changePos = 0;
				break;
			default:
				cout << "Incorrect input!";
				break;
			}
		}

		list.updateItem(list.todoitems[chooseItem - 1], chooseItem - 1);
		break;
	}
	case 4:
	{
		list.clean();
		break;
	}
	}

	
	


}

