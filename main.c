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
		printf_s("队列功能: 1.初始化队列 2.入队 3.出队 4.取得队头元素 5.清空队列 6.遍历和检测队列长度 7.销毁 8.退出\n");
		printf_s("请输入你的选择:\n");
		scanf_s("%d", &choice);
		switch (choice)
		{

		case 1:
			InitLQueue(Q);
			break;
		case 2:

			printf_s("输入入队类型: ");
			printf_s("1. 整型 2. 浮点型(精确到小数点后2位) 3. 字符/字符串\n");
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
				EnLQueue(Q, &a,t);
				break;
			}
			
			case 2: {
				double c;
				printf_s("入队的数据 :");
				scanf_s("%lf", &c);
				EnLQueue(Q, &c,t);
				break;
			}
			case 3: {
				char d[20];
				printf_s("入队的数据(最大长度为20): ");
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