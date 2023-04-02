#include "boss.h"

Boss::Boss(string Id, string Name, int DeptId)
{
	this->Id = Id;
	this->Name = Name;
	this->DeptId = DeptId;
}

void Boss::showInfo()
{
	cout << "编号：" << Id << '\t';
	cout << "姓名：" << Name << '\t';
	cout << "岗位：" << this->getDept() << '\t';
	cout << "职责：管理所有事务" << endl;
}

string Boss::getDept()
{
	return "老板";
}