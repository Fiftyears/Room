#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LQueue.h"

void InitLQueue(LQueue* Q) //���г�ʼ��
{
	Q->front = (Node*)malloc(sizeof(Node));
	Q->front->next = NULL;
	Q->rear = Q->front;
	Q->length = 0;
	
}

Status EnLQueue(LQueue* Q, void* e,int t) //���
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

Status DeLQueue(LQueue* Q) //����
{
	if (Q->length == 0) //�п�
	{
		printf_s("���ǿն���\n");
		return FALSE;
	}
	Node* p;
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	Q->length--;
	return TRUE;

}

Status GetHeadLQueue(LQueue* Q,void (*foo)(void* q, int typeData)) //��ȡ��ͷԪ��
{
	if (Q->front == NULL)
	{
		printf_s("��δ��ʼ�������ʼ��");
		return FALSE;
	}
	int e = 0;
	if (Q->length == 0)
	{
		printf_s("�����ѿ�\n");
		return FALSE;
	}
	else
	{
		printf_s("��ͷԪ���ǣ�");
		foo(Q->front->data, Q->front->type);
		printf_s("\n");
		return TRUE;

	}
}

void ClearLQueue(LQueue* Q) //���
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

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q, int typeData)) //��������
{
	
	Node* p;
	if (Q->length == 0)
	{
		printf_s("���ǿն���\n");
	}
	else
	{
		printf_s("���еĳ�����: %d\n", Q->length);
		printf_s("���еı���Ϊ: ");
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