#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;  //����һ�����������vector����
    v.reserve(30);  //�������ݿռ��С
    v.push_back(20);  //β�˲�����Ԫ��
    v.push_back(26);
    v.push_back(12);
    v.push_back(52);
    v.insert(v.begin(),2);    //bgegin����Ϊָ�룬ָ��v��ͷ�����ڴ˴�����2
    v.insert(v.end(),43);   //end����Ϊָ�룬ָ��v����Ԫ�صĺ��棬����43
    v.insert(v.begin()+2,15);   //�ڵڶ���Ԫ��ǰ����1

    v.erase(v.begin()+1);  //ɾ���ڶ���Ԫ��
    v.erase(v.begin(),v.begin()+2); //ɾ��ǰ����Ԫ��
    v.pop_back();  //ɾ��ĩβ��һ��Ԫ��
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i] <<"  ";
    }
    cout <<"\n ��Ԫ��Ϊ��"<<v.front() <<"\n";  //��Ԫ������
    cout<<" ĩԪ��Ϊ:"<<v.back()<<"\n";   //ĩβԪ������
    reverse(v.begin(),v.end());   //��ת����vectorԪ��

    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<"  ";
    }
    v.clear();   //���ȫ��Ԫ��
    cout <<"\n v�Ƿ�Ϊ�գ�"<<v.empty()<<"\n";  //�ж��Ƿ�Ϊ��
    return 0;
}
