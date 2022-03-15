#include <iostream>

using namespace std;
//函数模板的案例

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
    //自动类型推导
    cout<< myAdd02(a,b)<<endl;
    //显示指定类型
    cout <<myAdd02<int>(a,c)<<endl;

}
int main()
{
    test01();
    return 0;
}
