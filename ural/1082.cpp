#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1;i <= n;i++)
        {
            printf("%d",i);
            printf("%c",(i == n) ? '\n':' ');
        }
    }
}