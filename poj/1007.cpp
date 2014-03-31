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
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 1000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
#define PB push_back
struct word
{
    char a[55];
    int v;
    void scan()
    {
        scanf("%s",a);
        v = 0;
        for(int i = 0;i < strlen(a);i++)
        {
            for(int j = i + 1;j < strlen(a);j++)
            {
                if(a[i] > a[j])
                    v++;
            }
        }
    }
    bool friend operator < (const word &a,const word &b)
    {
        return a.v < b.v;
    }
}c[105];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 0;i < m;i++)
            c[i].scan();
        sort(c,c + m);
        for(int i = 0;i < m;i++)
            printf("%s\n",c[i].a);
    }
}
