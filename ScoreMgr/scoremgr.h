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

// 定义全局变量，记录学生总数和学科总数
extern int StuCount;
extern int SubjCount;
extern string Gen[2];
extern Proc Global;

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
	friend class Proc;
protected:
	string StuName;
	int Age;
	int Gender;
	int StuNum;
};

// Subject类用于记录学科基本信息
class Subject : public BaseData
{
public:
	virtual void Set();
	virtual void Print();
	virtual void Modify();
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
	Result(){}
	// 重载的构造函数，用于向继承的基类部分传递信息
	Result(Student Stu, Subject Subj):Student(Stu),Subject(Subj){}
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	friend class Proc;
protected:
	int Score;
	int Rank;
};

// Proc类包含了处理信息的各种函数
class Proc
{
public:
	void Line0();
	void Line1();
	void Welcome();
	void Menu();
	void NewData();
	void ReadData();
	void WriteData();
	void AddStu();
	void DelStu();
	void ModifyStu();
	void SearchStu();
	void AddSubj();
	void DelSubj();
	void ModifySubj();
	void SearchSubj();
	void SortSubj();
	void PrintByStu();
	void PrintBySubj();
	void PrintAll();
	void CalcGPA();
	void SortGPA();
	void CalcAllGPA();
};