#pragma once
#include<iostream>
#include<fstream>
#include "staff.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

using namespace std;

#define FILENAME "staff.txt"

class StaffManager
{
public:
	int size;
	Staff** Array;
	bool fileIsEmpty;

	StaffManager();

	void menu();

	void save();

	int getSize();

	void initArray();

	void add();

	void show();

	void del();

	void update();

	void search();

	void sort();

	void clear();

	void exitSystem();

	~StaffManager();

};