#include <iostream>
#include<string>
using namespace std;

//类模板没有自动类型推导
//类模板的参数列表中可以由默认参数
//定义类模板
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
    Person<string ,int>p1("孙悟空",999);
    p1.showPerson();
}


int main()
{
    test01();
    return 0;
}
