#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return (b==0)?a:gcd(b, a%b);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n;
        cin >> n;
        int ans;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            int opt;
            cin >> opt;
            if(i==0) ans = opt;
            else {
                ans = gcd(opt, ans);
                if(ans == 1) {
                    flag = true;
                }
            }
        }
        cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}
