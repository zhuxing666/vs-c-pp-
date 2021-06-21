#include<iostream>
using namespace std;
#include<string>
#define MAX  500
struct Person
{
	string m_Name;
	int m_Age;
	int m_Sex;
	int m_Phone;
	string m_Addr;

};

struct Addressbooks
{
	struct Person  PersonArray[MAX];
	int  m_Size;
};

void showMenu()      
{
	cout << "           通讯录          " << endl;
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks*abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		cout << "请输入你要添加的联系人：" << endl;
		string name;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex== 1 || sex== 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，重新输入！" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		cout << "请输入手机号：" << endl;
		int phone=0;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		cout << "亲输入地址：" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");

		
	}

}

void showPerson(Addressbooks*abs)
{
	if (abs->m_Size == 0)
	{
		cout << "人数为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->PersonArray[i].m_Name << "\t";
			cout << "性别：" << (abs->PersonArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->PersonArray[i].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[i].m_Phone << "\t";
			cout << "住址：" << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int  isExist(Addressbooks*abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->PersonArray[i].m_Name == name)

		{
			return i;
		}
		return -1;
	}
}

void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

void findPerson(Addressbooks*abs)
{
	cout << "请输入你要查找联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
		if (ret != -1)
		{
			cout << "姓名：" << abs->PersonArray[ret].m_Name << "\t";
			cout << "性别：" << abs->PersonArray[ret].m_Sex << "\t";
			cout << "年龄：" << abs->PersonArray[ret].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[ret].m_Phone << "\t";
			cout << "住址：" << abs->PersonArray[ret].m_Addr << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");

}

void modifyPerson(Addressbooks* abs)
{

	cout << "请输入你要修改联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[ret].m_Age = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		int phone = 0;
		cin >> phone;
		abs->PersonArray[ret].m_Phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->PersonArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

int  cleanPerson(Addressbooks*abs)
{
	cout << "是否要清空" << endl;
	int select = 0;
	cout << "1---yes" << endl;
	cout << "2——no" << endl;
	while (true)

	{
		cin >> select;
		if (select == 1)
		{
			abs->m_Size = 0;
			cout << "清空完成" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "下次清理" << endl;
			system("pause");
			return 0;
		}
	}
	
}



int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		showMenu();
	
		cout << "请输入你的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;


		default:
			break;
		}
		
	}
	system("pause");
	return 0;
}