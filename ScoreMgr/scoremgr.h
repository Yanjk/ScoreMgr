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

// ��ȫ�ֱ�����������������¼ѧ��������ѧ������
extern int SemCount;
extern int StuCount;
extern int SubjCount;
extern int SemCapacity;
extern int StuCapacity;
extern int SubjCapacity;
extern string Gen[2];
extern Proc Global;
extern Semester Sem, *Sems;
extern Student Stu, *Stus;
extern Subject Subj, *Subjs;
extern Result **Data;
extern ifstream InFile;
extern ofstream OutFile;
extern char FileName[20];

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
	void Copy(Student Stu);
	int operator == (Student Stu2);
	friend class Proc;
protected:
	string StuName;
	int Age;
	int Gender;
	int StuNum;
};

// Subject�����ڼ�¼ѧ�ƻ�����Ϣ
class Subject : public BaseData
{
public:
	virtual void Set();
	virtual void Print();
	virtual void Modify();
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
	int Rank;
};

// Proc������˴�����Ϣ�ĸ��ֺ���
class Proc
{
public:
	void Line0();
	void Line1();
	void Welcome();
	void Menu();
	void UpdateSems();
	void UpdateStus();
	void UpdateSubjs();
	void NewData();	
	void ReadData();
	void WriteData();
	void PrintStus();	//
	void PrintSubjs();	//
	void AddStu();		//
	void DelStu();		//
	void ModifyStu();	//
	void AddSubj();		//
	void DelSubj();		//
	void ModifySubj();	//
	void SearchStu();	//
	void SearchSubj();	//
	void SortSubj();	//
	void PrintByStu();	//
	void PrintBySubj();	//
	void CalcGPA();		//
	void SortGPA();		//
};