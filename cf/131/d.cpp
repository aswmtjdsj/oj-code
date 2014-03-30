/*
   to calc the number of bridges in an undircted graph
   nodes count from 1 to n
   if the graph is not connnected
   then break
   (actually we can still call it)
 */
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <map>
#define maxn 3005
#define maxm 6100
using namespace std;
struct edge
{
	int p,next;
	edge(){}
	edge(int a,int b):p(a),next(b){}
}e[maxm];
int v[maxn],color[maxn];
int n,con,tot,pre[maxn],cnt,bcnt,low[maxn],vis[maxn];
int ans[maxn];
map <pair<int,int>,int> M;
void init()
{
	con = bcnt = cnt = tot = 0;
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	memset(low,-1,sizeof(pre));
	memset(v,-1,sizeof(v));
	memset(color,-1,sizeof(color));
	memset(ans,-1,sizeof(ans));
}
void add(int p,int q)
{
	e[tot] = edge(q,v[p]);
	v[p] = tot++;
}
void dfs(int x)
{
	vis[x] = 1;
	con++;
	for(int k = v[x];~k;k = e[k].next)
		if(!vis[e[k].p])
			dfs(e[k].p);
}
void bridge(int xu,int xw)
{
	int k,u,w = xw;
	pre[w] = cnt++;
	low[w] = pre[w];
	for(k = v[w];~k;k = e[k].next)
	{
		u = e[k].p;
		if(pre[u] == -1)
		{
			bridge(w,u);
			if(low[w] > low[u])
				low[w] = low[u];
			if(low[u] == pre[u])
			{
				bcnt++;
				M[make_pair(w,u)] = M[make_pair(u,w)] = 1;
	//			printf("%d %d\n",w,u);
			}
		}
		else if(u != xu)
		{
			if(low[w] > pre[u])
				low[w] = pre[u];
		}
	}
}
void bfs(int x)
{
	ans[x] = 0;
	queue<int> Q;
	Q.push(x);
	while(!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for(int k = v[now];~k;k = e[k].next)
		{
			int p = e[k].p;
			if(ans[p] == -1 || ans[p] > ans[now] + 1)
			{
				ans[p] = ans[now] + 1;
				Q.push(p);
			}
		}
	}
}
int main()
{
	while(scanf("%d",&n)==1)
	{
		M.clear();
		init();//initialization
		for(int i = 0;i < n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			add(a,b);
			add(b,a);
		}
		for(int i = 1;i <= n;i++)//judge edge-connection component
			if(pre[i] == -1)
				bridge(i,i);
		for(int i = 1;i <= n;i++)
		{
			for(int k = v[i];~k;k = e[k].next)
				if(M[make_pair(i,e[k].p)] == 0)
				{
					color[i] = 0;
					break;
				}
		}
		for(int i = 1;i <= n;i++)
			if(color[i] == 0)
				bfs(i);
	//	printf("%d\n",bcnt);
//		for(int i = 1;i <= n;i++)
	//		printf("%d%c",color[i],i == n?'\n':' ');
		for(int i = 1;i <= n;i++)
			printf("%d%c",ans[i],i == n?'\n':' ');
	}
}
