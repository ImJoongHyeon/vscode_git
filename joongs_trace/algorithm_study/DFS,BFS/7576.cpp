#include<iostream>
#include<queue>

using namespace std;

int y[4] = { 1, -1, 0, 0 };
int x[4] = { 0, 0, 1, -1 };
int** tomato;

int main() {
	int M, N; cin >> M >> N;
	int X, Y, cnt;
	int nxt_x, nxt_y;
	queue<pair<pair<int, int>, int>>q;

	tomato = new int*[N];
	for (int i = 0; i < N; ++i) tomato[i] = new int[M];
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) q.push({{ i, j }, 0});
		}
	}

	while (!q.empty()) {
		Y = q.front().first.first; X = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			nxt_y = Y + y[i];
			nxt_x = X + x[i];
			if (nxt_y >= 0 && nxt_x >= 0 && nxt_y < N && nxt_x < M) {
				if (tomato[nxt_y][nxt_x] == 0) {
					tomato[nxt_y][nxt_x] = 1;
					q.push({ {nxt_y, nxt_x}, cnt + 1 });
				}
			}
		}
	}

	bool check = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tomato[i][j] == 0) check = false;
		}
		if (!check) break;
	}

	if (check) cout << cnt;
	else cout << -1;

	for (int i = 0; i < N; ++i) delete tomato[i];
	delete[] tomato;
	return 0;
}