#include "Scoremgr.h"

int StuCount=0;
int SubjCount=0;

string Gen[2]={"女","男"};

Proc Global;

void Proc::Line0()
{
	for (int i=0;i<80;++i)
		cout<<'*';
	cout<<endl;
}

void Proc::Line1()
{
	for (int i=0;i<80;++i)
		cout<<'*';
	cout<<endl<<endl;
}

void Proc::Welcome()
{
	int i;
	for (i=0;i<28;++i)
		cout<<'*';
	cout<<"欢迎使用学生成绩管理系统";
	for (i=0;i<28;++i)
		cout<<'*';
	cout<<endl;
	cout<<"                  *****     *****    *****     ****      ****** \n"
		<<"                 *         *        *     *    *   *     *      \n"
		<<"                  ****     *        *     *    ****      ****** \n"
		<<"                      *    *        *     *    *   *     *      \n"
		<<"                 *****      *****    *****     *    *    ****** \n\n";
	for (i=0;i<80;++i)
		cout<<'*';
	cout<<endl;
}

void Proc::Menu()
{
	Global.Line0();
	cout<<"请选择您所需的操作：\n1.查看信息\n2.修改信息\n3.计算排名与GPA\n0.退出系统\n\n";
	int Choice;
	cin.clear();
	cin.sync();
	cin>>Choice;
	while (Choice != 0)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout<<"输入错误，请重新输入："<<endl;
			cin>>Choice;
		}
		switch (Choice)
		{
		case 0:
			break;
		case 1:												// TODO
			break;
		case 2:												// TODO
			break;
		case 3:												// TODO
			break;
		default:
			cout<<"输入错误，请重新输入："<<endl;
			break;
		}
	}
}

void Proc::NewData()
{
	
}