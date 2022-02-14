#include <stdio.h>
#include <stdlib.h>
// ͼ���ڽӾ���洢
// ͼ����󶥵���
#define MAX 100
typedef struct
{
    int n,e; // ������������
    char vexs[MAX];   //��������
    int edges[MAX][MAX];  //�ߵ��ڽӾ���
}MGraph;


//ͼ���ڽӾ����������������ڽӾ���
void CreateMGrap(MGraph *G)
{
    int i,j,k;
    char ch1,ch2;
    printf("�����붥������");
    scanf("%d",&G->n);
    printf("�����������");
    scanf("%d",&G->e);
    printf("���������������Ϣ��ÿ�������Իس���Ϊ��������\n");
    for(i = 0;i<G->n;i++)
    {
        getchar();
        printf("�������%d�����㣺",i+1);
        scanf("%c",&(G->vexs[i]));
    }
    for(i = 0;i<G->n;i++)
    {
        for(j = 0;j<G->n;j++)
        {
            //���ڽӾ����Ԫ��ȫ������
            G->edges[i][j] = 0;
        }
    }
    for(k = 0;k<G->e;k++)
    {
        getchar();
        printf("������%d���ߣ������ʽ������1������2��:",k+1);
        scanf("%c,%c",&ch1,&ch2);
        for(i = 0;i<G->n;i++)
        {
            for(j = 0;j<G->n;j++)
            {
                if((ch1==G->vexs[i] && ch2==G->vexs[j]))
                {
                    G->edges[i][j] = 1;
                }
            }
        }
    }
}
//ͼ���ڽӾ����������
void DispMGraph(MGraph G)
{
    int i,j;
    printf("\nͼ���ڽӾ���\n");
    for(i=0;i<G.n;i++)
    {
        for(j=0;j<G.n;j++)
        {
            printf("%5d",G.edges[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    MGraph G;
    CreateMGrap(&G);
    DispMGraph(G);
    return 0;
}
