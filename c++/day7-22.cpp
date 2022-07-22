#include <iostream>
#include<iomanip>
#include<cstring>
//蛇形填数，填写n*n的矩阵
using namespace std;

int main()
{
    int n,x,y,total;
    cin>>n;
    int **a = new int *[n];
    for(int i=0;i<n;i++)
    {
        a[i] = new int[n];
        memset(a[i],0,n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(5)<<a[i][j];
        }
        cout<<endl;
    }
    x = y  = 0;
    total = a[0][0] = 1;
    while(total<n*n)
    {
        while(y+1<n && !a[x][y+1])
        {
            //向右
            a[x][++y] = ++total;
        }
        while(x+1<n && !a[x+1][y])
        {
            //向下
            a[++x][y] = ++total;
        }
        while(y-1>=0 && !a[x][y-1])
        {
            //向左
            a[x][--y] = ++total;
        }
        while(x-1>=0&& !a[x-1][y])
        {
            //向上
            a[--x][y] = ++total;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(5)<<a[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete [] a[i];
    }
    delete [] a;
    return 0;
}
