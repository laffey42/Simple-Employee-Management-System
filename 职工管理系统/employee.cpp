#include "employee.h"

Employee::Employee(string Id, string Name, int DeptId)
{
	this->Id = Id;
	this->Name = Name;
	this->DeptId = DeptId;
}

void Employee::showInfo()
{
	cout << "编号：" << Id << '\t';
	cout << "姓名：" << Name << '\t';
	cout << "岗位：" << this->getDept() << '\t';
	cout << "职责：完成经理交给的任务" << endl;
}

string Employee::getDept()
{
	return "普通员工";
}