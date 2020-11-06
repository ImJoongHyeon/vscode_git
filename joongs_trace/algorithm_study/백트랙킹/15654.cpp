//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int N, M;
//vector<int>p;
//
//inline bool ascend(int x, int y) {
//	return x < y ? true : false;
//}
//void NM(vector<bool>isused, vector<int>arr, int k);
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> M;
//	vector<int> arr(M, 0);
//	vector<bool> isused(N, false);
//	int temp;
//
//	for (int i = 0; i < N; ++i) {
//		cin >> temp;
//		p.push_back(temp);
//	}
//	sort(p.begin(), p.end(), ascend);
//	NM(isused, arr, 0);
//
//	return 0;
//}
//
//void NM(vector<bool>isused, vector<int>arr, int k) {
//	if (k == M) {
//		for (int i = 0; i < M; ++i) cout << arr[i] << ' ';
//		cout << '\n';
//		return;
//	}
//	for(int i = 0; i < N; ++i){
//		if (!isused[i]) {
//			arr[k] = p[i];
//			isused[i] = true;
//			NM(isused, arr, k + 1);
//			isused[i] = false;
//
//		}
//	}
//}