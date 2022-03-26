#include <iostream>
using namespace std;
#define  MaxVnum 100    //顶点数的最大值
typedef  char VexType;  //顶点的数据类型，根据需要定义
typedef  int  EdgeType;  //边上权值的数据类型，若不带权值的图，则为0或1

typedef struct
{
    VexType  Vex[MaxVnum];
    EdgeType  Edge[MaxVnum][MaxVnum];   //邻接矩阵存储边的信息
    int vexnum,edgenum;  //顶点数和边数
}AMGraph;

int LocateVex(AMGraph &G,VexType v)//查找元素v在一维数组 Vertex[] 中的下标，并返回下标
{
	int i;

	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.Vex[i])
		{
			return i;
		}
	 }

	 printf("No Such Vertex!\n");
	 return -1;
}








//创建无向图的邻接矩阵
void CreateAMGraph(AMGraph  &G)
{
    int i, j;
    VexType  u,v;
    cout <<  "请输入顶点数："<<endl;
    cin>>G.vexnum;
    cout<< "请输入边数："<<endl;
    cin >>G.edgenum;
    cout <<"请输入顶点信息："<<endl;
    for (int i=0;i<G.vexnum;i++)
    {
        //输入顶点信息，存入顶点信息数组
        cin>>G.Vex[i];
    }
    for(int i=0;i<G.vexnum;i++)
        {
            //初始化邻接矩阵所有值为0，若是网，则初始化为无穷大
            for(int j = 0;j<G.vexnum;j++)
            {
                G.Edge[i][j] = 0;
            }
        }
        cout <<"请输入每条边依附的两个顶点："<<endl;
        while(G.edgenum--)
        {
            cin >>  u>>v;
            i =LocateVex(G,u);  //查找顶点u的存储下标
            j = LocateVex(G,v);  //查找顶点v的存储下标
            if(i != -1 && j != -1)
                G.Edge[i][j] = G.Edge[j][i] = 1;  //邻接矩阵储置1，若是有向图，则为G.Edge[i][j] = 1
        }
}


using namespace std;
//图的邻接矩阵存储
int main()
{

    return 0;
}
