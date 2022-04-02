#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//模式匹配算法KMP
void get_next(string T,int next[],int Tl)
{
    //求模式串T的next函数值
    int j = 1,k = 0;
    next[1] = 0;
    while(j<Tl)
    {
        if(k==0 || T[j] == T[k] )
            next[++j] = ++k;
        else
            k = next[k];
    }
}

int Index_KMP(string S,string T,int pos,int next[],int Sl,int Tl)
{
    //利用模式串的next函数求在主串中第pos个字符之后的位置
    //其中，T非空，1<=pos<=S[0] ,S[0]为模式串的长度
    int i = pos,j = 0;
    while(i<=sl && j<=Tl)
    {
        if(j==0 || S[i] == T[j])
        {
            //继续比较后面的字符
            i++;
            j++;
        }else{
            j = next[j];    //模式串向右移动
        }
        if(j>Tl)
        {
            return i-Tl;
        }else{
            return 0;
        }
    }
}



int main()
{

    return 0;
}
