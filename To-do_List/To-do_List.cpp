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
	int id;
	string name;
	TodoItem todoitems[5];
};


int main()
{
	
}

