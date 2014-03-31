#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    printf("# Cards  Overhang\n");
    while(scanf("%d",&n) == 1)
    {
        double ans = 0;
        for(int i = 1;i <= n;i++)
            ans += 1.0 / (2.0 * i);
        printf("%5d %9.3lf\n",n,ans);
    }
}
