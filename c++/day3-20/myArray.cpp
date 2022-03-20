#include <iostream>
#include<string>
#include "myArray.hpp"
using namespace std;
//实现一个通用的数组类，要求如下：
//1.可以对内置数据类型以及自定义数据类型的数据进行存储
//2.将数组中的数据存储到堆区
//3.构造函数中可以掺入数组的容量
//4.提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//5.提供尾插法和尾删除法对数组中的数据进行增加和删除
//6.可以通过下标的方式访问数组中的元素
//7.可以获取数组中当前元素个数和容量

void printArray( MyArray <int>& arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout <<arr[i]<<endl;
    }
}


void test01()
{
    MyArray <int>arr1(5);
    for (int i=0; i<5;i++)
    {
        //利用尾插法向数组中插入数据
        arr1.Push_Back(i);
    }
    cout <<"arr1的打印输出为："<<endl;
    printArray(arr1);

    cout <<"arr1的容量是："<<arr1.getCapacity() <<endl;
    cout <<"arr1的大小是："<<arr1.getSize() <<endl;

    MyArray<int>arr2(arr1);
    cout <<"arr2的打印输出为："<<endl;
     printArray(arr2);
     //尾删除
     arr2.Pop_Back();
     cout <<"arr2尾删除后："<<endl;
     cout <<"arr2的容量是："<<arr2.getCapacity()<<endl;
     cout <<"arr2的大小是："<<arr2.getSize()<<endl;
    //MyArray<int>arr3(100);
    //arr3 = arr1;
}

//测试自定义的数据类型
class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string  m_name;
    int m_age;
};

void printPersonArray(MyArray<Person>  &arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout <<"姓名是："<<arr[i].m_name<< "年龄是："<<arr[i].m_age<<endl;
    }
}

void test02()
{
    MyArray<Person>arr(10);
    Person p1("孙悟空",999);
    Person p2("猪八戒",979);
    Person p3("赵云",25);
    Person p4("安琪拉",23);
    Person p5("韩信",30);
    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    //打印数组
    printPersonArray(arr);
    //打印数组的容量
    cout <<"arr的容量是："<<  arr.getCapacity()<<endl;
    //打印数组的大小
    cout <<"arr的大小是："<<arr.getSize()<<endl;

}





int main()
{
    test01();
    test02();
    return 0;
}
