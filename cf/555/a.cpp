#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;
pair <int, int> num[maxn];
int main() {
    int n, k;
    scanf(" %d %d", &n, &k);
    int cnt = 0;
    int ans = 0;
    ans += n - 1;
    for(int i = 0; i < k; i++) {
        int m;
        scanf(" %d", &m);
        ans += m - 1;
        for(int j = 0; j < m; j++) {
            int o;
            scanf(" %d", &o);
            num[cnt++] = make_pair(o, i);
        }
    }
    sort(num, num + n);
    int first = -1;
    bool sub = true;
    for(int i = 0; i < n - 1; i++) {
        if(first != -1 && first != num[i].second) {
            sub = false;
        }
        if(num[i].second == num[i+1].second) {
            if(sub) {
                ans -= 2;
            }
        }
        if(first == -1) {
            first = num[i].second;
        }
    }
    cout << ans << endl;
}
