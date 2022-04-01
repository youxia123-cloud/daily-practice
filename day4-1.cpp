#include <iostream>
#include<bits/stdc++.h>
#define Maxsize  100
using namespace std;
//模式匹配算法

int Index_BF(string S,string T,int pos,int Sl,int Tl)
{
    //求T在主串S中第pos个字符之后第一次出现的位置
    //其中，T非空，1<=pos<=s[0],  s[0]存放的S串的长度
    int i = pos, j = 0,sum = 0;
    while(i<Sl-1 && j<=Tl-1)
    {
        sum++;
        if(S[i]  == T[j])
        {
            //如果相等，则继续比较后面的字符
            i++;
            j++;
        }else{
            i = i-j+1;   //i回退到上一轮开始比较下一个字符
            j = 0;   //j回退到第一个字符
        }
    }
    cout<<"一共比较了"<<sum<<"次"<<endl;
    if(j>Tl-1)
    {
        cout<<"匹配成功"<<endl;
        return i-Tl;
    }else{
        return 0;
    }
}

int main()
{
    string  s1 = "abaabaabeca";
    string  s2 = "abaabe";
    int a,b;
    a = s1.size();
    b = s2.size();
    int c= Index_BF(s1,s2,0,a,b);
    cout<<c<<endl;

    return 0;
}
