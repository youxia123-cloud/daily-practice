#include <iostream>
#include<queue>
#include<string>

using namespace std;
//线索二叉树
typedef struct Bnode
{
    char data;
    struct Bnode *lchild,*rchild;
    int ltarg,rtarg;  //左右域
}BTnode, *BTtree;
//中序线索化
BTtree  pre = NULL;
void InThread(BTtree  &p)
{
    //pre是全局变量，指向刚刚访问过的节点，p指向当前节点，pre为p的前驱
    if(p)
    {
      InThread(p->lchild);//中序线索化p的左子树
      if(!p->lchild)
      {
          //p的左子树为空
          p->ltarg= 1;
          p->lchild = pre;
      }else{
        pre->rtarg = 0;
      }
      pre = p;
      InThread(p->rchild);  //创建中序线索化二叉树
}
}



void CreateInThread(BTtree &T )
{
    //创建中序线索二叉树
    pre = NULL; //初始化为空
    if(T)
    {
        InThread(T);  //中序线索化
        pre->rchild = NULL; //处理遍历的最后一个节点，其后继为空
        pre->rtarg = 1;
    }
}


//遍历中序线索二叉树
void InorderThread(BTtree T)
{
    BTtree p;
    p = T;
    while(p)
    {
        while(p->ltarg==0)
        {
            p = p->lchild;  //找最左节点
        }
        cout << p->data<<  "  "; //输出节点信息
        while(p->rtarg == 1 && p->rchild)
        {
            //右孩子为线索化，指向后继
            p = p->rchild;  //访问后继节点
            cout << p->data <<"  ";  //输出节点信息
        }
        p = p->rchild;   //转向p的右子树
    }
}
//typedef struct Bnode
//{
//    char data;
//    struct Bnode  *lchild,*rchild;
//}Bnode,*Btree;

////补空法创建二叉树
//void   Createtree(Btree &T)
//{
//    //二叉树补空后，按照先序遍历序列输入字符，创建字符
//    char ch;
//    cin >> ch;
//    if(ch== '#')
//    {
//        T = NULL;  //创建空的树
//    }else
//    {
//        T = new Bnode;
//        T->data = ch;  //生成根节点
//        Createtree(T->lchild);  //递归创建左子树
//        Createtree(T->rchild);  //递归创建右子树
//    }
//}
int main()
{

    return 0;
}
