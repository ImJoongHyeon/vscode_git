//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int R, C;
//string arr[21];
//int mx_cnt = 0;
//vector<bool>alphabet(26, false);
//void max_move_alpha(int y, int x, int cnt);
//
//int dx[4] = {0, 0, 1, -1};
//int dy[4] = {1, -1, 0, 0};
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> R >> C;
//	for (int i = 0; i < R; ++i) cin >> arr[i];
//	alphabet[arr[0][0] - 'A'] = true;
//	max_move_alpha(0, 0, 1);
//	cout << mx_cnt << '\n';
//	return 0;
//}
//
//void max_move_alpha(int y, int x, int cnt)
//{
//	mx_cnt = max(mx_cnt, cnt);
//	int tx, ty;
//	for (int i = 0; i < 4; ++i) {
//		tx = dx[i] + x;
//		ty = dy[i] + y;
//		if (tx < 0 || ty < 0 || tx >= C || ty >= R) continue;
//		int tmp = (int)arr[ty][tx] - 'A';
//		
//		if (alphabet[tmp]) continue;
//		alphabet[tmp] = true;
//		max_move_alpha(ty, tx, cnt + 1);
//		alphabet[tmp] = false;
//		
//	}
//}