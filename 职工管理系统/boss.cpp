#include "boss.h"

Boss::Boss(string Id, string Name, int DeptId)
{
	this->Id = Id;
	this->Name = Name;
	this->DeptId = DeptId;
}

void Boss::showInfo()
{
	cout << "��ţ�" << Id << '\t';
	cout << "������" << Name << '\t';
	cout << "��λ��" << this->getDept() << '\t';
	cout << "ְ�𣺹�����������" << endl;
}

string Boss::getDept()
{
	return "�ϰ�";
}