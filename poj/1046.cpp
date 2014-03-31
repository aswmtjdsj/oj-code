#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct point
{
    int x,y,z;
    point(){}
    point(int a,int b,int c):x(a),y(b),z(c){}
    point operator -(point p)
    {
        return point(x - p.x,y - p.y,z - p.z);
    }
    int norm()
    {
        return x * x + y * y + z * z;
    }
    void print()
    {
        printf("(%d,%d,%d)",x,y,z);
    }
}p[17],a;
int main()
{
    for(int i = 0;i < 16;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        p[i] = point(a,b,c);
    }
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c) == 3 && (~a || ~b || ~c))
    {
        point now = point(a,b,c);
        point MMM = point(266,266,266);
        for(int i = 0;i < 16;i++)
            if((MMM - now).norm() > (p[i] - now).norm())
                MMM = p[i];
        now.print();
        printf(" maps to ");
        MMM.print();
        puts("");
    }
}
