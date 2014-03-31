#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const double eps=1e-8;
struct P
{
    int x,y;
};
struct L
{
    P p,q;
};

long long xj(P p0,P p1,P p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

void solve(L l1,L l2)
{
    long long s1=xj(l1.p,l1.q,l2.p),s2=xj(l1.p,l1.q,l2.q);
    if (s1==0 && s2==0) {printf("LINE\n"); return;}
    if ((l1.q.x-l1.p.x)*(l2.q.y-l2.p.y)
            ==(l1.q.y-l1.p.y)*(l2.q.x-l2.p.x)) {printf("NONE\n"); return;}
    P a=l1.p,b=l1.q,c=l2.p,d=l2.q;
    double x=(double)((c.y-a.y)*(b.x-a.x)*(d.x-c.x)+a.x*(b.y-a.y)*
            (d.x-c.x)-c.x*(d.y-c.y)*(b.x-a.x))/((b.y-a.y)*(d.x-c.x)
            -(d.y-c.y)*(b.x-a.x));
    double y;
    if (abs(b.x-a.x)>eps) y=(double)((x-a.x)*(b.y-a.y))/(b.x-a.x)+a.y;
    else y=(double)((x-c.x)*(d.y-c.y)/(d.x-c.x)+c.y);
    printf("POINT %.2lf %.2lf\n",x,y);
}

int main()
{
    int o;
    scanf("%d",&o);
    printf("INTERSECTING LINES OUTPUT\n");
    L l1,l2;
    while (o--)
    {
        scanf("%d%d%d%d",&l1.p.x,&l1.p.y,&l1.q.x,&l1.q.y);
        scanf("%d%d%d%d",&l2.p.x,&l2.p.y,&l2.q.x,&l2.q.y);
        solve(l1,l2);
    }
    printf("END OF OUTPUT\n");
}
