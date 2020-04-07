#pragma once
#ifndef _SQSTACK_H
#define _SQSTACK_H

#include <iostream>
#define stackSize 10
using namespace std;

template <typename T>
class Stack
{
public:
	Stack();
    //void InitStack();
	void IsEmptyStack();
	void DestroyStack();
	void PushStack(T m);
	void PopStack(T &n);
	void ClearStack();
	void GetTopStack(T &n);
	void StackLength();

private:
	int* elem;
	int top;
	int size;
	bool IsDestory;
};

template <typename T>
Stack<T>::Stack()
{
	elem = new int[10];
	top = -1;
	IsDestory = 0;
}

template <typename T>
void Stack<T>::PushStack(T m)
{
	if (top == stackSize - 1)
		cout << "栈满了，不可入栈" << endl;
	else 
	{
		if (IsDestory)
		{
			elem = new int[10];
			top = -1;
			top++;
			elem[top] = m;
			IsDestory = false;
		}
		else
		{
			top++;
			elem[top] = m;
		}
		
	}
	
}

template <typename T>
void Stack<T>::PopStack(T &n)
{
	if (top == -1)
		cout << "栈空了，不可出栈" << endl;
	else
	{
		n = elem[top];
		cout << "出栈的值为: " << n << endl;
		top--;
		//return elem[top--];
	}
}

template <typename T>
void Stack<T>::StackLength()
{
	int i = top;
	cout << "top的值是(初始值为-1)："<<top << endl;
	if (top == -1)
		cout << "是空栈" << endl;
	else 
	{
		cout << "栈的遍历为：" << endl;
		while(i!=-1)
		{
			cout << elem[i] << endl;
		    i--;
		}
	}
}

template <typename T>
void Stack<T>::ClearStack()
{
	top = -1;
}

template <typename T>
void Stack<T>::IsEmptyStack()
{
	if (top == -1)
		cout << "是空栈" << endl;
	else
		cout << "不是空栈" << endl;
		
}

template <typename T>
void Stack<T>::GetTopStack(T &n)
{
	if (top == -1)
		cout << "是空栈" << endl;
	else
	{
		n = elem[top];
		cout << "栈顶元素为：" << n << endl;
	}
}

template <typename T>
void Stack<T>::DestroyStack()
{
	delete []elem;
	elem = NULL;
	top = -1;
	IsDestory = true;
}

#endif