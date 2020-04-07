#include <iostream>
#include "SqStack.h"
using namespace std;

int main()
{
	Stack<int> st;
	int n, q, choice = -1;

	while (choice != 8)
	{
		cout << "栈功能:  1.入栈 2.出栈 3.判空 4.取得栈顶元素 5.清空栈 6.检测栈长度 7.销毁 8.退出" << endl;
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
	
		case 1:
			cout << "请输入进栈的数字:";
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