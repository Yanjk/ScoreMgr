#include "Scoremgr.h"

void Proc::Menu()
{
	int Choice;
	do
	{
		cout<<"\n*********************\n"
			<<"��ѡ��������Ĳ�����\n"
			<<"1. ��Ϣ¼�����޸�\n"
			<<"2. ��Ϣ���������ݼ���\n"
			<<"0. �˳�ϵͳ\n"
			<<"*********************\n\n";
		GetInt(Choice, 2);
		switch (Choice)
		{
		case 0:
			break;

		//��Ϣ¼�����޸�
		case 1:
			{
				ReadFile();
				int Choice;
				do
				{
					cout<<"\n*****************************\n"
						<<"������������Ĳ�����\n"
						<<"1. ��ʾ��ǰ����ѧ����Ϣ\n"
						<<"2. ��ʾ��ǰ���пγ���Ϣ\n"
						<<"3. �༭ѧ����Ϣ\n"
						<<"4. �༭�γ���Ϣ\n"
						<<"5. ¼��ĳһѧ���ɼ�\n"
						<<"6. ¼��ĳһ�γ̳ɼ�\n"
						<<"7. ¼��ĳһѧ����ĳһ�γ̳ɼ�\n"
						<<"0. ���沢����\n"
						<<"*****************************\n\n";
					GetInt(Choice, 7);					
					switch (Choice)
					{
					case 0:
						break;
					// ��ʾ��ǰ����ѧ����Ϣ
					case 1:
						PrintStus();
						break;
					// ��ʾ��ǰ���пγ���Ϣ
					case 2:
						PrintSubjs();
						break;
					// �༭ѧ����Ϣ
					case 3:
						{
							int Choice;
							do
							{
								cout<<"\n��ѡ��������Ĳ�����\n"
									<<"1. ����\n"
									<<"2. ɾ��\n"
									<<"3. �޸�\n"
									<<"0. ����\n\n";
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
					// �༭�γ���Ϣ
					case 4:
						{
							int Choice;
							do
							{
								cout<<"\n��ѡ��������Ĳ�����\n"
									<<"1. ����\n"
									<<"2. ɾ��\n"
									<<"3. �޸�\n"
									<<"0. ����\n\n";
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
					// ¼��ĳһѧ���ɼ�
					case 5:
						GetStuScore();
						break;
					// ¼��ĳһ�γ̳ɼ�
					case 6:
						GetSubjScore();
						break;
					// ¼��ĳһѧ����ĳһ�γ̳ɼ�
					case 7:
						GetStuSubjScore();
						break;
					}
				} while (Choice != 0);			

				SaveFile();
				ReleaseMemory();
			}
			break;


		// ��Ϣ���������ݼ���
		case 2:	
			if ( ReadFile(0) )
			{
				int Choice;
				do
				{
					cout<<"\n*********************\n"
						<<"��ѡ��������Ĳ�����\n"
						<<"1. ��ʾ����ѧ����Ϣ\n"
						<<"2. ��ʾ���пγ���Ϣ\n"
						<<"3. ����ĳһѧ���ɼ�\n"
						<<"4. ����ĳһ�γ̳ɼ�\n"
						<<"5. ��ӡ�ܳɼ���\n"
						<<"6. ��ʾѧ��GPA����\n"
						<<"0. ����\n"
						<<"*********************\n\n";
					GetInt(Choice, 6);
					switch (Choice)
					{
					case 0:
						break;
					// ��ʾ����ѧ����Ϣ
					case 1:
						PrintStus();
						break;
					// ��ʾ���пγ���Ϣ
					case 2:
						PrintSubjs();
						break;
					// ����ĳһѧ���ɼ�
					case 3:
						PrintStuScore();
						break;
					// ����ĳһ�γ̳ɼ�
					case 4:
						PrintSubjScore();
						break;
					// ��ӡ�ܳɼ���
					case 5:
						PrintTable();
						break;
					// ��ʾѧ��GPA����
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

	cout<<"\n��л����ʹ�ã��ټ���\n"<<endl;
}
