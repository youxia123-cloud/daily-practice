#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//������Ϲ�ϵ�㷨
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
    int a[] = {3,5,6,7,9};     //�����ֵ�������ȫ���У������Ǵ�С����
    while(next_permutation(a,a+5))
        //������һ���У��ٶȽ�����ʱ�临�Ӷ���O(n!)
        Print(a);
    int b[] = {5,4,3,2,1};   //�����ֵ
    while(prev_permutation(b,b+5))
        Print(b);
    return 0;
}
