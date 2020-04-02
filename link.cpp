#include <iostream>
#include <string>
#include "link.h"
using namespace std;

List::List()
{
	Node* head = new Node();
	head->next = NULL;
}

void List::InitList() //����һ������
{
	int number = 0;
	int i = 0;
	
	Node* p1, * p2;
	p1 = p2 = new Node();
	cout << "������һЩ���֣���-1��β" << endl;
	cin >> p1->data;
	while (p1->data != -1)
	{
		i++;
		if (i == 1)
		{
			head = p1; //����ǵ�һ���ڵ㣬��ͷָ��ָ����
		}
		else
		{
			p2->next = p1;
		}

		p2 = p1;
		p1 = new Node();
		cin >> p1->data;
	}

	p2->next = NULL; //���ʹβ�ڵ��ָ����ָ��NULL��
}

void List::InsertList(int m,int n) //����ڵ㣬nΪҪ����ڼ���
{
	int number = 1;
	Node* p1 = head;
	Node *p2;
	if (n == 0)
	{
		if (head == NULL) //��������Ϊ��
		{
			head = new Node();
			head->data = m;
			head->next = NULL;
			return;
		}
		else //��������Ϊ��
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

	if (p1->next == NULL && number != n) //Ҫ����Ľڵ㳬��������
	{
		cout << "����������" << endl;
		//return ;
		
	}
	else if (p1->next == NULL) //Ҫ����Ľڵ�������β�ڵ�
	{
		p1->next = new Node();
		p1->next->data = m;
		p1->next->next = NULL;
	}
	else //Ҫ����Ľڵ��������м�
	{
		p2 = p1->next;
		p1->next = new Node();
		p1->next->data = m;
		p1->next->next = p2;
	}
	return;
}

void List::DeleteList(int n)
{
	int number = 1;
	Node* p1 = head;
	Node* p2;
	
	if (n == 1) //��ɾ������ͷ�ڵ�
	{
		if (p1->next == NULL) //��������ֻ��һ���ڵ�
		{
			delete head;
			head = NULL;
		}
		else //��������ֹһ���ڵ�
		{
			
			head = head->next;
			delete p1;
			p1 = NULL;
		}
	}
	else
	{
		while (number != n-1 && p1->next != NULL) //��ʼ����
		{
			number++;
			p1 = p1->next;
		}
		if (p1->next == NULL) //Ҫɾ���Ľڵ㳬��������
		{
			cout << "����������" << endl;
			
		}
		else if (p1->next->next == NULL) //Ҫɾ���Ľڵ�����������һ��
		{
			delete p1->next;
			p1->next = NULL;
			
		}
		else //Ҫɾ���Ľڵ��������м� 
		{
			p2 = p1->next;
			p1->next = p2->next;
			delete p2;
			p2 = NULL;
		}
	}
	return;
}

void List::RerverseList() //��ת����
{
	if (head->next == NULL)
	{
		cout << "����ֻ��һ���ڵ�" << endl;
			
	}
	else
	{
		Node* p = head->next;
		head->next = NULL;
		Node* tmp = NULL;
		while (p)
		{
			tmp = p->next;
			p->next = head->next;
			head->next = p;
			p = tmp;
		}
	}
}

int List::SearchList(int q)
{
	int i = 1;
	Node* p = head;
	if (p->next == NULL)
	{
		cout << "���ǿ�����" << endl;
	}
	
	else
	{
		while (p != NULL)
		{
			if (p->data != q)
			{
				i++;
				p = p->next;
			}
			else
				break;
		}
		if (p == NULL)
		{
			cout << "û�иýڵ�" << endl;
			return 0;
		}
		else
			return i;
	}
	{
		p = p->next;
	}
}

void List::FindMidNode()
{
	int i = 0;
	Node* p1 = head;
	Node* p2 = head;
	while (p1->next != NULL && p1->next->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
	}
	cout << "�м�ڵ�Ϊ" << p2->data << endl;
	return;
}

void List::TraverseList()
{
	Node* p;
	if (head == NULL)
	{
		cout << "���ǿ������޽ڵ�" << endl;
	}
	else
	{
		cout << "����ı���Ϊ: ";
		for (p = head; p; p = p->next)
		{
			cout << p->data << "->";
		}
		cout << "NULL" << endl;
	}
}

string List::IsLoop() 
{
	int i = 0;
	Node* p1 = head;
	Node* p2 = head;
	
	while (p1->next != NULL && p1->next->next != NULL )
	{
		
		p1 = p1->next->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			return "�л�";
		}
	}
	return "�޻�";
}

void List::DestroyList()
{
	Node* p, * q;
	for (p = head; p; p = q)
	{
		q = p->next;
		delete p;
	    p = NULL;
	}
	head = NULL;
	//Node* head = new Node();
	//head = NULL;
}