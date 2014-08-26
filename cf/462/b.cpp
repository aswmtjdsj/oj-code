#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long cnt[30];
char biu[100005];
int main() {
	long long n, k;
	cin >> n >> k;
	memset(cnt, 0, sizeof(cnt));
	cin >> biu;
	int len = strlen(biu);
	for(int i = 0; i < len; i++) {
		cnt[biu[i] - 'A']++;
	}
	sort(cnt, cnt + 26);
	/*for(int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
	cout << endl;*/
	long long ans = 0;
	for(int i = 25; i >= 0; i--) {
		if(cnt[i] < k) {
			ans += cnt[i] * cnt[i];
			k -= cnt[i];
		}
		else {
			ans += k * k;
			k = 0;
			break;
		}
	}
	cout << ans << endl;
}
