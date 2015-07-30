#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int STU_MAX = 100;
const int SUBJ_MAX = 100;

int StuCount=0;
int SubjCount=0;

class BaseData;
class Semester;
class Student;
class Subject;
class Result;
class Proc;

class BaseData
{
public:
	virtual void Set()=0;
	virtual void Print()=0;
	virtual void Modify()=0;
};

class Semester : public BaseData
{
public:
	Semester()	{}
	~Semester()	{}
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

class Student : public BaseData
{
public:
	Student()	{}
	~Student()	{}
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	friend class Proc;
protected:
	char StuName[20];
	int Age;
	int Gender;
	int StuNum;
};

class Subject : public BaseData
{
public:
	Subject()	{}
	~Subject()	{}
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	friend class Proc;
protected:
	char SubjName[20];
	int Credit;
	int SubjNum;
};

class Result : public Student, public Subject
{
public:
	Result()	{}
	~Result()	{}
	virtual void Set();
	virtual void Print();
	virtual void Modify();
	friend class Proc;
protected:
	int Score;
	int Rank;
};

class Proc
{
public:
	Proc()	{}
	~Proc()	{}
	void Welcome();
	void Menu();
	void ReadFile();
	void WriteFile();
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