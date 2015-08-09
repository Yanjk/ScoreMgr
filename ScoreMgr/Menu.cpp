#include "Scoremgr.h"

void Proc::Menu()
{
	int Choice;
	do
	{
		cout<<"\n*********************\n"
			<<"请选择您所需的操作：\n"
			<<"1. 信息录入与修改\n"
			<<"2. 信息检索与数据计算\n"
			<<"0. 退出系统\n"
			<<"*********************\n\n";
		GetInt(Choice, 2);
		switch (Choice)
		{
		case 0:
			break;

		//信息录入与修改
		case 1:
			{
				ReadFile();
				int Choice;
				do
				{
					cout<<"\n*****************************\n"
						<<"请输入您所需的操作：\n"
						<<"1. 显示当前所有学生信息\n"
						<<"2. 显示当前所有课程信息\n"
						<<"3. 编辑学生信息\n"
						<<"4. 编辑课程信息\n"
						<<"5. 录入某一学生成绩\n"
						<<"6. 录入某一课程成绩\n"
						<<"7. 录入某一学生的某一课程成绩\n"
						<<"0. 保存并返回\n"
						<<"*****************************\n\n";
					GetInt(Choice, 7);					
					switch (Choice)
					{
					case 0:
						break;
					// 显示当前所有学生信息
					case 1:
						PrintStus();
						break;
					// 显示当前所有课程信息
					case 2:
						PrintSubjs();
						break;
					// 编辑学生信息
					case 3:
						{
							int Choice;
							do
							{
								cout<<"\n请选择您所需的操作：\n"
									<<"1. 增加\n"
									<<"2. 删除\n"
									<<"3. 修改\n"
									<<"0. 返回\n\n";
								GetInt(Choice, 3);
								switch (Choice)
								{
								case 0:
									break;
								case 1:
									NewStu();
									break;
								case 2:
									DeleleStu();
									break;
								case 3:
									ModifyStu();
									break;
								}
							} while (Choice != 0);
						}
						break;
					// 编辑课程信息
					case 4:
						{
							int Choice;
							do
							{
								cout<<"\n请选择您所需的操作：\n"
									<<"1. 增加\n"
									<<"2. 删除\n"
									<<"3. 修改\n"
									<<"0. 返回\n\n";
								GetInt(Choice, 3);
								switch (Choice)
								{
								case 0:
									break;
								case 1:
									NewSubj();
									break;
								case 2:
									DeleleSubj();
									break;
								case 3:
									ModifySubj();
									break;
								}
							} while (Choice != 0);
						}
						break;
					// 录入某一学生成绩
					case 5:
						GetStuScore();
						break;
					// 录入某一课程成绩
					case 6:
						GetSubjScore();
						break;
					// 录入某一学生的某一课程成绩
					case 7:
						GetStuSubjScore();
						break;
					}
				} while (Choice != 0);			

				SaveFile();
				ReleaseMemory();
			}
			break;


		// 信息检索与数据计算
		case 2:	
			if ( ReadFile(0) )
			{
				int Choice;
				do
				{
					cout<<"\n*********************\n"
						<<"请选择您所需的操作：\n"
						<<"1. 显示所有学生信息\n"
						<<"2. 显示所有课程信息\n"
						<<"3. 搜索某一学生成绩\n"
						<<"4. 搜索某一课程成绩\n"
						<<"5. 打印总成绩表\n"
						<<"6. 显示学生GPA排名\n"
						<<"0. 返回\n"
						<<"*********************\n\n";
					GetInt(Choice, 6);
					switch (Choice)
					{
					case 0:
						break;
					// 显示所有学生信息
					case 1:
						PrintStus();
						break;
					// 显示所有课程信息
					case 2:
						PrintSubjs();
						break;
					// 搜索某一学生成绩
					case 3:
						PrintStuScore();
						break;
					// 搜索某一课程成绩
					case 4:
						PrintSubjScore();
						break;
					// 打印总成绩表
					case 5:
						PrintTable();
						break;
					// 显示学生GPA排名
					case 6:
						PrintRank();
						break;
					}
				} while (Choice != 0);
				ReleaseMemory();
			}
			break;
		
		}
	} while (Choice != 0);

	cout<<"\n感谢您的使用！再见！\n"<<endl;
}
