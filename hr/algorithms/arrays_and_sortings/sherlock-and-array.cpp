#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 100005
int a[maxn];
int l[maxn], r[maxn];
int main() {
    int n, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            l[i] = (i>0?l[i-1]:0) + a[i];
        }
        bool mark = false;
        for(int i = n - 1; i >= 0; i--) {
            r[i] = (i!=n-1?r[i+1]:0) + a[i];
            if((i!=n-1?r[i+1]:0) == (i!=0?l[i-1]:0)) {
                mark = true;
                break;
            }
        }
        if(mark) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
}
