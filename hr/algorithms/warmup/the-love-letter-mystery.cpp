#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string in;
        cin >> in;
        int l = in.size();
        int p = l / 2, q = p;
        if(l%2==0)p--;
        int ans = 0;
        while(true) {
            if(p < 0) break;
            if(in[p] != in[q]) {
                ans += abs(in[p] - in[q]);
            }
            p--;
            q++;
        }
        cout << ans << endl;
    }
    return 0;
}
