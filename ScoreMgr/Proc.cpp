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
Result **Data;
ifstream InFile;
ofstream OutFile;
char FileName[20]={0};

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
	cout<<"��ѡ��������Ĳ�����\n1.��Ϣ¼�����޸�\n2.��Ϣ���������ݼ���\n0.�˳�ϵͳ\n\n";
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
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::in|ios::binary|ios::_Nocreate);
			if (!InFile)
			{
				cout<<"��ѧ����Ϣ��δ¼�룬���������ļ���"<<endl;
				Global.NewData();
				Global.WriteData();
			}
			else
			{
				cout<<"��ѧ����Ϣ�Ѵ��ڣ����������ļ���"<<endl;
				Global.ReadData();
				InFile.close();
				OutFile.open(FileName,ios::out|ios::binary);
				Global.WriteData();
			}
			break;
		case 2:															// TODO
			break;
		default:
			cout<<"����������������룺"<<endl;
			break;
		}
		cin.clear();
		cin.sync();
		cout<<endl;
		Global.Line0();
		cout<<"��ѡ��������Ĳ�����\n1.��Ϣ¼�����޸�\n2.��Ϣ���������ݼ���\n0.�˳�ϵͳ\n\n";
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
	OutFile.open(FileName, ios::out|ios::binary);
	if (!OutFile)
	{
		cout<<"�ļ�����ʧ�ܡ������˳���"<<endl;
		exit(1);
	}
	StuCapacity = 10;
	SubjCapacity = 10;
	Data = new Result* [StuCapacity];
	for (int i=0; i<StuCapacity; ++i)
		Data[i] = new Result [SubjCapacity];
}

void Proc::ReadData()
{
	InFile.read((char*) &StuCount, sizeof(int));
	InFile.read((char*) &SubjCount, sizeof(int));
	StuCapacity = (StuCount-1) / 10 * 10 + 10;			// Count �� Capacity ��ʼ�����������ϵ
	SubjCapacity = (SubjCount-1) / 10 * 10 + 10;
	Data = new Result* [StuCapacity];
	for (int i=0; i<StuCapacity; ++i)
		Data[i] = new Result [SubjCapacity];
	for (int i=0; i<StuCapacity; ++i)
		for (int j=0; j<SubjCapacity; ++j)
			InFile.read((char*) &Data[i][j], sizeof(Result));
}

void Proc::WriteData()
{
	OutFile.write((char*) &StuCount, sizeof(int));
	OutFile.write((char*) &SubjCount, sizeof(int));
	for (int i=0; i<StuCapacity; ++i)
		for (int j=0; j<SubjCapacity; ++j)
			OutFile.write((char*) &Data[i][j], sizeof(Result));
}