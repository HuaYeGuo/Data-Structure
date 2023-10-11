#include <bits/stdc++.h>
#define MAXSIZE 100
#define Status int
#define ElemType int
#define OK 1
#define ERROR 0
using namespace std;

typedef struct{
	ElemType elem[MAXSIZE];
	int length;
}SqList;
Status InitList(SqList* L){
	L->length = 0;//初始化长度
	return OK;
}
//元素插入(i:插入的位置,e:插入的元素)
Status ListInsert(SqList* L,int i,ElemType e){
	int j;
	if(i < 1||i > L->length + 1)return ERROR;
	if(L->length == MAXSIZE){
		cout << "表已满！" << endl;
		return ERROR;
	}
	for(j = L->length;j > i - 1;j--){//从后往前覆盖,i从1开始
		L->elem[j] = L->elem[j - 1];
	}
	L -> elem[i - 1] = e;//在留出的位置赋值
	(L->length)++;//表长加一
	return OK;
}
//元素删除
Status ListDelete(SqList* L,int i,ElemType*e){
	if(i < 1||i > L->length)return ERROR;//排除非法输入/表空
	*e = L->elem[i - 1];//为了返回值
	for(int j = i - 1;j <= L->length;j++){//从前往后覆盖
		L->elem[j] = L->elem[j + 1];
	}
	(L->length)--;//长度减一
	return OK;
}
//输出打印
void ListPrint(SqList L){
	for(int i = 0;i < L.length;i++){
		cout << L.elem[i] << endl;
	}
}
//按正负拆分
void DisCreat(SqList A,SqList* B,SqList* C){
	for(int i = 0;i < A.length;i++){
		if(A.elem[i] < 0)
			ListInsert(B,B->length + 1,A.elem[i]);
		else
			ListInsert(C,C->length + 1,A.elem[i]);
	}
}
int main(){
	SqList L,B,C;
	ElemType e;
	ElemType data[9] = {11,-22,33,-3,-88,21,77,0,-9};
	InitList(&L);
	InitList(&B);
	InitList(&C);
	for(int i = 1;i <= 9;i++){
		ListInsert(&L,i,data[i - 1]);
	}
	cout << "插入完成后L = "<< endl;
	ListPrint(L);
	ListDelete(&L,1,&e);
	cout << "删除第一个后L = " << endl;
	ListPrint(L);
	DisCreat(L,&B,&C);
	cout << "拆分L后B = " << endl;
	ListPrint(B);
	cout << "拆分L后C = " << endl;
	ListPrint(C);
	cout << "拆分L后L = " << endl;
	ListPrint(L);
}

