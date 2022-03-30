#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//排列组合关系算法
void Print(int a[])
{
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout <<endl;
}
int main()
{
    int a[] = {3,5,6,7,9};     //随机赋值，如果是全排列，必须是从小到大
    while(next_permutation(a,a+5))
        //产生下一排列，速度较慢，时间复杂度是O(n!)
        Print(a);
    int b[] = {5,4,3,2,1};   //随机赋值
    while(prev_permutation(b,b+5))
        Print(b);
    return 0;
}
