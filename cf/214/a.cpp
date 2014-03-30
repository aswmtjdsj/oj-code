#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 0;i * i <= n;i++)
        for(int j = 0;j * j <= m;j++)
        {
            if(i * i + j == n && i + j * j == m)
                ans++;
        }
    cout << ans << endl;
}
