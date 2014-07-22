#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 100005
int n, k, v[maxn];

int main() 
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] <= k) {
            k -= v[i];
            ans++;
        }
        else {
            break;
        }
    }
    printf("%d\n", ans);
}
