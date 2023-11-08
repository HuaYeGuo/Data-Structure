#include <bits/stdc++.h> 
#define OK 1
#define ERROR 0

using namespace std;
typedef char TElemType;
//二叉树的二叉链表存储表示121页 
typedef struct BiNode {
	TElemType data;
	struct BiNode* lchild, * rchild;
}BiNode, * BiTree;

//初始化
int InitBiTree(BiTree& T) {
	T = NULL;
	return OK;
}
//先序遍历建立二叉链表P126页 
void CreateBiTree(BiTree& T) {
	TElemType ch;
	cin >> ch;
	if (ch == '#') T = NULL;
	else {
		T = new BiNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
} //CreateBiTree


//先序遍历 
void PrevOrder(BiTree T) {
	if (T) {
		cout << T->data;
		PrevOrder(T->lchild);
		PrevOrder(T->rchild);
	}
}
// 中序遍历 
void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	}
}
//后序遍历 
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data;
	}
}
//层序遍历
void LevelOrder(BiTree T) {
    if (T == NULL) return;

    queue<BiTree> q;
    q.push(T);

    while (!q.empty()) {
        BiTree current = q.front();
        q.pop();

        // 访问当前节点
        cout << current->data;

        if (current->lchild) {
            q.push(current->lchild);
        }
        if (current->rchild) {
            q.push(current->rchild);
        }
    }
}
 
//统计结点个数
int NodeCount(BiTree T) {
	if (T == NULL) return 0;
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
//计算叶子结点个数 
int CountLeaves(BiTree T) {
    if (T == NULL) {
        return 0;
    } else if (T->lchild == NULL && T->rchild == NULL) {
        return 1; // T是叶子节点
    } else {
        return CountLeaves(T->lchild) + CountLeaves(T->rchild);
    }
}

//计算二叉树深度
int Depth(BiTree T) {
	int m, n;
	if (T == NULL)return 0;
	else {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n) return m + 1;
		else return(n + 1);
	}
}
//复制二叉树 
void CopyTree(BiTree T, BiTree& NewT) {
	if (T == NULL) {
		NewT = NULL;
		return;
	}
	else {
		NewT = new BiNode;
		NewT->data = T->data;
		CopyTree(T->lchild, NewT->lchild);
		CopyTree(T->rchild, NewT->rchild);
	}
}
int main()
{
	//1.声明树
	cout << "请输入二叉树(用#表示空)" << endl;
	BiTree T;
	//2.构造树
	CreateBiTree(T);
	//复制二叉树 
	BiTree NewT = NULL;
    CopyTree(T, NewT);
	//3.先序遍历
	cout << "前序遍历结果为:" << endl;
	PrevOrder(T);
	cout << endl;
	//4.中序遍历
	cout << "中序遍历结果为:" << endl;
	InOrder(T);
	cout << endl;
	//5.后序遍历
	cout << "后序遍历结果为:" << endl;
	PostOrder(T);
	cout << endl;
	cout << "层序遍历结果为:" << endl;
    LevelOrder(T);
    cout << endl;
	//二叉树结点个数		
	cout << "二叉树结点个数:" << NodeCount(T) << endl;
	//二叉树叶子结点个数
	cout << "二叉树叶子结点个数:" << CountLeaves(T) << endl;
	//二叉树深度
	cout << "二叉树深度:" << Depth(T) << endl;
	//复制二叉树 
	cout << "复制后的二叉树前序遍历结果为:" << endl;
    PrevOrder(NewT);
    cout << endl;
    cout << "复制后的二叉树中序遍历结果为:" << endl;
    InOrder(NewT);
    cout << endl;
    cout << "复制后的二叉树后序遍历结果为:" << endl;
    PostOrder(NewT);
    cout << endl;

	return 0;
}
