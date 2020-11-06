//#include<iostream>
//#include<queue>
//using namespace std;
//
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	int T[15];
//
//	int P[15];
//	int max_profit = 0;
//	cin >> N;
//	for (int i = 0; i < N; ++i) cin >> T[i] >> P[i];
//	
//	int t, k;
//	queue<pair<int, int>>q;
//	q.push(make_pair(0, 0));
//	while (!q.empty()) {
//		t = q.front().first; k = q.front().second;
//		q.pop();
//		if (t < N) {
//			q.push(make_pair(t + T[t], k + P[t]));
//			q.push(make_pair(t + 1, k));
//		}
//		if (t <= N && k > max_profit) max_profit = k;
//	}
//
//	cout << max_profit;
//
//	return 0;
//}
