#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	int n, st;
	int cnt;
	int cur, nxt;
	while (T--) {
		cin >> n;
		cnt = 0;
		vector<int>project(n + 1);
		vector<int>degree(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> project[i];
			degree[project[i]]++;
		}
		queue<int>q;
		for (int i = 1; i <= n; ++i) {
			if (!degree[i]) {
				q.push(i);
				cnt++;
			}
		}
		while (!q.empty()) {
			cur = q.front();
			nxt = project[cur];
			q.pop();
			degree[nxt]--;
			if (!degree[nxt]) {
				q.push(nxt);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}