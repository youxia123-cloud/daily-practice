#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//pair������<utility>ͷ�ļ��ж��壬���������ǽ�һ��ֵ��ϳ�һ��ֵ
//set�������������������Ľṹ�洢���ݲ��Զ���������С��������

typedef pair<string,double> Record;    //��pair������ΪRecord

int main()
{
    pair<int ,double>p1;
    p1.first = 10;
    p1.second = 12.5;
    cout << p1.first<< "   " <<p1.second<<endl;
    Record p2 = make_pair("hello",100);
    cout<<p2.first <<"  " <<p2.second<<endl;
    set<int> s;
    for(int i= 10;i>0;i--)
    {
        //�����Ǵ�С��������
        s.insert(i);
    }
    set<int>s2(s);   //����s����s2
    s.erase(s.begin());
    s.erase(6);
    s.insert(5);  //���ﲻ���ظ�����
    set<int>::iterator   ii;     //iiΪ���������
    for(ii=s.begin();ii!=s.end();ii++)
    {
        cout<<*ii <<endl;
    }
    cout <<"\nԪ�ظ���Ϊ��"<<s.size();   //ͳ��set��Ԫ�ظ���
    ii = s.find(10);  //����Ԫ��ֵ��������ָ���Ԫ�صĵ�����
    if(ii!=s.end())
    {
        cout<< "\n����="<<*ii;
    }
    if(s.count(5))   //count����s��ֵΪ5��Ԫ�ظ���
    {
        cout <<"\n����Ԫ��5";
    }
    s.clear();   //�������Ԫ��
    cout <<"\nԪ���Ƿ�Ϊ�գ�"<<s.empty();
    return 0;
}
