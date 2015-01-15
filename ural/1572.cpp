#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int type,size;
    scanf("%d %d",&type,&size);
    int n;
    scanf("%d",&n);
    int ans = 0;
    double l,w;
    const double eps = 1e-6;
    switch(type)
    {
        case 1:
            l = size * 2;
            break;
        case 3:
            l = size;
            break;
        case 2:
            l = size * sqrt(2.0);
            break;
    }
    for(int i = 0;i < n;i++)
    {
        int t,s;
        scanf("%d %d",&t,&s);
        switch(t)
        {
            case 1:
                w = 2 * s;
                break;
            case 2:
                w = s;
                break;
            case 3:
                w = s * sqrt(3.0) / 2;
                break;
        }
        if(w <= l + eps)
            ans++;
    }
    printf("%d\n",ans);
}