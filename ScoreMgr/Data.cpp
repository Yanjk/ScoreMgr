#include "Scoremgr.h"

void Semester::Set()
{
	cout<<"������Ҫ������ѧ����Ϣ��\n"
		<<"ѧ����ѧ���:\n";
	GetInt(EntranceYear);
	cout<<"ѧ����ţ�����Ϊ2����"<<endl;
	cin>>YearNum;
	while ( YearNum <= 0 || YearNum > 5 )
	{
		cout<<"�����������������ѧ����ţ�"<<endl;
		cin>>YearNum;
	}
	cout<<"ѧ����ţ���ѧ��Ϊ1����ѧ��Ϊ2����"<<endl;
	cin>>TermNum;
	while ( TermNum != 1 && TermNum != 2 )
	{
		cout<<"�����������������ѧ����š�"<<endl;
		cin>>TermNum;
	}
	cout<<"���óɹ���"<<endl;
	Print();
}

void Semester::Print()
{
	cout<<"��ǰΪ"<<EntranceYear<<"����ѧѧ���ĵ�"<<YearNum<<"ѧ���"<<TermNum<<"ѧ�ڡ�"<<endl;
}

void Semester::Modify()
{
	Set();
}

istream & operator >> (istream &input, Semester Sem)
{
	cout<<"������Ҫ������ѧ����Ϣ��\n"
		<<"ѧ����ѧ���:\n";
	cin>>Sem.EntranceYear;
	cout<<"ѧ����ţ�����Ϊ2����"<<endl;
	cin>>Sem.YearNum;
	while ( Sem.YearNum <= 0 || Sem.YearNum > 5 )
	{
		cout<<"�����������������ѧ����ţ�"<<endl;
		cin>>Sem.YearNum;
	}
	cout<<"ѧ����ţ���ѧ��Ϊ1����ѧ��Ϊ2����"<<endl;
	cin>>Sem.TermNum;
	while ( Sem.TermNum != 1 && Sem.TermNum != 2 )
	{
		cout<<"�����������������ѧ����š�"<<endl;
		cin>>Sem.TermNum;
	}
	cout<<"���óɹ���";
	Sem.Print();
	cout<<endl;
	return input;
}

ostream & operator << (ostream &output, Semester Sem)
{
	cout<<"��ǰΪ"<<Sem.EntranceYear<<"����ѧѧ���ĵ�"<<Sem.YearNum<<"ѧ���"
		<<Sem.TermNum<<"ѧ�ڡ�"<<endl<<endl;
	return output;
}

int Semester::operator == (Semester Sem2)
{
	return ( (EntranceYear==Sem2.EntranceYear) && (YearNum==Sem2.YearNum)
		&& (TermNum==Sem2.TermNum));
}

void Student::Set()
{
	cout<<"\n������ѧ����Ϣ:\n������"<<endl;
	cin>>StuName;
	cout<<"���䣺"<<endl;
	GetInt(Age, 120);
	cout<<"�Ա�ŮΪ0����Ϊ1��:"<<endl;
	GetInt(Gender, 1);
	cout<<"ѧ�ţ�"<<endl;
	GetInt(StuNum);
	Print();
	cout<<endl;
}

void Student::Print()
{
	cout<<"   ����       ����       �Ա�        ѧ��\n"
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
		cout<<"\n������Ҫ�޸ĵ���Ŀ��\n"
			<<"1.����\n"
			<<"2.����\n"
			<<"3.�Ա�\n"
			<<"4.ѧ��\n"
			<<"0.�����޸�\n\n";
		GetInt(Choice, 4);
		switch (Choice)
		{
		case 0: 
			break;
		case 1:
			cout<<"�µ�����Ϊ��"<<endl;
			cin>>StuName;
			break;
		case 2:
			cout<<"�µ�����Ϊ��"<<endl;
			GetInt(Age, 120);
			break;
		case 3:
			cout<<"�µ��Ա�Ϊ��ŮΪ0����Ϊ1����"<<endl;
			GetInt(Gender, 1);
			break;
		case 4:
			cout<<"�µ�ѧ��Ϊ��"<<endl;
			GetInt(StuNum);
			break;
		}
		if ( Choice != 0 )
		{
			cout<<"�޸ĳɹ���"<<endl;
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
	cout<<"\n������γ���Ϣ��\n���ƣ�"<<endl;
	cin>>SubjName;
	cout<<"ѧ�֣�"<<endl;
	GetInt(Credit);
	cout<<"�γ̺ţ�"<<endl;
	GetInt(SubjNum);
	Print();
	cout<<endl;
}

void Subject::Print()
{
	cout<<"     �γ���        ѧ��       �γ̺�\n"
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
		cout<<"\n������Ҫ�޸ĵ���Ŀ��\n"
			<<"1.�γ���\n"
			<<"2.ѧ��\n"
			<<"3.�γ̺�\n"
			<<"0.�����޸�\n\n";
		GetInt(Choice, 3);
		switch (Choice)
		{
		case 0:
			break;
		case 1:
			cout<<"�µĿγ���Ϊ��"<<endl;
			cin>>SubjName;
			break;
		case 2:
			cout<<"�µ�ѧ��Ϊ��"<<endl;
			GetInt(Credit);
			break;
		case 3:
			cout<<"�µĿγ̺�Ϊ��"<<endl;
			GetInt(SubjNum);
			break;
		}
		if ( Choice >= 1 && Choice <= 3 )
		{
			cout<<"�޸ĳɹ���"<<endl;
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
	cout<<"\n������ "<<StuName<<" �� "<<SubjName<<" �γ̳ɼ���"<<endl;
	GetInt(Score);
	cout<<"�ɼ�¼��ɹ���\n\n";
}

void Result::Print()
{
	cout<<StuName<<" �� "<<SubjName<<" �γ̳ɼ�Ϊ "<<Score<<endl;
}

void Result::Modify()
{
	cout<<StuName<<" �� "<<SubjName<<" �γ�ԭ�ɼ�Ϊ "<<Score<<endl
		<<"�������޸ĺ�ĳɼ���"<<endl;
	int temp;
	GetInt(temp);
	cout<<"�Ƿ�ȷ���޸ĳɼ���������ѡ��\n����1ȷ�ϡ�\n";
	int Choice;
	cin>>Choice;
	if (Choice == 1)
	{
		Score = temp;
		cout<<"�޸ĳɹ��� "<<StuName<<" �� "<<SubjName<<" �γ̳ɼ�Ϊ "<<Score<<endl;
	}
	else
		cout<<"�ѷ����޸ġ�"<<endl;
	cin.clear();
	cin.sync();
}

void Result::Copy(Student Stu, Subject Subj)
{
	Student::Copy(Stu);
	Subject::Copy(Subj);
	Score = -1;
}
