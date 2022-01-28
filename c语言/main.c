//树的子系统
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define Max 100
int count = 0;  //定义计算节点个数的变量
typedef struct tnode
{
    char data; //二叉树节点的值
    struct tnode *lchild,*rchild; //左右孩子节点指针；
}BT;
BT *CreateBTree()
{//以先序序列输入节点的值，创建二叉链表
    BT  *t;
    char ch;
    scanf("%c",&ch);
    getchar();
    if(ch=='0')
    {
        t   = NULL;
    }else
    {
        t = (BT *)malloc(sizeof(BT));
        t->data = ch;
        printf("请输入%c节点的左孩子节点：",t->data);
        t->lchild = CreateBTree();
        printf("请输入 %c节点的右孩子节点：",t->data);
        t->rchild = CreateBTree();
    }
    return t;
}
void showBTree(BT *T)
{
    //用广义表表示法显示二叉树子函数
    if( T!= NULL)
        {
            printf("%c",T->data); //输入该节点的数据域
            if(T->lchild !=NULL) //左子树非空
            {
                printf(" ("); //输出左括号
                showBTree(T->lchild); //递归调用该函数输出左子树及其节点
                if(T->rchild != NULL)
                {
                    printf(",");
                    showBTree(T->rchild); //递归调用该函数输出其右子树及其节点
                }
                printf(") ");
            }
        }
}

void PreOrder(BT *T)
{
    //先序遍历二叉树
    if(T==NULL)
    {
        return;
    }else
    {
        printf("%c",T->data);  //输出节点的数据域
        PreOrder(T->lchild);  //先序递归遍历左子树
        PreOrder(T->rchild); //先序递归遍历右子树
    }
}


void InOrder(BT *T)
{
    //中序遍历二叉树
    if(T==NULL)
    {
        return; //递归调用的结束条件
    }else
    {
        InOrder(T->lchild); //中序递归遍历左子树
        printf("%c",T->data); //输出节点的数据域
        InOrder(T->rchild); //中序递归遍历节点的右子树
    }
}

void PostOrder(BT *T)
{
    //后序遍历二叉树T
    if(T==NULL )
    {
        return; //递归调用的结束条件
    }else
    {
        PostOrder(T->lchild); //后序递归遍历左子树
        PostOrder(T->rchild); //后序递归遍历右子树
        printf("%c",T->data); //输出节点的数据域
    }
}

void LevelOrder(BT *T)
{
    //按层次遍历二叉树T
    int f,r; //定义队头，队尾指针
    BT *p,*q[Max]; //定义循环队列，存放节点指针
    p = T;
    if(p!=NULL)
    {
        //若二叉树非空，则根节点地址入队
        f = 1;
        q[f] = p;
        r = 2;
    }
    while(f!=r)
    {
        //队列不为空时：
        p = q[f];
        printf("%c",p->data); //访问队首节点的数据域
        if(p->lchild != NULL)
        {
            //将队首节点的左孩子入队
            q[r] = p->lchild;
            r = (r + 1) % Max;
        }
        if(p->rchild != NULL)
        {
            //将队首节点的右孩子入队
            q[r] = p->rchild;
            r = (r + 1)% Max;
        }
        f = (f + 1) % Max;
    }
}


void Leafnum(BT *T)
{
    //求二叉树叶子节点数
    if(T)
    {
        //若树不为空
        if(T->lchild == NULL && T->rchild==NULL)
        {
            count ++; //全局变量count为计数值，其初始值为0
        }
        Leafnum(T->lchild); //递归统计T的左子树叶子节点数
        Leafnum(T->rchild); //递归统计T的右子树叶子节点数
    }
}


void Nodenum(BT *T)
{
    //求二叉树中总节点数
    if(T)
    {
        //若树不为空
        count ++; //全局变量count为计数值，其初始值为0
        Nodenum(T->lchild); //递归统计T的左子树节点数
        Nodenum(T->rchild); //递归统计T的右子树节点数
    }
}


int TreeDepth(BT *T)
{
    //求二叉树深度
    int ldep = 0,rdep = 0; //定义两个整型变量，用以存放左、右子树的深度
    if(T==NULL)
    {
        return 0;
    }else
    {
        ldep = TreeDepth(T->lchild); //递归统计T的左子树深度
        rdep = TreeDepth(T->rchild); //递归统计T的右子树深度
        if(ldep >rdep)
        {
            return ldep+1;
        }else
        {
            return rdep+1;
        }
    }
}

void MenuTree()
{
    //显示菜单子系统
    printf("\n              二叉树子系统");
    printf("\n=================================");
    printf("\n|     1--建立一个新二叉树--------");
    printf("\n|     2--广义表表示法显示--------");
    printf("\n|     3--先序遍历----------------");
    printf("\n|     4--中序遍历----------------");
    printf("\n|     5--后序遍历----------------");
    printf("\n|     6--层次遍历----------------");
    printf("\n|     7--求叶子节点数目----------");
    printf("\n|     8--求二叉树总结点数目------");
    printf("\n|     9--求树深度----------------");
    printf("\n|     0--返回--------------------");
    printf("\n=================================");
    printf("\n请输入菜单号（0~9）：");
}

int main()
{
    BT *T = NULL;
    char  ch1,ch2,a;
    ch1 = 'y';
    while(ch1=='y' || ch1=='Y')
    {
        MenuTree();
        scanf("%c",&ch2);
        getchar();
        switch(ch2)
            {
            case '1':
                printf("请按先序序列输入二叉树的节点：\n");
                printf("说明：输入节点后按回车键（'0'表示后继节点为空）：\n");
                printf("请输入根节点：");
                T = CreateBTree();
                printf("二叉树成功建立！");
                break;
            case '2':
                printf("二叉树广义表表示法如下：");
                showBTree(T);
                break;
            case '3':
                printf("二叉树的先序遍历序列为：");
                PreOrder(T);
                break;
            case '4':
                printf("二叉树的中序遍历序列为：");
                InOrder(T);
                break;
            case '5':
                printf("二叉树的后序遍历序列为：");
                PostOrder(T);
                break;
            case '6':
                printf("二叉树的层次遍历序列为：");
                LevelOrder(T);
                break;
            case '7':
                count = 0;
                Leafnum(T);
                printf("该二叉树有%d个叶子。",count);
                break;
            case '8':
                count = 0;
                Nodenum(T);
                printf("该二叉树共有%d个节点。",count);
                break;
            case '9':
                printf("该二叉树的深度是%d。",TreeDepth(T));
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("输入有误，请输入0-9进行选择！");
            }
            if(ch2!='0')
            {
                printf("\n按回车键继续，按任意键返回主菜单！\n");
                a = getchar();
                if(a!='\xA')
                {
                    getchar();
                    ch1='n';
                }
            }
    }
    return 0;
}
