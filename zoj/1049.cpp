#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
const double det = 50.0;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        double ans = (x * x + y * y) * pi / 2.0;
        printf("Property %d: This property will begin eroding in year %.0lf.\n",i + 1,0.5 + ans / det);
    }
    printf("END OF OUTPUT.\n");
}
