#include <iostream>

using namespace std;
typedef struct Bnode
{
    char data;
    struct Bnode  *lchild,*rchild;
}Bnode,*Btree;

//���շ�����������
void   Createtree(Btree &T)
{
    //���������պ󣬰�������������������ַ��������ַ�
    char ch;
    cin >> ch;
    if(ch== '#')
    {
        T = NULL;  //�����յ���
    }else
    {
        T = new Bnode;
        T->data = ch;  //���ɸ��ڵ�
        Createtree(T->lchild);  //�ݹ鴴��������
        Createtree(T->rchild);  //�ݹ鴴��������
    }
}

//������������
int Depth(Btree  T)
{
    int m,n;
    if(T == NULL)
    {
        //����ǿ��������Ϊ0
        return 0;
    }else{
        m = Depth(T->lchild); //�ݹ���������������
        n = Depth(T->rchild);  //�ݹ���������������
        if(m>n)
        {
            return m+1;   //����������������ȵ����ֵ��1
        }else{
            return n+1;
        }
    }
}

//���������Ҷ����
int  LeafCount(Btree T)
{
    if(T == NULL)
    {
        //���Ϊ������Ҷ����Ϊ0
        return 0;
    }else{
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            //��������Ϊ�գ���Ҷ����Ϊ1
            return 1;
        }else{
            return LeafCount(T->lchild) + LeafCount(T->rchild);  //��������Ҷ��֮��
        }
    }
}

//��������Ľڵ���
int NodeCount(Btree T)
{
    if(T == NULL)
    {
        //���Ϊ�������ڵ���Ϊ0
        return 0;
    }else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) +1; //���������ڵ�֮�ͼ�1
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
    cout <<"����������ȣ�"<<a<<endl;
    cout <<"��������Ҷ������"<<b<<endl;
    cout <<"�������Ľڵ�����"<<c<<endl;
    return 0;
}
