#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int y[4] = { 1, -1, 0, 0 };
int x[4] = { 0, 0, 1, -1 };

int main() {
	int N; cin >> N;
	string arr[100];
	vector<bool>check[100];

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		check[i].resize(N, false);
	}
	int noa = 0;

	int cur_x, cur_y;
	char cur_c;

	int nxt_x, nxt_y;
	
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!check[i][j]) {
				queue<pair<pair<int, int>,char>>q;
				q.push({ {i, j}, arr[i][j] });
				check[i][j] = true;
				while (!q.empty()) {
					cur_y = q.front().first.first;
					cur_x = q.front().first.second;
					cur_c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						nxt_y = cur_y + y[k];
						nxt_x = cur_x + x[k];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < N) {
							if (cur_c == arr[nxt_y][nxt_x] && !check[nxt_y][nxt_x]) {
								q.push({ {nxt_y, nxt_x}, cur_c });
								check[nxt_y][nxt_x] = true;
								
							}
						}
					}
				}
				noa++;
			}
		}
	}*/

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!check[i][j]) {
				queue<pair<pair<int, int>,char>>q;
				q.push({ {i, j}, arr[i][j] });
				if (arr[i][j] == 'B') arr[i][j] = 'Y';
				else arr[i][j] = 'X';
				check[i][j] = true;
				while (!q.empty()) {
					cur_y = q.front().first.first;
					cur_x = q.front().first.second;
					cur_c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						nxt_y = cur_y + y[k];
						nxt_x = cur_x + x[k];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < N) {
							if (cur_c == arr[nxt_y][nxt_x] && !check[nxt_y][nxt_x]) {
								q.push({ {nxt_y, nxt_x}, cur_c });
								check[nxt_y][nxt_x] = true;
								if (arr[nxt_y][nxt_x] == 'B') arr[nxt_y][nxt_x] = 'Y';
								else arr[nxt_y][nxt_x] = 'X';
							}
						}
					}
				}
				noa++;
			}
		}
	}


	cout << noa << ' ';
	noa = 0;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) check[i][j] = false;
	

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!check[i][j]) {
				queue<pair<pair<int, int>,char>>q;
				q.push({ {i, j}, arr[i][j] });
				check[i][j] = true;
				while (!q.empty()) {
					cur_y = q.front().first.first;
					cur_x = q.front().first.second;
					cur_c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						nxt_y = cur_y + y[k];
						nxt_x = cur_x + x[k];
						if (nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < N) {
							if (cur_c == arr[nxt_y][nxt_x] && !check[nxt_y][nxt_x]) {
								q.push({ {nxt_y, nxt_x}, cur_c });
								check[nxt_y][nxt_x] = true;
							}
						}
					}
				}
				noa++;
			}
		}
	}
	cout << noa;

	return 0;
}