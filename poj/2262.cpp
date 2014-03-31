/*
 * POJ 2262 Goldbach's Conjecture
 * coded by BUPT-aswmtjdsj@BSW
 * time:2010-09-07
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
    int n;
    select();
    while(scanf("%d",&n) != EOF && n)
    {
        for(int i = 3;i <= n / 2;i += 2)
        {
            if(prime[i] && prime[n - i])
            {
                printf("%d = %d + %d\n",n,i,n - i);
                break;
            }
        }
    }
    return 0;
}
