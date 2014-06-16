#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int maxn = 1005;
int sgn(double x){return x < -eps?-1:x > eps;}
#define rep(i,j,k) for(int (i) = (j);(i) < (k);(i) ++)
struct matrix
{
    int r,c;
    double v[5][5];
    matrix(){}
    matrix(int a,int b):r(a),c(b)
    {
        rep(i,0,r)
            fill(v[i],v[i] + c,0.0);
        if(r == c)
        {
            rep(i,0,r)
                v[i][i] = 1.0;
        }
    }
    matrix init()
    {
        return matrix(r,c); 
    }
    matrix operator * (const matrix p)
    {
        matrix ans(r,p.c);
        rep(i,0,r)
            rep(j,0,ans.c)
            {
                double tmp = 0.0;
                rep(k,0,c)
                    tmp += v[i][k] * p.v[k][j];
                ans.v[i][j] = tmp;
            }
        return ans;
    }
};
matrix power(matrix a,int n)
{
    matrix e(a.c,a.c);//square matrix of a.c * a.c
    if(n == 0)
        return e;
    matrix ans = power(a,n/2);
    ans = ans * ans;
    return (n%2)?ans * a : ans;
}
struct point
{
    double x,y,z;
    point(){}
    point(double a,double b,double c):x(a),y(b),z(c){}
    void in()
    {
        scanf("%lf %lf %lf",&x,&y,&z);
    }
    void print()
    {
        printf("%.2lf %.2lf %.2lf\n",x + eps,y + eps,z + eps);
    }
}p[maxn];
int n;
point fuck(point now,matrix a)
{
    matrix o(4,1);
    o.v[0][0] = now.x;
    o.v[1][0] = now.y;
    o.v[2][0] = now.z;
    o.v[3][0] = 1.0;
    matrix ans = a * o;
    return point(ans.v[0][0],ans.v[1][0],ans.v[2][0]);
}
char op[20];
matrix dfs(int times)
{
    matrix ans(4,4);
    double v[5];
    int what;
    while(scanf("%s",op) == 1)
    {
        matrix temp(4,4);
        if(op[0] == 'e')
            break;
        else if(op[0] == 'r')
        {
            if(op[1] == 'e')
            {
                scanf("%d",&what);
                temp = dfs(what);
            }
            else
            {
                rep(i,0,4)
                    scanf("%lf",&v[i]);
                double l = 0.0;
                rep(i,0,3)
                    l += v[i] * v[i];
                l = sqrt(l);
                v[3] = v[3] / 180.0 * pi;
                double ct = cos(v[3]),st = sin(v[3]);
                rep(i,0,3)
                    v[i] /= l;
                temp.v[0][0] = (1.0 - ct) * v[0] * v[0] + ct;
                temp.v[0][1] = (1.0 - ct) * v[0] * v[1] - st * v[2];
                temp.v[0][2] = (1.0 - ct) * v[0] * v[2] + st * v[1];
                temp.v[1][0] = (1.0 - ct) * v[1] * v[0] + st * v[2];
                temp.v[1][1] = (1.0 - ct) * v[1] * v[1] + ct;
                temp.v[1][2] = (1.0 - ct) * v[1] * v[2] - st * v[0];
                temp.v[2][0] = (1.0 - ct) * v[2] * v[0] - st * v[1];
                temp.v[2][1] = (1.0 - ct) * v[2] * v[1] + st * v[0];
                temp.v[2][2] = (1.0 - ct) * v[2] * v[2] + ct;
            }
        }
        else if(op[0] == 't')
        {
            rep(i,0,3)
            {
                scanf("%lf",&v[i]);
                temp.v[i][3] = v[i];
            }
        }
        else if(op[0] == 's')
        {
            rep(i,0,3)
            {
                scanf("%lf",&v[i]);
                temp.v[i][i] = v[i];
            }
        }
        ans = temp * ans;
    }
    return power(ans,times);
}
int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        matrix temp(4,4);
        temp = dfs(1) * temp;
        for(int i = 0;i < n;i++)
        {
            p[i].in();
            p[i] = fuck(p[i],temp);
            p[i].print();
        }
        puts("");
    }
}
