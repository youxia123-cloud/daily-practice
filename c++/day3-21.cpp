#include <iostream>
#include<string>
#include<vector>
using namespace std;
//vector��������Զ������������
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

    //���������������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //���������е�����
    for(vector<Person>::iterator it =v.begin(); it != v.end();it++)
    {
        cout << "�����ǣ�"<<(*it).m_name <<"�����ǣ�"<<(*it).m_age <<endl;
    }

}

//����Զ�����������ָ��
void test02()
{
    vector<Person*>v;
    Person p1("aaa",10);
    Person p2("bbb",15);
    Person p3("ccc",19);
    Person p4("ddd",23);
    Person p5("fff",27);

    //���������������
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //��������
    for(vector<Person*>::iterator  it = v.begin(); it != v.end();it++)
    {
        cout <<"�����ǣ�"<<(*it)->m_name<<"�����ǣ�"<<(*it)->m_age<<endl;
    }
}


int main()
{
    test01();
    test02();
    return 0;
}
