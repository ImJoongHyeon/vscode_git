#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int y[4] = { 1, -1, 0, 0 };
int x[4] = { 0, 0, 1, -1 };
vector<bool>arr[51];
int X, Y;
int cnt;
int M, N, K;

void organic_cabbage(int Y, int X) {
	arr[Y][X] = 0;
	int idx_y, idx_x;
	for (int i = 0; i < 4; ++i) {
		idx_y = Y + y[i]; idx_x = X + x[i];
		if (idx_y < N && idx_y >= 0 && idx_x < M && idx_x >= 0)
			if (arr[idx_y][idx_x]) organic_cabbage(idx_y, idx_x);
	}
}

int main() {
	int T; cin >> T;
	for (int i = 0; i < 51; ++i) arr[i].resize(51, false);
	while (T--) {
		cin >> M >> N >> K;
		while (K--) {
			cin >> X >> Y;
			arr[Y][X] = true;
		}
		cnt = 0;
		//queue<pair<int, int>>q;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j]) {
					/*q.push({ i, j });
					while (!q.empty()) {
						Y = q.front().first;
						X = q.front().second;
						arr[Y][X] = false;
						q.pop();
						for (int k = 0; k < 4; ++k) {
							idx_y = Y + y[k]; idx_x = X + x[k];
							if (idx_y < N && idx_y >= 0 && idx_x < M && idx_x >= 0)
								if (arr[idx_y][idx_x])
									q.push({ Y + y[k], X + x[k] });
						}
					}
					*/
					organic_cabbage(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}