#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) {
        string p;
        cin >> p;
        int l = p.size();
        int cur = 0;
        int ans = 0;
        for(int i = 0; i < l; i++) {
            if(cur == 0) {
                if(p[i] == 'A') cur = 1;
                else if(p[i] == 'B') cur = 2;
            } else if(cur == 1) {
                if(p[i] == 'A') ans++;
                else if(p[i] == 'B') cur = 2;
            } else {
                if(p[i] == 'A') cur = 1;
                else if(p[i] == 'B') ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
