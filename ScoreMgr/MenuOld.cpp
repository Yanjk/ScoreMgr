#include "Scoremgr.h"

void Proc::MenuOld()
{
	Line0();
	int Choice;
	do
	{
		cout<<"��ѡ��������Ĳ�����\n"
			<<"1.��Ϣ¼�����޸�\n"
			<<"2.��Ϣ���������ݼ���\n"
			<<"0.�˳�ϵͳ\n\n";
		GetInt(Choice, 2);
		switch (Choice)
		{
		case 0:
			break;

		//��Ϣ¼�����޸�
		case 1:
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::binary);

			// ��û�и�ѧ�ڵ������ļ�
			if (!InFile)
			{
				InFile.close();
				InFile.clear();
				cout<<"��ѧ����Ϣ��δ¼�룬���������ļ���¼����Ϣ��"<<endl;
				NewData();
				int Choice;
				do
				{
					cout<<"\n������������Ĳ�����\n"
						<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
						<<"2.��ʾ��ǰ���пγ���Ϣ\n"
						<<"3.����ѧ����Ϣ\n"
						<<"4.�����γ���Ϣ\n"
						<<"5.¼��ĳһѧ���ɼ�\n"
						<<"6.¼��ĳһ�γ̳ɼ�\n"
						<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
						<<"0.���沢����\n\n";
					GetInt(Choice, 7);					
					switch (Choice)
					{
					case 0:
						break;
					case 1:
						PrintStus();
						break;
					case 2:
						PrintSubjs();
						break;
					case 3:
						Stu.Set();
						UpdateStus();
						break;
					case 4:
						Subj.Set();
						UpdateSubjs();
						break;
					case 5:
						{
							int Index = GetStu();
							if (Index >= 0)
							{
								if (PrintSubjs())
								{
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
							int Index = GetSubj();
							if (Index >= 0)
							{
								if (StuCount == 0)
									cout<<"ѧ����ϢΪ�գ�"<<endl;
								else
								{
									if (PrintStus())
									{
										cout<<"�밴����˳�����������ѧ���ĸÿγ̳ɼ���δѡ��������-1��"<<endl;
										cin.clear();
										cin.sync();
										for (int i=0; i<StuCount; ++i)
											cin>>Data[i][Index].Score;
										cout<<"�ɹ�¼��ÿγ̳ɼ���"<<endl;
									}
								}
							}
						}
						break;
					case 7:
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
										cin>>Data[StuIndex][SubjIndex].Score;
										cout<<"�ɹ�¼��óɼ���"<<endl;
									}
							}
						}
						break;
					}
				} while (Choice != 0);			
			}

			// �����и�ѧ�ڵ������ļ�
			else
			{
				cout<<"��ѧ����Ϣ�Ѵ��ڣ����������ļ���"<<endl;
				ReadData();
				InFile.close();
				OutFile.open(FileName, ios::binary);
				if (!OutFile)
				{
					cout<<"�ļ���ʧ�ܡ������˳���"<<endl;
					exit(1);
				}
				int Choice;
				do
				{
					cout<<"\n��ѡ��������Ĳ�����\n"
						<<"1.��ʾ��ǰ����ѧ����Ϣ\n"
						<<"2.��ʾ��ǰ���пγ���Ϣ\n"
						<<"3.����ѧ����Ϣ������/ɾ��/�޸ģ�\n"
						<<"4.���Ŀγ���Ϣ������/ɾ��/�޸ģ�\n"
						<<"5.¼��ĳһѧ���ɼ�\n"
						<<"6.¼��ĳһ�γ̳ɼ�\n"
						<<"7.¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
						<<"0.���沢����\n\n";
					GetInt(Choice, 7);
					switch (Choice)
					{
					case 0:
						break;
					case 1:
						PrintStus();
						break;
					case 2:
						PrintSubjs();
						break;
					case 3:
						{
							int Choice;
							do
							{
								cout<<"\n��ѡ��������Ĳ�����\n"
									<<"1.����\n"
									<<"2.ɾ��\n"
									<<"3.�޸�\n"
									<<"0.����\n\n";
								GetInt(Choice, 3);
								switch (Choice)
								{
								case 0:
									break;
								case 1:
									Stu.Set();
									UpdateStus();
									break;
								case 2:
									{
										int Index = GetStu();
										if (Index >= 0)
											UpdateStus(Index);
									}
									break;
								case 3:
									{
										int Index = GetStu();
										if (Index>= 0)
											Stus[Index].Modify();
									}
									break;
								}
							} while (Choice != 0);
						}
						break;
					case 4:
						{
							int Choice;
							do
							{
								cout<<"\n��ѡ��������Ĳ�����\n"
									<<"1.����\n"
									<<"2.ɾ��\n"
									<<"3.�޸�\n"
									<<"0.����\n\n";
								GetInt(Choice, 3);
								switch (Choice)
								{
								case 0:
									break;
								case 1:
									Subj.Set();
									UpdateSubjs();
									break;
								case 2:
									{
										int Index = GetSubj();
										if (Index >= 0)
											UpdateSubjs(Index);
									}
									break;
								case 3:
									{
										int Index = GetSubj();
										if (Index>= 0)
											Subjs[Index].Modify();
									}
									break;
								}
							} while (Choice != 0);
						}
						break;
					case 5:
						{
							int Index = GetStu();
							if (Index >= 0)
							{
								if(PrintSubjs())
								{
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
							int Index = GetSubj();
							if (Index >= 0)
							{
								if(PrintStus())
								{
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
							int StuIndex = GetStu();
							if (StuIndex >= 0)
							{
								int SubjIndex = GetSubj();
								if (SubjIndex >= 0)
									Data[StuIndex][SubjIndex].Modify();
							}
						}
						break;
					}
				} while (Choice != 0);		
			}

			WriteData();
			OutFile.close();
			ReleaseData();
			break;

		// ��Ϣ���������ݼ���
		case 2:	
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::binary);
			if (!InFile)
			{
				InFile.close();
				InFile.clear();
				cout<<"��ѧ����Ϣ��δ¼�룬����Ϊ�գ�"<<endl;
				break;
			}
			else
			{
				ReadData();
				int Choice;
				do
				{
					cout<<"\n��ѡ��������Ĳ�����\n"
						<<"1.��ʾ����ѧ����Ϣ\n"
						<<"2.��ʾ���пγ���Ϣ\n"
						<<"3.��ѧ�������ɼ�\n"
						<<"4.���γ������ɼ�\n"
						<<"5.��ʾѧ��GPA����\n"
						<<"0.����\n\n";
					GetInt(Choice, 5);
					switch (Choice)
					{
					case 0:
						break;
					case 1:
						PrintStus();
						break;
					case 2:
						PrintSubjs();
						break;
					case 3:
						{
							int Index = GetStu();
							if (Index >= 0)
							{
								PrintByStu(Index);
								if (CalcGPA(Index))
									cout<<Stus[Index].StuName<<" ��GPAΪ "<<Stus[Index].GPA<<endl<<endl;
							}
						}
						break;
					case 4:
						{
							int Index = GetSubj();
							if (Index >= 0)
								PrintBySubj(Index);
						}
						break;
					case 5:
						if (CalcAllGPA())
							SortGPA();
						else
							cout<<"ѧ���ɼ���ϢΪ�գ�"<<endl;
						break;
					}
				} while (Choice != 0);
				InFile.close();
				ReleaseData();
			}
			break;
		
		}
	} while (Choice != 0);

	cout<<"\n��л����ʹ�ã��ټ���\n"<<endl;
	Line1();
}
