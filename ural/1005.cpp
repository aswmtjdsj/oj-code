#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 22
int st[maxn];
int ab(int x)
{
    return x >= 0?x:-x;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&st[i]);
    int ans = 2000000;
    for(int idx = 0;idx < (1 << n);idx++)
    {
        int a = 0,b = 0;
        for(int i = 0;i < n;i++)
        {
            if((idx >> i) & 1)
                a += st[i];
            else
                b += st[i];
        }
        ans = min(ans,ab(a - b));
    }
    printf("%d\n",ans);
}