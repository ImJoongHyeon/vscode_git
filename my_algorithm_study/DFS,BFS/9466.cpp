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
		for (int i = 1; i <= n; ++i) cin >> project[i];
		
		for (int i = 1; i <= n; ++i) {
			if(project[i]){
				st = i;
				queue<int>q;
				q.push(i);
				while (!q.empty()) {
					cur = q.front();
					nxt = project[cur];
					q.pop();
					if (st != nxt && cur != nxt) q.push(nxt);
				}
				if (st == nxt) {
					cur = st;
					while (project[cur]) {
						nxt = project[cur];
						project[cur] = 0;
						cur = nxt;
					}
				}
				else cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}