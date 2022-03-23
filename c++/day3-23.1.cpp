#include <iostream>
#include<queue>
//�������Ĳ�α���

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

//��α���
bool Leveltraverse(Btree T)
{
    Btree  p;
    if(!T)
    {
        return false;
    }
    queue<Btree>Q;  //����һ����ͨ�Ķ��У��Ƚ��ȳ�����������ָ�������
    Q.push(T);  //��ָ�����
    while(! Q.empty())
    {
        //������в�Ϊ��
        p = Q.front();  //ȡ����ͷԪ����Ϊ��ǰ�ڵ�
        Q.pop();  //��ͷԪ�س���
        cout <<p->data <<"    ";
        if(p->lchild)
        {
            Q.push(p->lchild);  //����ָ�����
        }
        if(p->rchild)
        {
            Q.push(p->rchild); //�Һ���ָ�����
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
