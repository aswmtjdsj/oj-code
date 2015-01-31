#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int ans=0;
        // Computer answer
        ans += n / c;
        int w = n / c;
        while(true) {
            ans += w / m;
            w = (w / m) + (w % m);
            if(w < m) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
