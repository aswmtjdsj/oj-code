#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-9;
#define maxn 302
int comp(double x)
{
    return (fabs(x) < eps?0:x<-eps?-1:1);
}
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
    point operator - (const point &p)
    {
        return point(x - p.x,y - p.y);
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }
}p[maxn];
double d[maxn][maxn] = {0.0};
int n;
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        double x,y;
        scanf("%lf %lf",&x,&y);
        p[i] = point(x,y);
    }
    //puts("AA");
    double sum = 0.0;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
            d[i][j] = d[j][i] = (p[i] - p[j]).norm();
    /*for(int i = 0;i < n;i++)
      for(int j = 0;j < n;j++)
      printf("%.8lf%c",d[i][j],j==n-1?'\n':' ');*/
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
        {
            bool flag = false;
            for(int k = 0;k < n;k++)
            {
                if(i == k || k == j)
                    continue;
                /*cout << i << ' ' << j << endl;
                  printf("%.10lf\n",d[i][j]);
                  cout << i << ' ' << k << ' ' << j << endl;
                  printf("%.10lf\n",d[i][k] + d[k][j]);*/
                if(comp(d[i][j] - d[i][k] - d[k][j]) == 0)
                {   
                    flag = true;
                    break;
                }
            }
            if(!flag)
                sum += d[i][j];
        }
    printf("%.0lf\n",floor(sum + 0.5 + eps));
    //cout << floor(sum+0.5 + eps) << endl;
}