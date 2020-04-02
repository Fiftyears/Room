#pragma once
class DoubleList
{
public:
	DoubleList();
	void InitList();
	void InsertList(int m, int n);
	void DeleteList(int n);
	void TraverseList();
	void DestroyList();

private:
	typedef struct _node {
		int data;
		struct _node* next;
		struct _node* prior;

	}Node;

	Node* head;
};