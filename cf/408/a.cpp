#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int k[105];
        for(int i = 0; i < n; i ++) {
            cin >> k[i];
        }

        int ans = 100000000;
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = 0; j < k[i]; j++) {
                int biu;
                cin >> biu;
                temp += 5 * biu;
                temp += 15;
            }
            ans = min(ans, temp);
        }
        cout << ans << endl;
    }
}
