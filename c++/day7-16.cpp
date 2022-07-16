#include <iostream>
#include<string>
using namespace std;

class Student
{
public:
    Student(string name,int age);    //�вι��캯��
    //�����������캯��
    Student(const Student&  another);
    //������������
    ~Student();
    void study();
    void exam();
    void setName(string name);
    void setAge(int age);
    //����������Ա����
    void Info() const;
    string getName();
    string nickname;
private:
    string _name;
    int _age;
};
//���캯��
Student::Student(string name,int age)
{
    _name = name;
    _age = age;
}
//�������캯��
Student::Student(const Student& another)
{
    cout<<"���ÿ������캯����"<<endl;
    _name = another._name;
    _age = another._age;
}
//��������
Student::~Student()
{
    cout<<"������������"<<endl;
}

void Student::study()
{
    cout<<"ѧϰ"<<endl;
}
void Student::exam()
{
    cout<<"����"<<endl;
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
    cout<<"���Ǹ�����Ϣ��"<<endl;
}

int main()
{
    Student  stu("С��",17);
    stu.setName("Tom");
    cout<<stu.getName()<<endl;
    stu.exam();
    stu.study();
    //ʹ�ö���A�����µĶ���B
    Student stu1(stu);
    stu1.exam();
    const Student stu2("wind",19);
    stu2.Info();

    return 0;
}
