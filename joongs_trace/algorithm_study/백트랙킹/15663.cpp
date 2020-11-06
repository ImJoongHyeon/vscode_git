//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//using namespace std;
//
//int N, M;
//set<vector<int>>s;
//vector<int>p;
//
//inline bool ascend(int x, int y) {
//	return (x < y) ? true : false;
//}
//
//void NM2(vector<bool> isused, vector<int>arr, int k);
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> M;
//	
//	vector<bool>isused(N, false);
//	vector<int>arr(M, 0);
//	int temp;
//	for (int i = 0; i < N; ++i) {
//		cin >> temp;
//		p.push_back(temp);
//	}
//	sort(p.begin(), p.end(), ascend);
//	NM2(isused, arr, 0);
//
//
//	for (auto it = s.begin(); it != s.end(); ++it) {
//		for (int i = 0; i < M; ++i) {
//			cout << it->at(i) << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}
//
//void NM2(vector<bool>isused, vector<int>arr, int k)
//{
//	if (k == M) {
//		s.insert(arr);
//		return;
//	}
//	for (int i = 0; i < N; ++i) {
//		if (!isused[i]) {
//			arr[k] = p[i];
//			isused[i] = true;
//			NM2(isused, arr, k + 1);
//			isused[i] = false;
//		}
//	}
//}