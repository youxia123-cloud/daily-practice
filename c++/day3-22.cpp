#include <iostream>

using namespace std;

typedef struct Bnode
{
    char data;
    struct Bnode  *lchild,*rchild;
}Bnode,*Btree;

//����������
void  createtree(Btree &T)
{
    //ѯ�ʷ�����������
    char check;
    T = new Bnode;
    cout <<"������ڵ���Ϣ��"<<endl;   //������ڵ���Ŀ
    cin >> T->data;
    cout <<"�Ƿ����"<<T->data <<"�����ӣ���Y/N��"<<endl;   //ѯ���Ƿ񴴽�T��������
    cin>>check;
    if(check=='y' || check =='Y')
    {
        createtree(T->lchild);
    }
    else{
        T->lchild = NULL;
    }
    cout <<"�Ƿ����"<<T->data<<"���Һ��ӣ���Y/N��"<<endl;
    cin >> check;
    if(check=='Y' || check=='y')
    {
        createtree(T->rchild);
    }
    else{
        T->rchild = NULL;
    }
}

//�������ı���
//�������
void preorder(Btree T)
{
    if(T)
    {
        cout <<T->data<<"  "<<endl;
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

//�������
void inorder(Btree T)
{
    if(T)
    {
        inorder(T->lchild);
        cout <<T->data<<"  "<<endl;
        inorder(T->rchild);
    }
}

//�������
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
