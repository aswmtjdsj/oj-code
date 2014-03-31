#include <iostream>
#include <cmath>
#include <cstdio>
#define see(x) //cerr << " LINE : " << __LINE__ << #x << " : " << x.a << " " << x.b << endl
using namespace std;
struct PII
{
    double a,b;
    PII(){}
    PII(double x,double y):a(x),b(y){}
}x[20],y[20];
int main()
{
    double a,b;
    int t;
    while(scanf("(%lf,%lf)",&a,&b) != EOF)
    {
        char c = getchar();
        t = 0;
        x[t] = PII(a,b);
        see(x[t]);
        while(c == ' ')
        {
            scanf("(%lf,%lf)",&a,&b);
            t++;
            x[t] = PII(a,b);
            see(x[t]);
            c = getchar();
        }
        scanf("(%lf,%lf)",&a,&b);
        t = 0;
        y[t] = PII(a,b);
        c = getchar();
        see(y[t]);
        while(c == ' ')
        {
            scanf("(%lf,%lf)",&a,&b);
            t++;
            y[t] = PII(a,b);
            see(y[t]);
            c = getchar();
        }
        double p;
        scanf("%lf",&p);
        c = getchar();
        double sum = 0,ans;
        for(int i = 0;i <= t;i++)
        {
            double tt = sqrt((x[i].a - y[i].a) * (x[i].a - y[i].a) + (x[i].b - y[i].b) * (x[i].b - y[i].b));
            tt = pow(tt,p);
            sum += tt;
        }
        ans = pow(sum,1.0 / p);
        printf("%.10lf\n",ans);
    }
}
