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
void LinkStack<T>::Push(T m) //入栈
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
		if (head == NULL) //若为空栈
		{
			cout << "这是空栈" << endl;
		}
		else //若不为空栈
		{
			n = head->data;
			head = head->next;
			count--;
			cout << "出栈的元素是：" << n << endl;
			delete p1;
			p1 = NULL;
		}
}

template <typename T>
void LinkStack<T>::GetLStackTop(T &n)
{
	if (count==0)
		cout << "是空栈" << endl;
	else
	{
		n = head->data;
		cout << "栈顶元素为：" << n << endl;
	}
	
}

template <typename T>
void LinkStack<T>::isEmpty()
{
	if (count)
		cout << "不是空栈" << endl;
	else
		cout << "是空栈" << endl;
}
	
template <typename T>
void LinkStack<T>::LStackLen()
{
	Node* p;
	cout << "栈的长度为：" << count << endl;
	if (head == NULL)
	{
		cout << "是空栈" << endl;
	}
	else
	{
		cout << "栈的遍历为: " << endl;
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
		cout << "是空栈，不用销毁" << endl;
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