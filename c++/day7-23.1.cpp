#include <iostream>
//������ͣ���ȣ�
using namespace std;

int main()
{
    int k,n=1,a;
    double sum = 0;
    cin>>k;
    while(sum<=k)
    {
        sum+= 1.0/n;
        a = n;
        n++;
    }
    cout<<a<<endl;
    return 0;
}
