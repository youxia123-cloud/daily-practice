#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;
//´òÓ¡É³Â©£¨PTA£©
int main()
{
    int x,n;
    char y;
    cin>>x>>y;
    n = floor(sqrt((x+1)/2));

    for(int i=0;i<n;i++)
    {
        for(int k=0;k<i;k++)
        {
            cout<<" ";
        }
        for(int j=2*(n-i)-1;j>0;j--)
        {
            cout<<y;
        }
        cout<<endl;
    }
     for(int i=1;i<n;i++)
    {
        for(int k=i+1;k<n;k++)
        {
            cout<<" ";
        }
        for(int j=2*i+1;j>0;j--)
        {
            cout<<y;
        }
        cout<<endl;
    }
    cout<<x-(2*n*n-1)<<endl;
    return 0;
}
