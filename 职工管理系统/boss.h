#pragma once
#include<iostream>
#include<string>
#include "staff.h"

using namespace std;

class Boss :public Staff
{
public:
	Boss(string Id, string Name, int DeptId);

	void showInfo();

	string getDept();
};