#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    long long ans = -1, n, m, k;
    while(cin >> n >> m >> k) {
        ans = -1;
        if(k > n + m - 2) {
            printf("-1\n");
            continue;
        }
        long long nk, mk, ak, bk;
        nk = max(0ll, k - m + 1);
        mk = k - nk;
        //cout << mk << ' ' << nk << endl;
        ak = n/(nk+1);
        bk = m/(mk+1);
        ans = max(ak*bk, ans);
        mk = max(0ll, k - n + 1);
        nk = k - mk;
        //cout << mk << ' ' << nk << endl;
        ak = n/(nk+1);
        bk = m/(mk+1);
        ans = max(ak*bk, ans);
        cout << ans << endl;
    }
    return 0;
}
