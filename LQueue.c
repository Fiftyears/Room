#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LQueue.h"

void InitLQueue(LQueue* Q) //队列初始化
{
	Q->front = (Node*)malloc(sizeof(Node));
	Q->front->next = NULL;
	Q->rear = Q->front;
	Q->length = 0;
	
}

Status EnLQueue(LQueue* Q, void* e,int t) //入队
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = (void*)malloc(21);
	memcpy(p->data, e, 20);
	p->next = NULL;
	p->type = t;
	if (Q->length == 0)
	{
		Q->front = p;
	}
	else
	{
		Q->rear->next = p;
	}
	Q->rear = p;
	Q->length++;
	
	return TRUE;
}

Status DeLQueue(LQueue* Q) //出队
{
	if (Q->length == 0) //判空
	{
		printf_s("这是空队列\n");
		return FALSE;
	}
	Node* p;
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	Q->length--;
	return TRUE;

}

Status GetHeadLQueue(LQueue* Q,void (*foo)(void* q, int typeData)) //获取队头元素
{
	if (Q->front == NULL)
	{
		printf_s("还未初始化，请初始化");
		return FALSE;
	}
	int e = 0;
	if (Q->length == 0)
	{
		printf_s("队列已空\n");
		return FALSE;
	}
	else
	{
		printf_s("队头元素是：");
		foo(Q->front->data, Q->front->type);
		printf_s("\n");
		return TRUE;

	}
}

void ClearLQueue(LQueue* Q) //清空
{
	Node* p, * q;
	for (p = Q->front; p; p = q)
	{
		q = p->next;
		free(p);
		p = NULL;
	}
	Q->front = NULL;
	Q->length = 0;
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int typeData)) //遍历队列
{
	
	Node* p;
	if (Q->length == 0)
	{
		printf_s("这是空队列\n");
	}
	else
	{
		printf_s("队列的长度是: %d\n", Q->length);
		printf_s("队列的遍历为: ");
		for (p = Q->front; p; p = p->next)
		{
			foo(p->data, p->type);
		}
		printf_s("\n");
	}
	return TRUE;
}

void DestoryLQueue(LQueue* Q)
{
	Node* p, * q;
	for (p = Q->front; p; p = q)
	{
		q = p->next;
		free(p);
		p = NULL;
	}
	Q->front = NULL;
	Q->length = 0;
	
}

void LPrint(void* q, int typeData) 
{
	if (typeData == 2)
		printf_s("%.2lf ", *(double*)q);
	if (typeData == 1)
		printf_s("%d ", *(int*)q);
	if (typeData == 3)
		printf_s("%s ", (char*)q);
}