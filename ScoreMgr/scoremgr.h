// 头文件，声明了系统中所用的类名、变量与函数

// 确保头文件只被编译一次
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// 定义系统所允许处理的最大学生数和最大科目数
const int STU_MAX = 100;
const int SUBJ_MAX = 100;

// 声明所有的类
class BaseData;
class Semester;
class Student;
class Subject;
class Result;
class Proc;

const string Gen[2]={"女","男"};

extern Proc Global;

void GetInt (int& Int);
void GetInt (int& Int, int UpperBnd);

// 虚基类，作为所有数据类的基类
class BaseData
{
public:
	virtual void Set()=0;
	virtual void Print()=0;
	virtual void Modify()=0;
};

// Semester类用于记录当前处理的学期信息
class Semester : public BaseData
{
public:
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	friend istream & operator >> (istream &input, Semester Sem);
	friend ostream & operator << (ostream &output, Semester Sem);
	int operator == (Semester Sem2);
	friend class Proc;
protected:
	int EntranceYear;
	int YearNum;
	int TermNum;
};

// Student类用于记录学生基本信息
class Student : public BaseData
{
public:
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	void PrintBrief();
	void Copy(Student Stu);
	int operator == (Student Stu2);
	friend class Proc;
protected:
	string StuName;
	int Age;
	int Gender;
	int StuNum;
	int GPA;
};

// Subject类用于记录学科基本信息
class Subject : public BaseData
{
public:
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	void PrintBrief();
	void Copy(Subject Subj);
	int operator == (Subject Subj2);
	friend class Proc;
protected:
	string SubjName;
	int Credit;
	int SubjNum;
};

// Result类多重继承于Student类和Subject类，记录某一学生在某一学科中的成绩情况
class Result : public Student, public Subject
{
public:
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	void Copy(Student Stu, Subject Subj);
	friend class Proc;
protected:
	int Score;
};

// Proc类包含了处理信息的各种函数
class Proc
{
public:
	int StuCount;
	int StuCapacity;
	int SubjCount;
	int SubjCapacity;

	Semester Sem;
	Student *Stus;
	Subject *Subjs;
	Result **Data;
	ifstream InFile;
	ofstream OutFile;
	char FileName[20];

	void Welcome();
	void Menu();

	int ReadFile(int Mode = 1);
	void SaveFile();
	void ReleaseMemory();

	void UpdateStus(Student Stu);
	void UpdateStus(int Index);
	void UpdateSubjs(Subject Subj);
	void UpdateSubjs(int Index);

	int GetStu();
	int GetSubj();

	void NewStu();
	void DeleleStu();
	void ModifyStu();
	void NewSubj();
	void DeleleSubj();
	void ModifySubj();

	int PrintStus();
	int PrintSubjs();
	void PrintByStu(int Index);
	void PrintBySubj(int Index);
	void PrintStuScore();
	void PrintSubjScore();
	void PrintTable();
	void PrintRank();

	void GetStuScore();
	void GetSubjScore();
	void GetStuSubjScore();

	int CalcGPA(int Index);
	int CalcAllGPA();
	void SortGPA();
};