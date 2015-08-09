#include "Scoremgr.h"

// ȫ�ֱ��������ڵ���ȫ�ֵĲ�������
Proc Global;

// �Ľ��Ķ���int�ĺ�����ȷ�������������
void GetInt (int& Int)
{
	cin.clear();
	cin.sync();
	cin>>Int;
	while (cin.fail())
	{
		cin.clear();
		cin.sync();
		cout<<"����������������룺\n";
		cin>>Int;
	}
}

// �Ľ��Ķ���int�ĺ�����ȷ���������0��UpperBound֮�������
void GetInt (int& Int, int UpperBnd)
{
	cin.clear();
	cin.sync();
	cin>>Int;
	while (cin.fail() || Int < 0 || Int > UpperBnd)
	{
		cin.clear();
		cin.sync();
		cout<<"����������������룺\n";
		cin>>Int;
	}
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

int Proc::ReadFile(int Mode)
{
	Sem.Set();
	sprintf(FileName,"%d_%d_%d.txt", Sem.EntranceYear, Sem.YearNum, Sem.TermNum);
	InFile.open(FileName);
	if ( !InFile )
	{
		if (Mode == 0)
		{
			cout<<"��ѧ������δ¼�롣\n";
			return 0;
		}
		cout<<"��ѧ������δ¼�롣���������ļ���\n";
		InFile.close();
		InFile.clear();
		OutFile.open(FileName);
		OutFile<<0<<' '<<10<<' '<<0<<' '<<10<<'\n';
		OutFile.close();
		StuCount = 0;
		StuCapacity = 10;
		Stus = new Student [StuCapacity];
		SubjCount = 0;
		SubjCapacity = 10;
		Subjs = new Subject [SubjCapacity];
		Data = new Result* [StuCapacity];
		for (int i=0; i<StuCapacity; ++i)
			Data[i] = new Result [SubjCapacity];
		return 0;
	}
	else
	{
		cout<<"�ҵ���ѧ�����ݡ������ļ���ȡ��\n";
		InFile >> StuCount >> StuCapacity >> SubjCount >> SubjCapacity;
		Stus = new Student [StuCapacity];
		for (int i=0; i<StuCount; ++i)
			InFile >> Stus[i].StuName >> Stus[i].Age
				>> Stus[i].Gender >> Stus[i].StuNum;
		Subjs = new Subject [SubjCapacity];
		for (int i=0; i<SubjCount; ++i)
			InFile >> Subjs[i].SubjName >> Subjs[i].Credit >> Subjs[i].SubjNum;
		Data = new Result* [StuCapacity];
		for (int i=0; i<StuCapacity; ++i)
			Data[i] = new Result [SubjCapacity];
		for (int i=0; i<StuCount; ++i)
			for (int j=0; j<SubjCount; ++j)
			{
				Data[i][j].Copy(Stus[i], Subjs[j]);
				InFile >> Data[i][j].Score;
			}
		InFile.close();
		return 1;
	}
}

void Proc::SaveFile()
{
	OutFile.open(FileName);
	if ( !OutFile )
	{
		cout<<"�ļ������ʧ�ܣ�\n";
		return;
	}
	OutFile << StuCount <<" "<< StuCapacity <<" "<< SubjCount <<" "<< SubjCapacity<<'\n'<<'\n';
	for (int i=0; i<StuCount; ++i)
		OutFile << Stus[i].StuName <<' '<< Stus[i].Age <<' '
				<< Stus[i].Gender <<' '<< Stus[i].StuNum <<"\n";
	OutFile<<'\n';
	for (int i=0; i<SubjCount; ++i)
		OutFile << Subjs[i].SubjName <<' '<< Subjs[i].Credit <<' '<< Subjs[i].SubjNum <<'\n';
	OutFile<<'\n';
	for (int i=0; i<StuCount; ++i)
	{
		for (int j=0; j<SubjCount; ++j)
			OutFile << Data[i][j].Score <<' ';
		OutFile<<endl;
	}
}

void Proc::ReleaseMemory()
{
	for (int i=0; i<StuCapacity; ++i)
		delete []Data[i];
	delete []Data;
	delete []Subjs;
	delete []Stus;
}

void Proc::UpdateStus(Student Stu)
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
	for (int i=0; i<SubjCount; ++i)
		Data[StuCount-1][i].Copy(Stu, Subjs[i]);
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

void Proc::UpdateSubjs(Subject Subj)
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
	for (int i=0; i<StuCount; ++i)
		Data[i][SubjCount-1].Copy(Stus[i], Subj);
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

// �����Ҫ���ҵ�ѧ������Stu�������ҵ���ѧ���������ظ�ѧ����Stus[]�е��±ꡣ
// ����-1��ʾδ�ҵ�������-2��ʾ�ҵ�����һ��ͬ����ѧ����
int Proc::GetStu()
{
	cin.clear();
	cin.sync();
	int RepeatCount=0;
	cout<<"���������������ѧ��������ѧ�ţ�"<<endl;
	// ��cin.peek()�ж������������������ѧ��
	char ch = cin.peek();
	// �жϣ����������ѧ��
	if ((ch >= '0') && (ch <= '9'))
	{
		int StuNum;
		cin >> StuNum;
		for (int i=0; i<StuCount; ++i)
			if (Stus[i].StuNum == StuNum)
			{
				++RepeatCount;
				cout<<"���ҵ���ѧ����ѧ����Ϣ��\n";
				Stus[i].Print();
				cout<<endl;
				return i;
			}
		cout<<"δ�ҵ���ѧ����\n";
		return -1;
	}
	// �жϣ��������������
	else
	{
		string StuName;
		cin >> StuName;
		int j = -1;
		for (int i=0; i<StuCount; ++i)
			if (Stus[i].StuName == StuName)
			{
				++RepeatCount;
				j = i;
			}
		if (RepeatCount == 0)
		{
			cout<<"δ�ҵ���ѧ����\n";
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
			cout<<endl;
			return j;
		}
	}
}

int Proc::GetSubj()
{
	cin.clear();
	cin.sync();
	int RepeatCount=0;
	cout<<"��������������Ŀγ�����γ̺ţ�"<<endl;
	// ��cin.peek()�ж���������ǿγ������ǿγ̺�
	char ch = cin.peek();
	// �жϣ���������ǿγ̺�
	if ((ch >= '0') && (ch <= '9'))
	{
		int SubjNum;
		cin >> SubjNum;
		for (int i=0; i<SubjCount; ++i)
			if (Subjs[i].SubjNum == SubjNum)
			{
				++RepeatCount;
				cout<<"���ҵ��ÿγ̡��γ���Ϣ��\n";
				Subjs[i].Print();
				cout<<endl;
				return i;
			}
		cout<<"δ�ҵ��ÿγ̣�\n";
		return -1;
	}
	// �жϣ���������ǿγ���
	else
	{
		string SubjName;
		cin >> SubjName;
		int j = -1;
		for (int i=0; i<SubjCount; ++i)
			if (Subjs[i].SubjName == SubjName)
			{
				++RepeatCount;
				j = i;
			}
		if (RepeatCount == 0)
		{
			cout<<"δ�ҵ��ÿγ̣�\n";
			return -1;
		}
		else if (RepeatCount > 1)
		{
			cout<<"����ͬ���γ̣����ÿγ̺����²��ҡ�\n";
			return -2;
		}
		else
		{
			cout<<"���ҵ��ÿγ̡��γ���Ϣ��\n";
			Subjs[j].Print();
			cout<<endl;
			return j;
		}
	}
}

void Proc::NewStu()
{
	Student tempStu;
	tempStu.Set();
	UpdateStus(tempStu);
}

void Proc::DeleleStu()
{
	int Index = GetStu();
	if (Index >= 0)
		UpdateStus(Index);
}

void Proc::ModifyStu()
{
	int Index = GetStu();
	if (Index >= 0)
		Stus[Index].Modify();
}

void Proc::NewSubj()
{
	Subject tempSubj;
	tempSubj.Set();
	UpdateSubjs(tempSubj);
}

void Proc::DeleleSubj()
{
	int Index = GetSubj();
	if (Index >= 0)
		UpdateSubjs(Index);
}

void Proc::ModifySubj()
{
	int Index = GetSubj();
	if (Index >= 0)
		Subjs[Index].Modify();
}

int Proc::PrintStus()
{
	if (StuCount == 0)
	{
		cout<<"ѧ����ϢΪ�գ�"<<endl;
		return 0;
	}
	else
	{
		cout<<"\nȫ��ѧ����Ϣ��\n"
			<<"   ����       ����       �Ա�        ѧ��\n";
		for (int i=0; i<StuCount; ++i)
			Stus[i].PrintBrief();
		cout<<endl;
		return 1;
	}
}

int Proc::PrintSubjs()
{
	if (SubjCount == 0)
	{
		cout<<"�γ���ϢΪ�գ�"<<endl;
		return 0;
	}
	else
	{
		cout<<"\nȫ���γ���Ϣ��\n"
			<<"     �γ���         ѧ��       �γ̺�\n";
		for (int i=0; i<SubjCount; ++i)
			Subjs[i].PrintBrief();
		cout<<endl;
		return 1;
	}
}

void Proc::PrintByStu(int Index)
{
	int Count = 0;
	for (int i=0; i<SubjCount; ++i)
	{
		if ((Data[Index][i].Score >= 0) && (Data[Index][i].Score <=100))
		{
			++Count;
			if (Count == 1)
				cout<<"    �γ���        �ɼ�\n";
			cout<<setw(10)<<Subjs[i].SubjName
				<<setw(10)<<Data[Index][i].Score<<endl;
		}
	}
	if (Count == 0)
		cout<<"��ѧ���ĳɼ���ϢΪ�գ�"<<endl;
	cout<<endl;
}

void Proc::PrintBySubj(int Index)
{
	int Count = 0;
	for (int i=0; i<StuCount; ++i)
	{
		if ((Data[i][Index].Score >= 0) && (Data[i][Index].Score <=100))
		{
			++Count;
			if (Count == 1)
				cout<<"    ����        �ɼ�\n";
			cout<<setw(8)<<Stus[i].StuName
				<<setw(10)<<Data[i][Index].Score<<endl;
		}
	}
	if (Count == 0)
		cout<<"�ÿγ̵ĳɼ���ϢΪ�գ�"<<endl;
	cout<<endl;
}

void Proc::PrintStuScore()
{
	int Index = GetStu();
	if (Index >= 0)
	{
		PrintByStu(Index);
		if (CalcGPA(Index))
			cout<<Stus[Index].StuName<<" ��GPAΪ "<<Stus[Index].GPA<<endl<<endl;
	}
}

void Proc::PrintSubjScore()
{
	int Index = GetSubj();
	if (Index >= 0)
		PrintBySubj(Index);
}

void Proc::PrintTable()
{
	if (StuCount == 0)
	{
		cout<<"ѧ����ϢΪ�գ��޷���ӡ�ɼ���\n";
		return;
	}
	if (SubjCount == 0)
	{
		cout<<"�γ���ϢΪ�գ��޷���ӡ�ɼ���\n";
		return;
	}
	for (int i=0; i<80; ++i)
		cout<<'=';
	cout<<endl;
	int Cursor = -1;
	while (Cursor < SubjCount-1)
	{
		int temp = Cursor + 1;
		cout<<setw(8)<<' ';
		for (int i=0; (i<6) && (Cursor < SubjCount-1); ++i)
			cout<<setw(11)<< Subjs[ ++Cursor ].SubjName;
		cout<<endl;
		for (int i=0; i<80; ++i)
			cout<<'-';
		for (int i=0; i<StuCount; ++i)
		{
			cout<<setw(6)<< Stus[i].StuName <<" |";
			for (int j=temp; (j < temp+6) && (j < SubjCount); ++j)
				cout<<setw(11)<< Data[i][j].Score;
			cout<<endl;
		}
	}
	cout<<endl;
	for (int i=0; i<80; ++i)
		cout<<'=';
	cout<<endl;

}

void Proc::PrintRank()
{
	if (CalcAllGPA())
		SortGPA();
	else
		cout<<"ѧ���ɼ���ϢΪ�գ�"<<endl;
}

void Proc::GetStuScore()
{
	int Index = GetStu();
	if (Index >= 0)
		if (PrintSubjs())
		{
			cout<<"�밴����˳���������������ѧ���ĸ��Ƴɼ����ûس��ָ�����δѡ��������-1��"<<endl;
			cin.clear();
			cin.sync();
			for (int i=0; i<SubjCount; ++i)
				GetInt(Data[Index][i].Score, 100);
			cout<<"�ɹ�¼���ѧ���ɼ���"<<endl;
		}
	cin.clear();
	cin.sync();
}

void Proc::GetSubjScore()
{
	int Index = GetSubj();
	if (Index >= 0)
		if (PrintStus())
		{
			cout<<"�밴����˳���������������ѧ���ĸÿγ̳ɼ����ûس��ָ�����δѡ��������-1��"<<endl;
			cin.clear();
			cin.sync();
			for (int i=0; i<StuCount; ++i)
				GetInt(Data[i][Index].Score, 100);
			cout<<"�ɹ�¼��ÿγ̳ɼ���"<<endl;
		}
	cin.clear();
	cin.sync();
}

void Proc::GetStuSubjScore()
{
	int StuIndex = GetStu();
	if (StuIndex >= 0)
	{
		int SubjIndex = GetSubj();
		if (SubjIndex >= 0)
			if ((Data[StuIndex][SubjIndex].Score >= 0) && 
				(Data[StuIndex][SubjIndex].Score <= 100))
				Data[StuIndex][SubjIndex].Modify();
			else 
			{
				cout<<"�������ѧ���ĸÿγ̳ɼ���δѡ��������-1��"<<endl;
				cin.clear();
				cin.sync();
				GetInt(Data[StuIndex][SubjIndex].Score, 100);
				cout<<"�ɹ�¼��óɼ���"<<endl;
			}
	}
}

int Proc::CalcGPA(int Index)
{
	int CreditSum = 0;
	int ScoreSum = 0;
	for (int i=0; i<SubjCount; ++i)
		if ((Data[Index][i].Score >= 0) && (Data[Index][i].Score <= 100))
		{
			CreditSum += Subjs[i].Credit;
			ScoreSum += Data[Index][i].Score * Subjs[i].Credit;
		}
	if (CreditSum == 0)
		return 0;
	Stus[Index].GPA = ScoreSum / CreditSum;
	return 1;
}

int Proc::CalcAllGPA()
{
	int Flag = 0;
	for (int i=0; i<StuCount; ++i)
		if (Global.CalcGPA(i))
			Flag = 1;
	return Flag;
}

void Proc::SortGPA()
{
	int* Index = new int [StuCount];
	int IndexCount = 0;
	for (int i=0; i<StuCount; ++i)
		if ((Stus[i].GPA >= 0) && (Stus[i].GPA <= 100))
			Index [IndexCount++] = i;
	int temp;
	int LowerBnd = 0;
	int UpperBnd = IndexCount - 1;
	int Changed;
	while (LowerBnd < UpperBnd)
	{
		for (int i=LowerBnd; i<UpperBnd; ++i)
		{
			if (Stus[Index[i]].GPA < Stus[Index[i+1]].GPA)
			{
				temp = Index[i];
				Index[i] = Index[i+1];
				Index[i+1] = temp;
				Changed = i;
			}
			UpperBnd = i;
		}
		for (int i=UpperBnd; i>LowerBnd; --i)
		{
			if (Stus[Index[i]].GPA > Stus[Index[i-1]].GPA)
			{
				temp = Index[i];
				Index[i] = Index[i-1];
				Index[i-1] = temp;
				Changed = i;
			}
			LowerBnd = i;
		}
		cout<<"\n  ����       ����       GPA\n";
		for (int i=0; i<IndexCount; ++i)
		{
			cout<<setw(5)<<i+1<<setw(11)<<Stus[Index[i]].StuName
				<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<Stus[Index[i]].GPA<<endl;
		}
		cout<<endl;
	}
}