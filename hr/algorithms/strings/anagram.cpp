#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char ab[10005];
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", ab);
        int l = strlen(ab);
        if(l % 2) {
            puts("-1");
        }
        else {
            int cnt[30] = {0};
            for(int i = 0; i < l / 2; i++) {
                cnt[ab[i]-'a']++;
                cnt[ab[i+l/2]-'a']--;
            }
            int ans = 0;
            for(int i = 'a'; i <= 'z'; i++) {
                if(cnt[i-'a']>0) {
                    ans += cnt[i-'a'];
                }
            }
            printf("%d\n", ans);
        }
    }
}
