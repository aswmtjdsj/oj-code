#include <iostream>
#include <cstdio>
//#include <cstdlib>
//#include <ctime>
using namespace std;
int n,a[505][505],b[505][505],c[505][505],d[505],d1[505],d2[505];
int main()
{
    scanf("%d",&n);
    //while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&a[i][j]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&b[i][j]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&c[i][j]);
        //srand(time(NULL));
        bool mark = true;
        for(int t = 0;t < 10;t++)
        {
            int ord = n / 2;
            //int ord = rand() % n;
            ord = min(ord + t,n - 1);
            for(int i = 0;i < n;i++)
                d[i] = a[ord][i];
            for(int i = 0;i < n;i++)
            {
                int temp = 0;
                for(int j = 0;j < n;j++)
                    temp += d[j] * a[j][i];
                d1[i] = temp;
            }
            for(int i = 0;i < n;i++)
            {
                int temp = 0;
                for(int j = 0;j < n;j++)
                    temp += d1[j] * b[j][i];
                d2[i] = temp;
            }
            for(int i = 0;i < n;i++)
            {
                int temp = 0;
                for(int j = 0;j < n;j++)
                    temp += d[j] * c[j][i];
                if(temp != d2[i])
                {
                    mark = false;
                    break;
                }
            }
            if(!mark)
                break;
        }
        printf("%s\n",mark?"YES":"NO");
    }
}
