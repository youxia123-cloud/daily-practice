#include <iostream>
#include<bits/stdc++.h>
#define Maxsize  100
using namespace std;
//ģʽƥ���㷨

int Index_BF(string S,string T,int pos,int Sl,int Tl)
{
    //��T������S�е�pos���ַ�֮���һ�γ��ֵ�λ��
    //���У�T�ǿգ�1<=pos<=s[0],  s[0]��ŵ�S���ĳ���
    int i = pos, j = 0,sum = 0;
    while(i<Sl-1 && j<=Tl-1)
    {
        sum++;
        if(S[i]  == T[j])
        {
            //�����ȣ�������ȽϺ�����ַ�
            i++;
            j++;
        }else{
            i = i-j+1;   //i���˵���һ�ֿ�ʼ�Ƚ���һ���ַ�
            j = 0;   //j���˵���һ���ַ�
        }
    }
    cout<<"һ���Ƚ���"<<sum<<"��"<<endl;
    if(j>Tl-1)
    {
        cout<<"ƥ��ɹ�"<<endl;
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
