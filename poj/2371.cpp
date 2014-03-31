#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    sort(a + 1,a + n + 1);
    char opt[100];
    scanf("%s",opt);
    int k;
    scanf("%d",&k);
    for(int i = 0;i < k;i++)
    {
        int o;
        scanf("%d",&o);
        printf("%d\n",a[o]);
    }
}
