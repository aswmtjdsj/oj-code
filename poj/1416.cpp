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
char str[10];
int tar,t,l,may[10];
struct ANS
{
    int cnt,v;
    bool flag;
    int com[10];
}ans[720];
void dfs(int v,int cnt)
{
    for(int len = 1;len <= l;len++)
    {
        if(v + len <= l)
        {
            int tem;
            char st[10];
            strncpy(st,&str[v],len);
            st[len] = 0;
            sscanf(st,"%d",&tem);
            may[cnt] = tem;
            if(v + len == l)
            {
                for(int i = 0;i <= cnt;i++)
                {
                    ans[t].com[i] = may[i];
                    ans[t].v += ans[t].com[i];
                    ans[t].cnt = cnt;
                }
                t++;
                return ;
            }
            dfs(v + len,cnt + 1);
        }
    }
}
int main()
{
    while(scanf("%d %s",&tar,str) == 2 && (tar || strcmp(str,"0")))
    {
        int temp;
        sscanf(str,"%d",&temp);
        if(temp == tar)
        {
            printf("%d %d\n",temp,temp);
            continue;
        }
        l = strlen(str);
        temp = 0;
        for(int i = 0;i < l;i++)
            temp += str[i] - '0';
        if(temp > tar)
        {
            printf("error\n");
            continue;
        }
        t = 0;
        for(int i = 0;i < 720;i++)
            ans[i].v = ans[i].flag = 0;
        dfs(0,0);
        for(int i = 0;i < t;i++)
            if(ans[i].v <= tar)
                ans[i].flag = true;
        int mark,mark2 = -1;
        for(int i = 0;i < t;i++)
        {
            if(ans[i].flag && ans[i].v > mark2)
            {
                mark2 = ans[i].v;
                mark = i;
            }
        }
        int count = 0;
        for(int i = 0;i < t;i++)
        {
            if(ans[i].flag && ans[i].v == ans[mark].v)
                count++;
        }
        if(count > 1)
        {
            printf("rejected\n");
            continue;
        }
        printf("%d",ans[mark].v);
        for(int i = 0;i <= ans[mark].cnt;i++)
            printf(" %d",ans[mark].com[i]);
        printf("\n");
    }
}
