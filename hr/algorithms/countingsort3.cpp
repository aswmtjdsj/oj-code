#include <cstdio>
using namespace std;

int main() {
    int cnt[100] = {0};
    int sum[100] = {0};
    int n;
    char abc[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf(" %d %s",&a, abc);
        cnt[a]++;
    }
    int m = 100;
    for(int i = 0; i < 100; i++) {
        if(i > 0) {
            sum[i] = sum[i-1] + cnt[i];
        }
        else {
            sum[i] = cnt[i];
        }
        printf("%d%c", sum[i], i==99?'\n':' ');
    }
}
