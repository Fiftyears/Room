#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkStack
{
public:
	LinkStack();
	void Push(T m);
	void Pop(T &n);
	void GetLStackTop(T &n);
	void isEmpty();
	void LStackLen();
	void ClearStack();
	void DestroyStack();

private:
	typedef struct _node {
		T data;
		struct _node* next;

	}Node;

	Node* head;
	int count;
};

template <typename T>
LinkStack<T>::LinkStack()
{
	Node* head = new Node();
	head->next = NULL;
	count = 0;
}

template <typename T>
void LinkStack<T>::Push(T m) //��ջ
{
	
	Node* p1 = new Node();
	p1->data = m;
	p1->next = head;
	head = p1;
	count++;
	
	return;
}

template <typename T>
void LinkStack<T>::Pop(T &n)
{
	Node* p1 = head;
		if (head == NULL) //��Ϊ��ջ
		{
			cout << "���ǿ�ջ" << endl;
		}
		else //����Ϊ��ջ
		{
			n = head->data;
			head = head->next;
			count--;
			cout << "��ջ��Ԫ���ǣ�" << n << endl;
			delete p1;
			p1 = NULL;
		}
}

template <typename T>
void LinkStack<T>::GetLStackTop(T &n)
{
	if (count==0)
		cout << "�ǿ�ջ" << endl;
	else
	{
		n = head->data;
		cout << "ջ��Ԫ��Ϊ��" << n << endl;
	}
	
}

template <typename T>
void LinkStack<T>::isEmpty()
{
	if (count)
		cout << "���ǿ�ջ" << endl;
	else
		cout << "�ǿ�ջ" << endl;
}
	
template <typename T>
void LinkStack<T>::LStackLen()
{
	Node* p;
	cout << "ջ�ĳ���Ϊ��" << count << endl;
	if (head == NULL)
	{
		cout << "�ǿ�ջ" << endl;
	}
	else
	{
		cout << "ջ�ı���Ϊ: " << endl;
		for (p = head; p; p = p->next)
		{
			cout << p->data << endl;
		}
		
	}
}

template <typename T>
void LinkStack<T>::DestroyStack()
{
	
	Node* p, * q;
	if (count == 0)
		cout << "�ǿ�ջ����������" << endl;
	else
	{
	for (p = head; p; p = q)
	{
		q = p->next;
		delete p;
		p = NULL;
	}
	head = NULL;
	count = 0;
	}
}