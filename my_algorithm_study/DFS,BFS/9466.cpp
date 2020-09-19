#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	int n, st, cur;
	int cnt;
	while (T--) {
		cin >> n;
		cnt = 0;

		vector<bool>visit(n+1, false);
		vector<int>project(n + 1);

		for (int i = 1; i <= n; ++i) cin >> project[i];
		cout << cnt << '\n';
	}

	return 0;
}