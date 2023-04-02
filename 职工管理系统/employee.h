#pragma once
#include<iostream>
#include<string>
#include "staff.h"

using namespace std;

class Employee : public Staff
{
public:
	Employee(string Id, string Name, int DeptId);

	void showInfo();

	string getDept();
};