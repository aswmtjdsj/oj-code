#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#define maxm 3000000
#define maxn 3005
const long long inf = 200000000000000ll;
using namespace std;
struct edge
{
    int p;
    long long val;
    int next;
    edge(){}
    edge(int a,long long b,int c):p(a),val(b),next(c){}
}e[maxm];
int st[maxn];
bool vis[maxn];
long long d[maxn];
int n,p,tot;
char in[255];
int cnt;
void init()
{
    tot = 0;
    memset(st,-1,sizeof(st));
}
void add(int p,int q,long long val)
{
    e[tot] = edge(q,val,st[p]);
    st[p] = tot++;
}
void dij(int s)
{
    memset(vis,0,sizeof(vis));
    for(int i = 1;i < cnt;i++)
        d[i] = inf;
    d[s] = 0;
    for(int i = 1;i < cnt;i++)
    {
        int mark = 1;
        long long MMM = inf;
        for(int j = 1;j < cnt;j++)
            if(!vis[j] && MMM > d[j])
            {
                mark = j;
                MMM = d[j];
            }
        vis[mark] = true;
        for(int k = st[mark];~k;k = e[k].next)
        {
            //puts("fuck");
            int p = e[k].p;
            if(!vis[p] && d[p] > d[mark] + e[k].val)
                d[p] = d[mark] + e[k].val;
        }
    }
}
int tempp[70],fuck;
int main()
{
    int cas = 1;
    while(scanf("%d %d",&p,&n) == 2 && (p || n))
    {
        map <string,int> M;
        init();
        cnt = 1;
        printf("Database %d\n",cas++);
        for(int i = 0;i < p;i++)
        {
            fuck = 0;
            int opt;
            scanf("%d",&opt);
            gets(in);
            istringstream input(in);
            string what = "",temp;
            int flag = 1;
            while(input >> temp)
            {
                if(flag % 2)
                    what += temp;
                else
                {
                    what += temp;
                    if(temp[temp.size() - 1] == ',' || temp[temp.size() - 1] == ':')
                        what = what.substr(0,what.size() - 1);
                    //cout << what << ' ';
                    if(M[what] == 0)
                        M[what] = cnt++;
                    tempp[fuck++] = M[what];
                    //cout << M[what] << endl;
                    what = "";
                    if(temp[temp.size() - 1] == ':')
                        break;
                }
                flag++;
            }
            for(int j = 0;j < fuck;j++)
                for(int k = j + 1;k < fuck;k++)
                {
                    add(tempp[j],tempp[k],opt);
                    add(tempp[k],tempp[j],opt);
                }
        }
        dij(M["Kevin,Bacon"]);
        for(int i = 0;i < n;i++)
        {
            string a,b,c;
            cin >> a >> b;
            c = a + b;
            long long ans = d[M[c]];
            cout << a << ' ' << b << ": ";
            if(ans == inf)
                cout << "infinity" << endl;
            else
                cout << ans << endl;
        }
        puts("");
    }
}
