#include "Scoremgr.h"

int StuCount=0;
int SubjCount=0;

string Gen[2]={"Ů","��"};

Proc Global;

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

void Proc::Menu()
{
	Global.Line0();
	cout<<"��ѡ��������Ĳ�����\n1.�鿴��Ϣ\n2.�޸���Ϣ\n3.����������GPA\n0.�˳�ϵͳ\n\n";
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
		case 1:												// TODO
			break;
		case 2:												// TODO
			break;
		case 3:												// TODO
			break;
		default:
			cout<<"����������������룺"<<endl;
			break;
		}
	}
}

void Proc::NewData()
{
	
}