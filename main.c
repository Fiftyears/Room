#include <stdio.h>
#include "LQueue.h"

int main()
{
	LQueue aq;
	LQueue* Q = &aq;
	void (*pf)(void* q, int typeData);
	pf = LPrint;
	 
	int t, q, choice = -1;

	while (choice != 8)
	{
		printf_s("���й���: 1.��ʼ������ 2.��� 3.���� 4.ȡ�ö�ͷԪ�� 5.��ն��� 6.�����ͼ����г��� 7.���� 8.�˳�\n");
		printf_s("���������ѡ��:\n");
		scanf_s("%d", &choice);
		switch (choice)
		{

		case 1:
			InitLQueue(Q);
			break;
		case 2:

			printf_s("�����������: ");
			printf_s("1. ���� 2. ������(��ȷ��С�����2λ) 3. �ַ�/�ַ���\n");
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
				EnLQueue(Q, &a,t);
				break;
			}
			
			case 2: {
				double c;
				printf_s("��ӵ����� :");
				scanf_s("%lf", &c);
				EnLQueue(Q, &c,t);
				break;
			}
			case 3: {
				char d[20];
				printf_s("��ӵ�����(��󳤶�Ϊ20): ");
				scanf_s("%s", &d,sizeof(d));
				EnLQueue(Q, d,t);
				break;
			}
			}

			break;
		case 3:
			DeLQueue(Q);
			break;
		case 4:
			GetHeadLQueue(Q, pf);
			break;
		case 5:
			ClearLQueue(Q);
		case 6:
			TraverseLQueue(Q, pf);
			break;
		case 7:
			DestoryLQueue(Q);
			break;
		case 8:
			break;
		default:
			break;
		}
	}
}