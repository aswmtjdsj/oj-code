#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#define PB push_back
#define sqr(x) ((x) * (x))
using namespace std;
const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
    return fabs(x) < eps ? 0:x < -eps?-1:1;
}
#define maxn 205
#define maxm 50005
int n,m,q;
inline int ab(int x)
{
    return x >= 0?x:-x;
}
struct method
{
    int type;
    int cnt;
    int in[7];
}mth[maxm];
int ans[10];
struct skiplist
{
    int skip[maxm];
    bool tr[maxm];
    void init(int m)
    {
        fill(tr,tr + m,1);
    }
    int jump(int pos)
    {
        if(pos >= m)
            return m;
        return tr[pos]?pos:skip[pos] = jump(skip[pos]);
    }
    int erase(int l,int r)
    {
        int now = jump(l),pos = now;//
        int num = 0;
        while(pos <= r)
        {
            if(tr[pos])
            {
                tr[pos] = false;
                skip[pos] = now;
                pos++;
                num++;
            }
            else
                pos = jump(pos);
        }
        skip[now] = pos;
        return num;
    }
}skip[maxn];
void gao(int row,int le,int ri,int co)
{
    ans[co] += skip[row].erase(le,ri);
}
int main()
{
    while(scanf("%d %d %d",&n,&m,&q) == 3)
    {
        for(int i = 0;i < n;i++)
            skip[i].init(m);
        memset(ans,0,sizeof(ans));
        for(int i = 0;i < q;i++)
        {
            char opt[20];
            int a[10];
            scanf("%s",opt);
            switch(opt[0])
            {
                case 'C':
                    mth[i].type = 1;
                    mth[i].cnt = 4;
                    break;
                case 'D':
                    mth[i].type = 2;
                    mth[i].cnt = 4;
                    break;
                case 'R':
                    mth[i].type = 3;
                    mth[i].cnt = 5;
                    break;
                case 'T':
                    mth[i].type = 4;
                    mth[i].cnt = 4;
                    break;
            }
            for(int j = 0;j < mth[i].cnt;j++)
                scanf("%d",&mth[i].in[j]);
        }
        for(int i = q - 1;i >= 0;i--)
        {
            int hi,lo,le,ri,c,cnt = mth[i].cnt,type = mth[i].type;
            int in[10];
            for(int j = 0;j < cnt;j++)
                in[j] = mth[i].in[j];
            c = in[cnt-1];
            if(mth[i].type == 1)
            {
                hi = max(0,in[0] - in[2]);
                lo = min(n - 1,in[0] + in[2]);
                for(int j = hi;j <= lo;j++)
                {
                    int offset = floor(sqrt(sqr((double)in[2]) - sqr((double)j - in[0])));
                    le = max(0,in[1] - offset);
                    ri = min(m - 1,in[1] + offset);
                    gao(j,le,ri,c);
                }
            }
            else if(mth[i].type == 2)
            {
                hi = max(0,in[0] - in[2]);
                lo = min(n - 1,in[0] + in[2]);
                for(int j = hi;j <= lo;j++)
                {
                    int offset = in[2] - ab(j - in[0]);
                    le = max(0,in[1] - offset);
                    ri = min(m - 1,in[1] + offset);
                    gao(j,le,ri,c);
                }
            }
            else if(mth[i].type == 3)
            {
                hi = in[0];
                lo = min(n - 1,in[0] + in[2] - 1);
                for(int j = hi;j <= lo;j++)
                {
                    le = in[1];
                    ri = min(m - 1,in[1] + in[3] - 1);
                    gao(j,le,ri,c);
                }
            }
            else
            {
                hi = in[0];
                lo = min(n - 1,in[0] + in[2] / 2);
                for(int j = hi;j <= lo;j++)
                {
                    int offset = (in[2] - (j - in[0]) * 2) / 2;
                    le = max(0,in[1] - offset);
                    ri = min(m - 1,in[1] + offset);
                    gao(j,le,ri,c);
                }
            }
        }
        for(int i = 1;i <= 9;i++)
            printf("%d%c",ans[i],i==9?'\n':' ');
    }
}
