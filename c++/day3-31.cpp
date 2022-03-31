#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define  MaxVnum 100    //�����������ֵ
typedef  char VexType;  //������������ͣ�������Ҫ����
typedef  int  EdgeType;  //����Ȩֵ���������ͣ�������Ȩֵ��ͼ����Ϊ0��1
bool  visited[MaxVnum];
typedef struct
{
    VexType  Vex[MaxVnum];
    EdgeType  Edge[MaxVnum][MaxVnum];   //�ڽӾ���洢�ߵ���Ϣ
    int vexnum,edgenum;  //�������ͱ���
}AMGraph;

int LocateVex(AMGraph &G,VexType v)//����Ԫ��v��һά���� Vertex[] �е��±꣬�������±�
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

//��������ͼ���ڽӾ���
void CreateAMGraph(AMGraph  &G)
{
    int i, j;
    VexType  u,v;
    cout <<  "�����붥������"<<endl;
    cin>>G.vexnum;
    cout<< "�����������"<<endl;
    cin >>G.edgenum;
    cout <<"�����붥����Ϣ��"<<endl;
    for (int i=0;i<G.vexnum;i++)
    {
        //���붥����Ϣ�����붥����Ϣ����
        cin>>G.Vex[i];
    }
    for(int i=0;i<G.vexnum;i++)
        {
            //��ʼ���ڽӾ�������ֵΪ0�������������ʼ��Ϊ�����
            for(int j = 0;j<G.vexnum;j++)
            {
                G.Edge[i][j] = 0;
            }
        }
        cout <<"������ÿ�����������������㣺"<<endl;
        while(G.edgenum--)
        {
            cin >>  u>>v;
            i =LocateVex(G,u);  //���Ҷ���u�Ĵ洢�±�
            j = LocateVex(G,v);  //���Ҷ���v�Ĵ洢�±�
            if(i != -1 && j != -1)
                G.Edge[i][j] = G.Edge[j][i] = 1;  //�ڽӾ�����1����������ͼ����ΪG.Edge[i][j] = 1
        }
}


//ͼ�ı���
//�����ڽӾ���Ĺ����������BFS
void BFS_AM(AMGraph G,int v)
{
    int u,w;
    queue<int>Q;     //����һ����ͨ���У�������int����
    cout <<G.Vex[v]<<"\t";
    visited[v] = true;
    Q.push(v);    //Դ��v���
    while(! Q.empty())
    {
        //������в�Ϊ��
        u = Q.front();   //ȡ����ͷԪ�ظ�ֵ��u
        Q.pop();   //��ͷԪ�س���
        for(w = 0;w<G.vexnum;w++)
        {
            //���μ��u�������ڽӵ�
            if(G.Edge[u][w] && ! visited[w])
            {
                //u��w�ڽӶ���wû�б�����
                cout <<G.Vex[w] <<" \t";
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}





using namespace std;
//ͼ���ڽӾ���洢
int main()
{
    AMGraph  t;
    CreateAMGraph(t);
    BFS_AM(t,0);
    return 0;
}
