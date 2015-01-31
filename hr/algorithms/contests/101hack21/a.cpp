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
    for(int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;
        int temp = 0;
        for(int i = 0; i < n; i++) {
            int o;
            cin >> o;
            if(o <= 0) {
                temp++;
            }
        }
        if(temp < k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
