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
	cout << "*****[1]����Ա����Ϣ*****" << endl;
	cout << "*****[2]��ʾԱ����Ϣ*****" << endl;
	cout << "*****[3]ɾ��Ա����Ϣ*****" << endl;
	cout << "*****[4]�޸�Ա����Ϣ*****" << endl;
	cout << "*****[5]����Ա����Ϣ*****" << endl;
	cout << "*****[6]���ձ������*****" << endl;
	cout << "*****[7]��������ĵ�*****" << endl;
	cout << "*****[0]�˳��������*****" << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	cout << "����������"; cin >> sizeAdd;
	if (sizeAdd <= 0)
	{
		cout << "��������룡" << endl;
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
		cout << "��" << i + 1 << "λԱ��" << endl;
		cout << "��ţ�"; cin >> Id;
		cout << "������"; cin >> Name;
		cout << "��λ��ţ�"; cin >> DeptId;
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
			cout<< "��Ч���룡" << endl;
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
	cout << "���ӳɹ���" << endl;
}

void StaffManager::show()
{
	if (this->fileIsEmpty)
	{
		cout << "�����ݣ�" << endl;
		return;
	}
	cout << "Ա����Ϣ���£�" << endl;
	for (int i = 0; i < size; i++)
		this->Array[i]->showInfo();
}

void StaffManager::del()
{
	if (size == 0)
	{
		cout << "�����ݣ�" << endl;
		return;
	}
	string IdDel;
	cout << "������Ա����ţ�"; cin >> IdDel;
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
	if (flag) cout << "ɾ���ɹ���" << endl;
	else cout << "ɾ��ʧ�ܣ�" << endl;
}

void StaffManager::update()
{
	if (size == 0)
	{
		cout << "�����ݣ�" << endl;
		return;
	}
	string IdUpdate;
	cout << "������Ա����ţ�"; cin >> IdUpdate;
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (this->Array[i]->Id == IdUpdate)
		{
			string Id, Name;
			int DeptId;
			cout << "��ţ�"; cin >> Id;
			cout << "������"; cin >> Name;
			cout << "��λ��ţ�"; cin >> DeptId;
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
				cout << "��Ч���룡" << endl;
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
	if (flag) cout << "�޸ĳɹ���" << endl;
	else cout << "�޸�ʧ�ܣ�" << endl;
}

void StaffManager::search()
{
	if (size == 0)
	{
		cout << "�����ݣ�" << endl;
		return;
	}
	string IdSearch;
	cout << "������Ա����ţ�"; cin >> IdSearch;
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
	if (flag) cout << "��ѯ�ɹ���" << endl;
	else cout << "��ѯʧ�ܣ�" << endl;
}

void StaffManager::sort()
{
	if (size == 0)
	{
		cout << "�����ݣ�" << endl;
		return;
	}
	char ch;
	cout << "[1]��������" << endl;
	cout << "[2]��������" << endl;
	cout << "��ѡ��"; cin >> ch;
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
		cout << "����ʧ�ܣ���Ч���룡" << endl;
		return;
	}
	this->save();
	cout << "������ɣ�������£�" << endl;
	this->show();
}

void StaffManager::clear()
{
	char ch;
	cout << "�Ƿ�ȷ��������ݣ�[Y/N]" << endl;
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
		cout << "��ճɹ���" << endl;
		break;
	case'N':
	case'n':
		cout << "���ʧ�ܣ��ֶ�ȡ����" << endl;
		return;
	default:
		cout << "���ʧ�ܣ���Ч���룡" << endl;
		return;
	}
}

void StaffManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
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

