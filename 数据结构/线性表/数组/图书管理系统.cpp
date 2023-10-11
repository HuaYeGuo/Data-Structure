#include<bits/stdc++.h> 
#define Status int
#define MAXSIZE 100
#define N 1
#define ElemType Book
#define ERROR 0
#define OK 1
using namespace std; 


typedef struct {
	char no[20];
	char name[50];
	float price;
}Book; 

typedef struct{
	Book elem[MAXSIZE];
	int length;
}SqList;

//初始化顺序表
Status InitList(SqList &L){
	if(!L.elem) exit(ERROR);
	L.length = 0;
	return OK;
} 
Status ListInsert(SqList &L,int i,ElemType e){
	int j;
	if((i < 0)||(i > L.length + 1))return ERROR;
	if(L.length == MAXSIZE) return 	ERROR;		
 	for(j = L.length - 1;j >= i - 1;i--){
	L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
void Listprint(SqList &L){
	int i;
	for(i = 0;i < L.length;i++){
		cout << "书名：" << L.elem[i].name << 
		"作者："<<L.elem[i].no << "价格："
		<< L.elem[i].price<<endl; 
	}
}

int main(){
	int i,num;
	SqList L;
	InitList(L);
	cout<<"要输入几本书的信息："<<endl;
	cin >> num;
	for(i = 0;i < num;i++){
		cout<<"请输入第"<<i + 1<<"本图书信息"<<endl;
		Book infor;
		cout<<"书名："<<endl;
		cin>>infor.name;
		cout<<"作者："<<endl;
		cin>>infor.no; 
		cout<<"价格："<<endl;
		cin>>infor.price;
		if(ListInsert(L,i + 1,infor))
		cout<<"添加成功"<<endl;
		else 
		cout<<"添加失败"<<endl; 
	} 
	Listprint(L);
}
