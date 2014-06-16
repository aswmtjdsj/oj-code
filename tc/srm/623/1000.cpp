/*class ApplesAndPears {
public:
	int getArea(vector <string> board, int K) {
		int n = len(board);
		vector < vector<int> > ve(n), va(n), vp(n);
		for(int i = 0; i < n; i++) {
			ve[i].resize(n);
			va[i].resize(n);
			vp[i].resize(n);
			for(int j = 0; j < n; j++) {
				ve[i][j] = va[i][j] = vp[i][j] = 0;
				if(board[i][j] == '.') {
					ve[i][j] = 1;
				}
				else if( board[i][j] == 'A') {
					va[i][j] = 1;
				}
				else {
					vp[i][j] = 1;
				}
				if(i > 0) {
					ve[i][j] += ve[i-1][j];
					va[i][j] += va[i-1][j];
					vp[i][j] += vp[i-1][j];
				}
				if(j > 0) {
					ve[i][j] += ve[i][j-1];
					va[i][j] += va[i][j-1];
					vp[i][j] += vp[i][j-1];
				}
				if(i > 0 && j > 0) {
					ve[i][j] -= ve[i-1][j-1];
					va[i][j] -= va[i-1][j-1];
					vp[i][j] -= vp[i-1][j-1];
				}
			}
		}
		/*for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << ve[i][j] << (j==n-1?'\n':' ');
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << va[i][j] << (j==n-1?'\n':' ');
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << vp[i][j] << (j==n-1?'\n':' ');
			}
		}*/
		int ze = ve[n-1][n-1], za = va[n-1][n-1], zp = vp[n-1][n-1];
		int ans = 1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int r = 0; r < n; r++) {
					if(i + r >= n) break;
					for(int c = 0; c < n; c++) {
						if(j + c >= n) break;
						int area = (r+1) * (c+1);
						int ia = i + r, jb = j + c;
						int te = ve[ia][jb] - (j>0?ve[ia][j-1]:0) - (i>0?ve[i-1][jb]:0) + ((i>0&&j>0)?ve[i-1][j-1]:0);
						int ta = va[ia][jb] - (j>0?va[ia][j-1]:0) - (i>0?va[i-1][jb]:0) + ((i>0&&j>0)?va[i-1][j-1]:0);
						int tp = vp[ia][jb] - (j>0?vp[ia][j-1]:0) - (i>0?vp[i-1][jb]:0) + ((i>0&&j>0)?vp[i-1][j-1]:0);
						//printf("r:%d-%d c:%d-%d, .: %d, a: %d, p: %d\n", i, i+r, j, j+c, te, ta, tp);

						// for empty
						if(ze - te >= ta + tp && K >= ta + tp) {
							ans = max(ans, area);
						}

						// for apple
						if(za - ta >= te + tp) {
							if(ze > 0 && K >= tp + area - ta) {
								ans = max(ans, area);
							}
							else if(ze == 0 && ta == area) {
								ans = max(ans, area);
							}
						}

						// for pear 
						if(zp - tp >= te + ta) {
							if(ze > 0 && K >= ta + area - tp) {
								ans = max(ans, area);
							}
							else if(ze == 0 && tp == area) {
								ans = max(ans, area);
							}
						}
					}
				}
			}
		}
		return ans;
	}
};*/
