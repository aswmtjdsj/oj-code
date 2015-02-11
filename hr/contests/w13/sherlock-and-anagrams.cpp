#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int l = s.size();
        int ans = 0;
        for(int i = 0; i < l; i++) {
            for(int k = 1; k <= l; k++) {
                if(i + k > l) break;
                string a = s.substr(i, k);
                sort(a.begin(), a.end());
                for(int j = i + 1; j < l; j++) {
                    if(j + k > l) break;
                    string b = s.substr(j, k);
                    sort(b.begin(), b.end());
                    if(a == b) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
