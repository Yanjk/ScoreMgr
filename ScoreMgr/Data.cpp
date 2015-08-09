#include "Scoremgr.h"

void Semester::Set()
{
	cout<<"请输入要操作的学期信息：\n"
		<<"学生入学年份:\n";
	GetInt(EntranceYear);
	cout<<"学年序号（如大二为2）："<<endl;
	cin>>YearNum;
	while ( YearNum <= 0 || YearNum > 5 )
	{
		cout<<"输入错误，请重新输入学年序号："<<endl;
		cin>>YearNum;
	}
	cout<<"学期序号（上学期为1，下学期为2）："<<endl;
	cin>>TermNum;
	while ( TermNum != 1 && TermNum != 2 )
	{
		cout<<"输入错误，请重新输入学期序号。"<<endl;
		cin>>TermNum;
	}
	cout<<"设置成功！"<<endl;
	Print();
}

void Semester::Print()
{
	cout<<"当前为"<<EntranceYear<<"年入学学生的第"<<YearNum<<"学年第"<<TermNum<<"学期。"<<endl;
}

void Semester::Modify()
{
	Set();
}

istream & operator >> (istream &input, Semester Sem)
{
	cout<<"请输入要操作的学期信息：\n"
		<<"学生入学年份:\n";
	cin>>Sem.EntranceYear;
	cout<<"学年序号（如大二为2）："<<endl;
	cin>>Sem.YearNum;
	while ( Sem.YearNum <= 0 || Sem.YearNum > 5 )
	{
		cout<<"输入错误，请重新输入学年序号："<<endl;
		cin>>Sem.YearNum;
	}
	cout<<"学期序号（上学期为1，下学期为2）："<<endl;
	cin>>Sem.TermNum;
	while ( Sem.TermNum != 1 && Sem.TermNum != 2 )
	{
		cout<<"输入错误，请重新输入学期序号。"<<endl;
		cin>>Sem.TermNum;
	}
	cout<<"设置成功！";
	Sem.Print();
	cout<<endl;
	return input;
}

ostream & operator << (ostream &output, Semester Sem)
{
	cout<<"当前为"<<Sem.EntranceYear<<"年入学学生的第"<<Sem.YearNum<<"学年第"
		<<Sem.TermNum<<"学期。"<<endl<<endl;
	return output;
}

int Semester::operator == (Semester Sem2)
{
	return ( (EntranceYear==Sem2.EntranceYear) && (YearNum==Sem2.YearNum)
		&& (TermNum==Sem2.TermNum));
}

void Student::Set()
{
	cout<<"\n请输入学生信息:\n姓名："<<endl;
	cin>>StuName;
	cout<<"年龄："<<endl;
	GetInt(Age, 120);
	cout<<"性别（女为0，男为1）:"<<endl;
	GetInt(Gender, 1);
	cout<<"学号："<<endl;
	GetInt(StuNum);
	Print();
	cout<<endl;
}

void Student::Print()
{
	cout<<"   姓名       年龄       性别        学号\n"
		<<setw(7)<<StuName<<setw(10)<<Age
		<<setw(11)<<Gen[Gender]<<setw(14)<<StuNum<<endl;
}

void Student::PrintBrief()
{
	cout<<setw(7)<<StuName<<setw(10)<<Age
		<<setw(11)<<Gen[Gender]<<setw(14)<<StuNum<<endl;
}

void Student::Modify()
{
	int Choice;
	do
	{
		cout<<"\n请输入要修改的项目：\n"
			<<"1.姓名\n"
			<<"2.年龄\n"
			<<"3.性别\n"
			<<"4.学号\n"
			<<"0.结束修改\n\n";
		GetInt(Choice, 4);
		switch (Choice)
		{
		case 0: 
			break;
		case 1:
			cout<<"新的姓名为："<<endl;
			cin>>StuName;
			break;
		case 2:
			cout<<"新的年龄为："<<endl;
			GetInt(Age, 120);
			break;
		case 3:
			cout<<"新的性别为（女为0，男为1）："<<endl;
			GetInt(Gender, 1);
			break;
		case 4:
			cout<<"新的学号为："<<endl;
			GetInt(StuNum);
			break;
		}
		if ( Choice != 0 )
		{
			cout<<"修改成功！"<<endl;
			Print();
		}
	} while (Choice != 0);
	cout<<endl;
}

void Student::Copy(Student Stu)
{
	StuName = Stu.StuName;
	Age = Stu.Age;
	Gender = Stu.Gender;
	StuNum = Stu.StuNum;
}

int Student::operator == (Student Stu2)
{
	return ( (StuName ==Stu2.StuName) && (Age == Stu2.Age) 
		&& (Gender == Stu2.Gender) && (StuNum == Stu2.StuNum) );
}

void Subject::Set()
{
	cout<<"\n请输入课程信息：\n名称："<<endl;
	cin>>SubjName;
	cout<<"学分："<<endl;
	GetInt(Credit);
	cout<<"课程号："<<endl;
	GetInt(SubjNum);
	Print();
	cout<<endl;
}

void Subject::Print()
{
	cout<<"     课程名        学分       课程号\n"
		<<setw(12)<<SubjName<<setw(10)<<Credit
		<<setw(14)<<SubjNum<<endl;
}

void Subject::PrintBrief()
{
	cout<<setw(12)<<SubjName<<setw(10)<<Credit
		<<setw(14)<<SubjNum<<endl;
}

void Subject::Modify()
{
	int Choice;
	do
	{
		cout<<"\n请输入要修改的项目：\n"
			<<"1.课程名\n"
			<<"2.学分\n"
			<<"3.课程号\n"
			<<"0.结束修改\n\n";
		GetInt(Choice, 3);
		switch (Choice)
		{
		case 0:
			break;
		case 1:
			cout<<"新的课程名为："<<endl;
			cin>>SubjName;
			break;
		case 2:
			cout<<"新的学分为："<<endl;
			GetInt(Credit);
			break;
		case 3:
			cout<<"新的课程号为："<<endl;
			GetInt(SubjNum);
			break;
		}
		if ( Choice >= 1 && Choice <= 3 )
		{
			cout<<"修改成功！"<<endl;
			Print();
		}
	} while (Choice != 0);
	cout<<endl;
}

void Subject::Copy(Subject Subj)
{
	SubjName = Subj.SubjName;
	Credit = Subj.Credit;
	SubjNum = Subj.SubjNum;
}

int Subject::operator == (Subject Subj2)
{
	return ( (SubjName == Subj2.SubjName) && (Credit == Subj2.Credit)
		&& (SubjNum == Subj2.SubjNum) );
}

void Result::Set()
{
	cout<<"\n请输入 "<<StuName<<" 的 "<<SubjName<<" 课程成绩："<<endl;
	GetInt(Score);
	cout<<"成绩录入成功！\n\n";
}

void Result::Print()
{
	cout<<StuName<<" 的 "<<SubjName<<" 课程成绩为 "<<Score<<endl;
}

void Result::Modify()
{
	cout<<StuName<<" 的 "<<SubjName<<" 课程原成绩为 "<<Score<<endl
		<<"请输入修改后的成绩："<<endl;
	int temp;
	GetInt(temp);
	cout<<"是否确认修改成绩？请慎重选择！\n输入1确认。\n";
	int Choice;
	cin>>Choice;
	if (Choice == 1)
	{
		Score = temp;
		cout<<"修改成功！ "<<StuName<<" 的 "<<SubjName<<" 课程成绩为 "<<Score<<endl;
	}
	else
		cout<<"已放弃修改。"<<endl;
	cin.clear();
	cin.sync();
}

void Result::Copy(Student Stu, Subject Subj)
{
	Student::Copy(Stu);
	Subject::Copy(Subj);
	Score = -1;
}
