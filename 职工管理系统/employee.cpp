#include "employee.h"

Employee::Employee(string Id, string Name, int DeptId)
{
	this->Id = Id;
	this->Name = Name;
	this->DeptId = DeptId;
}

void Employee::showInfo()
{
	cout << "��ţ�" << Id << '\t';
	cout << "������" << Name << '\t';
	cout << "��λ��" << this->getDept() << '\t';
	cout << "ְ����ɾ�����������" << endl;
}

string Employee::getDept()
{
	return "��ͨԱ��";
}