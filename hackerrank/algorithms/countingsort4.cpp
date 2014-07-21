#include <cstdio>
#include <vector>

using namespace std;

#define maxn 1000005
#define maxl 12
#define maxx 102

int tot, n;
vector<vector<int> > st;

char s[maxn][maxl];

int main() {

    tot = 0;
    st.clear();
    st.resize(100);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int b;
        scanf("%d %s", &b, s[i]);
        st[b].push_back(i);
    }
    bool mark = false;
    for(int i = 0; i < 100; i++) {
        for(auto idx = st[i].begin(); idx != st[i].end(); idx++) {
            int p = *idx;
            if(mark) {
                printf(" ");
                mark = false;
            }
            if(p < n/2) {
                printf("-");
            }
            else {
                printf("%s", s[p]);
            }
            if(idx + 1 == st[i].end()) {
                mark = true;
            }
            else {
                printf(" ");
            }
        }
    }
    puts("");
}
