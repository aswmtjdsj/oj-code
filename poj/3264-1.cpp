#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 50005
#define LL(x) ((x) << 1)
#define RR(x) (LL(x) + 1)
#define lc l , m , LL(k)
#define rc m + 1 , r , RR(k)
using namespace std;
const int inf = ~0u >> 1;
struct ST
{
    int c;
}big[maxn * 4],small[maxn * 4];
int a[maxn],n,q;
void bd1(int l,int r,int k)
{
    if(l == r)
    {
        big[k].c = a[l];
        return ;
    }
    int m = (l + r) >> 1;
    bd1(lc);
    bd1(rc);
    big[k].c = max(big[LL(k)].c,big[RR(k)].c);
}
void bd2(int l,int r,int k)
{
    if(l == r)
    {
        small[k].c = a[l];
        return ;
    }
    int m = (l + r) >> 1;
    bd2(lc);
    bd2(rc);
    small[k].c = min(small[LL(k)].c,small[RR(k)].c);
}
int qr1(int ll,int rr,int l,int r,int k)
{
    if(ll <= l && r <= rr)
        return big[k].c;
    int m = (l + r) >> 1;
    int a = 0,b = 0;
    if(ll <= m)
        a = max(a,qr1(ll,rr,lc));
    if(rr > m)
        b = max(b,qr1(ll,rr,rc));
    return max(a,b);
}
int qr2(int ll,int rr,int l,int r,int k)
{
    if(ll <= l && r <= rr)
        return small[k].c;
    int m = (l + r) >> 1;
    int a = inf,b = inf;
    if(ll <= m)
        a = min(a,qr2(ll,rr,lc));
    if(rr > m)
        b = min(b,qr2(ll,rr,rc));
    return min(a,b);
}
void print(int x)
{
    bool mark = false;
    if(x < 0)
    {
        x = -x;
        mark = true;
    }
    char str[20];
    int cnt = 0;
    do
    {
        str[++cnt] = (x % 10) + '0';
        x /= 10;
    }while(x);
    if(mark)
        putchar('-');
    for(int i = cnt;i>=1;i--)
        putchar(str[i]);
}
char str[100];
int main()
{
    while(gets(str) != NULL)
    {
        if(str[0] != 0)
            break;
    }
    int l = strlen(str);
    int mark = 0;
    n = 0;
    q = 0;
    for(int i = 0;i < l;i++)
    {
        if(str[i] != ' ')
        {
            if(mark == 0)
            {
                n *= 10;
                n += str[i] - '0';
            }
            else
            {
                q *= 10;
                q += str[i] - '0';
            }
        }
        else
            mark++;
    }
    //scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++)
    {
        while(gets(str) != NULL)
            if(str[0] != 0)
                break;
        int l = strlen(str);
        a[i] = 0;
        for(int j = 0;j < l;j++)
        {
            a[i] *= 10;
            a[i] += str[j] - '0';
        }
        //scanf("%d",&a[i]);
    }
    bd1(1,n,1);
    bd2(1,n,1);
    for(int i = 0;i < q;i++)
    {
        int l = 0,r = 0;
        //scanf("%d %d",&l,&r);
        while(gets(str) != NULL)
            if(str[0] != 0)
                break;
        int len = strlen(str);
        mark = 0;
        for(int j = 0;j < len;j++)
        {
            if(str[j] != ' ')
            {
                if(mark == 0)
                {
                    l *= 10;
                    l += str[j] - '0';
                }
                else
                {
                    r *= 10;
                    r += str[j] - '0';
                }
            }
            else
                mark++;
        }
        int low = qr2(l,r,1,n,1),hi = qr1(l,r,1,n,1);
        //printf("%d\n",hi - low);
        print(hi - low);
        puts("");
    }
}
