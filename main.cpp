#include <iostream>
#include "linkstack.h"
using namespace std;

int main()
{
	LinkStack<int> st;
	int n, q, choice = -1;

	while (choice != 8)
	{
		cout << "栈功能:  1.入栈 2.出栈 3.判空 4.取得栈顶元素 5.检测栈长度 6.销毁 7.退出" << endl;
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入进栈的整数（可改）:";
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