#include <iostream>

using namespace std;

typedef struct Bnode
{
    char data;
    struct Bnode  *lchild,*rchild;
}Bnode,*Btree;

//创建二叉树
void  createtree(Btree &T)
{
    //询问法创建二叉树
    char check;
    T = new Bnode;
    cout <<"请输入节点信息："<<endl;   //输入根节点数目
    cin >> T->data;
    cout <<"是否添加"<<T->data <<"的左孩子？（Y/N）"<<endl;   //询问是否创建T的左子树
    cin>>check;
    if(check=='y' || check =='Y')
    {
        createtree(T->lchild);
    }
    else{
        T->lchild = NULL;
    }
    cout <<"是否添加"<<T->data<<"的右孩子？（Y/N）"<<endl;
    cin >> check;
    if(check=='Y' || check=='y')
    {
        createtree(T->rchild);
    }
    else{
        T->rchild = NULL;
    }
}

//二叉树的遍历
//先序遍历
void preorder(Btree T)
{
    if(T)
    {
        cout <<T->data<<"  "<<endl;
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

//中序遍历
void inorder(Btree T)
{
    if(T)
    {
        inorder(T->lchild);
        cout <<T->data<<"  "<<endl;
        inorder(T->rchild);
    }
}

//后序遍历
void posorder(Btree T)
{
    if(T)
    {
        posorder(T->lchild);
        posorder(T->rchild);
        cout <<T->data<<"  "<<endl;
    }
}





int main()
{
     Btree t1;
    createtree(t1);
    preorder(t1);
    inorder(t1);
    posorder(t1);
    return 0;
}
