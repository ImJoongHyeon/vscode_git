#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int y[8] = {2, 1. -1, -2, -2, -1, 1, 2};
int x[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	int T; cin >> T;
	int l;
	int cur_x, nxt_x, cur_y, nxt_y, cnt;
	int des_x, des_y;
	vector<bool>v[300];
	for (int i = 0; i < 300; ++i) v[i].resize(300, false);

	while (T--)
	{
		cin >> l;
		cin >> cur_x >> cur_y >> des_x >> des_y;
		
		queue<pair<pair<int, int>, int>>q;
		q.push({ {cur_y, cur_x}, 0});
		v[cur_y][cur_x] = true;

		while (!q.empty()) {
			cur_y = q.front().first.first;
			cur_x = q.front().first.second;
			cnt = q.front().second;
			
			if (cur_y == des_y && cur_x == des_x) {
				cout << cnt << '\n';
				break;
			}
			q.pop();

			for (int i = 0; i < 8; ++i) {
				nxt_y = cur_y + y[i];
				nxt_x = cur_x + x[i];
				if (nxt_y >= 0 && nxt_y < l && nxt_x >= 0 && nxt_x < l) {
					if (!v[nxt_y][nxt_x]) {
						q.push({ {nxt_y, nxt_x}, cnt + 1 });
						v[nxt_y][nxt_x] = true;
					}
				}
			}
		}
		for (int i = 0; i < l; ++i) for (int j = 0; j < l; ++j) v[i][j] = false;
		
	}
	return 0;
}