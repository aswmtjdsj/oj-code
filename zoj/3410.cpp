#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct PII
{
    int t;
    int d;
    void read()
    {
        //t.read();
        scanf("%d",&t);
        scanf("%d",&d);
    }
    bool friend operator <(const PII &a,const PII &b)
    {
        return a.d < b.d;
    }
}p[25005];
void solve(int n,int k)
{
    for(int i = 0;i < n;i++)
        p[i].read();
    sort(p,p + n);
    int limit = 0,now = 0;
    priority_queue <int,vector <int> ,less <int> > pq;
    for(int i = 0;i < n;i++)
    {
        limit = p[i].d;
        now += p[i].t;
        pq.push(p[i].t);
        while(now > limit)
        {
            now -= pq.top();
            pq.pop();
        }
    }
    //cout << "size " << pq.size() << endl;
    printf("%d\n",(n - pq.size() < k)?n - pq.size():-1); 
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        solve(n,k);
    }
}
/*
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int a[1010][1010];
void solve()
{
int m;
scanf("%d",&m);
for(int i = 0;i < m;i++)
{
scanf("%d",&a[i][0]);
for(int j = 1;j <= a[i][0];j++)
scanf("%d",&a[i][j]);
}
int limit = 0,temp,now = 0;
priority_queue <int,vector <int> ,less <int> > pq;
for(int i = 0;i < m;i++)
{
scanf("%d",&temp);
now += temp;
for(int j = 1;j <= a[i][0];j++)
{
limit += a[i][j];
pq.push(a[i][j]);
}
while(limit > now)
{
limit -= pq.top();
pq.pop();
}
}
printf("%d\n",pq.size());
}
int main()
{
int t;
while(scanf("%d",&t) == 1)
{
for(int i = 0;i < t;i++)
solve();
}
}
*/
