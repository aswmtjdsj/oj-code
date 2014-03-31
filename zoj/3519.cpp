#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 505
int a[maxn];
bool v[maxn];
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int in;
        scanf("%d",&in);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a + n);
        memset(v,0,sizeof(v));
        for(int i = 0;i < n;i++)
        {
            if(a[i] > in && !v[i])
            {
                in += 2;
                v[i] = true;
            }
        }
        for(int i = 0;i < n;i++)
        {
            if(!v[i])
            {
                v[i] = true;
                in ++;
            }
        }
        printf("%d\n",in);
    }
}
