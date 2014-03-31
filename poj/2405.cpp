#include <iostream>
#include <cstdio>
using namespace std;
#include <cmath>
int main()
{
    double d,v;
    while(scanf("%lf %lf",&d,&v) == 2 && (d || v))
    {
        printf("%.3lf\n",pow(d * d * d - 6 * v / acos(-1.0),1.0 / 3.0));
    }
}
