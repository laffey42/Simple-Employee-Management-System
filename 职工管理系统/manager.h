#pragma once
#include<iostream>
#include<string>
#include "staff.h"

using namespace std;

class Manager : public Staff
{
public:
	Manager(string Id, string Name, int DeptId);

	void showInfo();

	string getDept();
};