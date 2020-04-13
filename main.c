#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "AQueue.h"
//#define _CRT_SECURE_NO_WARNINGS

int main()
{
	AQueue aq;
	AQueue* Q = &aq;
	void (*pf)(void* q, int typeData);
	pf = APrint;

	int t, q, choice = -1;

	while (choice != 9)
	{
		printf_s("���й���: 1.��ʼ������ 2.��� 3.���� 4.�п� 5.ȡ�ö�ͷԪ�� 6.��ն��� 7.�����ͼ����г��� 8.���� 9.�˳�\n");
		printf_s( "���������ѡ��:");
		scanf_s("%d", &choice);
		switch (choice)
		{

		case 1:
			InitAQueue(Q); 
			break;
		case 2:
			
			printf_s("�����������: ");
			printf_s("1. ���� 2. ������(�ɵ�С�������λ) 3.�ַ���\n");
			scanf_s("%d", &t);
			while (t < 1 || t>3)
			{
				printf_s("Ӧ������[1,3]֮���������\n�����䣺");
				scanf_s("%d", &t);
			}
			
			switch (t)
			{
			case 1: {
				int a;
				printf_s("��ӵ����� :");
				scanf_s("%d", &a);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &a);
				break;
			}
			
			case 2: {
				double c;
				printf_s("��ӵ����� :");
				scanf_s("%lf", &c);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &c);
				break;
			}
			case 3: {
				char d[20];
				printf_s("��ӵ�����(��󳤶�Ϊ20) :");
				scanf_s("%s",d,sizeof(d));
				Q->type[Q->rear] = t;
				EnAQueue(Q, d);
				break;
			}
			}

			break;
		case 3:
			DeAQueue(Q);
			break;
		case 4:
			break;
		case 5:
			GetHeadAQueue(Q,pf);
			break;
		case 6:
			ClearAQueue(Q);
			break; 
		case 7:
			TraverseAQueue(Q,pf);
			break;
		case 8:
			DestoryAQueue(Q);
			break;
		case 9:
			break;
		default:
			break;
		}

	}
	return 0;
}