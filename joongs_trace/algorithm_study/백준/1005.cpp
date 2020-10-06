#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int T, N, K, X, Y, W;
	cin >> T;
	int result;

	while (T--) {
		cin >> N >> K;
		vector<int>build_time(N + 1, 0);
		vector<int>* adj = new vector<int>[N+1];
		vector<int>indeg(N + 1, 0);
		result = 0;
		for (int i = 1; i <= N; ++i) cin >> build_time[i];
		for (int i = 0; i < K; ++i) {
			cin >> X >> Y;
			adj[X].push_back(Y);
			
		}
		cin >> W;
		
		queue<int>q;
		for (int i = 1; i <= N; ++i) {
			if (indeg[i] == 0) {
				if (i == W) {
					result = build_time[i];
					while (!q.empty()) q.pop();
					break;
				}
				q.push(i);
			}
		}
		int f;
		int ad;
		while (!q.empty()) {
			f = q.front();
			q.pop();
			result += build_time[f];
			if (f == W) break;
			for (int i = 0; i < adj[f].size(); ++i) {

			}
		}
		cout << result << '\n';
		delete[]adj;
	}
	return 0;
}