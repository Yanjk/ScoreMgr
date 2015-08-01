#include "Scoremgr.h"

// 全局变量，记录各类对象的数量
int SemCount=0;
int StuCount=0;
int SubjCount=0;
int SemCapacity=0;
int StuCapacity=0;
int SubjCapacity=0;

string Gen[2]={"女","男"};

Proc Global;
Semester Sem, *Sems;
Student Stu, *Stus;
Subject Subj, *Subjs;

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
	cout<<"请选择您所需的操作：\n1.输入信息\n2.查看信息\n3.修改信息\n4.计算排名与GPA\n0.退出系统\n\n";
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
		case 1:
			Sem.Set();
			break;
		case 2:												// TODO
			break;
		case 3:												// TODO
			break;
		case 4:												// TODO
			break;
		default:
			cout<<"输入错误，请重新输入："<<endl;
			break;
		}
		cin.clear();
		cin.sync();
		cout<<endl;
		Global.Line0();
		cout<<"请选择您所需的操作：\n1.输入信息\n2.查看信息\n3.修改信息\n4.计算排名与GPA\n0.退出系统\n\n";
		cin>>Choice;
	}
	cout<<"\n感谢您的使用！再见！\n"<<endl;
	Global.Line1();
}

void Proc::UpdateSems()
{
	int i;
	for (i=0; i<SemCount; ++i)
		if ( Sems[i] == Sem )
			return;
	if ( SemCount == SemCapacity )
	{
		Semester *temp = new Semester [SemCapacity + 10];
		for (i=0; i<SemCount; ++i)
			temp[i] = Sems[i];
		delete []Sems;
		Sems=temp;
	}
	Sems[SemCount++] = Sem;
}

void Proc::UpdateStus()
{
	int i;
	for (i=0; i<StuCount; ++i)
		if ( Stus[i] == Stu )
			return;
	if ( StuCount == StuCapacity )
	{
		Student *temp = new Student [StuCapacity + 10];
		for (i=0; i<StuCount; ++i)
			temp[i] = Stus[i];
		delete []Stus;
		Stus=temp;
	}
	Stus[StuCount++] = Stu;
}

void Proc::UpdateSubjs()
{
	int i;
	for (i=0; i<SubjCount; ++i)
		if ( Subjs[i] == Subj )
			return;
	if ( SubjCount == SubjCapacity )
	{
		Subject *temp = new Subject [SubjCapacity + 10];
		for (i=0; i<SubjCount; ++i)
			temp[i] = Subjs[i];
		delete []Subjs;
		Subjs=temp;
	}
	Subjs[SubjCount++] = Subj;
}

void Proc::NewData()
{
	Sem.Set();
}