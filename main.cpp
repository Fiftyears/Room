#include <iostream>
#include "doublelist.h"
using namespace std;

int main()
{
	DoubleList list;

	int n, m, q, choice = -1, is_created = 0;

	while (choice != 5)
	{
		cout << "������: 0.�������� 1.ɾ������ 2.�������� 3.��ӡ���� 4.�������� 5.�˳�" << endl;
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			if (is_created == 1)
			{
				cout << "�����Ѿ�����\n" << endl;
				break;
			}
			list.InitList();
			is_created = 1;
			break;
		case 1:
			cout << "ɾ����n����,������nֵ(��1��ʼ):";
			cin >> q;
			list.DeleteList(q);
			break;
		case 2:
			cout << "��m���뵽��n��������(��0��ʼ),��������������m n:";
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