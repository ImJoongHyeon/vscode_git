//#include<iostream>
//#include<vector>
//using namespace std;
//
//int N, M;
//
//void NM(vector<int>v, int k);
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> M;
//	vector<int>v;
//	NM(v, 0);
//	return 0;
//}
//
//void NM(vector<int>v, int k) {
//	if (k == M) {
//		for (auto i : v) cout << i << ' ';
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; i < N; ++i) {
//		v.push_back(i + 1);
//		NM(v, k + 1);
//		v.pop_back();
//	}
//}