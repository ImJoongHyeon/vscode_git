#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int y[4] = { 1, -1, 0, 0 };
int x[4] = { 0, 0, 1, -1 };


int main() {
	int M, N, K;
	int** arr;
	cin >> M >> N >> K;
	arr = new int*[M];
	
	vector<int>area;

	for (int i = 0; i < M; ++i) {
		arr[i] = new int[N];
		for (int j = 0; j < N; ++j) {
			arr[i][j] = 0;
		}
	}

	int x1, x2, y1, y2;
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; ++i) {
			for (int j = x1; j < x2; ++j)
				arr[i][j] = 1;
		}
	}

	int cur_x, cur_y, nxt_x, nxt_y;
	int ext;

	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!arr[i][j]) {
				queue<pair<int, int>>q;
				q.push({ i, j });
				ext = 1;
				while (!q.empty()) {
					cur_y = q.front().first;
					cur_x = q.front().second;
					arr[cur_y][cur_x] = 1;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						nxt_y = cur_y + y[k];
						nxt_x = cur_x + x[k];
						if (nxt_y >= 0 && nxt_y < M && nxt_x >= 0 && nxt_x < N) {
							if (!arr[nxt_y][nxt_x]) {
								q.push({ nxt_y, nxt_x });
								arr[nxt_y][nxt_x] = 1;
								ext++;
							}
						}
					}
				}
				cnt++;
				area.push_back(ext);
			}
		}
	}

	sort(area.begin(), area.end());

	cout << cnt << '\n';
	for (auto i : area) cout << i << ' ';

	for (int i = 0; i < M; ++i) delete arr[i];
	delete[]arr;
	return 0;
}