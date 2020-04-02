#include <iostream>
#include "doublelist.h"
using namespace std;

DoubleList::DoubleList()
{
	Node* head = new Node();
	head->next = NULL;
	head->prior = NULL;
}

void DoubleList::InitList()
{
	int number = 0;
	int i = 0;
	Node* p1, * p2;
	p1 = p2 = new Node();
	cout << "请输入一些数字，以-1结尾" << endl;
	cin >> p1->data;
	while (p1->data != -1)
	{
		i++;
		if (i == 1)
		{
			head = p1; //如果是第一个节点，让头指针指向它
		}
		else
		{
			p2->next = p1;
			p1->prior = p2;
		}

		p2 = p1;
		p1 = new Node();
		cin >> p1->data;
	}

	p2->next = NULL; //最后使尾节点的指针域指向NULL；
}

void DoubleList::InsertList(int m, int n) //插入节点，n为要插入第几个
{
	int number = 1;
	Node* p1 = head;
	Node* p2;
	if (n == 0)
	{
		if (head == NULL) //若该链表为空
		{
			head = new Node();
			head->data = m;
			head->next = NULL;
			return;
		}
		else //若该链表不为空
		{
			head = new Node();
			head->data = m;
			head->next = p1;
			return;
		}
	}

		while (number != n && p1->next != NULL)
		{
			number++;
			p1 = p1->next;
		}

		if (p1->next == NULL && number != n) //要插入的节点超出链表长度
		{
			cout << "超出链表长度" << endl;
			//return ;

		}
		else if (p1->next == NULL) //要插入的节点是链表尾节点
		{
			
			p1->next = new Node();
			p1->next->data = m;
			p1->next->next = NULL;
			p1->next->prior = p1;
		}
		else //要插入的节点在链表中间
		{
			p2 = p1->next;
			p1->next = new Node();
			p1->next->data = m;
			p1->next->next = p2;
			p1->next->prior = p1;
		}
	
	return;
}

void DoubleList::DeleteList(int n)
{
	int number = 0;
	Node* p1 = head;
	Node* p2;

	if (n == 1) //若删除的是头节点
	{
		if (p1->next == NULL) //若该链表只有一个节点
		{
			delete head;
			head = NULL;
		}
		else //若该链表不止一个节点
		{
			
			head = head->next;
			delete p1;
			
			p1 = NULL;
		}
	}

	else
	{
		while (number != n - 1 && p1->next != NULL) 
		{
			number++;
			p1 = p1->next;
		}
		if (p1->next == NULL) //要删除的节点超出链表长度
		{
			cout << "超出链表长度" << endl;
			//return 0;

		}
		else if (p1->next->next == NULL) //要删除的节点是链表的最后一个
		{
			delete p1->next;
			p1->next = NULL;
			//return 0;

		}
		else //要删除的节点在链表中间 
		{
			/*p2 = p1->next;
			p1->next = p2->next;*/
			p1->next->prior = p1->prior;
			p1->prior->next = p1->next;
			delete p1;
			p1 = NULL;
		}
	}
	return;
}

void DoubleList::TraverseList()
{
	Node* p;
	if (head == NULL)
	{
		cout << "这是空链表，无节点" << endl;
	}
	else
	{
		cout << "链表的遍历为: ";
		for (p = head; p; p = p->next)
		{
			cout << p->data <<"<"<< "->";
		}
		cout << "NULL" << endl;
	}
}

void DoubleList::DestroyList()
{
	Node* p, * q;
	for (p = head; p; p = q)
	{
		q = p->next;
		delete p;
		p = NULL;
	}
	head = NULL;
}