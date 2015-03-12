#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int maxn = 1905;
map <int, int> b[maxn];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, h, i;
    cin >> n >> h >> i;
    for(int i = 0; i < n; i++) {
        b[i].clear();
        int u;
        scanf(" %d", &u);
        int opt;
        for(int j = 0; j < u; j++) {
            scanf(" %d", &opt);
            b[i][opt]++;
        }
    }
    return 0;
}
