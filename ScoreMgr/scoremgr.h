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

// ����ȫ�ֱ�������¼ѧ��������ѧ������
extern int StuCount;
extern int SubjCount;
extern string Gen[2];
extern Proc Global;

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
	Result(){}
	// ���صĹ��캯����������̳еĻ��ಿ�ִ�����Ϣ
	Result(Student Stu, Subject Subj):Student(Stu),Subject(Subj){}
	virtual void Set();
	virtual void Print();
	virtual void Modify();
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