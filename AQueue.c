#include <stdio.h>
#include <string.h>
#include "AQueue.h"

void InitAQueue(AQueue* Q)
{
	for (int i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(21);
	Q->front = Q->rear = 0;
	Q->length = 0;

}

//Status EnAQueue(AQueue* Q, void* data) //入队
Status EnAQueue(AQueue* Q,void *data)
{
	if (Q->length == MAXQUEUE) //判满
	{
		printf_s("队列已满\n");
		return FALSE;
	}
	else
	{
		memcpy(Q->data[Q->rear], data, 20);
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		Q->length++;
		return TRUE;
	}
	
}

Status DeAQueue(AQueue* Q) //出队
{
	if (Q->length == 0) //判空
	{
		printf_s("队列已空\n");
		return FALSE;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXQUEUE;
		Q->length--;
		return TRUE;
	}
}

Status GetHeadAQueue(AQueue* Q, void (*foo)(void* q, int typeData))
{
	int e = 0;
	if (Q->length == 0)
	{
		printf_s("队列已空\n");
		return FALSE;
	}
	else
	{
		/*e = Q->data[Q->front];
		printf_s("队头元素是：%d\n", e);*/
		printf_s("队头元素是：");
		foo(Q->data[Q->front], Q->type[Q->front]);
		printf_s("\n");
		return TRUE;
		
	}
}

void ClearAQueue(AQueue* Q)
{
	Q->length = 0;
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue* Q)
{
	for (int i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	Q->data[0] = NULL;
}

Status TraverseAQueue(AQueue* Q, void (*foo)(void* q,int typeData))
{
	if (Q->data[0] == NULL)
	{
		printf_s("请先初始化队列\n");
		return FALSE;
	}	

	 if (Q->length == 0)
	{
		printf_s("队列已空\n");
		return FALSE;
	}
	else
	{
		printf("队列的长度是：%d\n", Q->length);
		printf("队列的遍历为：");
		if (Q->front < Q->rear)
		{
			int i = 0;
			while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)
			{
				foo(Q->data[Q->front + i], Q->type[Q->front + i]);
				i = (i + 1) % MAXQUEUE;
			}
		}
		else //if (Q->front > Q->rear)
		{
			for (int k = Q->front; k <= MAXQUEUE - 1; k++)
			{
				//printf_s("%d ", Q->data[k]);
				foo(Q->data[k], Q->type[k]);
			}
			for (int j = 0; j < Q->rear; j++)
			{
				//printf_s("%d ", Q->data[j]);
				foo(Q->data[j], Q->type[j]);
			}
		}
		
		/*while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) 
		{
			foo(Q->data[Q->front + i], Q->type[Q->front + i]);
			i = (i + 1) % MAXQUEUE;
		}*/
		
		printf_s("\n");
		
		return TRUE;
	}
}

void APrint(void* q,int typeData)
{
	if (typeData == 2)
		printf_s("%.3lf ", *(double*)q);
	/*if (typeData == 2)
		printf_s("%c ", *(char*)q);*/
	if (typeData == 1)
		printf_s("%d ", *(int*)q);
	if (typeData == 3)
		printf_s("%s ", (char*)q);
}