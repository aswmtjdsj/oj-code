#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = acos(-1.0);
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        double x,y;
        cin >> x>> y;
        double r = sqrt(x*x+y*y);
        double ans=pi*r*r/100.0;
        ans=ceil(ans);
        printf("Property %d: This property will begin eroding in year %.0f.\n",i,ans);
    }
    puts("END OF OUTPUT.");
}
