#include <iostream>
#include<string>
#include<vector>
using namespace std;
//vector容器存放自定义的数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};


void test01()
{
    vector<Person>v;
    Person p1("aaa",10);
    Person p2("bbb",15);
    Person p3("ccc",19);
    Person p4("ddd",23);
    Person p5("fff",27);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //遍历容器中的数据
    for(vector<Person>::iterator it =v.begin(); it != v.end();it++)
    {
        cout << "姓名是："<<(*it).m_name <<"年龄是："<<(*it).m_age <<endl;
    }

}

//存放自定义数据类型指针
void test02()
{
    vector<Person*>v;
    Person p1("aaa",10);
    Person p2("bbb",15);
    Person p3("ccc",19);
    Person p4("ddd",23);
    Person p5("fff",27);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //遍历容器
    for(vector<Person*>::iterator  it = v.begin(); it != v.end();it++)
    {
        cout <<"姓名是："<<(*it)->m_name<<"年龄是："<<(*it)->m_age<<endl;
    }
}


int main()
{
    test01();
    test02();
    return 0;
}
