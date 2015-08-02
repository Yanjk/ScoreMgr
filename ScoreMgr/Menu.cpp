#include "Scoremgr.h"

void Proc::Menu()
{
	Global.Line0();
	cout<<"请选择您所需的操作：\n"
		<<"1.信息录入与修改\n"
		<<"2.信息检索与数据计算\n"
		<<"0.退出系统\n\n";
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
			cout<<"输入错误，请重新输入："<<endl;
			cin>>Choice;
		}
		switch (Choice)
		{
		case 0:
			break;

		//信息录入与修改
		case 1:
			Sem.Set();
			sprintf(FileName,"%d_%d_%d.score",Sem.EntranceYear,Sem.YearNum,Sem.TermNum);
			InFile.open(FileName, ios::in|ios::binary|ios::_Nocreate);

			// 若没有该学期的数据文件
			if (!InFile)
			{
				cout<<"该学期信息尚未录入，将创建新文件以录入信息。"<<endl;
				Global.NewData();
				cout<<"\n请输入您所需的操作：\n"
					<<"1.显示当前所有学生信息\n"
					<<"2.显示当前所有课程信息\n"
					<<"3.新增学生信息\n"
					<<"4.新增课程信息\n"
					<<"5.录入某一学生成绩\n"
					<<"6.录入某一课程成绩\n"
					<<"7.录入某一学生的某一课程成绩\n"
					<<"0.保存并返回\n\n";
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
						cout<<"输入错误，请重新输入："<<endl;
						cin>>Choice;
					}
					switch (Choice)
					{
					case 0:
						break;
					case 1:
						if (StuCount == 0)
							cout<<"学生信息为空！"<<endl;
						else
							Global.PrintStus();
						break;
					case 2:
						if (SubjCount == 0)
							cout<<"课程信息为空！"<<endl;
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
									cout<<"课程信息为空！"<<endl;
								else
								{
									Global.PrintSubjs();
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
							int Index = Global.GetSubj();
							if (Index >= 0)
							{
								if (StuCount == 0)
									cout<<"学生信息为空！"<<endl;
								else
								{
									Global.PrintStus();
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
										cout<<"请输入该学生的该课程成绩。未选课请输入-1。"<<endl;
										cin.clear();
										cin.sync();
										cin>>Data[StuIndex][SubjIndex].Score;
										cout<<"成功录入该成绩。"<<endl;
									}
							}
						}
						break;
					default:
						cout<<"输入错误，请重新输入："<<endl;
						break;
					}
					cout<<"\n请输入您所需的操作：\n"
						<<"1.显示当前所有学生信息\n"
						<<"2.显示当前所有课程信息\n"
						<<"3.新增学生信息\n"
						<<"4.新增课程信息\n"
						<<"5.录入某一学生成绩\n"
						<<"6.录入某一课程成绩\n"
						<<"7.录入某一学生的某一课程成绩\n"
						<<"0.保存并返回\n\n";
					cin.clear();
					cin.sync();
					cin>>Choice;
				}				
			}

			// 若已有该学期的数据文件
			else
			{
				cout<<"该学期信息已存在，将打开已有文件。"<<endl;
				Global.ReadData();
				InFile.close();
				OutFile.open(FileName, ios::out|ios::binary);
				if (!OutFile)
				{
					cout<<"文件打开失败。意外退出。"<<endl;
					exit(1);
				}
				cout<<"\n请选择您所需的操作：\n"
					<<"1.显示当前所有学生信息\n"
					<<"2.显示当前所有课程信息\n"
					<<"3.更改学生信息（增加/删除/修改）\n"
					<<"4.更改课程信息（增加/删除/修改）\n"
					<<"5.录入某一学生成绩\n"
					<<"6.录入某一课程成绩\n"
					<<"7.录入某一学生的某一课程成绩\n"
					<<"0.保存并返回\n\n";
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
						cout<<"输入错误，请重新输入："<<endl;
						cin>>Choice;
					}
					switch (Choice)
					{
					case 0:
						break;
					case 1:
						if (StuCount == 0)
							cout<<"学生信息为空！"<<endl;
						else
							Global.PrintStus();
						break;
					case 2:
						if (SubjCount == 0)
							cout<<"课程信息为空！"<<endl;
						else
							Global.PrintSubjs();
						break;
					case 3:
						{
							cout<<"\n请选择您所需的操作：\n"
								<<"1.增加\n"
								<<"2.删除\n"
								<<"3.修改\n"
								<<"0.返回\n";
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
									cout<<"输入错误，请重新输入："<<endl;
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
									cout<<"输入错误，请重新输入："<<endl;
									break;
								}
								cout<<"\n请选择您所需的操作：\n"
									<<"1.增加\n"
									<<"2.删除\n"
									<<"3.修改\n"
									<<"0.返回\n";
								cin.clear();
								cin.sync();
								cin>>Choice;
							}
						}
						break;
					case 4:
						{
							cout<<"\n请选择您所需的操作：\n"
								<<"1.增加\n"
								<<"2.删除\n"
								<<"3.修改\n"
								<<"0.返回\n";
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
									cout<<"输入错误，请重新输入："<<endl;
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
									cout<<"输入错误，请重新输入："<<endl;
									break;
								}
								cout<<"\n请选择您所需的操作：\n"
									<<"1.增加\n"
									<<"2.删除\n"
									<<"3.修改\n"
									<<"0.返回\n";
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
									cout<<"课程信息为空！"<<endl;
								else
								{
									Global.PrintSubjs();
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
							int Index = Global.GetSubj();
							if (Index >= 0)
							{
								if (StuCount == 0)
									cout<<"学生信息为空！"<<endl;
								else
								{
									Global.PrintStus();
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
						cout<<"输入错误，请重新输入："<<endl;
						break;
					}
					cout<<"\n请选择您所需的操作：\n"
						<<"1.显示当前所有学生信息\n"
						<<"2.显示当前所有课程信息\n"
						<<"3.更改学生信息（增加/删除/修改）\n"
						<<"4.更改课程信息（增加/删除/修改）\n"
						<<"5.录入某一学生成绩\n"
						<<"6.录入某一课程成绩\n"
						<<"7.录入某一学生的某一课程成绩\n"
						<<"0.保存并返回\n\n";
					cin.clear();
					cin.sync();
					cin>>Choice;
				}				
			}
			Global.WriteData();
			Global.ReleaseData();
			OutFile.close();
			break;

		// 信息检索与数据计算
		case 2:															// TODO
			break;
		default:
			cout<<"输入错误，请重新输入："<<endl;
			break;
		}
		cout<<endl;
		Global.Line0();
		cout<<"请选择您所需的操作：\n"
			<<"1.信息录入与修改\n"
			<<"2.信息检索与数据计算\n"
			<<"0.退出系统\n\n";
		cin.clear();
		cin.sync();
		cin>>Choice;
	}
	cout<<"\n感谢您的使用！再见！\n"<<endl;
	Global.Line1();
}
