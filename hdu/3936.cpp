#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 4
using namespace std;
const long long mod = 1000000007ll;
struct MATRIX
{
    long long num[maxn][maxn];
    int x,y;
    void init()
    {
        for(int i = 1;i <= x;i++)
            for(int j = 1;j <= y;j++)
                num[i][j] = 0;
    }
    MATRIX(){}
    MATRIX(const MATRIX& p)
    {
        x = p.x;
        y = p.y;
        for(int i = 1;i <= x;i++)
            for(int j = 1;j <= y;j++)
                num[i][j] = p.num[i][j];
    }
    MATRIX operator *(const MATRIX &a)
    {
        MATRIX b;
        b.x = x;
        b.y = a.y;
        for(int i = 1;i <= b.x;i++)
            for(int j = 1;j <= b.y;j++)
            {
                long long temp = 0;
                for(int k = 1;k <= a.x;k++)
                {
                    temp += (num[i][k] * a.num[k][j])%mod;
                    temp %= mod;
                }
                b.num[i][j] = temp % mod;
            }
        return b;
    }
}unit;
MATRIX operator ^(const MATRIX &a,long long mi)
{
    if(mi==0)
        return unit;
    MATRIX temp = a ^ (mi / 2);
    temp = temp * temp;
    if(mi%2)
        temp = temp * a;
    return temp;
}

int main()
{
    int n;
    unit.x = unit.y = 2;
    unit.num[1][1] = unit.num[2][2] = 1;
    unit.num[1][2] = unit.num[2][1] = 0;
    MATRIX ext,f;
    ext.x = 2;
    ext.y = 2;
    ext.num[1][1] = ext.num[1][2] = ext.num[2][1] = 1;
    ext.num[2][2] = 0;
    f.x = 2;
    f.y = 2;
    f.num[1][1] = f.num[2][1] = 1;
    f.num[1][2] = f.num[2][2] = 0;
    while(scanf("%d",&n) == 1)
    {
        long long l,r;
        for(int i = 0;i < n;i++)
        {
            scanf("%I64d %I64d",&l,&r);
            MATRIX L,R;
            long long sl,sr;
            if(l == 1)
                sl = 0;
            else
            {
                L = (ext ^ (2*(l-1)+1-2)) * f;
                sl = (L.num[1][1] * L.num[2][1])%mod;
            }
            R = (ext ^ (2*r+1 - 2)) * f;
            sr = (R.num[1][1] * R.num[2][1]) % mod;
            //cout << "sl " << sl << endl;
            //cout << "sr " << sr << endl;
            printf("%I64d\n",(sr - sl + mod) % mod);
        }
    }
}
