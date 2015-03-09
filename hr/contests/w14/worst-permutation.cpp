#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 100005;
int n, k, a[maxn], ind[maxn];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
        ind[a[i]] = i;
    }
    /*for(int i = 1; i <= n; i++) {
        cout << ind[i] << endl;
    }*/
    if(k >= n) {
        for(int i = 1; i <= n; i++) {
            printf("%d%c", n-i+1, (i==n)?'\n':' ');
        }
    } else {
        int j = n;
        for(int i = 1; i <= k; i++) {
            while(j > 0 && ind[j] == (n-j+1)) {
                j--;
            }
            if(j == 0) break;
            // cout << "H: " << j << endl;
            swap(a[ind[j]], a[n-j+1]);
            ind[a[ind[j]]] = ind[j];
            ind[j] = n-j+1;
        }
        for(int i = 1; i <= n; i++) {
            printf("%d%c", a[i], (i==n)?'\n':' ');
        }
    }

    return 0;
}
