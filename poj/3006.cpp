/*
 * POJ 3006 Dirichlet's Theorem on Arithmetic Progressions
 * coded by BUPT-aswmtjdsj@BSW
 * time:2010-09-06
 * @915
 * */
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
const double eps=1e-7;
const ll MAX=1<<30;
bool prime[1000005];
void select()
{
    int i,j;
    prime[0] = prime[1] = false;
    prime[2] = true;
    for(i = 3;i <= 1000000;i ++)
    {
        if(i % 2)
            prime[i] = true;
        else
            prime[i] = false;
    }
    for(i = 3;i <= 1000;i +=2 )
    {
        if(prime[i])
        {
            for(j = i << 1;j <= 1000000;j += i)
                prime[j] = false;
        }
    }
}
int main()
{
    select();
    int a,d,n;
    while(scanf("%d%d%d",&a,&d,&n) != EOF && (a || d || n))
    {
        if(prime[a])
            n--;
        while(n > 0)
        {
            a += d;
            if(prime[a])
                n --;
        }
        printf("%d\n",a);
    }
    return 0;
}
