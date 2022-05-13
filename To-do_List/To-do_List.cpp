#include "Header.h"

void deleteItem(int id);

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
	
}

