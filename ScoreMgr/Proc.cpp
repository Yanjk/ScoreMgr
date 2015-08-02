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

void Proc::UpdateStus()
{
	for (int i=0; i<StuCount; ++i)
		if ( Stus[i].StuNum == Stu.StuNum )
		{
			cout<<"��ѧ���Ѵ��ڣ���¼ʧ�ܣ�"<<endl;
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
	cout<<"ѧ����Ϣ��¼�ɹ���"<<endl;
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
	cout<<"ѧ����Ϣɾ���ɹ���"<<endl;
}

void Proc::UpdateSubjs()
{
	for (int i=0; i<SubjCount; ++i)
		if ( Subjs[i].SubjNum == Subj.SubjNum )
		{
			cout<<"�ÿγ̺��Ѵ��ڣ���¼ʧ�ܣ�"<<endl;
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
	cout<<"�γ���Ϣ��¼�ɹ���"<<endl;
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
	cout<<"�γ���Ϣɾ���ɹ���"<<endl;
}

void Proc::NewData()
{
	OutFile.open(FileName, ios::out|ios::binary);
	if (!OutFile)
	{
		cout<<"�ļ���ʧ�ܡ������˳���"<<endl;
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
		cout<<"�ļ���ʧ�ܡ������˳���"<<endl;
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
	cout<<"�ļ�����ɹ���"<<endl;
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

// �����Ҫ���ҵ�ѧ������Stu�������ҵ���ѧ���������ظ�ѧ����Stus[]�е��±ꡣ
// ����-1��ʾδ�ҵ�������-2��ʾ�ҵ�����һ��ͬ����ѧ����
int Proc::GetStu()
{
	cin.clear();
	cin.sync();
	cout<<"���������������ѧ��������ѧ�ţ�"<<endl;
	// ��cin.peek()�ж������������������ѧ��
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
				cout<<"���ҵ���ѧ����ѧ����Ϣ��"<<endl;
				Stus[i].Print();
				return i;
			}			
		if (RepeatCount == 0)
		{
			cout<<"δ�ҵ���ѧ����"<<endl;
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
			cout<<"δ�ҵ���ѧ����"<<endl;
			return -1;
		}
		else if (RepeatCount > 1)
		{
			cout<<"����ͬ��ѧ��������ѧ�����²��ҡ�"<<endl;
			return -2;
		}
		else
		{
			cout<<"���ҵ���ѧ����ѧ����Ϣ��"<<endl;
			Stus[j].Print();
			return j;
		}
	}
}

int Proc::GetSubj()
{
	cin.clear();
	cin.sync();
	cout<<"��������������Ŀγ�����γ̺ţ�"<<endl;
	// ��cin.peek()�ж���������ǿγ������ǿγ̺�
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
				cout<<"���ҵ��ÿγ̡��γ���Ϣ��"<<endl;
				Subjs[i].Print();
				return i;
			}			
		if (RepeatCount == 0)
		{
			cout<<"δ�ҵ��ÿγ̣�"<<endl;
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
			cout<<"δ�ҵ��ÿγ̣�"<<endl;
			return -1;
		}
		else if (RepeatCount > 1)
		{
			cout<<"����ͬ���γ̣����ÿγ̺����²��ҡ�"<<endl;
			return -2;
		}
		else
		{
			cout<<"���ҵ��ÿγ̡��γ���Ϣ��"<<endl;
			Subjs[j].Print();
			return j;
		}
	}
}

void Proc::PrintStus()
{
	cout<<"\nȫ��ѧ����Ϣ��\n"
		<<"   ����       ����       �Ա�        ѧ��\n";
	for (int i=0; i<StuCount; ++i)
		Stus[i].PrintBrief();
	cout<<endl;
}

void::Proc::PrintSubjs()
{
	cout<<"\nȫ���γ���Ϣ��\n"
		<<"     �γ���         ѧ��       �γ̺�\n";
	for (int i=0; i<SubjCount; ++i)
		Subjs[i].PrintBrief();
	cout<<endl;
}