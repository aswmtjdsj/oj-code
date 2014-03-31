/*
 *    poj 3070
 *       */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
const int mod = 10000;

struct matrix
{
    vector< vector<int> > v;
    int r, c;
    matrix(){}
    matrix(int a, int b):r(a), c(b)
    {
        v.resize(r);
        for(int i = 0;i < r;i++)
            v[i].resize(c);
    }
    vector <int> & operator [](int i)
    {
        return v[i];
    }
    void operator = (int t)
    {
        for(int i = 0;i < r;i++) fill(v[i].begin(), v[i].end(), t);
    }
    matrix operator * (matrix b)
    {
        matrix temp(r, b.c);
        for(int i = 0;i < temp.r;i++)
            for(int j = 0;j < temp.c;j++)
            {
                int p = 0;
                for(int k = 0;k < c;k++)
                {
                    p += v[i][k] * b[k][j];
                    p %= mod;
                }
                temp[i][j] = p;
            }
        return temp;
    }
};
matrix id(int n)
{
    matrix a(n, n);
    for(int i = 0;i < n;i++) a[i][i] = 1;
    return a;
}
matrix operator ^ (matrix a, int n)
{
    if(n == 0)
        return id(a.c);
    matrix ans = a ^ (n/2);
    ans = ans * ans;
    if(n % 2)
        ans = ans * a;
    return ans;
}

int main()
{
    matrix tr(2, 2);
    tr[0][0] = tr[1][0] = tr[0][1] = 1;
    tr[1][1] = 0;
    int n;
    while(scanf("%d",&n) == 1 && n != -1)
    {
        matrix ans = tr ^ n;
        int fuck = ans[1][0];
        printf("%d\n", fuck);
    }
}
