#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


void BFS(int n, int m);
int paper[500][500] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> paper[i][j];
		}
	}

	BFS(n, m);
	return 0;
}

void BFS(int n, int m) {
	queue<pair<int, int>>q;
	int count = 0;
	int volume = 0;
	int x, y;
	vector<int>v(1, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (paper[i][j] == 1) {
				count++;
				q.push(make_pair(i, j));
				paper[i][j] = 0;
				while (!q.empty()) {
					x = q.front().first; y = q.front().second;
					
					volume++;
					q.pop();
					if (x + 1 < n && paper[x + 1][y] == 1) {		//�Ʒ�
						q.push(make_pair(x + 1, y));
						paper[x + 1][y] = 0;
					}
					if (y + 1 < m && paper[x][y + 1] == 1) {		//������
						q.push(make_pair(x, y + 1));
						paper[x][y + 1] = 0;
					}
					if (y - 1 >= 0 && paper[x][y - 1] == 1) {		//������
						q.push(make_pair(x, y - 1));
						paper[x][y - 1] = 0;
					}
					if (x - 1 >= 0 && paper[x - 1][y] == 1) {
						q.push(make_pair(x - 1, y));
						paper[x - 1][y] = 0;
					}
				}
				v.push_back(volume);
				volume = 0;
			}

		}
	}
	cout << count << ' ' << *max_element(v.begin(), v.end());

}