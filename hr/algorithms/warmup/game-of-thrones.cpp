#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   
    string s;
    cin>>s;
    int cnt[30];
    memset(cnt, 0, sizeof(cnt));
    for(auto i: s) {
        cnt[i-'a']++;
    }
    int fuck = 0;
    int flag = 1;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] % 2 != 0) {
            fuck++;
        }
        if(fuck > 1) {
            flag = 0;
            break;
        }
    }
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
