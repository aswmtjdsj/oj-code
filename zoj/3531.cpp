#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 11
#define hashsize (6400013)
#define maxm (hashsize + 10)
int ans;
const int inf = 1 << 30;
char mst[maxn][maxn];
int vis[maxm];
int cas;
int tot;
struct HASH
{
    int x,step;
    HASH(){}
    HASH(int _x,int _s):x(_x),step(_s){}
}h[maxm];
inline int find(int x)
{
    int z = x % hashsize;
    return vis[z] == cas?h[z].step:-1;
}
inline void insert(int x,int value)
{
    int z = x % hashsize;
    vis[z] = cas;
    h[z] = HASH(x,value);
}
inline void update(int x,int value)
{
    int z = x % hashsize;
    h[z].step = value;
}
struct node
{
    int x,y;
    node(){}
    node(int a,int b):x(a),y(b){}
    bool operator ==(const node p)
    {
        return x == p.x && y == p.y;
    }
}pa,pb,en[2],ki,pc[6];
int r,c;
int pcs;
char dir;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char rd[] = {'N','S','W','E'};
int co(char _d)
{
    for(int i = 0;i < 4;i++)
        if(rd[i] == _d)
            return i;
}
int hash(int _d,node p[],bool gd[])
{
    int x = 0;
    for(int i = 0;i < pcs;i++)
        if(gd[i])
            x |= (1 << i);
    int idx = 100;
    for(int i = 2;i >= 0;i--)
    {
        x += idx * p[i].x;
        idx *= 10;
        x += idx * p[i].y;
        idx *= 10;
    }
    x += (_d + 1) * idx;
    return x;
}
inline bool check(int x,int y)
{
    return 0 <= x && x < r && 0 <= y && y < c && mst[x][y] != 'R';
}
void bfs()
{
    queue <int> Q;
    bool gd[6];
    for(int i = 0;i < pcs;i++)
        gd[i] = true;
    node p[3];
    p[0] = ki;
    p[1] = pa;
    p[2] = pb;
    int s = hash(co(dir),p,gd);
    //cout << s << endl;
    if(find(s) == -1)
        insert(s,0);
    Q.push(s);
    //cout << s << endl;
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        //cout << now << endl;
        int step = find(now);
        int idx = 100000000;
        int tdir = now / idx - 1;
        now -= (tdir+1) * idx;
        idx /= 10;
        //cout << now << endl;
        for(int i = 0;i < 3;i++)
        {
            p[i].y = now / idx;
            now -= p[i].y * idx;
            idx /= 10;
            p[i].x = now / idx;
            now -= p[i].x * idx;
            idx /= 10;
        }
        //cout << now << endl;
        int x,y;
        x = p[0].x + dx[tdir];
        y = p[0].y + dy[tdir];
        if(!check(x,y))
        {
            x = p[0].x;
            y = p[0].y;
            tdir ^= 1;
        }
        node tk = node(x,y);
        for(int i = 0;i < 4;i++)
        {
            bool dg[6] = {0};
            int ax = p[1].x + dx[i],ay = p[1].y + dy[i];
            int bx = p[2].x + dx[i^1],by = p[2].y + dy[i^1];
            if(!check(ax,ay) ||  node(ax,ay) == p[0] || node(ax,ay) == p[2])//they can stay in the same point???
                continue;
            if(!check(bx,by) || node(bx,by) == p[0] || node(bx,by) == node(ax,ay))
            {
                bx = p[2].x;
                by = p[2].y;
            }
            int what = 0;
            for(int j = 0;j < pcs;j++)
                if(((now >> j) & 1) && !(node(ax,ay) == pc[j]))
                {   
                    dg[j] = 1;
                    what |= 1 << j;
                }
            node q[3];
            q[0] = tk;
            q[1] = node(ax,ay);
            q[2] = node(bx,by);
            int ano = step + 1;
            if((en[0] == q[1] && en[1] == q[2]) || (en[0] == q[2] && en[1] == q[1]))
            {
                if(what == 0)
                    ans = min(ano,ans);
                else
                    continue;
            }
            if(q[0] == q[1] || q[0] == q[2])
                continue;
            int temp = hash(tdir,q,dg);
            int comp = find(temp);
            if(comp == -1 || comp > ano)
            {
                if(comp == -1)
                    insert(temp,ano);
                else
                    update(temp,ano);
                Q.push(temp);
            }
        }
    }
    printf("%d\n",ans == inf?-1:ans);
}
int main()
{
    cas = 0;
    while(scanf("%d %d",&r,&c) == 2)
    {
        cas++;
        int end = 0;
        pcs = 0;
        tot = 0;
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
            {
                char opt;
                scanf(" %c",&opt);
                mst[i][j] = opt;
                switch(opt)
                {
                    case 'A':
                        pa = node(i,j);
                        break;
                    case 'B':
                        pb = node(i,j);
                        break;
                    case 'K':
                        ki = node(i,j);
                        break;
                    case 'E':
                        en[end++] = node(i,j);
                        break;
                    case 'M':
                        pc[pcs++] = node(i,j);
                        break;
                }
            }
        ans = inf;
        scanf(" %c",&dir);
        bfs();
    }
}
