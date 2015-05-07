#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    string from, to;
    cin >> n;
    
    cin >> from >> to;
    
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int a = from[i] - '0', b = to[i] - '0';        
        int c = abs(a - b), d = min(a, b) + 10 - max(a, b);
        ans += min(c, d);
    }
    cout << ans << endl;
}
