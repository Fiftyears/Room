#include <iostream>
#include "SqStack.h"
using namespace std;

int main()
{
	Stack<int> st;
	int n, q, choice = -1;

	while (choice != 8)
	{
		cout << "ջ����:  1.��ջ 2.��ջ 3.�п� 4.ȡ��ջ��Ԫ�� 5.���ջ 6.���ջ���� 7.���� 8.�˳�" << endl;
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
	
		case 1:
			cout << "�������ջ������:";
			cin >> q;
			st.PushStack(q);
			break;
		case 2:
			st.PopStack(n);
			break;
		case 3:
			st.IsEmptyStack();
			break;
		case 4:
			st.GetTopStack(n);
			break;
		case 5:
			st.ClearStack();
			break;
		case 6:
			st.StackLength();
			break;
		case 7:
			st.DestroyStack();
			break;
		case 8:
			break;
		default:
			break;
		}

	}

	return 0;
}