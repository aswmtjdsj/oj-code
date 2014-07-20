class EmoticonsDiv1 {
public:
	int printSmiles(int smiles) {
		typedef pair<int, pair<int,int> > status;
		queue<status> Q;
		map <pair<int,int>,int> M;
		status a;
		a.first = 0;
		a.second.first = 1;
		a.second.second = 0;
		int ans = smiles;
		M[a.second] = smiles;
		Q.push(a);
		while(!Q.empty()) {
			status cur = Q.front();
			Q.pop();
			if(M[cur.second] != 0 && M[cur.second] <= cur.first) {
				continue;
			}
			else {
				M[cur.second] = cur.first;
			}
			
			if(cur.first < ans) {
				if(cur.second.first <= 0) {
				}
				else if(cur.second.first == smiles) {
					ans = cur.first;
				}
				else if(cur.second.first > smiles) {
					status nn = cur;
					nn.first++;
					nn.second.first--;
					Q.push(nn);
				}
				else {
					status n1 = cur;
					n1.first++;
					n1.second.first += n1.second.second;
					Q.push(n1);
					status n2 = cur;
					n2.first++;
					n2.second.second = n2.second.first;
					Q.push(n2);
					status n3 = cur;
					n3.first++;
					n3.second.first--;
					Q.push(n3);
				}
			}
		}
		return ans;
	}
};
