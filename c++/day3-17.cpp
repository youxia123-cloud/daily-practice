#include <iostream>
#include<string>
using namespace std;

//��ģ��û���Զ������Ƶ�
//��ģ��Ĳ����б��п�����Ĭ�ϲ���
//������ģ��
template<class NameType,class AgeType>
class Person{
public:
    Person(NameType name,AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    NameType m_name;
    AgeType m_age;
    void showPerson()
    {
        cout << "name:" <<this->m_name << "age:" <<this->m_age<<endl;
    }

};

void test01()
{
    Person<string ,int>p1("�����",999);
    p1.showPerson();
}


int main()
{
    test01();
    return 0;
}
