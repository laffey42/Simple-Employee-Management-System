#pragma once
#include<iostream>
#include<string>

using namespace std;

class Staff
{
public:
	virtual void showInfo() = 0;

	virtual string getDept() = 0;

	string Id;
	string Name;
	int DeptId;
};