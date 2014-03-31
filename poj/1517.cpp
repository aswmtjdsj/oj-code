#include <iostream>
#include <cstdio>
using namespace std;
int a[10];
double exp(int x)
{
    double e = 1.0;
    for(int i = 1;i <= x;i++)
        e += 1.0 / (double)a[i];
    return e;
}
int main()
{
    a[0] = 1;
    for(int i = 1;i <= 9;i++)
        a[i] = a[i - 1] * i;
    int n;
    printf("n e\n");
    printf("- -----------\n");
    for(int i = 0;i < 10;i++)
        printf("%d %.9lf\n",i,exp(i));
}
