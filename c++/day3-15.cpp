#include <iostream>

using namespace std;
//����ģ��İ���

int  myAdd01(int a,int b)
{
    return a+b;
}
template<class T>
T myAdd02(T a,T b)
{
    return a+b;
}



void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd01(a,c) <<endl;
    //�Զ������Ƶ�
    cout<< myAdd02(a,b)<<endl;
    //��ʾָ������
    cout <<myAdd02<int>(a,c)<<endl;

}
int main()
{
    test01();
    return 0;
}
