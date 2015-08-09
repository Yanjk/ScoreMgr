#include "Scoremgr.h"

// 全局变量，用于调用全局的操作函数
Proc Global;

// 改进的读入int的函数，确保读入的是整数
void GetInt (int& Int)
{
	cin.clear();
	cin.sync();
	cin>>Int;
	while (cin.fail())
	{
		cin.clear();
		cin.sync();
		cout<<"输入错误，请重新输入：\n";
		cin>>Int;
	}
}

// 改进的读入int的函数，确保读入的是0到UpperBound之间的整数
void GetInt (int& Int, int UpperBnd)
{
	cin.clear();
	cin.sync();
	cin>>Int;
	while (cin.fail() || Int < 0 || Int > UpperBnd)
	{
		cin.clear();
		cin.sync();
		cout<<"输入错误，请重新输入：\n";
		cin>>Int;
	}
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

int Proc::ReadFile(int Mode)
{
	Sem.Set();
	sprintf(FileName,"%d_%d_%d.txt", Sem.EntranceYear, Sem.YearNum, Sem.TermNum);
	InFile.open(FileName);
	if ( !InFile )
	{
		if (Mode == 0)
		{
			cout<<"该学期数据未录入。\n";
			return 0;
		}
		cout<<"该学期数据未录入。将创建新文件。\n";
		InFile.close();
		InFile.clear();
		OutFile.open(FileName);
		OutFile<<0<<' '<<10<<' '<<0<<' '<<10<<'\n';
		OutFile.close();
		StuCount = 0;
		StuCapacity = 10;
		Stus = new Student [StuCapacity];
		SubjCount = 0;
		SubjCapacity = 10;
		Subjs = new Subject [SubjCapacity];
		Data = new Result* [StuCapacity];
		for (int i=0; i<StuCapacity; ++i)
			Data[i] = new Result [SubjCapacity];
		return 0;
	}
	else
	{
		cout<<"找到该学期数据。将从文件读取。\n";
		InFile >> StuCount >> StuCapacity >> SubjCount >> SubjCapacity;
		Stus = new Student [StuCapacity];
		for (int i=0; i<StuCount; ++i)
			InFile >> Stus[i].StuName >> Stus[i].Age
				>> Stus[i].Gender >> Stus[i].StuNum;
		Subjs = new Subject [SubjCapacity];
		for (int i=0; i<SubjCount; ++i)
			InFile >> Subjs[i].SubjName >> Subjs[i].Credit >> Subjs[i].SubjNum;
		Data = new Result* [StuCapacity];
		for (int i=0; i<StuCapacity; ++i)
			Data[i] = new Result [SubjCapacity];
		for (int i=0; i<StuCount; ++i)
			for (int j=0; j<SubjCount; ++j)
			{
				Data[i][j].Copy(Stus[i], Subjs[j]);
				InFile >> Data[i][j].Score;
			}
		InFile.close();
		return 1;
	}
}

void Proc::SaveFile()
{
	OutFile.open(FileName);
	if ( !OutFile )
	{
		cout<<"文件意外打开失败！\n";
		return;
	}
	OutFile << StuCount <<" "<< StuCapacity <<" "<< SubjCount <<" "<< SubjCapacity<<'\n'<<'\n';
	for (int i=0; i<StuCount; ++i)
		OutFile << Stus[i].StuName <<' '<< Stus[i].Age <<' '
				<< Stus[i].Gender <<' '<< Stus[i].StuNum <<"\n";
	OutFile<<'\n';
	for (int i=0; i<SubjCount; ++i)
		OutFile << Subjs[i].SubjName <<' '<< Subjs[i].Credit <<' '<< Subjs[i].SubjNum <<'\n';
	OutFile<<'\n';
	for (int i=0; i<StuCount; ++i)
	{
		for (int j=0; j<SubjCount; ++j)
			OutFile << Data[i][j].Score <<' ';
		OutFile<<endl;
	}
}

void Proc::ReleaseMemory()
{
	for (int i=0; i<StuCapacity; ++i)
		delete []Data[i];
	delete []Data;
	delete []Subjs;
	delete []Stus;
}

void Proc::UpdateStus(Student Stu)
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
	for (int i=0; i<SubjCount; ++i)
		Data[StuCount-1][i].Copy(Stu, Subjs[i]);
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

void Proc::UpdateSubjs(Subject Subj)
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
	for (int i=0; i<StuCount; ++i)
		Data[i][SubjCount-1].Copy(Stus[i], Subj);
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

// 获得需要查找的学生，用Stu保存所找到的学生，并返回该学生在Stus[]中的下标。
// 返回-1表示未找到，返回-2表示找到多于一个同名的学生。
int Proc::GetStu()
{
	cin.clear();
	cin.sync();
	int RepeatCount=0;
	cout<<"请输入您想操作的学生姓名或学号："<<endl;
	// 用cin.peek()判断所输入的是姓名还是学号
	char ch = cin.peek();
	// 判断：若输入的是学号
	if ((ch >= '0') && (ch <= '9'))
	{
		int StuNum;
		cin >> StuNum;
		for (int i=0; i<StuCount; ++i)
			if (Stus[i].StuNum == StuNum)
			{
				++RepeatCount;
				cout<<"已找到该学生。学生信息：\n";
				Stus[i].Print();
				cout<<endl;
				return i;
			}
		cout<<"未找到该学生！\n";
		return -1;
	}
	// 判断：若输入的是姓名
	else
	{
		string StuName;
		cin >> StuName;
		int j = -1;
		for (int i=0; i<StuCount; ++i)
			if (Stus[i].StuName == StuName)
			{
				++RepeatCount;
				j = i;
			}
		if (RepeatCount == 0)
		{
			cout<<"未找到该学生！\n";
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
			cout<<endl;
			return j;
		}
	}
}

int Proc::GetSubj()
{
	cin.clear();
	cin.sync();
	int RepeatCount=0;
	cout<<"请输入您想操作的课程名或课程号："<<endl;
	// 用cin.peek()判断所输入的是课程名还是课程号
	char ch = cin.peek();
	// 判断：若输入的是课程号
	if ((ch >= '0') && (ch <= '9'))
	{
		int SubjNum;
		cin >> SubjNum;
		for (int i=0; i<SubjCount; ++i)
			if (Subjs[i].SubjNum == SubjNum)
			{
				++RepeatCount;
				cout<<"已找到该课程。课程信息：\n";
				Subjs[i].Print();
				cout<<endl;
				return i;
			}
		cout<<"未找到该课程！\n";
		return -1;
	}
	// 判断：若输入的是课程名
	else
	{
		string SubjName;
		cin >> SubjName;
		int j = -1;
		for (int i=0; i<SubjCount; ++i)
			if (Subjs[i].SubjName == SubjName)
			{
				++RepeatCount;
				j = i;
			}
		if (RepeatCount == 0)
		{
			cout<<"未找到该课程！\n";
			return -1;
		}
		else if (RepeatCount > 1)
		{
			cout<<"存在同名课程！请用课程号重新查找。\n";
			return -2;
		}
		else
		{
			cout<<"已找到该课程。课程信息：\n";
			Subjs[j].Print();
			cout<<endl;
			return j;
		}
	}
}

void Proc::NewStu()
{
	Student tempStu;
	tempStu.Set();
	UpdateStus(tempStu);
}

void Proc::DeleleStu()
{
	int Index = GetStu();
	if (Index >= 0)
		UpdateStus(Index);
}

void Proc::ModifyStu()
{
	int Index = GetStu();
	if (Index >= 0)
		Stus[Index].Modify();
}

void Proc::NewSubj()
{
	Subject tempSubj;
	tempSubj.Set();
	UpdateSubjs(tempSubj);
}

void Proc::DeleleSubj()
{
	int Index = GetSubj();
	if (Index >= 0)
		UpdateSubjs(Index);
}

void Proc::ModifySubj()
{
	int Index = GetSubj();
	if (Index >= 0)
		Subjs[Index].Modify();
}

int Proc::PrintStus()
{
	if (StuCount == 0)
	{
		cout<<"学生信息为空！"<<endl;
		return 0;
	}
	else
	{
		cout<<"\n全部学生信息：\n"
			<<"   姓名       年龄       性别        学号\n";
		for (int i=0; i<StuCount; ++i)
			Stus[i].PrintBrief();
		cout<<endl;
		return 1;
	}
}

int Proc::PrintSubjs()
{
	if (SubjCount == 0)
	{
		cout<<"课程信息为空！"<<endl;
		return 0;
	}
	else
	{
		cout<<"\n全部课程信息：\n"
			<<"     课程名         学分       课程号\n";
		for (int i=0; i<SubjCount; ++i)
			Subjs[i].PrintBrief();
		cout<<endl;
		return 1;
	}
}

void Proc::PrintByStu(int Index)
{
	int Count = 0;
	for (int i=0; i<SubjCount; ++i)
	{
		if ((Data[Index][i].Score >= 0) && (Data[Index][i].Score <=100))
		{
			++Count;
			if (Count == 1)
				cout<<"    课程名        成绩\n";
			cout<<setw(10)<<Subjs[i].SubjName
				<<setw(10)<<Data[Index][i].Score<<endl;
		}
	}
	if (Count == 0)
		cout<<"该学生的成绩信息为空！"<<endl;
	cout<<endl;
}

void Proc::PrintBySubj(int Index)
{
	int Count = 0;
	for (int i=0; i<StuCount; ++i)
	{
		if ((Data[i][Index].Score >= 0) && (Data[i][Index].Score <=100))
		{
			++Count;
			if (Count == 1)
				cout<<"    姓名        成绩\n";
			cout<<setw(8)<<Stus[i].StuName
				<<setw(10)<<Data[i][Index].Score<<endl;
		}
	}
	if (Count == 0)
		cout<<"该课程的成绩信息为空！"<<endl;
	cout<<endl;
}

void Proc::PrintStuScore()
{
	int Index = GetStu();
	if (Index >= 0)
	{
		PrintByStu(Index);
		if (CalcGPA(Index))
			cout<<Stus[Index].StuName<<" 的GPA为 "<<Stus[Index].GPA<<endl<<endl;
	}
}

void Proc::PrintSubjScore()
{
	int Index = GetSubj();
	if (Index >= 0)
		PrintBySubj(Index);
}

void Proc::PrintTable()
{
	if (StuCount == 0)
	{
		cout<<"学生信息为空，无法打印成绩表！\n";
		return;
	}
	if (SubjCount == 0)
	{
		cout<<"课程信息为空，无法打印成绩表！\n";
		return;
	}
	for (int i=0; i<80; ++i)
		cout<<'=';
	cout<<endl;
	int Cursor = -1;
	while (Cursor < SubjCount-1)
	{
		int temp = Cursor + 1;
		cout<<setw(8)<<' ';
		for (int i=0; (i<6) && (Cursor < SubjCount-1); ++i)
			cout<<setw(11)<< Subjs[ ++Cursor ].SubjName;
		cout<<endl;
		for (int i=0; i<80; ++i)
			cout<<'-';
		for (int i=0; i<StuCount; ++i)
		{
			cout<<setw(6)<< Stus[i].StuName <<" |";
			for (int j=temp; (j < temp+6) && (j < SubjCount); ++j)
				cout<<setw(11)<< Data[i][j].Score;
			cout<<endl;
		}
	}
	cout<<endl;
	for (int i=0; i<80; ++i)
		cout<<'=';
	cout<<endl;

}

void Proc::PrintRank()
{
	if (CalcAllGPA())
		SortGPA();
	else
		cout<<"学生成绩信息为空！"<<endl;
}

void Proc::GetStuScore()
{
	int Index = GetStu();
	if (Index >= 0)
		if (PrintSubjs())
		{
			cout<<"请按以上顺序依次逐行输入该学生的各科成绩（用回车分隔）。未选课请输入-1。"<<endl;
			cin.clear();
			cin.sync();
			for (int i=0; i<SubjCount; ++i)
				GetInt(Data[Index][i].Score, 100);
			cout<<"成功录入该学生成绩。"<<endl;
		}
	cin.clear();
	cin.sync();
}

void Proc::GetSubjScore()
{
	int Index = GetSubj();
	if (Index >= 0)
		if (PrintStus())
		{
			cout<<"请按以上顺序依次逐行输入各学生的该课程成绩（用回车分隔）。未选课请输入-1。"<<endl;
			cin.clear();
			cin.sync();
			for (int i=0; i<StuCount; ++i)
				GetInt(Data[i][Index].Score, 100);
			cout<<"成功录入该课程成绩。"<<endl;
		}
	cin.clear();
	cin.sync();
}

void Proc::GetStuSubjScore()
{
	int StuIndex = GetStu();
	if (StuIndex >= 0)
	{
		int SubjIndex = GetSubj();
		if (SubjIndex >= 0)
			if ((Data[StuIndex][SubjIndex].Score >= 0) && 
				(Data[StuIndex][SubjIndex].Score <= 100))
				Data[StuIndex][SubjIndex].Modify();
			else 
			{
				cout<<"请输入该学生的该课程成绩。未选课请输入-1。"<<endl;
				cin.clear();
				cin.sync();
				GetInt(Data[StuIndex][SubjIndex].Score, 100);
				cout<<"成功录入该成绩。"<<endl;
			}
	}
}

int Proc::CalcGPA(int Index)
{
	int CreditSum = 0;
	int ScoreSum = 0;
	for (int i=0; i<SubjCount; ++i)
		if ((Data[Index][i].Score >= 0) && (Data[Index][i].Score <= 100))
		{
			CreditSum += Subjs[i].Credit;
			ScoreSum += Data[Index][i].Score * Subjs[i].Credit;
		}
	if (CreditSum == 0)
		return 0;
	Stus[Index].GPA = ScoreSum / CreditSum;
	return 1;
}

int Proc::CalcAllGPA()
{
	int Flag = 0;
	for (int i=0; i<StuCount; ++i)
		if (Global.CalcGPA(i))
			Flag = 1;
	return Flag;
}

void Proc::SortGPA()
{
	int* Index = new int [StuCount];
	int IndexCount = 0;
	for (int i=0; i<StuCount; ++i)
		if ((Stus[i].GPA >= 0) && (Stus[i].GPA <= 100))
			Index [IndexCount++] = i;
	int temp;
	int LowerBnd = 0;
	int UpperBnd = IndexCount - 1;
	int Changed;
	while (LowerBnd < UpperBnd)
	{
		for (int i=LowerBnd; i<UpperBnd; ++i)
		{
			if (Stus[Index[i]].GPA < Stus[Index[i+1]].GPA)
			{
				temp = Index[i];
				Index[i] = Index[i+1];
				Index[i+1] = temp;
				Changed = i;
			}
			UpperBnd = i;
		}
		for (int i=UpperBnd; i>LowerBnd; --i)
		{
			if (Stus[Index[i]].GPA > Stus[Index[i-1]].GPA)
			{
				temp = Index[i];
				Index[i] = Index[i-1];
				Index[i-1] = temp;
				Changed = i;
			}
			LowerBnd = i;
		}
		cout<<"\n  排名       姓名       GPA\n";
		for (int i=0; i<IndexCount; ++i)
		{
			cout<<setw(5)<<i+1<<setw(11)<<Stus[Index[i]].StuName
				<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<Stus[Index[i]].GPA<<endl;
		}
		cout<<endl;
	}
}