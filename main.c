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
		printf_s("队列功能: 1.初始化队列 2.入队 3.出队 4.判空 5.取得队头元素 6.清空队列 7.遍历和检测队列长度 8.销毁 9.退出\n");
		printf_s( "请输入你的选择:");
		scanf_s("%d", &choice);
		switch (choice)
		{

		case 1:
			InitAQueue(Q); 
			break;
		case 2:
			
			printf_s("输入入队类型: ");
			printf_s("1. 整型 2. 浮点型(可到小数点后三位) 3.字符串\n");
			scanf_s("%d", &t);
			while (t < 1 || t>3)
			{
				printf_s("应输入在[1,3]之间的整数！\n请重输：");
				scanf_s("%d", &t);
			}
			
			switch (t)
			{
			case 1: {
				int a;
				printf_s("入队的数据 :");
				scanf_s("%d", &a);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &a);
				break;
			}
			
			case 2: {
				double c;
				printf_s("入队的数据 :");
				scanf_s("%lf", &c);
				Q->type[Q->rear] = t;
				EnAQueue(Q, &c);
				break;
			}
			case 3: {
				char d[20];
				printf_s("入队的数据(最大长度为20) :");
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