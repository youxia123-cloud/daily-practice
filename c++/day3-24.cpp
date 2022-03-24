#include <iostream>
#include<queue>
#include<string>

using namespace std;
//����������
typedef struct Bnode
{
    char data;
    struct Bnode *lchild,*rchild;
    int ltarg,rtarg;  //������
}BTnode, *BTtree;
//����������
BTtree  pre = NULL;
void InThread(BTtree  &p)
{
    //pre��ȫ�ֱ�����ָ��ոշ��ʹ��Ľڵ㣬pָ��ǰ�ڵ㣬preΪp��ǰ��
    if(p)
    {
      InThread(p->lchild);//����������p��������
      if(!p->lchild)
      {
          //p��������Ϊ��
          p->ltarg= 1;
          p->lchild = pre;
      }else{
        pre->rtarg = 0;
      }
      pre = p;
      InThread(p->rchild);  //��������������������
}
}



void CreateInThread(BTtree &T )
{
    //������������������
    pre = NULL; //��ʼ��Ϊ��
    if(T)
    {
        InThread(T);  //����������
        pre->rchild = NULL; //������������һ���ڵ㣬����Ϊ��
        pre->rtarg = 1;
    }
}


//������������������
void InorderThread(BTtree T)
{
    BTtree p;
    p = T;
    while(p)
    {
        while(p->ltarg==0)
        {
            p = p->lchild;  //������ڵ�
        }
        cout << p->data<<  "  "; //����ڵ���Ϣ
        while(p->rtarg == 1 && p->rchild)
        {
            //�Һ���Ϊ��������ָ����
            p = p->rchild;  //���ʺ�̽ڵ�
            cout << p->data <<"  ";  //����ڵ���Ϣ
        }
        p = p->rchild;   //ת��p��������
    }
}
//typedef struct Bnode
//{
//    char data;
//    struct Bnode  *lchild,*rchild;
//}Bnode,*Btree;

////���շ�����������
//void   Createtree(Btree &T)
//{
//    //���������պ󣬰�������������������ַ��������ַ�
//    char ch;
//    cin >> ch;
//    if(ch== '#')
//    {
//        T = NULL;  //�����յ���
//    }else
//    {
//        T = new Bnode;
//        T->data = ch;  //���ɸ��ڵ�
//        Createtree(T->lchild);  //�ݹ鴴��������
//        Createtree(T->rchild);  //�ݹ鴴��������
//    }
//}
int main()
{

    return 0;
}
