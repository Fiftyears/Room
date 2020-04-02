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
		cout << "������: 0.�������� 1.ɾ������ 2.�������� 3.��ӡ���� 4.����ת 5.����ĳ�ڵ� 6.�ҵ��м�ڵ� 7.�����л� 8.�������� 9.�˳�" << endl;
		cout <<"���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			if (is_created == 1)
			{
				cout <<"�����Ѿ�����\n" <<endl;
				break;
			}
			list.InitList();
			is_created = 1;
			break;
		case 1:
			cout << "ɾ����n����,������nֵ(��1��ʼ):" ;
			cin >> q;
			list.DeleteList(q);
			break;
		case 2:
			cout << "��m���뵽��n��������(nΪ0������ڵ�һ����ǰ��),��������������m n:" ;
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
			cout << "������Ҫ�ҵ�ֵ(������ͬ�����ҵ�һ��):";
			cin >> q;
			cout << "�ǵ�" << list.SearchList(q) << "���ڵ�" << endl;
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