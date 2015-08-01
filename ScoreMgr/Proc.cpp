#include "Scoremgr.h"

// ȫ�ֱ�������¼������������
int SemCount=0;
int StuCount=0;
int SubjCount=0;
int SemCapacity=0;
int StuCapacity=0;
int SubjCapacity=0;

string Gen[2]={"Ů","��"};

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
	cout<<"��ӭʹ��ѧ���ɼ�����ϵͳ";
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
	cout<<"��ѡ��������Ĳ�����\n1.������Ϣ\n2.�鿴��Ϣ\n3.�޸���Ϣ\n4.����������GPA\n0.�˳�ϵͳ\n\n";
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
			cout<<"����������������룺"<<endl;
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
			cout<<"����������������룺"<<endl;
			break;
		}
		cin.clear();
		cin.sync();
		cout<<endl;
		Global.Line0();
		cout<<"��ѡ��������Ĳ�����\n1.������Ϣ\n2.�鿴��Ϣ\n3.�޸���Ϣ\n4.����������GPA\n0.�˳�ϵͳ\n\n";
		cin>>Choice;
	}
	cout<<"\n��л����ʹ�ã��ټ���\n"<<endl;
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