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
        int a, b;
        cin >> a >> b;
        int sa = sqrt(a), sb = sqrt(b);
        int ans = sb - sa + 1;
        if(sa * sa < a) ans--;
        cout << ans << endl;
    }
    return 0;
}
