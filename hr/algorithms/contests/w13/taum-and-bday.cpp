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
        long long b, w, x, y, z, ans;
        cin >> b >> w;
        cin >> x >> y >> z;
        if(x + z < y) {
            ans = x * b + (x + z) * w;
        } else if(y + z < x) {
            ans = (y + z) * b + y * w;
        } else {
            ans = x * b + y * w;
        }
        cout << ans << endl;
    }
    return 0;
}
