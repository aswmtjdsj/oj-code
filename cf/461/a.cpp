#include <iostream>

using namespace std;
int main() {
	int n;
	char m[105][105];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> m[i];
	}
	bool flag = true;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	for(int i = 0; i < n && flag; i++) {
		for(int j = 0; j < n && flag; j++) {
			int cnt = 0;
			for(int d = 0; d < 4; d++) {
				int a = i + dx[d], b = j + dy[d];
				if(0 <= a && a < n && 0 <= b && b < n) {
					if(m[a][b] == 'o') {
						cnt++;
					}
				}
			}
			if(cnt % 2 != 0) {
				flag = false;
			}
		}
	}
	cout << (flag?"YES":"NO") << endl;
}
