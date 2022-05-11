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

	int id;
	string name;
	TodoItem* todoitems = new TodoItem[size];

	void addNewItem(TodoItem item);
	void deleteItem(int id);
	void updateItem(TodoItem item);
	void clean();

};


int main()
{
	
}

