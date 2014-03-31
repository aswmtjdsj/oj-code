#include <iostream>
#include <cstdio>
#include <cmath>
#define fang(x) ((x) * (x))
using namespace std;
struct point
{
    int x,y,z;
    void read()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
    void put()
    {
        printf("(%d,%d,%d)",x,y,z);
    }
}map[16],now;
double dis(point a,point b)
{
    return sqrt((double)fang(a.x - b.x) + fang(a.y - b.y) + fang(a.z - b.z));
}
int main()
{
    for(int i = 0;i < 16;i++)
        map[i].read();
    while(1)
    {
        now.read();
        if(now.x == -1 && now.y == -1 && now.z == -1)
            break;
        double min = 10000;
        int ans = 0;
        for(int i = 0;i < 16;i++)
        {
            if(min > dis(now,map[i]))
            {
                min = dis(now,map[i]);
                ans = i;
            }
        }
        now.put();
        printf(" maps to ");
        map[ans].put();
        printf("\n");
    }
}
