#include <iostream>
#include<cstring>
using namespace std;
//��Ŀ����
/*
������nյ�ƣ����Ϊ1��n����ʼʱ���еĵƶ��ǹصģ����Ϊ1�����߹������ѱ����1�ı����ĵƿ��ذ��£����Ĺ��ϣ��صĴ򿪣���
���Ϊ2���˰ѱ����2�ı����ĵƿ��ذ��£����Ϊ3�����ְѱ����3�ı����ĵƿ��ذ��¡���ֱ����k����Ϊֹ������n��k��0<n,k��1000����
����ļ�յ���ǿ��ŵġ�
*/
bool a[1005];
int main()
{
    int n,k;
    bool first = 1;
    memset(a,0,sizeof(a));  //��ʼ��a����ȫ��Ϊ0
    cin >>  n>>k;
    for(int i = 1;i < k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%i==0)
            {
                a [j] =  !a[j] ;
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(a[j])
        {
            if(first)
            {
                first  = 0;
            }else{
                cout<<"  ";
            }
            cout << j ;
        }
    }
    return 0;
}
