/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * use int type to store data
 * O(n) input to find the left-down-most point
 * O(nlogn) sort using polar order by vector product(not atan...)
 * O(n) graham scan(cancel the common-in-line point)
 * O(n) rotating calipers
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn (50000 + 5)
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
int n,head;
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
    point operator -(const point &q)
    {
        return point(x - q.x,y - q.y);
    }
    int operator *(const point &q)
    {
        return x * q.x + y * q.y;
    }
    int operator ^(const point &q)
    {
        return x * q.y - y * q.x;
    }
    int norm()
    {
        return x * x + y * y;
        //return sqrt((double)x * x + y * y);
    }
}c,p[maxn],stack[maxn];
int comp(double a)
{
    if(fabs(a) < eps)
        return 0;
    else if(a > eps)
        return 1;
    else
        return -1;
}
int product(point a,point b,point o)
{
    return (b - o) ^ (a - o);
}
bool cmp1(point a,point b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);//comp(a.y - b.y) < 0 || (comp(a.y - b.y) == 0 && comp(a.x - b.x) < 0);
}
bool cmp2(point a,point b)
{
    return product(a,b,c) < 0 || (product(a,b,c) == 0 && (a - c).norm() < (b - c).norm());
    /*double t1 = atan2((double)a.y - c.y,(double)a.x - c.x),t2 = atan2((double)b.y - c.y,(double)b.x - c.x);
      return comp(t1 - t2) < 0 || (comp(t1 - t2) == 0 && (a-c).norm() < (b -c).norm());//comp((a - c).norm() - (b - c).norm()) < 0);*/
}
void scan()
{
    head = 1;
    stack[0] = p[0];
    stack[1] = p[1];
    for(int i = 2;i < n;i++)
    {
        while(head >= 1 && product(p[i],stack[head],stack[head - 1]) <= 0)
            head--;
        stack[++head] = p[i];
    }
}
double rc()
{
    int size = head + 1;
    int q = 1;
    int ans = 0;
    stack[size] = stack[0];
    for(int p = 0;p < size;p++)
    {
        while(product(stack[q + 1],stack[p + 1],stack[p]) > product(stack[q],stack[p + 1],stack[p]))//comp(product(stack[q + 1],stack[p + 1],stack[p]) - product(stack[q],stack[p + 1],stack[p])) > 0)
            q = (q + 1) % size;
        ans = max(ans,max((stack[p] - stack[q]).norm(),(stack[p + 1] - stack[q + 1]).norm()));
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n) == 1)
    {
        int mark = 0;
        for(int i = 0;i < n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            p[i] = point(a,b);
            if(!i)
                c = p[i];
            else
            {
                if(cmp1(p[i],c))
                {
                    c = p[i];
                    mark = i;
                }
            }
        }
        p[mark] = p[0];
        p[0] = c;
        sort(p + 1,p + n,cmp2);
        scan();
        int ans = rc();
        printf("%d\n",ans);
    }
}
