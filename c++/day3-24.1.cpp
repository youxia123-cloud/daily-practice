#include <iostream>

using namespace std;
typedef struct Bnode
{
    char data;
    struct Bnode  *lchild,*rchild;
}Bnode,*Btree;

//补空法创建二叉树
void   Createtree(Btree &T)
{
    //二叉树补空后，按照先序遍历序列输入字符，创建字符
    char ch;
    cin >> ch;
    if(ch== '#')
    {
        T = NULL;  //创建空的树
    }else
    {
        T = new Bnode;
        T->data = ch;  //生成根节点
        Createtree(T->lchild);  //递归创建左子树
        Createtree(T->rchild);  //递归创建右子树
    }
}

//求二叉树的深度
int Depth(Btree  T)
{
    int m,n;
    if(T == NULL)
    {
        //如果是空树，深度为0
        return 0;
    }else{
        m = Depth(T->lchild); //递归计算左子树的深度
        n = Depth(T->rchild);  //递归计算右子树的深度
        if(m>n)
        {
            return m+1;   //返回左右子树的深度的最大值加1
        }else{
            return n+1;
        }
    }
}

//求二叉树的叶子数
int  LeafCount(Btree T)
{
    if(T == NULL)
    {
        //如果为空树，叶子数为0
        return 0;
    }else{
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            //左右子树为空，则叶子数为1
            return 1;
        }else{
            return LeafCount(T->lchild) + LeafCount(T->rchild);  //左右子树叶子之和
        }
    }
}

//求二叉树的节点数
int NodeCount(Btree T)
{
    if(T == NULL)
    {
        //如果为空树，节点数为0
        return 0;
    }else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) +1; //左右子树节点之和加1
    }

}




int main()
{
    int a,b,c;
    Btree t1;
    Createtree(t1);
    a = Depth(t1);
    b = LeafCount(t1);
    c = NodeCount(t1);
    cout <<"二叉树的深度："<<a<<endl;
    cout <<"二叉树的叶子数："<<b<<endl;
    cout <<"二叉树的节点数："<<c<<endl;
    return 0;
}
