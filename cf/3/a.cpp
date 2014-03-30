#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 10
int d[maxn][maxn];
int ch[maxn][maxn];
int dx[]={0,0,-1,1,-1,1,-1,1};
int dy[]={-1,1,0,0,-1,-1,1,1};
char str[][4]={"L","R","D","U","LD","LU","RD","RU"};
struct node
{
	int x,y;
	node(){}
	node(int a,int b):x(a),y(b){}
}st,en;
node pre[maxn][maxn];
bool check(int a,int b)
{
	return 1 <= a && a <= 8 && 1 <= b && b <= 8;
}
void bfs()
{
	queue <node> Q;
	Q.push(st);
	memset(d,-1,sizeof(d));
	memset(ch,-1,sizeof(ch));
	d[st.x][st.y] = 0;
	while(!Q.empty())
	{
		node n = Q.front();
		Q.pop();
		for(int i = 0;i < 8;i++)
		{
			int x = n.x + dx[i],y = n.y + dy[i];
			if(check(x,y) && (d[x][y] == -1 || d[x][y] > d[n.x][n.y] + 1))
			{
				d[x][y] = d[n.x][n.y] + 1;
				pre[x][y] = n;
				ch[x][y] = i;
				Q.push(node(x,y));
			}	
		}
	}
}
int main()
{
	char opt[10];
	scanf("%s",opt);
	st = node(opt[0]-'a'+1,opt[1]-'0');
	scanf("%s",opt);
	en = node(opt[0]-'a'+1,opt[1]-'0');
	swap(st.x,st.y);
	swap(en.x,en.y);
	bfs();
	printf("%d\n",d[en.x][en.y]);
	int num = ch[en.x][en.y];
	node tp = en;
	while(num != -1)
	{
		printf("%s\n",str[num]);
		tp = pre[tp.x][tp.y];
		num = ch[tp.x][tp.y];
	}
}
