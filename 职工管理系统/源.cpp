#include<iostream>
#include<string>
#include<fstream>
#include "staffManager.h"
#include "staff.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

using namespace std;

int main(void)
{
	char ch;
	StaffManager sm;
	while (true)
	{
		sm.menu();
		cout << "请选择："; cin >> ch;
		system("cls");
		switch (ch)
		{
		case'1':
			sm.add();
			break;
		case'2':
			sm.show();
			break;
		case'3':
			sm.del();
			break;
		case'4':
			sm.update();
			break;
		case'5':
			sm.search();
			break;
		case'6':
			sm.sort();
			break;
		case'7':
			sm.clear();
			break;
		case'0':
			sm.exitSystem();
			break;
		default:
			cout << "非法的选择！" << endl;
		}
		system("pause");
		system("cls");
	}
	return 0;
}