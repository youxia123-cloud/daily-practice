#include <iostream>
#include<algorithm>
using namespace std;
struct Node
{
    int x,y;
}p[1001];
int Cmp(Node a,Node b)
{
    if(a.x != b.x)
        return a.x < b.x;  //������߲���ȣ��Ͱ��մ�С�����˳������

    return a.y < b.y;  //���x��ȣ�����y��С�����˳������
}
void Print(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout <<endl;
}

int main()
{
    int a[] = {-1,9,-34,100,45,2,98,32};
    int len = sizeof(a) / sizeof(int);
    sort(a,a+len);  //��С��������
    Print(a,len);
    sort(a,a+len,greater<int>());  //�Ӵ�С����
    Print(a,len);

    //�Խṹ������
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        cin >>p[i].x >>p[i].y;
    sort(p+1,p+n+1,Cmp);
    for(int i=1;  i<=n;i++)
    {
        cout <<p[i].x <<p[i].y;
    }
    return 0;
}
