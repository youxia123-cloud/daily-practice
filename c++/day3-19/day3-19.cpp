#include <iostream>
//#include<string>

using namespace std;

//��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
//#include  "person.cpp"

//�ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ��Ȼ�󽫺�׺����Ϊ.hpp�ļ�
#include "person.hpp"


//��ģ����ļ���д���⼰���
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name,T2 age);
//    void showPerson();
//
//    T1 m_name;
//    T2 m_age;
//
//};
//template<class T1, class T2>
//Person<T1,T2>::Person(T1 name,T2 age)
//{
//    this->m_name = name;
//    this->m_age = age;
//}
//template<class T1,class T2>
//void Person<T1,T2>::showPerson()
//{
//    cout <<"�����ǣ�"<<this->m_name<<"�����ǣ�"<<this->m_age<<endl;
//}

void test01()
{
    Person <string,int>p("Tom",19);
    p.showPerson();
}





int main()
{
    test01();
    return 0;
}
