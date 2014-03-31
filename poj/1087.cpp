#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
const int inf = ~0u >> 1;
#define maxn 305
#define maxm 2000
#define maxl 30
int n,N,M,K;
int tot;
struct edge
{
    int p,val,next;
    edge(){}
    edge(int a,int b,int c):p(a),val(b),next(c){}
}e[maxm];
int flow[maxn],v[maxn],arc[maxn],d[maxn],cnt[maxn],pre[maxn],path[maxn];
void init()
{
    tot = 0;
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    memset(v,-1,sizeof(v));
}
int label[maxn];
char pro[maxn];
void add(int p,int q,int val)
{
    e[tot] = edge(q,val,v[p]);
    v[p] = tot++;
    e[tot] = edge(p,0,v[q]);
    v[q] = tot++;
}
int mflow()
{
    cnt[0] = n + 1;
    int s = 0,t = n;
    int sum,now,i,k,least,loc;
    bool flag;
    for(int i = 0;i <= n;i++)arc[i] = v[i];
    for(sum = 0,now = inf,i = s;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i];~k;k = e[k].next)
        {
            if(e[k].val && d[i] == d[e[k].p] + 1)
            {
                now = min(now,e[k].val);
                pre[e[k].p] = i;
                path[e[k].p] = k;
                arc[i] = k;
                i = e[k].p;
                if(i == t)
                {
                    for(sum += now;i != s;i = pre[i])
                    {
                        e[path[i]].val -= now;
                        e[path[i]^1].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n + 1,k = v[i];~k;k = e[k].next)
            {
                if(e[k].val && d[e[k].p] < least)
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            cnt[d[i]]--;
            if(cnt[d[i]] == 0)
                break;
            d[i] = least + 1;
            cnt[d[i]]++;
            arc[i] = loc;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return sum ;
}
int main()
{
    map <string,int> MAP;
    scanf("%d",&N);
    int cnt = 1;
    memset(pro,0,sizeof(pro));
    string opt,_opt;
    for(int i = 1;i <= N;i++)
    {
        cin >> opt;
        MAP[opt] = cnt;
        pro[cnt++] = 1;//to sink
    }
    scanf("%d",&M);
    init();
    for(int i = 1;i <= M;i++)
    {
        int a,b;
        cin >> opt >> _opt;
        MAP[opt] = cnt;
        a = cnt;
        pro[cnt++] = 2;//to source
        if(MAP[_opt] == 0)
        {
            MAP[_opt] = cnt;
            b = cnt;
            pro[cnt++] = 3;//middle
        }
        else
            b = MAP[_opt];
        add(a,b,1);
    }
    scanf("%d",&K);
    n = N + M + K + 1;
    for(int i = 1;i <= K;i++)
    {
        cin >> opt >> _opt;
        int a = MAP[opt],b = MAP[_opt];
        add(a,b,inf);
    }
    for(int i = 1;i < cnt;i++)
    {
        if(pro[i] == 1)
            add(i,n,1);
        else if(pro[i] == 2)
            add(0,i,1);
    }
    /*for(int i = 0;i <= n;i++)
     *      for(int j = v[i];~j;j = e[j].next)
     *              {
     *                          if(e[j].val)
     *                                          cout << i << ' ' << e[j].p << ' ' << e[j].val << endl;
     *                                                  }*/
    printf("%d\n",M - mflow());
}
