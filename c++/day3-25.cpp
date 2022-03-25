#include <iostream>
#define MAXBIT  100
#define MAXVALUE 50
#define MAXLEAF 50
using namespace std;
//��������



//�ڵ�ṹ��
typedef struct
{
    double  weight; //Ȩֵ
    int parent;   //˫��
    int lchild;   //����
    int rchild;  //�Һ���
    char value;  //�ýڵ��ʾ���ַ�
}HNodeType;

//����ṹ��
typedef struct
{
    int bit[MAXBIT];  //�洢���������
    int start;   //���뿪ʼ�±�
}HCodeType;
HNodeType   HuffNode[MAXBIT];
//�������������
void HuffmanCode(HCodeType  HuffCode[MAXLEAF],int n)
{
        HCodeType   cd;  //����һ����ʱ���������������ʱ����Ϣ
        int i,j,c,p;
        for (i = 0;i<n;i++)
        {
            cd.start = n - 1;
            c = i;  //iΪҶ�ӽڵ���
            p = HuffNode[c].parent;
            while(p != -1)
            {
                if(HuffNode[p].lchild == c)
                {
                    cd.bit[cd.start] = 0;
                }else{
                    cd.bit[cd.start] = 1;
                }
                cd.start --;    //start��ǰ�ƶ�һλ
                c = p;    //c��p�������ƣ�׼����һѭ��
                p = HuffNode[c].parent;
            }
            //��Ҷ�ӽڵ�ı�����Ϣ����ʱ����cd�и��Ƴ������������ṹ��������
            for(j = cd.start+1;j<n;j++)
            {
                HuffCode[i].bit[j] = cd.bit[j];
            }
            HuffCode[i].start = cd.start;
        }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<2*n-1;i++)
    {
        HuffNode[i].weight = 0;  //Ȩֵ
        HuffNode[i].parent = -1, //˫��
        HuffNode[i].lchild = -1; //����
        HuffNode[i].rchild = -1; //�Һ���
    }
    //����n��Ҷ�ӽڵ���ַ���Ȩֵ
    for(int i=0;i<n;i++)
    {
        cout <<"Please input value and weight of leaf node "<< i+1<<endl;
        cin>>HuffNode[i].value>>HuffNode[i].weight;
    }
    //ѭ�������������
    int i,j,x1,x2;  //x1��x2Ϊ������СȨֵ�ڵ�����
    double m1,m2;    //m1��m2Ϊ������СȨֵ�ڵ��Ȩֵ
    for(i = 0;i<n-1;i++)
    {
        m1 = m2 = MAXVALUE;  //��ʼ��Ϊ���ֵ
        x1 = x2 = -1;  //��ʼ��Ϊ-1
        //�ҳ����нڵ���Ȩֵ��С����˫�׽ڵ�������ڵ�
        for(j = 0;j<n+1;j++)
        {
            if (HuffNode[j].weight <m1 && HuffNode[j].parent == -1)
            {
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
            }
            else if(HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
            {
                m2 = HuffNode[j].weight;
                 x2 = j;
            }
        }
        //����������Ϣ
        HuffNode[x1].parent = n + i;    //x1�ĸ���Ϊ�½ڵ���n+i
        HuffNode[x2].parent = n+ i;   //x2�ĸ���Ϊ�½ڵ���n+i
        HuffNode[n+i].weight = m1 + m2; //�½ڵ�ȨֵΪ������СȨֵֵ��m1��m2
        HuffNode[n+i].lchild = x1;   //�½ڵ�n+i������Ϊx1
        HuffNode[n+i].rchild = x2;  //�½ڵ�n+i���Һ���Ϊx2
    }
    return 0;
}
