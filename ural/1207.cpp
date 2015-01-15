#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define maxn 10002
#define sqr(x) ((x) * (x))
const double eps = 1e-10;// cause the max range of coordinate can be 1e9, so when using atan2, we should calc more accurately to judge equality... eg. 1e-10

int dblcmp(double x){return fabs(x) < eps? 0: x < -eps? -1 : 1;}

struct pii
{
    double x, y;
    int id;
    pii(){}
    pii(double _x, double _y, int _id):x(_x), y(_y), id(_id){}
    double norm(){return sqr(x)+sqr(y);}
    bool operator < (pii b){return dblcmp(y-b.y) < 0 || (dblcmp(y-b.y) == 0 && dblcmp(x-b.x) < 0);}
    void read(int i)
    {
        scanf("%lf %lf", &x, &y);
        id = i;
    }
    void put()
    {
        printf("%lf %lf %d\n", x, y, id);
    }
} pt[maxn], low;

bool cmp(pii a, pii b)
{
    double ta = atan2(a.y-low.y, a.x-low.x), tb = atan2(b.y-low.y, b.x-low.x);
    return dblcmp(ta-tb) < 0 || (dblcmp(ta-tb)==0 && a.norm() < b.norm());
}

int n, lowid;

int main()
{
    scanf("%d", &n);
    lowid = -1;
    low = pii(1e9+1, 1e9+1, lowid);
    for(int i = 0;i < n;i++)
    {
        pt[i].read(i+1);
        if(pt[i] < low)
        {
            low = pt[i];
            lowid = i;
        }
    }
    swap(pt[0], pt[lowid]);
    sort(pt + 1, pt + n, cmp);
    for(int i = 0;i < n;i++)pt[i].put();
    int ans[2];
    ans[0] = pt[0].id;
    ans[1] = pt[n/2].id;
    printf("%d %d\n", ans[0], ans[1]);
}
