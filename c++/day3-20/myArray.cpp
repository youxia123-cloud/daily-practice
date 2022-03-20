#include <iostream>
#include<string>
#include "myArray.hpp"
using namespace std;
//ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//1.���Զ��������������Լ��Զ����������͵����ݽ��д洢
//2.�������е����ݴ洢������
//3.���캯���п��Բ������������
//4.�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
//5.�ṩβ�巨��βɾ�����������е����ݽ������Ӻ�ɾ��
//6.����ͨ���±�ķ�ʽ���������е�Ԫ��
//7.���Ի�ȡ�����е�ǰԪ�ظ���������

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
        //����β�巨�������в�������
        arr1.Push_Back(i);
    }
    cout <<"arr1�Ĵ�ӡ���Ϊ��"<<endl;
    printArray(arr1);

    cout <<"arr1�������ǣ�"<<arr1.getCapacity() <<endl;
    cout <<"arr1�Ĵ�С�ǣ�"<<arr1.getSize() <<endl;

    MyArray<int>arr2(arr1);
    cout <<"arr2�Ĵ�ӡ���Ϊ��"<<endl;
     printArray(arr2);
     //βɾ��
     arr2.Pop_Back();
     cout <<"arr2βɾ����"<<endl;
     cout <<"arr2�������ǣ�"<<arr2.getCapacity()<<endl;
     cout <<"arr2�Ĵ�С�ǣ�"<<arr2.getSize()<<endl;
    //MyArray<int>arr3(100);
    //arr3 = arr1;
}

//�����Զ������������
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
        cout <<"�����ǣ�"<<arr[i].m_name<< "�����ǣ�"<<arr[i].m_age<<endl;
    }
}

void test02()
{
    MyArray<Person>arr(10);
    Person p1("�����",999);
    Person p2("��˽�",979);
    Person p3("����",25);
    Person p4("������",23);
    Person p5("����",30);
    //�����ݲ��뵽������
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    //��ӡ����
    printPersonArray(arr);
    //��ӡ���������
    cout <<"arr�������ǣ�"<<  arr.getCapacity()<<endl;
    //��ӡ����Ĵ�С
    cout <<"arr�Ĵ�С�ǣ�"<<arr.getSize()<<endl;

}





int main()
{
    test01();
    test02();
    return 0;
}
