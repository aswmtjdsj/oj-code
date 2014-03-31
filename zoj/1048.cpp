#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    double sum = 0,a;
    for(int i = 0;i < 12;i++)
    {
        scanf("%lf",&a);
        sum += a;
    }
    printf("$%.2lf\n",sum / 12.0);
}
