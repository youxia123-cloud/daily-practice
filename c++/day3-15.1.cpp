#include <iostream>

using namespace std;
//��ͨ�����ͺ���ģ�������
//1.�������ģ�����ͨ���������Ե���ʹ�ã����ȵ�����ͨ����
//2.����ͨ����ģ��� �����б�ķ�ʽ��ǿ�Ƶ��ú���ģ��
//3.����ģ����Է�����������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
//����ģ�����ͨ������ò�Ҫ������  �������������

void myPrint(int a,int b)
{
    cout <<"���õ�����ͨ����"<<endl;

}

template<class T>
void myPrint(T a, T b)
{
    cout << "���õ��Ǻ���ģ��"<<endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
    cout << "���õ������صĺ���ģ��"<<endl;
}

void test01()
{
    int a =10;
    int b =20;
    //myPrint(a, b);
    //ͨ����ģ��Ĳ����б�ǿ�Ƶ��ú���ģ��
    //myPrint<>(a,b);
    myPrint(a,b,100);
    //�������ģ��������õ�ƥ�䣬����ʹ�ú���ģ��
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1,c2);

}

int main()
{
    test01();
    return 0;
}
