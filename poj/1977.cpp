#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
const int mod = 2;

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
                    p %= 2;
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
    int tc;
    scanf("%d",&tc);
    for(int cas = 0;cas < tc;cas++)
    {
        int n, t;
        scanf(" %d %d", &n, &t);
        vector <string> name;
        vector <vector<string> > rel;
        rel.resize(n);
        matrix ans(1, n);
        matrix tr(n, n);
        tr = 0;
        for(int i = 0;i < n;i++)
        {
            string input;
            cin >> input;
            name.push_back(input);
            int value, num;
            scanf("%d %d", &value, &num);
            ans[0][i] = value;
            for(int j = 0;j < num;j++)
            {
                cin >> input;
                rel[i].push_back(input);
            }
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < rel[i].size();j++)
            {
                for(int k = 0;k < n;k++)
                {
                    if(name[k] == rel[i][j])
                    {
                        tr[i][k] = 1;
                        break;
                    }
                }
            }
        }
        for(int i = 0;i < n;i++) tr[i][i] += 1;
        /*for(int i = 0;i < n;i++)
         *                      for(int j = 0;j < n;j++)
         *                                                      printf("%d%c",tr[i][j],j==n-1?'\n':' ');*/
        ans = ans * (tr ^ (t - 1));
        int fin = 0;
        for(int i = 0;i < n;i++) if(ans[0][i]) fin++;
        printf("%d\n", fin);
    }
}
