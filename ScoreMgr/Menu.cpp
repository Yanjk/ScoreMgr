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

		//��Ϣ¼�����޸�
		case 1:
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::in|ios::binary|ios::_Nocreate);

			// ��û�и�ѧ�ڵ������ļ�
			if (!InFile)
			{
				cout<<"��ѧ����Ϣ��δ¼�룬���������ļ���¼����Ϣ��"<<endl;
				Global.NewData();
				cout<<"\n������������Ĳ�����\n"
					<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
					<<"2.��ʾ��ǰ���пγ���Ϣ\n"
					<<"3.����ѧ����Ϣ\n"
					<<"4.�����γ���Ϣ\n"
					<<"5.¼��ĳһѧ���ɼ�\n"
					<<"6.¼��ĳһ�γ̳ɼ�\n"
					<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
					<<"0.���沢����\n\n";
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
						if (StuCount == 0)
							cout<<"ѧ����ϢΪ�գ�"<<endl;
						else
							Global.PrintStus();
						break;
					case 2:
						if (SubjCount == 0)
							cout<<"�γ���ϢΪ�գ�"<<endl;
						else
							Global.PrintSubjs();
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
								if (SubjCount == 0)
									cout<<"�γ���ϢΪ�գ�"<<endl;
								else
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
						}
						break;
					case 6:
						{
							int Index = Global.GetSubj();
							if (Index >= 0)
							{
								if (StuCount == 0)
									cout<<"ѧ����ϢΪ�գ�"<<endl;
								else
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
						}
						break;
					case 7:
						{
							int StuIndex = Global.GetStu();
							if (StuIndex >= 0)
							{
								int SubjIndex = Global.GetSubj();
								if (SubjIndex >= 0)
									if ((Data[StuIndex][SubjIndex].Score >= 0) && 
										(Data[StuIndex][SubjIndex].Score <= 100))
										Data[StuIndex][SubjIndex].Modify();
									else 
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
						<<"0.���沢����\n\n";
					cin.clear();
					cin.sync();
					cin>>Choice;
				}				
			}

			// �����и�ѧ�ڵ������ļ�
			else
			{
				cout<<"��ѧ����Ϣ�Ѵ��ڣ����������ļ���"<<endl;
				Global.ReadData();
				InFile.close();
				OutFile.open(FileName, ios::out|ios::binary);
				if (!OutFile)
				{
					cout<<"�ļ���ʧ�ܡ������˳���"<<endl;
					exit(1);
				}
				cout<<"\n��ѡ��������Ĳ�����\n"
					<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
					<<"2.��ʾ��ǰ���пγ���Ϣ\n"
					<<"3.����ѧ����Ϣ������/ɾ��/�޸ģ�\n"
					<<"4.���Ŀγ���Ϣ������/ɾ��/�޸ģ�\n"
					<<"5.¼��ĳһѧ���ɼ�\n"
					<<"6.¼��ĳһ�γ̳ɼ�\n"
					<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
					<<"0.���沢����\n\n";
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
						if (StuCount == 0)
							cout<<"ѧ����ϢΪ�գ�"<<endl;
						else
							Global.PrintStus();
						break;
					case 2:
						if (SubjCount == 0)
							cout<<"�γ���ϢΪ�գ�"<<endl;
						else
							Global.PrintSubjs();
						break;
					case 3:
						{
							cout<<"\n��ѡ��������Ĳ�����\n"
								<<"1.����\n"
								<<"2.ɾ��\n"
								<<"3.�޸�\n"
								<<"0.����\n";
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
									Stu.Set();
									Global.UpdateStus();
									break;
								case 2:
									{
										int Index = Global.GetStu();
										if (Index >= 0)
											Global.UpdateStus(Index);
									}
									break;
								case 3:
									{
										int Index = Global.GetStu();
										if (Index>= 0)
											Stus[Index].Modify();
									}
									break;
								default:
									cout<<"����������������룺"<<endl;
									break;
								}
								cout<<"\n��ѡ��������Ĳ�����\n"
									<<"1.����\n"
									<<"2.ɾ��\n"
									<<"3.�޸�\n"
									<<"0.����\n";
								cin.clear();
								cin.sync();
								cin>>Choice;
							}
						}
						break;
					case 4:
						{
							cout<<"\n��ѡ��������Ĳ�����\n"
								<<"1.����\n"
								<<"2.ɾ��\n"
								<<"3.�޸�\n"
								<<"0.����\n";
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
									Subj.Set();
									Global.UpdateSubjs();
									break;
								case 2:
									{
										int Index = Global.GetSubj();
										if (Index >= 0)
											Global.UpdateSubjs(Index);
									}
									break;
								case 3:
									{
										int Index = Global.GetSubj();
										if (Index>= 0)
											Subjs[Index].Modify();
									}
									break;
								default:
									cout<<"����������������룺"<<endl;
									break;
								}
								cout<<"\n��ѡ��������Ĳ�����\n"
									<<"1.����\n"
									<<"2.ɾ��\n"
									<<"3.�޸�\n"
									<<"0.����\n";
								cin.clear();
								cin.sync();
								cin>>Choice;
							}
						}
						break;
					case 5:
						{
							int Index = Global.GetStu();
							if (Index >= 0)
							{
								if (SubjCount == 0)
									cout<<"�γ���ϢΪ�գ�"<<endl;
								else
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
						}
						break;
					case 6:
						{
							int Index = Global.GetSubj();
							if (Index >= 0)
							{
								if (StuCount == 0)
									cout<<"ѧ����ϢΪ�գ�"<<endl;
								else
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
						}
						break;
					case 7:
						{
							int StuIndex = Global.GetStu();
							if (StuIndex >= 0)
							{
								int SubjIndex = Global.GetSubj();
								if (SubjIndex >= 0)
									Data[StuIndex][SubjIndex].Modify();
							}
						}
						break;
					default:
						cout<<"����������������룺"<<endl;
						break;
					}
					cout<<"\n��ѡ��������Ĳ�����\n"
						<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
						<<"2.��ʾ��ǰ���пγ���Ϣ\n"
						<<"3.����ѧ����Ϣ������/ɾ��/�޸ģ�\n"
						<<"4.���Ŀγ���Ϣ������/ɾ��/�޸ģ�\n"
						<<"5.¼��ĳһѧ���ɼ�\n"
						<<"6.¼��ĳһ�γ̳ɼ�\n"
						<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
						<<"0.���沢����\n\n";
					cin.clear();
					cin.sync();
					cin>>Choice;
				}				
			}
			Global.WriteData();
			Global.ReleaseData();
			OutFile.close();
			break;

		// ��Ϣ���������ݼ���
		case 2:															// TODO
			break;
		default:
			cout<<"����������������룺"<<endl;
			break;
		}
		cout<<endl;
		Global.Line0();
		cout<<"��ѡ��������Ĳ�����\n"
			<<"1.��Ϣ¼�����޸�\n"
			<<"2.��Ϣ���������ݼ���\n"
			<<"0.�˳�ϵͳ\n\n";
		cin.clear();
		cin.sync();
		cin>>Choice;
	}
	cout<<"\n��л����ʹ�ã��ټ���\n"<<endl;
	Global.Line1();
}
