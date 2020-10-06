#include<iostream>
#include<queue>

using namespace std;

int*** tomato;

int z[6] = { 1, -1, 0, 0, 0, 0 };
int y[6] = { 0, 0, 1, -1, 0, 0 };
int x[6] = {0, 0, 0, 0, 1, -1 };


int main() {
	int M, N, H; cin >> M >> N >> H;
	int cur_x, cur_y, cur_z, nxt_x, nxt_y, nxt_z, cnt;
	queue<pair<pair<pair<int, int>, int>, int>>q;
	
	tomato = new int** [H];
	for (int i = 0; i < H; ++i) {
		tomato[i] = new int*[N];
		for (int j = 0; j < N; ++j) {
			tomato[i][j] = new int[M];
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
					q.push({ { {i, j}, k }, 0 });
			}
		}
	}
	while (!q.empty()) {
		cur_z = q.front().first.first.first;
		cur_y = q.front().first.first.second;
		cur_x = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 6; ++i) {
			nxt_z = cur_z + z[i];
			nxt_y = cur_y + y[i];
			nxt_x = cur_x + x[i];
			if (nxt_z >= 0 && nxt_z < H && nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < M) {
				if (tomato[nxt_z][nxt_y][nxt_x] == 0) {
					tomato[nxt_z][nxt_y][nxt_x] = 1;
					q.push({ { {nxt_z, nxt_y}, nxt_x }, cnt+1 });
				}
			}
		}
	}
	
	bool check = true;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (tomato[i][j][k] == 0) check = false;
			}
		}
		if (!check) break;
	}

	if (check) cout << cnt;
	else cout << -1;

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			delete tomato[i][j];
		}
		tomato[i];
	}
	delete[]tomato;
	return 0;
}