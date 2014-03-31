#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Scenario #%d:\n",i + 1);
        if(!(a % 2) || !(b % 2))
            printf("%.2lf\n",(double) a * b);
        else
            printf("%.2lf\n",(double) a * b - 1.0 + sqrt(2.0));

        printf("\n");
    }
}
