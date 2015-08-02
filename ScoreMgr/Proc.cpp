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
Semester Sem;
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

void Proc::UpdateStus()
{
	for (int i=0; i<StuCount; ++i)
		if ( Stus[i].StuNum == Stu.StuNum )
		{
			cout<<"该学号已存在，记录失败！"<<endl;
			return;
		}
	if ( StuCount == StuCapacity )
	{
		StuCapacity += 10;
		Student *temp = new Student [StuCapacity];
		for (int i=0; i<StuCount; ++i)
			temp[i] = Stus[i];
		delete []Stus;
		Stus = temp;
	}
	Stus[StuCount++] = Stu;
	cout<<"学生信息记录成功。"<<endl;
}

void Proc::UpdateStus(int Index)
{
	for (int i=Index+1; i<StuCount; ++i)
		Stus[i-1] = Stus[i];
	--StuCount;
	if ((StuCount % 10 == 0) && (StuCount != 0))
	{
		StuCapacity -= 10;
		Student *temp = new Student [StuCapacity];
		for (int i=0; i<StuCount; ++i)
			temp[i] = Stus[i];
		delete []Stus;
		Stus = temp;
	}
	cout<<"学生信息删除成功。"<<endl;
}

void Proc::UpdateSubjs()
{
	for (int i=0; i<SubjCount; ++i)
		if ( Subjs[i].SubjNum == Subj.SubjNum )
		{
			cout<<"该课程号已存在，记录失败！"<<endl;
			return;
		}
	if ( SubjCount == SubjCapacity )
	{
		SubjCapacity += 10;
		Subject *temp = new Subject [SubjCapacity];
		for (int i=0; i<SubjCount; ++i)
			temp[i] = Subjs[i];
		delete []Subjs;
		Subjs = temp;
	}
	Subjs[SubjCount++] = Subj;
	cout<<"课程信息记录成功。"<<endl;
}

void Proc::UpdateSubjs(int Index)
{
	for (int i=Index+1; i<SubjCount; ++i)
		Subjs[i-1] = Subjs[i];
	--SubjCount;
	if (SubjCount % 10 == 0)
	{
		SubjCapacity -= 10;
		Subject *temp = new Subject [SubjCapacity];
		for (int i=0; i<SubjCount; ++i)
			temp[i] = Subjs[i];
		delete []Subjs;
		Subjs = temp;
	}
	cout<<"课程信息删除成功。"<<endl;
}

void Proc::NewData()
{
	OutFile.open(FileName, ios::out|ios::binary);
	if (!OutFile)
	{
		cout<<"文件打开失败。意外退出。"<<endl;
		exit(1);
	}
	StuCapacity = 10;
	SubjCapacity = 10;
	Stus = new Student [StuCapacity];
	Subjs = new Subject [SubjCapacity];
	Data = new Result* [StuCapacity];
	for (int i=0; i<StuCapacity; ++i)
		Data[i] = new Result [SubjCapacity];
}

void Proc::ReadData()
{
	InFile.read((char*) &StuCount, sizeof(int));
	InFile.read((char*) &StuCapacity, sizeof(int));
	InFile.read((char*) &SubjCount, sizeof(int));
	InFile.read((char*) &SubjCapacity, sizeof(int));
	//	StuCapacity = (StuCount-1) / 10 * 10 + 10;
	//	SubjCapacity = (SubjCount-1) / 10 * 10 + 10;
	Stus = new Student [StuCapacity];
	for (int i=0; i<StuCapacity; ++i)
		InFile.read((char*) &Stus[i], sizeof(Student));
	Subjs = new Subject [SubjCapacity];
	for (int i=0; i<SubjCapacity; ++i)
		InFile.read((char*) &Subjs[i], sizeof(Subject));
	Data = new Result* [StuCapacity];
	for (int i=0; i<StuCapacity; ++i)
		Data[i] = new Result [SubjCapacity];
	for (int i=0; i<StuCapacity; ++i)
		for (int j=0; j<SubjCapacity; ++j)
			InFile.read((char*) &Data[i][j], sizeof(Result));
}

void Proc::WriteData()
{
	/*
	OutFile.close();
	OutFile.open(FileName, ios::out|ios::binary);
	if (!OutFile)
	{
		cout<<"文件打开失败。意外退出。"<<endl;
		exit(1);
	}
	*/
	OutFile.write((char*) &StuCount, sizeof(int));
	OutFile.write((char*) &StuCapacity, sizeof(int));
	OutFile.write((char*) &SubjCount, sizeof(int));
	OutFile.write((char*) &SubjCapacity, sizeof(int));
	for (int i=0; i<StuCapacity; ++i)
		OutFile.write((char*) &Stus[i], sizeof(Student));
	for (int i=0; i<SubjCapacity; ++i)
		OutFile.write((char*) &Subjs[i], sizeof(Subject));
	for (int i=0; i<StuCapacity; ++i)
		for (int j=0; j<SubjCapacity; ++j)
			OutFile.write((char*) &Data[i][j], sizeof(Result));
	cout<<"文件保存成功！"<<endl;
}

void Proc::ReleaseData()
{
	for (int i=StuCapacity-1; i>=0; --i)
	{
		cout<<i<<endl;
		delete []Data[i];
	}
	delete []Data;
	delete []Subjs;
	delete []Stus;
}

// 获得需要查找的学生，用Stu保存所找到的学生，并返回该学生在Stus[]中的下标。
// 返回-1表示未找到，返回-2表示找到多于一个同名的学生。
int Proc::GetStu()
{
	cin.clear();
	cin.sync();
	cout<<"请输入您想操作的学生姓名或学号："<<endl;
	// 用cin.peek()判断所输入的是姓名还是学号
	char ch = cin.peek();
	int n;
	if ((ch >= '0') && (ch <= '9'))
		n = 1;
	else
		n = 2;
	int RepeatCount=0;
	if (n == 1)
	{
		int StuNum;
		cin>>StuNum;
		for (int i=0; i<StuCount; ++i)
			if (Stus[i].StuNum == StuNum)
			{
				Stu = Stus[i];
				++RepeatCount;
				cout<<"已找到该学生。学生信息："<<endl;
				Stus[i].Print();
				return i;
			}			
		if (RepeatCount == 0)
		{
			cout<<"未找到该学生！"<<endl;
			return -1;
		}
	}
	else
	// n == 2
	{
		int RepeatCount=0;
		string StuName;
		cin>>StuName;
		int j = -1;
		for (int i=0; i<StuCount; ++i)
			if (Stus[i].StuName == StuName)
			{
				Stu = Stus[i];
				++RepeatCount;
				j = i;
			}
		if (RepeatCount == 0)
		{
			cout<<"未找到该学生！"<<endl;
			return -1;
		}
		else if (RepeatCount > 1)
		{
			cout<<"存在同名学生！请用学号重新查找。"<<endl;
			return -2;
		}
		else
		{
			cout<<"已找到该学生。学生信息："<<endl;
			Stus[j].Print();
			return j;
		}
	}
}

int Proc::GetSubj()
{
	cin.clear();
	cin.sync();
	cout<<"请输入您想操作的课程名或课程号："<<endl;
	// 用cin.peek()判断所输入的是课程名还是课程号
	char ch = cin.peek();
	int n;
	if ((ch >= '0') && (ch <= '9'))
		n = 1;
	else
		n = 2;
	int RepeatCount=0;
	if (n == 1)
	{
		int SubjNum;
		cin>>SubjNum;
		for (int i=0; i<SubjCount; ++i)
			if (Subjs[i].SubjNum == SubjNum)
			{
				Subj = Subjs[i];
				++RepeatCount;
				cout<<"已找到该课程。课程信息："<<endl;
				Subjs[i].Print();
				return i;
			}			
		if (RepeatCount == 0)
		{
			cout<<"未找到该课程！"<<endl;
			return -1;
		}
	}
	else
	// n == 2
	{
		int RepeatCount=0;
		string SubjName;
		cin>>SubjName;
		int j = -1;
		for (int i=0; i<SubjCount; ++i)
			if (Subjs[i].SubjName == SubjName)
			{
				Subj = Subjs[i];
				++RepeatCount;
				j = i;
			}
		if (RepeatCount == 0)
		{
			cout<<"未找到该课程！"<<endl;
			return -1;
		}
		else if (RepeatCount > 1)
		{
			cout<<"存在同名课程！请用课程号重新查找。"<<endl;
			return -2;
		}
		else
		{
			cout<<"已找到该课程。课程信息："<<endl;
			Subjs[j].Print();
			return j;
		}
	}
}

void Proc::PrintStus()
{
	cout<<"\n全部学生信息：\n"
		<<"   姓名       年龄       性别        学号\n";
	for (int i=0; i<StuCount; ++i)
		Stus[i].PrintBrief();
	cout<<endl;
}

void::Proc::PrintSubjs()
{
	cout<<"\n全部课程信息：\n"
		<<"     课程名         学分       课程号\n";
	for (int i=0; i<SubjCount; ++i)
		Subjs[i].PrintBrief();
	cout<<endl;
}