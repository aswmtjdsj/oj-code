/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * binary search + maxflow(recreat the graph)
 * but maybe multi-assignment is better....
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cctype>
#define maxn 2000
#define maxe 1200000
using namespace std;
const int inf = ~0u>>1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),val(c),anti(d){}
}v[maxn],e[maxe],arc[maxn],path[maxn],e2[maxe],v2[maxn];
int flow[maxn],cnt[maxn],d[maxn],pre[maxn];
int n,tot,tot2;
void init()
{
    tot = 0;
    for(int i = 0;i <= n;i++)
    {
        d[i] = 0;
        cnt[i] = 0;
        v[i].next = -1;
    }
    cnt[0] = n + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,v[p].next,val,tot + 1);
    v[p].next = tot++;
    e[tot] = edge(p,v[q].next,0,tot - 1);
    v[q].next = tot++;
}/*
    void adde(int p,int q,int val)
    {
    add(p,q,val);
    add(q,p,0);
    }*/
int mflow(int s,int t)
{
    //cout << inf << endl;
    int k,least,loc,i,now,total;
    bool flag;
    for(int i = 0;i <= n;i++)
        arc[i].next = v[i].next;
    for(i = s,total = 0,now = inf;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val > 0 && d[i] == d[e[k].p]  + 1)
            {
                now = min(e[k].val,now);
                pre[e[k].p] = i;
                path[e[k].p].next = k;
                arc[i].next = k;
                i = e[k].p;
                if(i == t)
                {
                    for(total += now;i != s;i = pre[i])
                    {
                        e[path[i].next].val -= now;
                        e[e[path[i].next].anti].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n,k = v[i].next;~k;k = e[k].next)
            {
                if(e[k].val && d[e[k].p] < least)
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            arc[i].next = loc;
            cnt[d[i]]--;
            if(cnt[d[i]] == 0)
                break;
            d[i] = least + 1;
            cnt[d[i]]++;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return total;
}
char str[10005];
int main()
{
    int N,M;
    while(scanf("%d %d",&N,&M) == 2 && (N || M))
    {
        init();
        n = N + M + 1;
        gets(str);
        for(int i = 1;i <= N;i++)
        {
            add(0,i,1);
            gets(str);//cin.getline(str,10000);         
            //cout << str << endl;
            int l = strlen(str);
            int j = 0;
            while(j < l)
            {
                while(j < l && !isdigit(str[j]))
                    j++;
                int temp = 0;
                if(j >= l)
                    break;
                bool mark = false;
                while(j < l && str[j] != ' ')
                {
                    //cout << j << endl;
                    mark = true;
                    temp = temp * 10 + str[j] - '0';
                    j++;
                }
                if(mark)
                    add(i,temp + N + 1,1);
            }
            /*istringstream in(str);
              in >> str;
              int p;

            //cout << str << endl;
            while(in >> p)
            {
            add(i,p + N + 1,1);
            //cout << p << ' ';
            }*/
            //cout << endl;
        }
        for(int i = 0;i < M;i++)
            add(i + N + 1,n,N);
        for(int i = 0;i < tot;i++)
            e2[i] = e[i];
        for(int i = 0;i <= n;i++)
            v2[i] = v[i];
        int lo = 1,hi = N;
        tot2 = tot;
        while(lo < hi)
        {
            int mid = (lo + hi) >> 1;
            init();
            tot = tot2;
            for(int i = 0;i < tot;i++)
                e[i] = e2[i];
            for(int i = 0;i <= n;i++)
                v[i] = v2[i];
            for(int k = v[n].next;~k;k = e[k].next)
            {
                if(e[k].val == 0)
                    e[k - 1].val = mid;
            }
            int ans = mflow(0,n);
            //cout << ans << endl;
            if(ans < N)
                lo = mid + 1;
            else
                hi = mid;
        }
        printf("%d\n",(lo + hi) / 2);
    }
}
