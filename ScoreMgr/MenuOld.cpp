#include "Scoremgr.h"

void Proc::MenuOld()
{
	Line0();
	int Choice;
	do
	{
		cout<<"请选择您所需的操作：\n"
			<<"1.信息录入与修改\n"
			<<"2.信息检索与数据计算\n"
			<<"0.退出系统\n\n";
		GetInt(Choice, 2);
		switch (Choice)
		{
		case 0:
			break;

		//信息录入与修改
		case 1:
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::binary);

			// 若没有该学期的数据文件
			if (!InFile)
			{
				InFile.close();
				InFile.clear();
				cout<<"该学期信息尚未录入，将创建新文件以录入信息。"<<endl;
				NewData();
				int Choice;
				do
				{
					cout<<"\n请输入您所需的操作：\n"
						<<"1.显示当前所有学生信息\n"
						<<"2.显示当前所有课程信息\n"
						<<"3.新增学生信息\n"
						<<"4.新增课程信息\n"
						<<"5.录入某一学生成绩\n"
						<<"6.录入某一课程成绩\n"
						<<"7.录入某一学生的某一课程成绩\n"
						<<"0.保存并返回\n\n";
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
									cout<<"请按以上顺序依次输入该学生的各科成绩。未选课请输入-1。"<<endl;
									cin.clear();
									cin.sync();
									for (int i=0; i<SubjCount; ++i)
										cin>>Data[Index][i].Score;
									cout<<"成功录入该学生成绩。"<<endl;
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
									cout<<"学生信息为空！"<<endl;
								else
								{
									if (PrintStus())
									{
										cout<<"请按以上顺序依次输入各学生的该课程成绩。未选课请输入-1。"<<endl;
										cin.clear();
										cin.sync();
										for (int i=0; i<StuCount; ++i)
											cin>>Data[i][Index].Score;
										cout<<"成功录入该课程成绩。"<<endl;
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
										cout<<"请输入该学生的该课程成绩。未选课请输入-1。"<<endl;
										cin.clear();
										cin.sync();
										cin>>Data[StuIndex][SubjIndex].Score;
										cout<<"成功录入该成绩。"<<endl;
									}
							}
						}
						break;
					}
				} while (Choice != 0);			
			}

			// 若已有该学期的数据文件
			else
			{
				cout<<"该学期信息已存在，将打开已有文件。"<<endl;
				ReadData();
				InFile.close();
				OutFile.open(FileName, ios::binary);
				if (!OutFile)
				{
					cout<<"文件打开失败。意外退出。"<<endl;
					exit(1);
				}
				int Choice;
				do
				{
					cout<<"\n请选择您所需的操作：\n"
						<<"1.显示当前所有学生信息\n"
						<<"2.显示当前所有课程信息\n"
						<<"3.更改学生信息（增加/删除/修改）\n"
						<<"4.更改课程信息（增加/删除/修改）\n"
						<<"5.录入某一学生成绩\n"
						<<"6.录入某一课程成绩\n"
						<<"7.录入某一学生的某一课程成绩\n"
						<<"0.保存并返回\n\n";
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
								cout<<"\n请选择您所需的操作：\n"
									<<"1.增加\n"
									<<"2.删除\n"
									<<"3.修改\n"
									<<"0.返回\n\n";
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
								cout<<"\n请选择您所需的操作：\n"
									<<"1.增加\n"
									<<"2.删除\n"
									<<"3.修改\n"
									<<"0.返回\n\n";
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
									cout<<"请按以上顺序依次输入该学生的各科成绩。未选课请输入-1。"<<endl;
									cin.clear();
									cin.sync();
									for (int i=0; i<SubjCount; ++i)
										cin>>Data[Index][i].Score;
									cout<<"成功录入该学生成绩。"<<endl;
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
									cout<<"请按以上顺序依次输入各学生的该课程成绩。未选课请输入-1。"<<endl;
									cin.clear();
									cin.sync();
									for (int i=0; i<StuCount; ++i)
										cin>>Data[i][Index].Score;
									cout<<"成功录入该课程成绩。"<<endl;
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

		// 信息检索与数据计算
		case 2:	
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::binary);
			if (!InFile)
			{
				InFile.close();
				InFile.clear();
				cout<<"该学期信息尚未录入，数据为空！"<<endl;
				break;
			}
			else
			{
				ReadData();
				int Choice;
				do
				{
					cout<<"\n请选择您所需的操作：\n"
						<<"1.显示所有学生信息\n"
						<<"2.显示所有课程信息\n"
						<<"3.按学生搜索成绩\n"
						<<"4.按课程搜索成绩\n"
						<<"5.显示学生GPA排名\n"
						<<"0.返回\n\n";
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
									cout<<Stus[Index].StuName<<" 的GPA为 "<<Stus[Index].GPA<<endl<<endl;
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
							cout<<"学生成绩信息为空！"<<endl;
						break;
					}
				} while (Choice != 0);
				InFile.close();
				ReleaseData();
			}
			break;
		
		}
	} while (Choice != 0);

	cout<<"\n感谢您的使用！再见！\n"<<endl;
	Line1();
}
