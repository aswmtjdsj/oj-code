#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const long long mod = 1000000007ll;
const int R = 2;
const int C = 2;
struct matrix
{
    int r,c;
    long long mat[R+1][C+1];
    matrix(){}
    matrix(int a,int b):r(a),c(b)
    {
        memset(mat,0,sizeof(mat));
    }
    matrix operator *(const matrix p)
    {
        matrix w(r,p.c);
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= p.c;j++)
            {
                long long temp = 0;
                for(int k = 1;k <= c;k++)
                    temp += (mat[i][k] * p.mat[k][j]) % mod;
                w.mat[i][j] = temp % mod;
            }
        return w;
    }
};
matrix modp(matrix a,int p)
{
    matrix w(R,C);
    for(int i = 1;i <= R;i++)
        w.mat[i][i] = 1;
    while(p > 0)
    {
        if(p&1)
            w = w * a;
        a = a * a;
        p >>= 1;
    }
    return w;
}
int main()
{
    /*
     *     need f[0][0]
     *         need transform
     *             ans = transform ^ (n - 1) * f
     *                 during the period % mod
     *                     */
    int t;
    cin >> t;
    while(t--) {
        int a, b, n;
        cin >> a >> b >> n;
        matrix f, t, c;
        f.r = 2;
        f.c = 1;
        f.mat[1][1] = b;
        f.mat[2][1] = a;
        t.r = 2;
        t.c = 2;
        t.mat[1][1] = 1;
        t.mat[2][1] = 1;
        t.mat[1][2] = 1;
        t.mat[2][2] = 0;
        c = modp(t, n-1) * f;
        cout << c.mat[1][1] << endl;
    }
}