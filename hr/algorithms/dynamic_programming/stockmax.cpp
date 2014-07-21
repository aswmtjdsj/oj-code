#include <cstdio>
#include <iostream>
using namespace std;

int a[50005];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int j = 0;
        long long ans = 0;
        while(j < n) {
            int m = j;
            int p = a[j];
            for(int i = j; i < n; i++) {
                if(p < a[i]) {
                    p = a[i];
                    m = i;
                }
            }
            //cout << "P: " << p << endl;
            for(int i = j; i < m; i++) {
                ans += a[m] - a[i];
            }
            j = m+1;
        }
        cout << ans << endl;
    }
    
}
