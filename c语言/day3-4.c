#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
typedef int DataType;   //����DataTypeΪint����
typedef struct qnode  //������д洢����
{
    DataType data;   //����ڵ��������
    struct qnode  *next; //����ڵ��ָ����
} LinkListQ;
typedef struct
{
    LinkListQ *front,*rear;  //������еĶ�ͷָ��Ͷ�βָ��
} LinkQueue;   //�����е�ͷָ������


//��ʼ�������еĺ���
LinkQueue *InitQueue()
{
    LinkQueue *Q;
    LinkListQ *p;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));  //����������ͷָ����ָ�ڵ�
    p = (LinkListQ *)malloc(sizeof(LinkListQ));  //���������е�ͷ�ڵ�
    Q->front = p;  //Qָ����ָ���frontָ��ָ��p
    Q->rear = p;   //Qָ����ָ���rearָ��ָ��p
    return Q;
}


//�ж϶���Ϊ�պ���
int EmptyQueue(LinkQueue *Q)
{
    if(Q->front ==Q->rear)
    {
        //������Ϊ��
        return 1;
    }else
    {
        return 0;
    }
}

//��Ӻ���
InQueue(LinkQueue *Q,DataType x)
{
    LinkListQ  *p;
    p = (LinkListQ *)malloc(sizeof(LinkListQ)); //�����µĽ��
    p->data = x; //��x�����µĽ���������
    p->next = NULL;
    Q->rear->next = p;   //���µĽڵ����������֮��
    Q->rear = p;  //����ָ��ָ���βԪ��
}


//���Ӻ���
int DeQueue(LinkQueue *Q,DataType *x)
{
    LinkListQ *p;
    if(EmptyQueue(Q))
    {
        //�����жϿն��еĺ���EmptyQueue(Q)���ж϶����Ƿ�Ϊ��
        printf("�ӿգ����ܳ���Ԫ�أ�");
        return 0;
    }else
    {
        //���в�Ϊ��
        p = Q->front->next;  //pָ���ͷԪ��
        *x = p->data;  //��ͷԪ��ȡ����ֵ��x
        Q->front->next = p->next;  // ��ͷָ���ָ�������¶�ͷԪ�صĵ�ַ
        if(p->next==NULL)
        {
            //������ֻ����һ��Ԫ�س���
            Q->rear = Q->front;  //���Ӻ��βָ��ָ���ͷָ�룬��ʱ�ӿ�
        }
        free(p);  //�ͷ�ԭ��ͷ�ڵ�ռ�
        return 1;
    }
}


//��ȡ��ͷԪ�غ���
int GetFront(LinkQueue *Q,DataType *x)
{
    //�����жϿն��еĺ���EmptyQueue(Q)���ж϶����Ƿ�Ϊ��
    if(EmptyQueue(Q))
    {
        printf("���пգ��޶�ͷԪ��");
        return 0;
    }else
    {
        //���в�Ϊ��
        *x = Q->front->next->data; // ��ͷԪ�ظ�ֵ������x
        return 1;
    }
}

//��ʾ������Ԫ�صĺ���
void ShowQueue(LinkQueue *Q)
{
    LinkListQ  *p = Q->front->next;
    if(p==NULL)
    {
        printf("����Ϊ�գ�û��Ԫ�أ�");
    }else
    {
       printf("�Ӷ���Ԫ����ջ�и�Ԫ��Ϊ��");
       while(p!=NULL)
       {
            printf("%5d",p->data);
            p = p->next;
       }
    }
}


//��ʾ�˵��Ӻ���
void MenuQueue()
{
    printf("\n     ������ϵͳ");
    printf("\n=============================");
    printf("\n|    1----��ʼ������        |");
    printf("\n|    2----��Ӳ���          |");
    printf("\n|    3----���Ӳ���          |");
    printf("\n|    4----���ͷԪ��        |");
    printf("\n|    5----��ʾ����������Ԫ��|");
    printf("\n|    0----����              |");
    printf("\n=============================");
    printf("\n������˵��ţ�0-5����");
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
            printf("���еĳ�ʼ����ɣ�");
            break;
        case '2':
            printf("������Ҫ��ӵ�Ԫ�ظ�����");
            scanf("%d",&n);
            printf("������%d������������ӣ�",n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&x);
                InitQueue(Q,x);
            }
            printf("��Ӳ�����ɣ�");
            break;
        case '3':
            printf("������Ҫ���ӵ�Ԫ�ظ�����");
            scanf("%d",&n);
            printf("���ӵ�Ԫ����������Ϊ��");
            for(i=0;i<n;i++)
            {
                flag = DeQueue(Q,&x);
                printf("%5d",x);
            }
            if(flag==1)
            {
                printf("\n���Ӳ����ɹ���");
            }else
            {
                printf("\n���Ӳ���ʧ�ܣ�");
            }
            break;
        case '4':
            if(flag=GetFront(Q,&x))
            {
                printf("��ǰ�Ķ�ͷԪ��ֵΪ��%d",x);
            }
            break;
        case '5':
            ShowQueue(Q);
            break;
        case '0':
            ch1 = 'n';
            break;
        default:
            printf("����������ѡ��0~4����ѡ��");
        }
        if(ch2 != '0')
        {
            printf("\n���س�����������������������˵���\n");
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
