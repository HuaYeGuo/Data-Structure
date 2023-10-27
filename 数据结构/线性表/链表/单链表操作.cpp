#include <bits/stdc++.h>	
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

using namespace std;
//定义单链表存储结构 
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node, * LinkList; //typedef struct Node *LinkList;  

//初始化，申请头结点  
Status InitList(LinkList& L) {
	L = new Node;//(LinkList)malloc(sizeof(Node))
	L->next = NULL;
	return OK;
}

//头插法建立一个带头结点的单链表
Status CreateListHead(LinkList& L, int n) {
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LinkList p = new Node;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}	
	return OK;
}

//尾差法建表
Status CreateListTail(LinkList& L, int n) {
	L = new Node;
	L->next = NULL;
	LinkList r = L;//r为指向尾部的结点
	for (int i = 0; i < n; i++) {
		LinkList p = new Node;//生成新节点
		cin >> p->data;//插入数据
		p->next = NULL;
		r->next = p;//插到表尾
		p = r;//r指向新的尾结点
	}
	return OK;
}

//判断是否为非空链表
Status ListEmpty(LinkList& L) {
	if (L->next) {
		return 	OK;//头指针不指向空，链表不为空. 
	}
	else
		return ERROR;
}

//销毁单链表，销毁包括头结点 ，销毁后不存在单链表 
Status DestoryList(LinkList& L) {
	LinkList p;
	//循环条件(L != NULL); 
	while (L) {
		p = L;
		L = L->next;
		delete p;//free(p) 
	}
	return OK;
}

//删除单链表L，将L重置为空表
Status Clear(LinkList& L) {
	LinkList p, q;//Node *p,*q;
	p = L->next;//p指向第一个结点 
	//循环条件(p != NULL) 
	while (p) {
		q = p->next;//q指向第一个节点的下一个结点(第二个节点) 
		delete p;
		p = q;//p释放后反复执行 
	}
	L->next = NULL;//将首指针指向空，将L重置为空链表 
	return OK;
}

//求单链表的表长
Status ListLength(LinkList& L) {
	LinkList p;
	p = L->next;
	int i = 0; //计数器
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

//单链表的按值查找
Status LocateElem(LinkList& L, ElemType e) {
	LinkList p;
	p = L->next;
	int j = 0;
	while (p && p->data != e) {
		p->next;
		j++;
	}
	if (p)return j;
	else return ERROR;
}

//单链表的插入(在第i个结点前插入值为e的新结点)
Status ListInsert(LinkList& L, int i, ElemType& e) {
	LinkList p = L;
	int j = 1;
	while (p && j < 1){
		p = p->next;
		j++;
	}
	if (!p || j > 1) {
		return ERROR;
	}
	LinkList s = new Node;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//单链表的删除(删除第i个结点)
Status ListDelete(LinkList& L, int i, ElemType& e) {
	LinkList p = L;
	int j = 1;
	while (p->next && j < 1) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > 1) {
		return ERROR;
	}
	p->next = p->next->next;//主要操作
	e = p->next->data;
	delete p->next;
	return OK;
}

int main() {

}
