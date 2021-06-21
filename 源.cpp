#include<iostream>
using namespace std;
#include<string >
#define MAX 500
struct Person//联系人结构
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};

struct Addressbooks  //通讯录
{
	struct Person PersonArray[MAX];//通讯录中最大联系人数组

	int m_Size; //当前通讯联系人个数
};

void showMenu()
{
	cout << "*******************" << endl;
	cout << "***1、添加联系人***" << endl;
	cout << "***2、显示联系人***" << endl;
	cout << "***3、删除联系人***"<< endl;
	cout << "***4、查找联系人***" << endl;
	cout << "***5、修改联系人***" << endl;
	cout << "***6、清空联系人***" << endl;
	cout << "***0、退出通讯录***" << endl;
	cout << "*******************" << endl;
}

void addPerson(Addressbooks*abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;

		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}

		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;


		cout << "输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;//更新人数
		cout << "你添加成功！" << endl;
		system("pause");
		system("cls");
	}

}

void showPerson(Addressbooks*abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录人数为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->PersonArray[i].m_Name << "\t";
			cout << "性别：" <<( abs->PersonArray[i].m_Sex==1?"男":"女")<< "\t";
			cout << "年龄：" << abs->PersonArray[i].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[i].m_Phone << "\t";
			cout << "住址：" << abs->PersonArray[i].m_Addr << endl;
			
		}
		system("pause");
		system("cls");
	}
}


//检测联系儿女存在否
int IsExist(Addressbooks*abs,string name)
{
	for (int i = 0;i < abs->m_Size; i++)
	{
		if (abs->PersonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	IsExist(abs, name);
	int ret = IsExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];//数据前移
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "未找到联系人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
		if (ret != 1)
		{
			cout << "姓名：" << abs->PersonArray[ret].m_Name << "\t";
			cout << "性别：" << (abs->PersonArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->PersonArray[ret].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[ret].m_Phone << "\t";
			cout << "住址：" << abs->PersonArray[ret].m_Addr << endl;
			
		}
		else
		{
			cout << "未找到" << endl;
		}
		system("pause");
		system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入修改的姓名：" << endl;
		string name;
		cin >> name;
		abs->PersonArray[ret].m_Name = name;

		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
	
		while(true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
		{
			abs->PersonArray[ret].m_Sex = sex;
			break;
		}
		cout << "输入有误，重新输入" << endl;
	}

	cout << "请输入年龄： " << endl;
	int age = 0;
	cin >> age;
	abs->PersonArray[ret].m_Age = age;


	cout << "输入联系电话：" << endl;
	string phone;
	cin >> phone;
	abs->PersonArray[ret].m_Phone = phone;

	cout << "请输入家庭住址：" << endl;
	string address;
	cin >> address;
	abs->PersonArray[ret].m_Addr = address;

	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}
	else
	{
	cout << "查无此人" << endl;
	}
}

//清空联系人
int cleanPerson(Addressbooks*abs)
{
	cout << "你确定要清空！" << endl;
	cout << "1====yes" << endl;
	cout << "2====no" << endl;

	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{

			abs->m_Size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else
		{
			cout << "暂时不清理" << endl;
			system("pause");
			system("cls");
			return 0;
		}
	}
	    system("pause");
	    system("cls");
}


int main()
{
	Addressbooks abs;        //初始化
	abs.m_Size = 0;

	int select = 0;//输入选择
	while (true)
	{
		//调用菜单
		showMenu();
		cout << "请输入你的选择： " << endl;
		cin >> select;
		switch (select)
		{
		case 1: //1、添加联系人
			addPerson(&abs);//修饰实参
			break;
		case 2:                         //2、显示联系人
			showPerson(&abs);
			break;
		case 3:                        //3、删除联系人
		/*{	cout << "请输入删除联系人姓名：" << endl;
		string name;
		cin >> name;
		if (IsExist(&abs, name) == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "找到此人" << endl;
		}
		}*/
			deletePerson(&abs);
			break;
		case 4:                       //4、查找联系人
			findPerson(&abs);
			break;
		case 5:                        //5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:                        //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;  //0、退出通讯录
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
