#include <iostream>
#include<cstring>
using namespace std;
//题目描述
/*
现在有n盏灯，编号为1～n，开始时所有的灯都是关的，编号为1的人走过来，把编号是1的倍数的灯开关按下（开的关上，关的打开），
编号为2的人把编号是2的倍数的灯开关按下，编号为3的人又把编号是3的倍数的灯开关按下……直到第k个人为止。给定n和k（0<n,k≤1000），
输出哪几盏灯是开着的。
*/
bool a[1005];
int main()
{
    int n,k;
    bool first = 1;
    memset(a,0,sizeof(a));  //初始化a数组全部为0
    cin >>  n>>k;
    for(int i = 1;i < k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%i==0)
            {
                a [j] =  !a[j] ;
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(a[j])
        {
            if(first)
            {
                first  = 0;
            }else{
                cout<<"  ";
            }
            cout << j ;
        }
    }
    return 0;
}
