#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define left l , m , k << 1
#define right m + 1 , r ,k << 1 | 1
const int inf = ~0u >> 1;
#define maxn 1000000
struct ST
{
    int M,m;
}st[maxn << 2];
int val[maxn + 5];
void build(int l,int r,int k)
{
    st[k].M = st[k].m = val[l];
    if(l == r)return ;
    int m = (l + r) >> 1;
    build(left);
    build(right);
    st[k].M = max(st[k << 1].M,st[k << 1 | 1].M);
    st[k].m = min(st[k << 1].m,st[k << 1 | 1].m);
}
int q1(int ll,int rr,int l,int r,int k)
{
    if(ll <= l && rr >= r)
        return st[k].M;
    int m = (l + r) >> 1;
    int a = -inf,b = -inf;
    if(ll <= m)
        a = max(a,q1(ll,rr,left));
    if(rr > m)
        b = max(b,q1(ll,rr,right));
    return max(a,b);
}
int q2(int ll,int rr,int l,int r,int k)
{
    if(ll <= l && rr >= r)
        return st[k].m;
    int m = (l + r) >> 1;
    int a = inf,b = inf;
    if(ll <= m)
        a = min(a,q2(ll,rr,left));
    if(rr > m)
        b = min(b,q2(ll,rr,right));
    return min(a,b);
}
void print(int x)
{
    //cout << x << 'x';
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
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    /*for(int i = 1;i <= n;i++)
      scanf("%d",&val[i]);*/
    getchar();
    int temp = 0,a;
    char opt;
    bool mark = false;
    int cnt = 0;
    while((opt = getchar()) != EOF)
    {
        a = opt - '0';
        if(opt == ' ' or opt == '\r' or opt == '\n')
        {
            val[++cnt] = temp;
            if(mark)
                val[cnt] = -val[cnt];
            mark = false;
            temp = 0;
        }
        else if(opt == '-')
            mark = true;
        else
            temp = temp * 10 + a;
    }
    build(1,n,1);
    for(int i = 1;i <= n;i++)
    {
        //puts("aa");
        int t = min(n,i + m - 1);
        //printf("%d",q2(i,t,1,n,1));
        print(q2(i,t,1,n,1));
        //printf("%c",(t == n)?'\n':' ');
        putchar((t == n)?'\n':' ');
        if(t == n)break;
    }
    for(int i = 1;i <= n;i++)
    {
        int t = min(n,i + m - 1);
        //printf("%d",q1(i,t,1,n,1));
        print(q1(i,t,1,n,1));
        //printf("%c",(t == n)?'\n':' ');
        putchar((t == n)?'\n':' ');
        if(t == n)break;
    }
}
