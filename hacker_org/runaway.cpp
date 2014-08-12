string maze = ".....X................X....XX.....X...X....X...X...X........X.XXX........X.X.X..XX.........X..X.X..X.XX.X....X..X..X.XX.X............XX........X..X........X.....XX.XX.XXX.X..X.X.X..XX.......X..X....X..X.X..X...X......XX..X........XXX.........X....XX..XXX..";
	cout << maze.size() << endl;
	int n = sqrt((double)maze.size());
	cout << n << endl;
	vector<string> biu;
	for(int i = 0; i < n; i++) {
		biu.push_back(maze.substr(i*n,n));
	}
	for(int i = 0; i < biu.size(); i++) {
		cout << biu[i] << endl;
	}
	bool op[8]; // 0 for down, 1 for right
	bool flag = false;
	int dx[] = {1, 0}, dy[] = {0, 1};
	for(int i = 6; i <= 10 && !flag; i++) {
		for(int j = 0; j < (1 << i) && !flag; j++) {
			for(int k = 0; k < i; k++) {
				if((j >> k) & 1) {
					op[k] = 1;
				}
				else {
					op[k] = 0;
				}
			}
			int cnt = 0;
			PII pos = MP(0,0);
			bool mark = true;
			while(mark) {
				int d = cnt % i;
				pos.first += dx[op[d]];
				pos.second += dy[op[d]];
				if(pos.second == n) {
					break;
				}
				if(pos.first == n) {
					break;
				}
				if(biu[pos.first][pos.second] == 'X') {
					mark = false;
					break;
				}
				cnt++;
			}
			if(mark) {
				for(int k = 0; k < i; k++) cout << op[k];
				cout << endl;
				flag = true;
			}
		}
	}
