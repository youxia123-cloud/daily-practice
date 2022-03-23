#include <iostream>
#include<queue>
//二叉树的层次遍历

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

//层次遍历
bool Leveltraverse(Btree T)
{
    Btree  p;
    if(!T)
    {
        return false;
    }
    queue<Btree>Q;  //创建一个普通的队列（先进先出），里面存放指针的类型
    Q.push(T);  //根指针入队
    while(! Q.empty())
    {
        //如果队列不为空
        p = Q.front();  //取出队头元素作为当前节点
        Q.pop();  //队头元素出队
        cout <<p->data <<"    ";
        if(p->lchild)
        {
            Q.push(p->lchild);  //左孩子指针入队
        }
        if(p->rchild)
        {
            Q.push(p->rchild); //右孩子指针入队
        }
    }
    return true;
}


int main()
{
    Btree t1;
    Createtree(t1);
    Leveltraverse(t1);
    return 0;
}
