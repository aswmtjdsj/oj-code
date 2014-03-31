#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 30
#define maxm 900
struct edge
{
    int p,next;
    edge(){}
    edge(int a,int b):p(a),next(b){}
}e[maxm];
int st[maxn];
int tot;
int n;
void init()
{
    fill(st,st + n + 1,-1);
    tot = 0;
}
void add(int p,int q)
{
    e[tot] = edge(q,st[p]);
    st[p] = tot++;
}
char opt[50];
int color[30];
bool used[30];
int main()
{
    while(scanf("%d",&n) == 1 && n )
    {
        gets(opt);
        init();
        fill(color,color + n + 1,0);
        for(int i = 1;i <= n;i++)
        {
            gets(opt);
            int l = strlen(opt);
            for(int j = 0;j < l;j++)
            {
                if(isupper(opt[j]) && opt[j] - 'A' + 1 != i)
                {
                    int a = opt[j] - 'A' + 1;
                    add(i,a);
                    add(a,i);
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            memset(used,0,sizeof(used));
            if(color[i] == 0)
            {
                color[i] = 1;
                used[1] = true;
            }
            for(int k = st[i];~k;k = e[k].next)
                used[color[e[k].p]] = true;
            int mark = 0;
            for(int k = 1;k <= n;k++)
                if(used[k] == 0)
                    mark = k;
            for(int k = st[i];~k;k = e[k].next)
                if(color[e[k].p] == 0)
                    color[e[k].p] = 1;
                else if(color[i] == color[e[k].p])
                    color[e[k].p] = mark;
        }
        memset(used,0,sizeof(used));
        for(int i = 1;i <= n;i++)
            used[color[i]] = true;
        int ans = 0;
        for(int i = 1;i <= n;i++)
            if(used[i])
                ans++;
        printf("%d channel%sneeded.\n",ans,ans==1?" ":"s ");
    }
}
