//������ϵͳ
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define Max 100
int count = 0;  //�������ڵ�����ı���
typedef struct tnode
{
    char data; //�������ڵ��ֵ
    struct tnode *lchild,*rchild; //���Һ��ӽڵ�ָ�룻
}BT;
BT *CreateBTree()
{//��������������ڵ��ֵ��������������
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
        printf("������%c�ڵ�����ӽڵ㣺",t->data);
        t->lchild = CreateBTree();
        printf("������ %c�ڵ���Һ��ӽڵ㣺",t->data);
        t->rchild = CreateBTree();
    }
    return t;
}
void showBTree(BT *T)
{
    //�ù�����ʾ����ʾ�������Ӻ���
    if( T!= NULL)
        {
            printf("%c",T->data); //����ýڵ��������
            if(T->lchild !=NULL) //�������ǿ�
            {
                printf(" ("); //���������
                showBTree(T->lchild); //�ݹ���øú����������������ڵ�
                if(T->rchild != NULL)
                {
                    printf(",");
                    showBTree(T->rchild); //�ݹ���øú������������������ڵ�
                }
                printf(") ");
            }
        }
}

void PreOrder(BT *T)
{
    //�������������
    if(T==NULL)
    {
        return;
    }else
    {
        printf("%c",T->data);  //����ڵ��������
        PreOrder(T->lchild);  //����ݹ����������
        PreOrder(T->rchild); //����ݹ����������
    }
}


void InOrder(BT *T)
{
    //�������������
    if(T==NULL)
    {
        return; //�ݹ���õĽ�������
    }else
    {
        InOrder(T->lchild); //����ݹ����������
        printf("%c",T->data); //����ڵ��������
        InOrder(T->rchild); //����ݹ�����ڵ��������
    }
}

void PostOrder(BT *T)
{
    //�������������T
    if(T==NULL )
    {
        return; //�ݹ���õĽ�������
    }else
    {
        PostOrder(T->lchild); //����ݹ����������
        PostOrder(T->rchild); //����ݹ����������
        printf("%c",T->data); //����ڵ��������
    }
}

void LevelOrder(BT *T)
{
    //����α���������T
    int f,r; //�����ͷ����βָ��
    BT *p,*q[Max]; //����ѭ�����У���Žڵ�ָ��
    p = T;
    if(p!=NULL)
    {
        //���������ǿգ�����ڵ��ַ���
        f = 1;
        q[f] = p;
        r = 2;
    }
    while(f!=r)
    {
        //���в�Ϊ��ʱ��
        p = q[f];
        printf("%c",p->data); //���ʶ��׽ڵ��������
        if(p->lchild != NULL)
        {
            //�����׽ڵ���������
            q[r] = p->lchild;
            r = (r + 1) % Max;
        }
        if(p->rchild != NULL)
        {
            //�����׽ڵ���Һ������
            q[r] = p->rchild;
            r = (r + 1)% Max;
        }
        f = (f + 1) % Max;
    }
}


void Leafnum(BT *T)
{
    //�������Ҷ�ӽڵ���
    if(T)
    {
        //������Ϊ��
        if(T->lchild == NULL && T->rchild==NULL)
        {
            count ++; //ȫ�ֱ���countΪ����ֵ�����ʼֵΪ0
        }
        Leafnum(T->lchild); //�ݹ�ͳ��T��������Ҷ�ӽڵ���
        Leafnum(T->rchild); //�ݹ�ͳ��T��������Ҷ�ӽڵ���
    }
}


void Nodenum(BT *T)
{
    //����������ܽڵ���
    if(T)
    {
        //������Ϊ��
        count ++; //ȫ�ֱ���countΪ����ֵ�����ʼֵΪ0
        Nodenum(T->lchild); //�ݹ�ͳ��T���������ڵ���
        Nodenum(T->rchild); //�ݹ�ͳ��T���������ڵ���
    }
}


int TreeDepth(BT *T)
{
    //����������
    int ldep = 0,rdep = 0; //�����������ͱ��������Դ���������������
    if(T==NULL)
    {
        return 0;
    }else
    {
        ldep = TreeDepth(T->lchild); //�ݹ�ͳ��T�����������
        rdep = TreeDepth(T->rchild); //�ݹ�ͳ��T�����������
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
    //��ʾ�˵���ϵͳ
    printf("\n              ��������ϵͳ");
    printf("\n=================================");
    printf("\n|     1--����һ���¶�����--------");
    printf("\n|     2--������ʾ����ʾ--------");
    printf("\n|     3--�������----------------");
    printf("\n|     4--�������----------------");
    printf("\n|     5--�������----------------");
    printf("\n|     6--��α���----------------");
    printf("\n|     7--��Ҷ�ӽڵ���Ŀ----------");
    printf("\n|     8--��������ܽ����Ŀ------");
    printf("\n|     9--�������----------------");
    printf("\n|     0--����--------------------");
    printf("\n=================================");
    printf("\n������˵��ţ�0~9����");
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
                printf("�밴������������������Ľڵ㣺\n");
                printf("˵��������ڵ�󰴻س�����'0'��ʾ��̽ڵ�Ϊ�գ���\n");
                printf("��������ڵ㣺");
                T = CreateBTree();
                printf("�������ɹ�������");
                break;
            case '2':
                printf("������������ʾ�����£�");
                showBTree(T);
                break;
            case '3':
                printf("�������������������Ϊ��");
                PreOrder(T);
                break;
            case '4':
                printf("�������������������Ϊ��");
                InOrder(T);
                break;
            case '5':
                printf("�������ĺ����������Ϊ��");
                PostOrder(T);
                break;
            case '6':
                printf("�������Ĳ�α�������Ϊ��");
                LevelOrder(T);
                break;
            case '7':
                count = 0;
                Leafnum(T);
                printf("�ö�������%d��Ҷ�ӡ�",count);
                break;
            case '8':
                count = 0;
                Nodenum(T);
                printf("�ö���������%d���ڵ㡣",count);
                break;
            case '9':
                printf("�ö������������%d��",TreeDepth(T));
                break;
            case '0':
                ch1 = 'n';
                break;
            default:
                printf("��������������0-9����ѡ��");
            }
            if(ch2!='0')
            {
                printf("\n���س�����������������������˵���\n");
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
