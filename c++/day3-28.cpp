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
        return a.x < b.x;  //如果两者不相等，就按照从小到大的顺序排序

    return a.y < b.y;  //如果x相等，则按照y从小到大的顺序排列
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
    sort(a,a+len);  //从小到大排序
    Print(a,len);
    sort(a,a+len,greater<int>());  //从大到小排序
    Print(a,len);

    //对结构体排序
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
