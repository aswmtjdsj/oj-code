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
    bool mark = false;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < cnt[i]; j++) {
            if(mark) {
                printf("%c", ' ');
                mark = false;
            }
            printf("%d", i);
            if(j == cnt[i]-1) {
                mark = true;
            }
            else {
                printf(" ");
            }
        }
    }
    puts("");
}
