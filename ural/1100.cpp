/*
 *    Coded by BUPT-[aswmtjds] @ Penalty in 915
 *       */
/*
 *    repeat count method
 *       because of rank is [1,100]
 *          so we can count every number in the range of rank
 *             to record the id
 *                and in the rank order and in the input order to output...
 *                   */
#include <iostream>
#include <cstdio>
using namespace std;
int num[150005],m[150005];
bool v[150005];
int main()
{
    int n;
    int up = -1,lo = 101;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d",&num[i],&m[i]);
        v[m[i]] = true;
        if(m[i] < lo)
            lo = m[i];
        if(m[i] > up)
            up = m[i];
    }
    for(int i = up;i >= lo;i--)
    {
        if(v[i])//if this i has ever happened
        {
            for(int j = 0;j < n;j++)
                if(m[j] == i)
                    printf("%d %d\n",num[j],m[j]);
        }
    }
}