#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-10;
inline double sqr(double x){return x * x;}
struct point
{
    double x,y,z;
    void input()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
}p[50];
struct vect//矢量定义
{
    double x,y,z,mod;
    void init(point p,point q) //矢量初始化并计算模长
    {
        x = q.x - p.x;
        y = q.y - p.y;
        z = q.z - p.z;
        mod = sqrt(sqr(x) + sqr(y) + sqr(z));
    }
    double cal()//对于速度矢量进行计算速率
    {
        return mod = sqrt(sqr(x) + sqr(y) + sqr(z));
    }   
}vec[50],v[50]; //位移矢量和速度矢量
double scalar(vect a,vect b) //点积
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
void function(double a,double b,double c,bool &mark,double &k1,double &k2)
{ //求解二次方程专用函数
    double det = sqr(b) - 4.0 * a * c; //delta
    if(det < eps && fabs(det) > eps) //delta<0则无解，无解即对应题目中无解情况
    {
        mark = false;
        return ;
    }
    else if(fabs(det) < eps) //唯一解
    {
        mark = true;
        k1 = k2 = -b / (2.0 * a);
        return ;
    }
    else //二解的话一正解一负解舍弃负解即可（貌似最后算出来delta都等于0？我没测试，大概吧。。。我甚至没去手工模拟一下负解所对应的实际情况是怎样的，就直接否决了，因为负解一定不会符合题意，根据我方程的参数即可知道）
    {
        mark = true;
        k1 = (-b - sqrt(det)) / (2.0 * a);
        k2 = (-b + sqrt(det)) / (2.0 * a);
        return ;
    }
}
void solve(int n)
{
    double m,m1,mt,m0,v0,k,t = 0.0,temp;
    int i;
    scanf("%lf%lf%lf%lf",&m,&m1,&m0,&v0);
    p[0].x = p[0].y = p[0].z = 0.0;
    for(i = 1;i <= n;i++)
    {
        p[i].input();
        vec[i - 1].init(p[i - 1],p[i]); //位移矢量初始化
    }
    //p[0] //对于原点处速度矢量和第一段距离的时间的求解
    /*
       0 = (M-m0)*Vx - m0*V0x //其实可以列一个三元一次方程组用行列式解，我嫌麻烦
       0 = (M-m0)*Vy - m0*V0y //也可以用纯几何的点积叉积做，我不会~算了~
       0 = (M-m0)*Vz - m0*V0z
       (Vx,Vy,Vz) = k * (Vecx,Vecy,Vecz) //求解对象即为k，因为速度矢量方向确定，但是大小不确定，解出大小即可
       V0x^2 + V0y^2 + V0z^2 = V0^2 //V0作为已知量，要做好未知量的化归转化，才方便求出可行解
       t0 = |Vec0| / |V[0]| //标量除法
       t += t0
       */
    mt = m - m0; //第一次后剩余质量
    k = sqrt(sqr(m0) * sqr(v0) / sqr(mt) / sqr(vec[0].mod));
    v[0].x = k * vec[0].x;
    v[0].y = k * vec[0].y;
    v[0].z = k * vec[0].z;
    temp = vec[0].mod / v[0].cal();
    t += temp;
    //对于一般点处，求解一般方程
    /*
       ti = |Veci| / |V[i]|
       Mt * Vx[i - 1] = (Mt - m0) * Vx[i] + m0 * V0x
       Mt * Vy[i - 1] = (Mt - m0) * Vy[i] + m0 * V0y
       Mt * Vz[i - 1] = (Mt - m0) * Vz[i] + m0 * V0z
       V[i](x,y,z) = k * Vec[i](x,y,z)
       V0x^2 + V0y^2 + V0z^2 = V0^2
       k^2*|Vec[i]|^2*(Mt-m0)^2 - 2*Mt(Mt-m0)*k*(scalar(Vec[i],V[i-1])) + Mt^2*|V[i-1]|^2 - m0^2*|V0|^2 = 0
       */
    for(i = 1;i < n;i++)
    {
        double k1,k2;
        double a,b,c;
        bool mark = true;
        a = sqr(vec[i].mod) * sqr(mt - m0);
        b = -2.0 * mt * (mt - m0) * scalar(vec[i],v[i - 1]);
        c = sqr(mt) * sqr(v[i - 1].cal()) - sqr(m0) * sqr(v0);
        function(a,b,c,mark,k1,k2); 
        if(mark)
        {
            /*see(k1);
              see(k2);*/
            if(k1 > 0)
                k = k1;
            if(k2 > 0)
                k = k2;
            v[i].x = k * vec[i].x;
            v[i].y = k * vec[i].y;
            v[i].z = k * vec[i].z;
            temp = vec[i].mod / v[i].cal();
            t += temp;
        }
        else
        {
            printf("Another kind of KKV.\n");
            return ;
        }
        mt = mt - m0;
    }
    printf("%.2lf\n",t);
}
int main()
{
    //freopen("3409.in","r",stdin);
    int n;
    while(scanf("%d",&n) != EOF)
    {
        solve(n);
    }
}
