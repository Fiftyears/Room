#include <iostream>
#include "doublelist.h"
using namespace std;

int main()
{
	DoubleList list;

	int n, m, q, choice = -1, is_created = 0;

	while (choice != 5)
	{
		cout << "链表功能: 0.创建链表 1.删除数字 2.插入数字 3.打印链表 4.销毁链表 5.退出" << endl;
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			if (is_created == 1)
			{
				cout << "链表已经创建\n" << endl;
				break;
			}
			list.InitList();
			is_created = 1;
			break;
		case 1:
			cout << "删除第n个数,请输入n值(从1开始):";
			cin >> q;
			list.DeleteList(q);
			break;
		case 2:
			cout << "将m插入到第n个数后面(从0开始),依此输入两个数m n:";
			cin >> m >> n;
			list.InsertList(m, n);
			break;
		case 3:
			list.TraverseList();
			break;
		case 4:
			list.DestroyList();
			break;
		case 5:
			break;
		default:
			break;
		}

	}

	return 0;
}