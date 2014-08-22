class Egalitarianism3Easy {
public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		vector < vector<int> >  graph(n);
		for(int i = 0; i < n; i++) {
			graph[i].resize(n);
			for(int j = 0; j < n; j++) {
				graph[i][j] = 1000000;
			}
			graph[i][i] = 0;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << graph[i][j] << ' ';
			}
			cout << endl;
		}
		int e = a.size();
		for(int i = 0; i < e; i++) {
			a[i]--;
			b[i]--;
			graph[a[i]][b[i]] = len[i];
			graph[b[i]][a[i]] = len[i];
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << graph[i][j] << ' ';
			}
			cout << endl;
		}
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(graph[i][k] + graph[k][j] < graph[i][j]) {
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << graph[i][j] << ' ';
			}
			cout << endl;
		}
		int ans = 0;
		for(int i = 0; i < (1 << n); i++) {
			vector<int> sel;
			for(int j = 0; j < n; j++) {
				if((1 << j) & i) {
					sel.PB(j);
				}
			}
			int num = sel.size();
			bool flag = true;
			int temp = -1;
			for(int p = 0; p < num; p++) {
				for(int q = p + 1; q < num; q++) {
					if(temp == -1) {
						temp = graph[sel[p]][sel[q]];
					}
					else {
						if(temp != graph[sel[p]][sel[q]]) {
							flag = false;
							break;
						}
					}
				}
				if(!flag) {
					break;
				}
			}
			if(flag) {
				ans = max(ans, (int)sel.size());
			}
		}
		return ans;
	}
};
