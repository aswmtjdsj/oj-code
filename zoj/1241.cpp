#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(x) ((x) * (x))
using namespace std;
int main()
{
    double a,b,c;
    int t = 1;
    while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
    {
        if(a == 0.0 && b == 0.0 && c == 0.0)
            break;
        printf("Triangle #%d\n",t++);
        if(a == -1.0)
        {
            if(b >= c)
                printf("Impossible.\n");
            else
                printf("a = %.3lf\n",sqrt(sqr(c) - sqr(b)));
        }
        else if(b == -1.0)
        {
            if(a >= c)
                printf("Impossible.\n");
            else
                printf("b = %.3lf\n",sqrt(sqr(c) - sqr(a)));
        }
        else
            printf("c = %.3lf\n",sqrt(sqr(a) + sqr(b)));
        printf("\n");
    }
}
