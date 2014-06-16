#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define maxa 65
#define maxl 100000
#define maxn 200
#define maxm 50000

const int inf = ~0u >> 1;

struct edge
{
	int p,next,val,cost;
	edge(){}
	edge(int a,int b,int c,int d):p(a),next(b),val(c),cost(d){}
}e[maxm];

int st[maxn],d[maxn],pre[maxn];
int sol[maxa];

int tot,n,m,s,t,flow;

bool in[maxn];

void init()
{
	tot = 0;
	fill(st,st + n + 1,-1);
}
void add(int p,int q,int val,int cost)
{
	e[tot] = edge(q,st[p],val,cost);
	st[p] = tot++;
	e[tot] = edge(p,st[q],0,-cost);
	st[q] = tot++;
}
int spfa()
{
	queue<int> Q;
	fill(d,d + n + 1,inf);
	fill(in,in + n + 1,0);
	fill(pre,pre + n + 1,-1);
	d[s] = 0;
	Q.push(s);
	in[s] = true;
	while(!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for(int k = st[now];~k;k = e[k].next)
		{
			if(e[k].val && d[e[k].p] > d[now] + e[k].cost)
			{
				d[e[k].p] = d[now] + e[k].cost;
				pre[e[k].p] = k;
				if(!in[e[k].p])
					Q.push(e[k].p);
			}
		}
	}
	return d[t];
}
int mincost()
{
	int cost = 0,now,u;
	while(1)
	{
		if(spfa() == inf)
			break;
		u = t;
		now = inf;
		while(pre[u] != -1)
		{
			now = min(now,e[pre[u]].val);
			u = e[pre[u] ^ 1].p;
		}
		u = t;
        flow += now;
		while(pre[u] != -1)
		{
			cost += now * e[pre[u]].cost;
			e[pre[u]].val -= now;
			e[pre[u] ^ 1].val += now;
			u = e[pre[u] ^ 1].p;
		}
	}
	return cost;
}
int main()
{
    int cas;
    scanf("%d", &cas);
    for(int C = 0; C < cas; C++) {
        int N;
        scanf("%d", &N);
        int li[maxa], ri[maxa];
        int nodes[maxa * 3];
        int acnt = 0;
        nodes[acnt++] = 1;
        nodes[acnt++] = maxl+1;
        for(int i = 0; i < N; i++) {
            scanf(" %d %d", &li[i], &ri[i]);
            bool mark = false;
            for(int j = 0; j < acnt; j++) {
                if(nodes[j] == li[i]) {
                    mark = true;
                    break;
                }
            }
            if(!mark) {
                nodes[acnt++] = li[i];
            }
            mark = false;
            for(int j = 0; j < acnt; j++) {
                if(nodes[j] == ri[i] + 1) {
                    mark = true;
                    break;
                }
            }
            if(!mark) {
                nodes[acnt++] = ri[i] + 1;
            }
        }
        sort(nodes, nodes+acnt);
        n = 1 + N + acnt + 1;
        init();
        s = 0;
        t = n;
        for(int j = 0; j < acnt-1; j++) {
            add(N + j + 1, t, nodes[j+1]-nodes[j], 0);
        }
        for(int i = 0;i < N;i++)
        {
            add(s, i+1, 1, 0);
            int j = 0;
            for(j = 0; j < acnt; j++) {
                if(li[i] == nodes[j]) {
                    break;
                }
            }
            while(nodes[j] <= ri[i]) {
                //cout << li[i] << ' ' << ri[i] << ' ' << nodes[j] << endl;
                add(i+1, N + j + 1, 1, N - i);
                j++;
            }
        }

        flow = 0;
        int ans = mincost();
        int cnt = 0, idx = st[s];
        memset(sol, 0, sizeof(sol));
        while(cnt < N) {
            int p = e[idx].p;
            int val = e[idx].val;
            idx = e[idx].next;
            if(val == 0) {
                sol[p] = 1;
            }
            cnt++;
        }
        printf("%d\n", flow);
        bool mark = false;
        for(int i = 1; i <= N; i++) {
            if(sol[i]) {
                if(mark) {
                    putchar(' ');
                }
                printf("%d", i);
                mark = true;
            }
        }
        puts("");
    }
}
