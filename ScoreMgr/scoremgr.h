// ͷ�ļ���������ϵͳ�����õ������������뺯��

// ȷ��ͷ�ļ�ֻ������һ��
#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// ����ϵͳ������������ѧ����������Ŀ��
const int STU_MAX = 100;
const int SUBJ_MAX = 100;

// �������е���
class BaseData;
class Semester;
class Student;
class Subject;
class Result;
class Proc;

const string Gen[2]={"Ů","��"};

extern Proc Global;

void GetInt (int& Int);
void GetInt (int& Int, int UpperBnd);

// ����࣬��Ϊ����������Ļ���
class BaseData
{
public:
	virtual void Set()=0;
	virtual void Print()=0;
	virtual void Modify()=0;
};

// Semester�����ڼ�¼��ǰ�����ѧ����Ϣ
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

// Student�����ڼ�¼ѧ��������Ϣ
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

// Subject�����ڼ�¼ѧ�ƻ�����Ϣ
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

// Result����ؼ̳���Student���Subject�࣬��¼ĳһѧ����ĳһѧ���еĳɼ����
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

// Proc������˴�����Ϣ�ĸ��ֺ���
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