#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int y[4] = { 1, -1, 0, 0 };
int x[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	string dis[100];
	for (int i = 0; i < N; ++i) cin >> dis[i];
	queue<pair<pair<int, int>, int>>q;
	q.push({ { 0, 0 }, 1 });
	dis[0][0] = '0';
	int p_x, p_y, cnt;
	int temp_y, temp_x;
	while (!q.empty()) {
		p_y = q.front().first.first;
		p_x = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		if (p_y == N - 1 && p_x == M - 1) {
			cout << cnt;
			break;
		}
		
		for (int i = 0; i < 4; ++i) {
			temp_x = p_x + x[i];
			temp_y = p_y + y[i];
			if (temp_y >= 0 && temp_y < N && temp_x >= 0 && temp_x < M) {
				if (dis[temp_y][temp_x] != '0') {
					q.push({{temp_y, temp_x }, cnt + 1});
					dis[temp_y][temp_x] = '0';
				}
			}
		}

	}
	return 0;
}