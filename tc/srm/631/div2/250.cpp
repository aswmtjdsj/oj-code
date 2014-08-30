
class TaroGrid {
public:
	int getNumber(vector <string> grid) {
		int n = grid.size();
		int ans = 1;
		for(int j = 0; j < n; j++) {
			int cnt = 0;
			char flag = 'W';
			for(int i = 0; i < n; i++) {
				if(grid[i][j] == flag) {
					cnt++;
				}
				else {
					cnt = 1;
					flag = grid[i][j];
				}
				ans = max(ans, cnt);
			}
		}
		return ans;
	}
};
