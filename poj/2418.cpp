/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 200000000;
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 1000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
struct stri
{
    char s[35];
    bool friend operator <(const stri &a,const stri &b)
    {
        return strcmp(a.s,b.s) < 0;
    }
    bool friend operator == (const stri &a,const stri &b)
    {
        return strcmp(a.s,b.s) == 0;
    }
}str[1000005];
int main()
{
    int t = 0,cnt = 0;
    while(gets(str[t].s) != NULL)
        t++;
    sort(str,str + t);
    for(int i = 0;i < t - 1;i++)
    {
        if(str[i] == str[i + 1])
            cnt ++;
        else
        {
            cnt ++;
            printf("%s %.4f\n",str[i].s,(double) 100.0 * cnt / t);
            cnt = 0;
        }
    }
    if(str[t - 1] == str[t - 2])
        printf("%s %.4f\n",str[t - 1].s,(double) 100.0 * (cnt + 1) / t);
    else
        printf("%s %.4f\n",str[t - 1].s,(double) 100.0 / t);
}
