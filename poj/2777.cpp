/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#define see(x) cerr << " LINE " << __LINE__ << ":" << #x << " : " << x << endl
#define SP system("pause")
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
#define maxn 100000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
#define PB push_back
struct segtree
{
    int l,r,c;
}st[maxn * 4];
int h;
void make(int x,int l,int r)
{
    st[x].l = l;
    st[x].r = r;
    st[x].c = 1;
    if(l < r)
    {
        int mid = (l + r) >> 1;
        make(left(x),l,mid);
        make(right(x),mid + 1,r);
    }
}
void update(int x,int l,int r,int c)
{
    if(l <= st[x].l && st[x].r <= r)
        st[x].c = c;
    else
    {
        if(st[x].c != -1)
        {
            st[left(x)].c = st[x].c;
            st[right(x)].c = st[x].c;
            st[x].c = -1;
        }
        if(l <= st[left(x)].r)
            update(left(x),l,r,c);
        if(r >= st[right(x)].l)
            update(right(x),l,r,c);
    }
}
int trs(int x)
{
    return 1 << (x - 1);
}
void search(int x,int l,int r)
{
    if(st[x].c > 0)
        h |= trs(st[x].c);
    else
    {
        if(l <= st[left(x)].r)
            search(left(x),l,r);
        if(r >= st[right(x)].l)
            search(right(x),l,r);
    }
}
int main()
{
    int l,t,o;
    scanf("%d%d%d",&l,&t,&o);
    int ans;
    make(1,1,l);
    for(int j = 0;j < o;j++)
    {
        char opt;
        int a,b,c;
        scanf(" %c",&opt);
        if(opt == 'C')
        {
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
        else
        {
            scanf("%d%d",&a,&b);
            h = 0;
            search(1,a,b);
            ans = 0;
            for(int i = 1;i <= 30;i++)
                if((h >> (i - 1)) & 1)
                    ans++;
            printf("%d\n",ans); 
        }
    }
}
