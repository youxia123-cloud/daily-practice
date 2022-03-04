#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef int DataType;   //定义DataType为int类型
typedef struct qnode  //链表队列存储类型
{
    DataType data;   //定义节点的数据域
    struct qnode  *next; //定义节点的指针域
} LinkListQ;
typedef struct
{
    LinkListQ *front,*rear;  //定义队列的对头指针和队尾指针
} LinkQueue;   //链队列的头指针类型


//初始化链队列的函数
LinkQueue *InitQueue()
{
    LinkQueue *Q;
    LinkListQ *p;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));  //建立链队列头指针所指节点
    p = (LinkListQ *)malloc(sizeof(LinkListQ));  //建立链队列的头节点
    Q->front = p;  //Q指针所指向的front指针指向p
    Q->rear = p;   //Q指针所指向的rear指针指向p
    return Q;
}


//判断队列为空函数
int EmptyQueue(LinkQueue *Q)
{
    if(Q->front ==Q->rear)
    {
        //链队列为空
        return 1;
    }else
    {
        return 0;
    }
}

//入队函数
InQueue(LinkQueue *Q,DataType x)
{
    LinkListQ  *p;
    p = (LinkListQ *)malloc(sizeof(LinkListQ)); //生成新的结点
    p->data = x; //将x存入新的结点的数据域
    p->next = NULL;
    Q->rear->next = p;   //将新的节点插入链队列之后
    Q->rear = p;  //队列指针指向队尾元素
}


//出队函数
int DeQueue(LinkQueue *Q,DataType *x)
{
    LinkListQ *p;
    if(EmptyQueue(Q))
    {
        //调用判断空队列的函数EmptyQueue(Q)，判断队列是否为空
        printf("队空，不能出队元素！");
        return 0;
    }else
    {
        //队列不为空
        p = Q->front->next;  //p指向队头元素
        *x = p->data;  //队头元素取出赋值给x
        Q->front->next = p->next;  // 队头指针的指针域存放新队头元素的地址
        if(p->next==NULL)
        {
            //队列中只含有一个元素出队
            Q->rear = Q->front;  //出队后队尾指针指向队头指针，此时队空
        }
        free(p);  //释放原队头节点空间
        return 1;
    }
}


//获取队头元素函数
int GetFront(LinkQueue *Q,DataType *x)
{
    //调用判断空队列的函数EmptyQueue(Q)，判断队列是否为空
    if(EmptyQueue(Q))
    {
        printf("队列空，无队头元素");
        return 0;
    }else
    {
        //队列不为空
        *x = Q->front->next->data; // 队头元素赋值给变量x
        return 1;
    }
}

//显示队列中元素的函数
void ShowQueue(LinkQueue *Q)
{
    LinkListQ  *p = Q->front->next;
    if(p==NULL)
    {
        printf("队列为空，没有元素！");
    }else
    {
       printf("从队列元素起栈中个元素为：");
       while(p!=NULL)
       {
            printf("%5d",p->data);
            p = p->next;
       }
    }
}


//显示菜单子函数
void MenuQueue()
{
    printf("\n     队列子系统");
    printf("\n=============================");
    printf("\n|    1----初始化队列        |");
    printf("\n|    2----入队操作          |");
    printf("\n|    3----出队操作          |");
    printf("\n|    4----求队头元素        |");
    printf("\n|    5----显示队列中所有元素|");
    printf("\n|    0----返回              |");
    printf("\n=============================");
    printf("\n请输入菜单号（0-5）：");
}


int main()
{
    int i,n,flag;
    LinkQueue *Q;
    DataType x;
    char ch1,ch2,a;
    ch1 = 'y';
    while(ch1=='y' || ch1=='Y')
    {
        MenuQueue();
        scanf("%c",&ch2);
        getchar();
        switch(ch2)
        {
        case '1':
            Q = InitQueue();
            printf("队列的初始化完成！");
            break;
        case '2':
            printf("请输入要入队的元素个数：");
            scanf("%d",&n);
            printf("请输入%d个整数进行入队：",n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&x);
                InitQueue(Q,x);
            }
            printf("入队操作完成！");
            break;
        case '3':
            printf("请输入要出队的元素个数：");
            scanf("%d",&n);
            printf("出队的元素书序依次为：");
            for(i=0;i<n;i++)
            {
                flag = DeQueue(Q,&x);
                printf("%5d",x);
            }
            if(flag==1)
            {
                printf("\n出队操作成功！");
            }else
            {
                printf("\n出队操作失败！");
            }
            break;
        case '4':
            if(flag=GetFront(Q,&x))
            {
                printf("当前的队头元素值为：%d",x);
            }
            break;
        case '5':
            ShowQueue(Q);
            break;
        case '0':
            ch1 = 'n';
            break;
        default:
            printf("输入有误，请选择0~4进行选择！");
        }
        if(ch2 != '0')
        {
            printf("\n按回车键继续，按任意键返回主菜单！\n");
            a = getchar();
            if(a!='\xA')
            {
                getchar();
                ch1 = 'n';
            }
        }
    }
    return 0;
}
