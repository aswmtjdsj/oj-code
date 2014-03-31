#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=50005;
struct node
{
    int l,r,x,y;
}a[N*4];
int w[N];

void build(int l,int r,int p)
{
    a[p].l=l; a[p].r=r;
    if (l==r)
    {
        a[p].x=a[p].y=w[l];
        return;
    }
    else
    {
        int mid=(l+r)/2;
        build (l,mid,2*p);
        build (mid+1,r,2*p+1);
        a[p].x=min(a[2*p].x,a[2*p+1].x);
        a[p].y=max(a[2*p].y,a[2*p+1].y);
    }
}

void cal(int l,int r,int p,int &x,int &y)
{
    if (l<=a[p].l && r>=a[p].r)
    {
        x=a[p].x; y=a[p].y;
        return;
    }
    int mid=(a[p].l+a[p].r)/2;
    if (r<=mid) cal(l,r,p*2,x,y);
    else if (l>mid) cal(l,r,p*2+1,x,y);
    else
    {
        int x1,y1,x2,y2;
        cal(l,mid,p*2,x1,y1);
        cal(mid+1,r,p*2+1,x2,y2);
        x=min(x1,x2);
        y=max(y1,y2);
    }
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
int main()
{
    int n,m,i,l,r,x,y;
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&w[i]);
    build (1,n,1);
    for (i=1; i<=m; i++)
    {
        scanf("%d%d",&l,&r);
        cal(l,r,1,x,y);
        print(y - x);
        puts("");
    }
}
