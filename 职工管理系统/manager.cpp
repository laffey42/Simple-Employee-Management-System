#include "manager.h"

Manager::Manager(string Id, string Name, int DeptId)
{
	this->Id = Id;
	this->Name = Name;
	this->DeptId = DeptId;
}

void Manager::showInfo()
{
	cout << "��ţ�" << Id << '\t';
	cout << "������" << Name << '\t';
	cout << "��λ��" << this->getDept() << '\t';
	cout << "ְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDept()
{
	return "����";
}