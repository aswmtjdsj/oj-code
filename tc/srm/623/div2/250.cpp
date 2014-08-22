/*class PT {
public:
	int x, y;
	PT(){}
	PT(int a, int b): x(a), y(b){}
	
};
bool operator <(PT a, PT b) {
	return a.y < b.y;
}
class CatchTheBeatEasy {
public:
	string ableToCatchAll(vector <int> x, vector <int> y) {
		vector < PT > fr;
		int n = x.size();
		for(int i = 0; i < n; i++) {
			fr.PB(PT(x[i],y[i]));
		}
		sort(fr.begin(), fr.end());
		for(int i = 0; i < n; i++) {
			cout << fr[i].x << ' ' << fr[i].y<< endl;
		}
		bool flag = true;
		PT cur(0, 0);
		int past = 0;
		for(int i = 0; i < n; i++) {
			if(abs(fr[i].y - past) >= (abs(fr[i].x - cur.x))) {
				cur.x = fr[i].x;
				past += fr[i].y - past;
			}
			else {
				flag = false;
				break;
			}
			//cout << cur.x << ' ' << past << endl;
		}
		return flag?"Able to catch":"Not able to catch";
	}
};*/
