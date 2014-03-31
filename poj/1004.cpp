#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double temp,sum = 0.0;
    int t = 0;
    freopen("data.in","r",stdin);
    while(scanf("%lf",&temp) == 1)
    {
        sum += temp;
        t++;
    }
    printf("$%.2lf\n",sum / (double) t);
}
