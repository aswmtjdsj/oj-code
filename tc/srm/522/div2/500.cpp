/*class BoxesDiv2 {
public:
	int findSize(vector <int> candyCounts) {
		int big_two = 21;
		priority_queue<int, std::vector<int>, std::greater<int> > candy_boxes;
		for(int i = 0; i < len(candyCounts); i++) {
			for(int j = 0; j < big_two; j++) {
				if((1 << j) >= candyCounts[i]) {
					candy_boxes.push((1 << j));
					break;
				}
			}
			int biu = candy_boxes.top();
		}
		cout << "biubiu" << endl;
		while(len(candy_boxes) > 1) {
			int a = candy_boxes.top();
			candy_boxes.pop();
			int b = candy_boxes.top();
			candy_boxes.pop();
			for(int j = 0; j < big_two; j++) {
				if((1 << j) >= a + b) {
					candy_boxes.push((1 << j));
					break;
				}
			}
		}
		int ans = candy_boxes.top();
		candy_boxes.pop();
		cout << ans;
		return ans;
	}
};*/
