#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
struct stu
{
    int a,b,c;
    stu(){}
    stu(int _a,int _b,int _c):a(_a),b(_b),c(_c){}
}s[50005];
bool operator < (stu p,stu q)
{
    return p.a < q.a || (p.a == q.a && p.b < q.b);
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 0;i < n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        s[i] = stu(a,b,i);
    }
    sort(s,s + n);
    int mark = n - 1;
    for(int i = n - 1;i >= n - k;i--)
    {
        if(s[i].b > s[mark].b)
            mark = i;
    }
    printf("%d\n",s[mark].c + 1);
}
