#include <iostream>
#include "linkstack.h"
using namespace std;

int main()
{
	LinkStack<int> st;
	int n, q, choice = -1;

	while (choice != 8)
	{
		cout << "ջ����:  1.��ջ 2.��ջ 3.�п� 4.ȡ��ջ��Ԫ�� 5.���ջ���� 6.���� 7.�˳�" << endl;
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "�������ջ���������ɸģ�:";
			cin >> q;
			st.Push(q);
			break;
		case 2:
			st.Pop(n);
			break;
		case 3:
			st.isEmpty();
			break;
		case 4:
			st.GetLStackTop(n);
			break;
		case 5:
			st.LStackLen();
			break;
		case 6:
			st.DestroyStack();
			break;
		case 7:
			break;
		default:
			break;
		}

	}
	return 0;
}