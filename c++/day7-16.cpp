#include <iostream>
#include<string>
using namespace std;

class Student
{
public:
    Student(string name,int age);    //有参构造函数
    //声明拷贝构造函数
    Student(const Student&  another);
    //声明析构函数
    ~Student();
    void study();
    void exam();
    void setName(string name);
    void setAge(int age);
    //声明常量成员函数
    void Info() const;
    string getName();
    string nickname;
private:
    string _name;
    int _age;
};
//构造函数
Student::Student(string name,int age)
{
    _name = name;
    _age = age;
}
//拷贝构造函数
Student::Student(const Student& another)
{
    cout<<"调用拷贝构造函数："<<endl;
    _name = another._name;
    _age = another._age;
}
//析构函数
Student::~Student()
{
    cout<<"调用析构函数"<<endl;
}

void Student::study()
{
    cout<<"学习"<<endl;
}
void Student::exam()
{
    cout<<"考试"<<endl;
}
void Student::setName(string name)
{
    _name = name;
}
string Student::getName()
{
    return _name;
}
void Student::setAge(int age)
{
    this->_age = age;
}
void Student::Info() const
{
    cout<<"这是个人信息！"<<endl;
}

int main()
{
    Student  stu("小明",17);
    stu.setName("Tom");
    cout<<stu.getName()<<endl;
    stu.exam();
    stu.study();
    //使用对象A创建新的对象B
    Student stu1(stu);
    stu1.exam();
    const Student stu2("wind",19);
    stu2.Info();

    return 0;
}
