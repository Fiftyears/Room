#include <iostream>
#include <string>
#include "link.h"
using namespace std;

int main()
{
	List list;
	
	int n, m, q,choice = -1, is_created = 0;
	

	while (choice != 9)
	{
		cout << "链表功能: 0.创建链表 1.删除数字 2.插入数字 3.打印链表 4.链表反转 5.查找某节点 6.找到中间节点 7.链表判环 8.销毁链表 9.退出" << endl;
		cout <<"请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			if (is_created == 1)
			{
				cout <<"链表已经创建\n" <<endl;
				break;
			}
			list.InitList();
			is_created = 1;
			break;
		case 1:
			cout << "删除第n个数,请输入n值(从1开始):" ;
			cin >> q;
			list.DeleteList(q);
			break;
		case 2:
			cout << "将m插入到第n个数后面(n为0则插入在第一个数前面),依此输入两个数m n:" ;
			cin >> m >> n;
			list.InsertList(m, n);
			break;
		case 3:
			list.TraverseList();
			break;
		case 4:
			list.RerverseList();
			break;
		case 5:
			cout << "请输入要找的值(若有相同的则找第一个):";
			cin >> q;
			cout << "是第" << list.SearchList(q) << "个节点" << endl;
			break;
		case 6:
			list.FindMidNode();
			break;
		case 7:
			cout <<list.IsLoop()<< endl;
			break;
		case 8:
			list.DestroyList();
		case 9:
			break;
		default:
			break;
		}
		 
	}

	return 0;
}