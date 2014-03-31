#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 10002
#define see(x) (cerr << #x << ":" << x << endl)
double s[maxn],last[maxn];
const double pi = acos(-1.0);
const double eps = 1e-6;
int comp(double x)
{
    return fabs(x) < eps?0:x < -eps?-1:1;
}
void gao()
{
    int n;
    int f;
    scanf("%d %d",&n,&f);
    f++;
    double sum = 0,rii;
    for(int i = 0;i < n;i++)
    {
        scanf("%lf",&rii);
        s[i] = rii * rii * pi;
        sum += s[i];
        //see(s[i]);
    }
    double l = 0.0,r = sum /(double) f,mid;
    //see(r);
    while(comp(l - r) < 0)
    {
        int i = 0;
        int cnt = 0;
        mid = (l + r) / 2.0;
        for(int j = 0;j < n;j++)
            last[j] = s[j];
        while(i < n)
        {
            //see(last[i]);
            //see(mid);
            if(comp(last[i] - mid) >= 0)
            {
                cnt++;
                last[i] -= mid;
            }
            else
            {
                //see(i);
                //puts("AA");
                i++;
            }
            if(cnt >= f)
                break;
        }
        //see(cnt);
        //see(mid);
        if(cnt >= f)
            l = mid;
        else
            r = mid;
    }
    printf("%.4lf\n",(l + r) / 2.0);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        gao();
}
