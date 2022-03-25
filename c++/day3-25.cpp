#include <iostream>
#define MAXBIT  100
#define MAXVALUE 50
#define MAXLEAF 50
using namespace std;
//哈夫曼树



//节点结构体
typedef struct
{
    double  weight; //权值
    int parent;   //双亲
    int lchild;   //左孩子
    int rchild;  //右孩子
    char value;  //该节点表示的字符
}HNodeType;

//编码结构体
typedef struct
{
    int bit[MAXBIT];  //存储编码的数组
    int start;   //编码开始下标
}HCodeType;
HNodeType   HuffNode[MAXBIT];
//输出哈夫曼编码
void HuffmanCode(HCodeType  HuffCode[MAXLEAF],int n)
{
        HCodeType   cd;  //定义一个临时变量来存放求解编码时的信息
        int i,j,c,p;
        for (i = 0;i<n;i++)
        {
            cd.start = n - 1;
            c = i;  //i为叶子节点编号
            p = HuffNode[c].parent;
            while(p != -1)
            {
                if(HuffNode[p].lchild == c)
                {
                    cd.bit[cd.start] = 0;
                }else{
                    cd.bit[cd.start] = 1;
                }
                cd.start --;    //start向前移动一位
                c = p;    //c，p变量上移，准备下一循环
                p = HuffNode[c].parent;
            }
            //把叶子节点的编码信息从临时编码cd中复制出来，放入编码结构体数组中
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
        HuffNode[i].weight = 0;  //权值
        HuffNode[i].parent = -1, //双亲
        HuffNode[i].lchild = -1; //左孩子
        HuffNode[i].rchild = -1; //右孩子
    }
    //输入n个叶子节点的字符及权值
    for(int i=0;i<n;i++)
    {
        cout <<"Please input value and weight of leaf node "<< i+1<<endl;
        cin>>HuffNode[i].value>>HuffNode[i].weight;
    }
    //循环构造哈夫曼树
    int i,j,x1,x2;  //x1和x2为两个最小权值节点的序号
    double m1,m2;    //m1和m2为两个最小权值节点的权值
    for(i = 0;i<n-1;i++)
    {
        m1 = m2 = MAXVALUE;  //初始化为最大值
        x1 = x2 = -1;  //初始化为-1
        //找出所有节点中权值最小、无双亲节点的两个节点
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
        //更新树的信息
        HuffNode[x1].parent = n + i;    //x1的父亲为新节点编号n+i
        HuffNode[x2].parent = n+ i;   //x2的父亲为新节点编号n+i
        HuffNode[n+i].weight = m1 + m2; //新节点权值为两个最小权值值和m1加m2
        HuffNode[n+i].lchild = x1;   //新节点n+i的左孩子为x1
        HuffNode[n+i].rchild = x2;  //新节点n+i的右孩子为x2
    }
    return 0;
}
