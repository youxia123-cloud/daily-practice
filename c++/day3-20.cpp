#include <iostream>
#include<vector>
#include<algorithm>    //��׼�㷨��ͷ�ļ�
using namespace std;

//vector����������õ���������



void myPrint(int val)
{
    cout << val << endl;
}
void test01()
{
    //������һ��vector������
    vector <int> v;
    //�������в�������,β������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //ͨ�����������������е�����
//    vector<int>::iterator  itBegin = v.begin();  //��ʼ��������ָ�������ĵ�һ��Ԫ��
//    vector<int>::iterator  itEnd = v.end();  //������������ָ�����������һ��Ԫ�ص���һ��λ��
//
//
//    //��һ�ֱ����ķ�ʽ
//    while(itBegin != itEnd)
//    {
//        cout << * itBegin <<endl;
//        itBegin ++;
//    }

    //�ڶ��ֱ����ķ�ʽ
//    for(vector<int>::iterator it = v.begin();it != v.end(); it++)
//    {
//        cout << *it <<endl;
//    }

    //�����ֱ�����ʽ
    for_each(v.begin(),v.end(),myPrint);
}


int main()
{
    test01();
    return 0;
}
