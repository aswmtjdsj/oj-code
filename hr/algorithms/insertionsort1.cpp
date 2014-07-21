#include <cstdio>

using namespace std;

int main() {
    int n;
    int a[1005];
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int i, p = a[n-1];
    for(i = n - 2; i >= 0; i--) {
        if(p > a[i]) {
            break;
        }
        else {
            a[i+1] = a[i];
        }
        for(int j = 0; j < n; j++) {
            printf("%d%c", a[j], j==n-1?'\n':' ');
        }
    }
    a[i+1] = p;
    for(int j = 0; j < n; j++) {
        printf("%d%c", a[j], j==n-1?'\n':' ');
    }
}
