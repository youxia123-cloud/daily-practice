#include <iostream>
#include<vector>
#include <algorithm>
#include<string>
using namespace std;

/*(HDU3527)
X国的情报委员收到一份可靠的信息，信息表明Y国将派间谍去窃取X国的机密文件。
X国指挥官手中有两份名单列表，一份是Y国派往X国的间谍名单列表，另一份是X国以前派往Y国的间谍名单列表。这两份名单列表可能有些重叠。
因为间谍可能同时扮演两个角色，称之为“双重间谍”。因此，Y国可以把双重间谍送回X国。
很明显，这对X国是有利的，因为双重间谍可以把Y国的机密文件带回，而不必担心被Y国边境拘留。所以指挥官决定抓住由Y国派出的间谍，让普通人和双重间谍进入。
那么你能确定指挥官需要抓捕的间谍名单吗？输入：有几个测试用例。每个测试用例都包含4部分。
第1部分包含3个正整数A、B、C，A是进入边境的人数，B是Y国将派出的间谍人数，C是X国以前派到Y国的间谍人数。
第2部分包含A个字符串，为进入边境的人员名单。
第3部分包含B个字符串，为由Y国派出的间谍名单。第4部分包含C个字符串，即双重间谍的名单。
每个测试用例后都有一个空白行。在一份名单列表中不会有任何名字重复，如果有重复的名字出现在两份名单列表中，则表示同一个人。
输出：输出指挥官抓捕的间谍名单（按列表B的出现顺序）。如果不应捕获任何人，则输出"No enemy spy"。


*/
vector<string> x,y,z,ans;
int main()
{
    int a, b, c;
    string s;
    while(cin>>a>>b>>c)
    {
        x.clear(),y.clear(),z.clear(),ans.clear();
        for(int i=0;i<a;i++)
        {
            cin>>s;
            x.push_back(s);
        }
        for(int i=0;i<b;i++)
        {
            cin >>s;
            y.push_back(s);
        }
        for(int i=0;i<c;i++)
        {
            cin>>s;
            z.push_back(s);
        }
        for(int i=0;i<b;i++)
        {
            //判断第二行在第一行出现但是没有在第三行出现的字符串
            if(find(x.begin(),x.end(),y[i]) != x.end())
                if(find(z.begin(), z.end(),y[i]) == z.end())
                    ans.push_back(y[i]);
        }
        if(!ans.size())
            cout <<"No enemy spy\n";
        else
        {
            for(int i=0;i<ans.size();i++)
            {
                if(i != 0)
                    cout <<" ";
                cout <<ans[i];
            }
            cout <<endl;
        }
    }
    return 0;
}
