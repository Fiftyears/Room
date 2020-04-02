#pragma once
#include <string>
using namespace std;

class List
{
public:
	List();
	void InitList();
	void InsertList(int m,int n);
	void DeleteList(int n);
	void RerverseList();
	int SearchList(int q);
	void FindMidNode();
	void TraverseList();
	//void Sort();
	string IsLoop();
	void DestroyList(); 

private:
	typedef struct _node{
		int data;
		struct _node *next;

	}Node ;

	Node* head;
};