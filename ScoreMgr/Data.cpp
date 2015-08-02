#include "Scoremgr.h"

void Semester::Set()
{
	Global.Line0();
	cout<<"������Ҫ������ѧ����Ϣ��\n"
		<<"ѧ����ѧ���:\n";
	cin>>EntranceYear;
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
	Global.Line1();
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
	Global.Line0();
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
	Global.Line1();
	return input;
}

ostream & operator << (ostream &output, Semester Sem)
{
	Global.Line0();
	cout<<"��ǰΪ"<<Sem.EntranceYear<<"����ѧѧ���ĵ�"<<Sem.YearNum<<"ѧ���"
		<<Sem.TermNum<<"ѧ�ڡ�"<<endl;
	Global.Line1();
	return output;
}

int Semester::operator == (Semester Sem2)
{
	return ( (EntranceYear==Sem2.EntranceYear) && (YearNum==Sem2.YearNum)
		&& (TermNum==Sem2.TermNum));
}

void Student::Set()
{
	Global.Line0();
	cout<<"������ѧ����Ϣ:\n������"<<endl;
	StuName.reserve(20);
	cin>>StuName;
	cout<<"���䣺"<<endl;
	cin>>Age;
	cout<<"�Ա�ŮΪ0����Ϊ1��:"<<endl;
	cin>>Gender;
	if ( Gender != 0 && Gender != 1 )
	{
		cout<<"������������������Ա�ŮΪ0����Ϊ1����"<<endl;
		cin>>Gender;
	}
	cout<<"ѧ�ţ�"<<endl;
	cin>>StuNum;
	cout<<"ѧ����Ϣ¼��ɹ���";
	Print();
	Global.Line1();
}

void Student::Print()
{
	cout<<"������"<<StuName<<"  ���䣺"<<Age<<"  �Ա�"<<Gen[Gender]
		<<"  ѧ�ţ�"<<StuNum<<endl;
}

void Student::Modify()
{
	Global.Line0();
	cout<<"��ѧ��ԭ��ϢΪ��"<<endl;
	Print();
	cout<<"\n������Ҫ�޸ĵ���Ŀ��\n"
		<<"1.����\n"
		<<"2.����\n"
		<<"3.�Ա�\n"
		<<"4.ѧ��\n"
		<<"0.�����޸�\n\n";
	int Choice;
	cin.clear();
	cin.sync();
	cin>>Choice;
	while (Choice != 0)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout<<"����������������룺"<<endl;
			cin>>Choice;
		}
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
			cin>>Age;
			break;
		case 3:
			cout<<"�µ��Ա�Ϊ��ŮΪ0����Ϊ1����"<<endl;
			cin>>Gender;
			break;
		case 4:
			cout<<"�µ�ѧ��Ϊ��"<<endl;
			cin>>StuNum;
			break;
		default:
			cout<<"����������������룺"<<endl;
			break;
		}
		if ( Choice >= 1 && Choice <= 4 )
		{
			cout<<"�޸ĳɹ���"<<endl;
			Print();
		}
		cout<<"\n������Ҫ�޸ĵ���Ŀ��\n"
			<<"1.����\n"
			<<"2.����\n"
			<<"3.�Ա�\n"
			<<"4.ѧ��\n"
			<<"0.�����޸�\n\n";
		cin.clear();
		cin.sync();
		cin>>Choice;
	}
	Global.Line1();
}

void Student::Copy(Student Stu)
{
	StuName=Stu.StuName;
	Age=Stu.Age;
	Gender=Stu.Gender;
	StuNum=Stu.StuNum;
}

int Student::operator == (Student Stu2)
{
	return ( (StuName==Stu2.StuName) &&  (Age==Stu2.Age) 
		&& (Gender==Stu2.Gender) && (StuNum==Stu2.StuNum) );
}

void Subject::Set()
{
	Global.Line0();
	cout<<"������γ���Ϣ��\n���ƣ�"<<endl;
	cin>>SubjName;
	cout<<"ѧ�֣�"<<endl;
	cin>>Credit;
	cout<<"�γ̺ţ�"<<endl;
	cin>>SubjNum;
	cout<<"�γ���Ϣ¼��ɹ���"<<endl;
	Print();
	Global.Line1();
}

void Subject::Print()
{
	cout<<"�γ�����"<<SubjName<<"  ѧ�֣�"<<Credit
		<<"  �γ̺ţ�"<<SubjNum<<endl;
}

void Subject::Modify()
{
	Global.Line0();
	cout<<"�ÿγ�ԭ��ϢΪ��"<<endl;
	Print();
	cout<<"\n������Ҫ�޸ĵ���Ŀ��\n"
		<<"1.�γ���\n"
		<<"2.ѧ��\n"
		<<"3.�γ̺�\n"
		<<"0.�����޸�\n\n";
	int Choice;
	cin.clear();
	cin.sync();
	cin>>Choice;
	while (Choice != 0)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout<<"����������������룺"<<endl;
			cin>>Choice;
		}
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
			cin>>Credit;
			break;
		case 3:
			cout<<"�µĿγ̺�Ϊ��"<<endl;
			cin>>SubjNum;
			break;
		default:
			cout<<"����������������룺"<<endl;
			break;
		}
		if ( Choice >= 1 && Choice <= 3 )
		{
			cout<<"�޸ĳɹ���"<<endl;
			Print();
		}
		cout<<"\n������Ҫ�޸ĵ���Ŀ��\n"
			<<"1.�γ���\n"
			<<"2.ѧ��\n"
			<<"3.�γ̺�\n"
			<<"0.�����޸�\n\n";
		cin.clear();
		cin.sync();
		cin>>Choice;
	}
	Global.Line1();	
}

void Subject::Copy(Subject Subj)
{
	SubjName=Subj.SubjName;
	Credit=Subj.Credit;
	SubjNum=Subj.SubjNum;
}

int Subject::operator == (Subject Subj2)
{
	return ( (SubjName==Subj2.SubjName) && (Credit==Subj2.Credit)
		&& (SubjNum==Subj2.SubjNum) );
}

void Result::Set()
{
	Global.Line0();
	cout<<"������ "<<StuName<<" �� "<<SubjName<<" �γ̳ɼ���"<<endl;
	cin>>Score;
	cout<<"�ɼ�¼��ɹ���"<<endl;
	Global.Line1();
}

void Result::Print()
{
	cout<<StuName<<" �� "<<SubjName<<" �γ̳ɼ�Ϊ "<<Score<<endl;
}

void Result::Modify()
{
	Global.Line0();
	cout<<StuName<<" �� "<<SubjName<<" �γ�ԭ�ɼ�Ϊ "<<Score<<endl
		<<"�������޸ĺ�ĳɼ���"<<endl;
	int Temp;
	cin>>Temp;
	cout<<"�Ƿ�ȷ���޸ĳɼ���������ѡ��\n����1ȷ�ϡ�\n";
	int Choice;
	cin>>Choice;
	if (Choice == 1)
	{
		Score = Temp;
		cout<<"�޸ĳɹ��� "<<StuName<<" �� "<<SubjName<<" �γ̳ɼ�Ϊ "<<Score<<endl;
	}
	else cout<<"�ѷ����޸ġ�"<<endl;
	Global.Line1();
}

void Result::Copy(Student Stu, Subject Subj)
{
	Student::Copy(Stu);
	Subject::Copy(Subj);
}
