#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;  //定义一个存放整数的vector容器
    v.reserve(30);  //调整数据空间大小
    v.push_back(20);  //尾端插入新元素
    v.push_back(26);
    v.push_back(12);
    v.push_back(52);
    v.insert(v.begin(),2);    //bgegin（）为指针，指向v的头部，在此处插入2
    v.insert(v.end(),43);   //end（）为指针，指向v最后的元素的后面，插入43
    v.insert(v.begin()+2,15);   //在第二个元素前插入1

    v.erase(v.begin()+1);  //删除第二个元素
    v.erase(v.begin(),v.begin()+2); //删除前三个元素
    v.pop_back();  //删除末尾的一个元素
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i] <<"  ";
    }
    cout <<"\n 首元素为："<<v.front() <<"\n";  //首元素引用
    cout<<" 末元素为:"<<v.back()<<"\n";   //末尾元素引用
    reverse(v.begin(),v.end());   //反转整个vector元素

    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<"  ";
    }
    v.clear();   //清空全部元素
    cout <<"\n v是否为空："<<v.empty()<<"\n";  //判断是否为空
    return 0;
}
