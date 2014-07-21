#include <cstdio>
using namespace std;

int main() {
    int cnt[100] = {0};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    int m = 100;
    for(int i = 0; i < 100; i++) {
        printf("%d%c", cnt[i], i==99?'\n':' ');
    }
}
