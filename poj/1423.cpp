#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double ans[8000005];
int main()
{
    ans[0] = 0;
    for(int i = 1;i <= 8000000;i++)
        ans[i] = log10((double)i) + ans[i-1];
    int t;
    scanf("%d",&t);
    for(int j = 0;j < t;j++)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
        {
            puts("1");
            continue;
        }
        if(n <= 8000000)
            printf("%.0lf\n",ceil(ans[n]));
        else
        {
            double tmp = ans[8000000];
            for(int i = 8000001;i <= n;i++)
                tmp += log10(double(i));
            printf("%.0lf\n",ceil(tmp));
        }
    }
}
