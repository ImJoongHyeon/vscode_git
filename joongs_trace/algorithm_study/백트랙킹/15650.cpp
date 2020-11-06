//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//int N, M;
//set<vector<int>>s;
//
//inline bool ascend(int x, int y) {
//	return (x < y) ? true : false;
//}
//
//void NM2(vector<bool> v, int k);
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> M;
//	vector<bool>v(N, false);
//	NM2(v, 0);
//	for (auto it = s.begin(); it != s.end(); ++it) {
//		for (int i = 0; i < M; ++i) {
//			cout << it->at(i) << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}
//
//void NM2(vector<bool> v, int k)
//{
//	if (k == M) {
//		vector<int> temp;
//		for (int i = 0; i < N; ++i) {
//			if (v[i] == true) temp.push_back(i + 1);
//		}
//		sort(temp.begin(), temp.end(), ascend);
//		s.insert(temp);
//		return;
//	}
//	for (int i = 0; i < N; ++i) {
//		if (!v[i]) {
//			v[i] = true;
//			NM2(v, k + 1);
//			v[i] = false;
//		}
//	}
//}
//
//
////void func_NM(int* arr, bool* isused, int k) {
////	if (k == M) {
////		for (int i = 0; i < M; ++i) cout << arr[i] + 1 << ' ';
////		cout << '\n';
////		return;
////	}
////
////	for (int i = 0; i < N; ++i) {
////		if (!isused[i]) {
////			arr[k] = i;
////			isused[i] = true;
////			func_NM(arr, isused, k + 1);
////			isused[i] = false;
////		}
////	}
////}
//
//
////#include <cstdio>
////#include <vector>
////using namespace std;
////
////int n, m, x;
////vector<int> a;
////
////void solve(int index, int cnt) {
////	if (cnt == m) {
////		for (auto i : a) printf("%d ", i + 1);
////		printf("\n");
////		return;
////	}
////	for (int i = index; i < n; i++) {
////		a.push_back(i);
////		solve(i + 1, cnt + 1);
////		a.pop_back();
////	}
////}
////
////int main() {
////	scanf("%d %d", &n, &m);
////	solve(0, 0);
////	return 0;
////}