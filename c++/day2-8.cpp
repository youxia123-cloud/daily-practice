#include <iostream>
//ð������,�鲢����
/*
��Ŀ����
��һ����ʽ�Ļ�վ�Ա���һ���ţ�����������ƺ����ĵ��Ŷ�ˮƽ��ת��һ����վ��ְ�������ŵĳ���������������ڳ��ᣬ���������ת180180�ȣ�����԰��������ڳ����λ�ý����������ַ��������������г����˳���������͸����������Ž���վ�ĳ��ᰴ����Ŵ�С�������С������ݺ󣬻�վ��������һ�����Զ���������һ����Ҫ�Ĺ����Ǳ�һ�����������ʼ�ĳ���˳�򣬼��������ö��ٲ����ܽ���������

�����ʽ
�����С�

��һ���ǳ�������N( \le 10000)N(��10000)��

�ڶ�����NN����ͬ������ʾ��ʼ�ĳ���˳��

�����ʽ
һ�����������ٵ���ת������

�����������
���� #1����
4
4 3 2 1
��� #1����
6

*/
using namespace std;

int main()
{
   int i,j,n,temp;
   int t = 0;
   int a[10000];
   cin >> n;
   for(i=0;i<n;i++){
    cin >>a[i];
   }
   for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                t++;
            }
        }
    }
    cout << t<<endl;

    return 0;
}