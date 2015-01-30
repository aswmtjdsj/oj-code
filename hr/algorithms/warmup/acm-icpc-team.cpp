#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector <string> member(n);
    for(auto &i: member) {
        cin >> i;
    }
    int maxx = -1, ans = 0;
    for(int i = 0; i < member.size(); i++) {
        for(int j = i + 1; j < member.size(); j++) {
            string temp = member[i];
            int _ = 0;
            for(int k = 0; k < temp.size(); k++) {
                if(member[i][k] == '1' || member[j][k] == '1') {
                    _++;
                }
            }
            if(_ > maxx) {
                maxx = _;
                ans = 1; 
            } else if(_ == maxx) {
                ans++;
            }
        }
    }
    cout << maxx << '\n' << ans << endl;
    return 0;
}
