#include <iostream>
#include <cstdio>
using namespace std;
int t[105][105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
            scanf("%d",&t[i][j]);
    for(int i = n - 1;i >= 1;i--)
    {
        for(int j = 1;j <= i;j++)
            t[i][j] += max(t[i + 1][j],t[i + 1][j + 1]);
    }
    printf("%d\n",t[1][1]);
}
