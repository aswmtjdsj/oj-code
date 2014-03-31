/*
 * Coded by BUPT-[aswmtjdsj] @ BSW in 915
 * */
/*
 * f(T) = N * T * (C - T * N)
 * calculate the minimum T to Maximize the value of function f(T)
 * make sure the T is an integer
 * (an integer point on the t-f(t) plane)
 * (if real T = 4.5,you need to output 4,you know that)
 * (regain the math knowledge in high school)
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c) != EOF)
    {
        if(c == 0 || n == 0)
            printf("0\n");
        else
        {
            double t = (double) c / (2.0 * n);
            printf("%.0lf\n",(t > floor(t) + 0.5)? floor(t) + 1: floor(t));
        }
    }
}
