//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int arr[13];
//int T;
//void Lotto(int cnt, int ps, int cur, vector<bool>chk) {
//	if (cnt == 6) {
//		for (int i = 0; i < T; ++i) {
//			if (chk[i] == true) cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	else {
//		if (T - ps > 6) {
//			chk[cur] = true;
//			Lotto(cnt + 1, ps, cur+1, chk);
//			chk[cur] = false;
//			Lotto(cnt, ps + 1, cur + 1, chk);
//		}
//		else {
//			chk[cur] = true;
//			Lotto(cnt + 1, ps, cur+1, chk);
//		}
//	}
//}
//
//int main() {
//	
//	do {
//		cin >> T;
//		if (T == 0) break;
//		else {
//			vector<int>v(T);
//			vector<bool>chk(T, false);
//			for (int i = 0; i < T; ++i) cin >> arr[i];
//			Lotto(0, 0, 0, chk);
//			cout << '\n';
//		}
//	} while (true);
//
//	return 0;
//}