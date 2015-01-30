#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// It is NOT mandatory to use the provided template. You can handle the IO section differently.

int main() {
    /* The code required to enter n,k, candies is provided*/

    int N, K, unfairness;
    cin >> N >> K;
    int candies[N];
    for (int i=0; i<N; i++)
        cin >> candies[i];
    
    sort(candies, candies + N);
    
    int i = 0, j = 0;
    int ans = 1000000000;
    while(j < N) {
        if(j - i + 1 < K) {
            j++;
        } else if(j - i + 1 == K) {
            ans = min(candies[j] - candies[i], ans);
            i++;
        }
    }
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    cout << ans << "\n";
    return 0;
}
