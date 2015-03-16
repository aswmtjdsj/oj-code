#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <int> kn;
    kn.clear();
    kn.push_back(1);
    kn.push_back(9);
    for(int i = 10; i <= maxn; i++) {
        long long s = i;
        s *= i;
        string _s = to_string(s), _i = to_string(i);
        string _a = _s.substr(0, _s.size() - _i.size()), _b = _s.substr(_s.size() - _i.size());
        int a = stoi(_a), b = stoi(_b);
        if(a+b == i) {
            kn.push_back(i);
            continue;
        }
        /*_a = _s.substr(0, _i.size()), _b = _s.substr(_i.size());
         *         a = stoi(_a), b = stoi(_b);
         *                 if(a+b == i && i % 10 != 0) {
         *                             kn.push_back(i);
         *                                     }*/
    }

    int p, q;
    cin >> p >> q;
    bool mark = false;
    for(auto i: kn) {
        if(i >= p && i <= q) {
            cout << i << ' ';
            mark = true;
        }
    } 
    if(!mark) {
        cout << "INVALID RANGE" << endl;
    }
    cout << endl;
    return 0;
}

