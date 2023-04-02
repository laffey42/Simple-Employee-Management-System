#include "manager.h"

Manager::Manager(string Id, string Name, int DeptId)
{
	this->Id = Id;
	this->Name = Name;
	this->DeptId = DeptId;
}

void Manager::showInfo()
{
	cout << "编号：" << Id << '\t';
	cout << "姓名：" << Name << '\t';
	cout << "岗位：" << this->getDept() << '\t';
	cout << "职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDept()
{
	return "经理";
}