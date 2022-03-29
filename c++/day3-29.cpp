#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//pair容器在<utility>头文件中定义，它的作用是将一对值组合成一个值
//set集合容器，类似于树的结构存储数据并自动将数据有小到大排列

typedef pair<string,double> Record;    //简化pair的声明为Record

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
        //这里是从小到大排序
        s.insert(i);
    }
    set<int>s2(s);   //复制s生成s2
    s.erase(s.begin());
    s.erase(6);
    s.insert(5);  //这里不会重复插入
    set<int>::iterator   ii;     //ii为正向迭代器
    for(ii=s.begin();ii!=s.end();ii++)
    {
        cout<<*ii <<endl;
    }
    cout <<"\n元素个数为："<<s.size();   //统计set中元素个数
    ii = s.find(10);  //查找元素值，并返回指向该元素的迭代器
    if(ii!=s.end())
    {
        cout<< "\n查找="<<*ii;
    }
    if(s.count(5))   //count返回s中值为5的元素个数
    {
        cout <<"\n存在元素5";
    }
    s.clear();   //清空所有元素
    cout <<"\n元素是否为空："<<s.empty();
    return 0;
}
