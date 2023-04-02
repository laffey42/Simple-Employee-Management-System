#include "staffManager.h"

StaffManager::StaffManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		size = 0;
		this->Array = NULL;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		size = 0;
		this->Array = NULL;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	size = this->getSize();
	this->Array = new Staff * [size];
	this->initArray();
	fileIsEmpty = false;
}

void StaffManager::menu()
{
	cout << "-------------------------" << endl;
	cout << "*****[1]增加员工信息*****" << endl;
	cout << "*****[2]显示员工信息*****" << endl;
	cout << "*****[3]删除员工信息*****" << endl;
	cout << "*****[4]修改员工信息*****" << endl;
	cout << "*****[5]查找员工信息*****" << endl;
	cout << "*****[6]按照编号排序*****" << endl;
	cout << "*****[7]清空所有文档*****" << endl;
	cout << "*****[0]退出管理程序*****" << endl;
	cout << "-------------------------" << endl; 
}

void StaffManager::save()
{
	if (size == 0)
	{
		this->fileIsEmpty = true;
		this->Array = NULL;
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		return;
	}
	else this->fileIsEmpty = false;
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		ofs << this->Array[i]->Id << '\t';
		ofs << this->Array[i]->Name << '\t';
		ofs << this->Array[i]->DeptId << endl;
	}
	ofs.close();
}

int StaffManager::getSize()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string Id, Name;
	int DeptId, count = 0;
	while (ifs >> Id && ifs >> Name && ifs >> DeptId)
	{
		count++;
	}
	ifs.close();
	return count;
}

void StaffManager::initArray()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string Id, Name;
	int DeptId, index = 0;
	while (ifs >> Id && ifs >> Name && ifs >> DeptId)
	{
		Staff* staff = NULL;
		bool flag = true;
		switch (DeptId)
		{
		case 1:
			staff = new Boss(Id, Name, DeptId);
			break;
		case 2:
			staff = new Manager(Id, Name, DeptId);
			break;
		case 3:
			staff = new Employee(Id, Name, DeptId);
			break;
		default:
			flag = false;
			break;
		}
		if (flag) this->Array[index++] = staff;
	}
	ifs.close();
}

void StaffManager::add()
{
	int sizeAdd = 0;
	cout << "新增人数："; cin >> sizeAdd;
	if (sizeAdd <= 0)
	{
		cout << "错误的输入！" << endl;
		return;
	}
	int sizeNew = size + sizeAdd;
	Staff** newArray = new Staff * [sizeNew];
	if (this->Array != NULL)
	{
		for (int i = 0; i < size; i++)
			newArray[i] = this->Array[i];
	}
	for (int i = 0; i < sizeAdd; i++)
	{
		system("cls");
		string Id, Name;
		int DeptId;
		cout << "第" << i + 1 << "位员工" << endl;
		cout << "编号："; cin >> Id;
		cout << "姓名："; cin >> Name;
		cout << "岗位编号："; cin >> DeptId;
		Staff* staff = NULL;
		bool flag = true;
		switch (DeptId)
		{
		case 1:
			staff = new Boss(Id, Name, DeptId); 
			break;
		case 2:
			staff = new Manager(Id, Name, DeptId);
			break;
		case 3:
			staff = new Employee(Id, Name, DeptId);
			break;
		default:
			cout<< "无效输入！" << endl;
			flag = false;
			break;
		}
		if (flag) newArray[size + i] = staff;
		else i--;
	}
	delete[] this->Array;
	this->Array = newArray;
	size = sizeNew;
	this->save();
	cout << "增加成功！" << endl;
}

void StaffManager::show()
{
	if (this->fileIsEmpty)
	{
		cout << "无数据！" << endl;
		return;
	}
	cout << "员工信息如下：" << endl;
	for (int i = 0; i < size; i++)
		this->Array[i]->showInfo();
}

void StaffManager::del()
{
	if (size == 0)
	{
		cout << "无数据！" << endl;
		return;
	}
	string IdDel;
	cout << "请输入员工编号："; cin >> IdDel;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (this->Array[i]->Id == IdDel)
		{	
			for (int j = i; j < size - 1; j++)
			{
				this->Array[j] = this->Array[j + 1];
			}
			size--;
			this->save();
			flag = true;
			break;
		}
	}
	if (flag) cout << "删除成功！" << endl;
	else cout << "删除失败！" << endl;
}

void StaffManager::update()
{
	if (size == 0)
	{
		cout << "无数据！" << endl;
		return;
	}
	string IdUpdate;
	cout << "请输入员工编号："; cin >> IdUpdate;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (this->Array[i]->Id == IdUpdate)
		{
			string Id, Name;
			int DeptId;
			cout << "编号："; cin >> Id;
			cout << "姓名："; cin >> Name;
			cout << "岗位编号："; cin >> DeptId;
			Staff* staff = NULL;
			bool fine = true;
			switch (DeptId)
			{
			case 1:
				staff = new Boss(Id, Name, DeptId);
				break;
			case 2:
				staff = new Manager(Id, Name, DeptId);
				break;
			case 3:
				staff = new Employee(Id, Name, DeptId);
				break;
			default:
				cout << "无效输入！" << endl;
				fine = false;
				break;
			}
			if (fine)
			{
				this->Array[i] = staff;
				this->save();
				flag = true;
			}
			break;
		}
	}
	if (flag) cout << "修改成功！" << endl;
	else cout << "修改失败！" << endl;
}

void StaffManager::search()
{
	if (size == 0)
	{
		cout << "无数据！" << endl;
		return;
	}
	string IdSearch;
	cout << "请输入员工编号："; cin >> IdSearch;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (this->Array[i]->Id == IdSearch)
		{
			this->Array[i]->showInfo();
			flag = true;
			break;
		}
	}
	if (flag) cout << "查询成功！" << endl;
	else cout << "查询失败！" << endl;
}

void StaffManager::sort()
{
	if (size == 0)
	{
		cout << "无数据！" << endl;
		return;
	}
	char ch;
	cout << "[1]升序排序" << endl;
	cout << "[2]降序排序" << endl;
	cout << "请选择："; cin >> ch;
	switch (ch)
	{
	case'1':
		for (int i = 0; i < size - 1; i++)
		{
			bool flag = false;
			for (int j = i + 1; j < size; j++)
			{
				if (this->Array[i]->Id.compare(this->Array[j]->Id) > 0)
				{
					Staff* staff;
					staff = this->Array[i];
					this->Array[i] = this->Array[j];
					this->Array[j] = staff;
					flag = true;
				}
			}
			if (!flag)break;
		}
		break;
	case'2':
		for (int i = 0; i < size - 1; i++)
		{
			bool flag = false;
			for (int j = i + 1; j < size; j++)
			{
				if (this->Array[i]->Id.compare(this->Array[j]->Id) < 0)
				{
					Staff* staff;
					staff = this->Array[i];
					this->Array[i] = this->Array[j];
					this->Array[j] = staff;
					flag = true;
				}
			}
			if (!flag)break;
		}
		break;
	default:
		cout << "排序失败：无效输入！" << endl;
		return;
	}
	this->save();
	cout << "排序完成，结果如下：" << endl;
	this->show();
}

void StaffManager::clear()
{
	char ch;
	cout << "是否确定清空数据？[Y/N]" << endl;
	cin >> ch;
	switch (ch)
	{
	case'Y':
	case'y':
		{
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);
		}
		if (this->Array != NULL)
		{
			for (int i = 0; i < size; i++)
			{
				delete this->Array[i];
				this->Array[i] = NULL;
			}
			delete[] this->Array;
			this->Array = NULL;
			this->size = 0;
			this->fileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
		break;
	case'N':
	case'n':
		cout << "清空失败：手动取消！" << endl;
		return;
	default:
		cout << "清空失败：无效输入！" << endl;
		return;
	}
}

void StaffManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

StaffManager::~StaffManager()
{
	if (this->Array != NULL)
	{
		delete[] this->Array;
		this->Array = NULL;
	}
}

