#include "Scoremgr.h"

void Proc::Menu()
{
	Global.Line0();
	cout<<"��ѡ��������Ĳ�����\n"
		<<"1.��Ϣ¼�����޸�\n"
		<<"2.��Ϣ���������ݼ���\n"
		<<"0.�˳�ϵͳ\n\n";
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
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::in|ios::binary|ios::_Nocreate);
			if (!InFile)
			{
				cout<<"��ѧ����Ϣ��δ¼�룬���������ļ���¼����Ϣ��"<<endl;
				Global.NewData();
				cout<<"������������Ĳ�����\n"
					<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
					<<"2.��ʾ��ǰ���пγ���Ϣ\n"
					<<"3.����ѧ����Ϣ\n"
					<<"4.�����γ���Ϣ\n"
					<<"5.¼��ĳһѧ���ɼ�\n"
					<<"6.¼��ĳһ�γ̳ɼ�\n"
					<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
					<<"8.�����޸ĵ��ļ�\n"
					<<"0.����\n\n";
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
						for (int i=0; i<StuCount; ++i)
							Stus[i].Print();
						if (StuCount == 0)
							cout<<"ѧ����ϢΪ�գ�"<<endl;
						break;
					case 2:
						for (int i=0; i<SubjCount; ++i)
							Subjs[i].Print();
						if (SubjCount == 0)
							cout<<"�γ���ϢΪ�գ�"<<endl;
						break;
					case 3:
						Stu.Set();
						Global.UpdateStus();
						break;
					case 4:
						Subj.Set();
						Global.UpdateSubjs();
						break;
					case 5:
						{
							int Index = Global.GetStu();
							if (Index >= 0)
							{
								Global.PrintSubjs();
								cout<<"�밴����˳�����������ѧ���ĸ��Ƴɼ���δѡ��������-1��"<<endl;
								cin.clear();
								cin.sync();
								for (int i=0; i<SubjCount; ++i)
									cin>>Data[Index][i].Score;
								cout<<"�ɹ�¼���ѧ���ɼ���"<<endl;
							}
						}
						break;
					case 6:
						{
							int Index = Global.GetSubj();
							if (Index >= 0)
							{
								Global.PrintStus();
								cout<<"�밴����˳�����������ѧ���ĸÿγ̳ɼ���δѡ��������-1��"<<endl;
								cin.clear();
								cin.sync();
								for (int i=0; i<StuCount; ++i)
									cin>>Data[i][Index].Score;
								cout<<"�ɹ�¼��ÿγ̳ɼ���"<<endl;
							}
						}
						break;
					case 7:
						{
							int StuIndex = Global.GetStu();
							if (StuIndex >= 0)
							{
								int SubjIndex = Global.GetSubj();
								if (SubjIndex >= 0)
								{
									cout<<"�������ѧ���ĸÿγ̳ɼ���δѡ��������-1��"<<endl;
									cin.clear();
									cin.sync();
									cin>>Data[StuIndex][SubjIndex].Score;
									cout<<"�ɹ�¼��óɼ���"<<endl;
								}
							}
						}
						break;
					case 8:
						Global.WriteData();
						break;
					default:
						cout<<"����������������룺"<<endl;
						break;
					}
					cout<<"\n������������Ĳ�����\n"
						<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
						<<"2.��ʾ��ǰ���пγ���Ϣ\n"
						<<"3.����ѧ����Ϣ\n"
						<<"4.�����γ���Ϣ\n"
						<<"5.¼��ĳһѧ���ɼ�\n"
						<<"6.¼��ĳһ�γ̳ɼ�\n"
						<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
						<<"8.�����޸ĵ��ļ�\n"
						<<"0.����\n\n";
					cin.clear();
					cin.sync();
					cin>>Choice;
				}
				Global.ReleaseData();
			}
			else
			{
				cout<<"��ѧ����Ϣ�Ѵ��ڣ����������ļ���"<<endl;
				Global.ReadData();
				InFile.close();
				OutFile.open(FileName,ios::out|ios::binary);
				if (!OutFile)
				{
					cout<<"�ļ���ʧ�ܡ������˳���"<<endl;
					exit(1);
				}
				// �˴����ѡ��˵�
				// Global.WriteData();
				Global.ReleaseData();
			}
			break;
		case 2:															// TODO
			break;
		default:
			cout<<"����������������룺"<<endl;
			break;
		}
		cin.clear();
		cin.sync();
		cout<<endl;
		Global.Line0();
		cout<<"��ѡ��������Ĳ�����\n"
			<<"1.��Ϣ¼�����޸�\n"
			<<"2.��Ϣ���������ݼ���\n"
			<<"0.�˳�ϵͳ\n\n";
		cin>>Choice;
	}
	cout<<"\n��л����ʹ�ã��ټ���\n"<<endl;
	Global.Line1();
}
