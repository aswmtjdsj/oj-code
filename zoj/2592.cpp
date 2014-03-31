#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        int n,sum = 0,a;
        scanf("%d",&n);
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&a);
            sum = (a > 0)?sum + 1:sum - 1;
        }
        printf("%d\n",(sum > 0)?sum : 0);
    }
}
