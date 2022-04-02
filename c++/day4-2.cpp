#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//ģʽƥ���㷨KMP
void get_next(string T,int next[],int Tl)
{
    //��ģʽ��T��next����ֵ
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
    //����ģʽ����next�������������е�pos���ַ�֮���λ��
    //���У�T�ǿգ�1<=pos<=S[0] ,S[0]Ϊģʽ���ĳ���
    int i = pos,j = 0;
    while(i<=sl && j<=Tl)
    {
        if(j==0 || S[i] == T[j])
        {
            //�����ȽϺ�����ַ�
            i++;
            j++;
        }else{
            j = next[j];    //ģʽ�������ƶ�
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
