#include <iostream>
//简单静态链表,有三个学生的数据节点组成
using namespace std;
struct student
{
    long num;
    float score;
    struct student *next;
};
int main()
{
    struct student a,b,c, *head,*p;
    a.num = 34341;
    a.score = 81.6;
    b.num = 34342;
    b.score = 90;
    c.num = 34343;
    c.score = 93;
    head = & a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    p = head;
    do
    {
        cout <<p->num<<"  "<<p->score <<endl;
        p = p->next;
    }while(p!=NULL);
    getchar();
    return 0;
}
