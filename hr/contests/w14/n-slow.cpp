#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 200005;
int a[maxn];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            scanf(" %d", &a[i]);
        }
        map <int, long long> c;
        c.clear();
        long long tot = 0;
        for(int l = 1; l <= n; l++) {
            for(int i = 0; i < n; i++) {
                if(i + l > n) break;
                int maxx = 0;
                for(int j = 0; j < l; j++) {
                    maxx = max(maxx, a[i+j]);
                }
                c[maxx]++;
                tot++;
            }
        }
        for(auto x: c) {
            cout << x.first << ' ' << x.second << endl;
            if(x.first <= k) {
                tot -= x.second;
            } else {
                // break;
            }
        }
        cout << tot << endl;
    }
    return 0;
}

