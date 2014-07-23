#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, a[1005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}
