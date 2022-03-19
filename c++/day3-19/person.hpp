#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#endif // PERSON_H_INCLUDED
#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age);
    void showPerson();

    T1 m_name;
    T2 m_age;

};
template<class T1, class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this->m_name = name;
    this->m_age = age;
}
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
    cout <<"�����ǣ�"<<this->m_name<<"�����ǣ�"<<this->m_age<<endl;
}





