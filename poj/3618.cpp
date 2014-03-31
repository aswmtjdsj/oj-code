#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int f(int x)
{
    return (x > 0)?x:-x;
}
int a[50005];
int T,n;
bool cmp(int a,int b)
{
    return f(a) < f(b);
}
int main()
{
    scanf("%d %d",&T,&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    sort(a,a + n,cmp);
    int c = 0,now = 0,det;
    for(int i = 0;i < n;i++)
    {
        det = f(a[i] - now);
        now = a[i];
        T -= det;
        if(T < 0)
            break;
        c++;
    }
    printf("%d\n",c);
}
