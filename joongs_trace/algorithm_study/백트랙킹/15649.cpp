//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int N, M;
//
//void func_NM(int* arr, bool* isused, int k);
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N >> M;
//	bool* isused;
//	int* arr;
//
//	isused = new bool[N]; //isused : 1부터 N까지 각 수가 쓰였는지 확인.
//	arr = new int[M]; // arr : 리스트에 들어있는 수.
//	
//	memset(isused, false, N);
//	fill(arr, arr + M, 0);
//
//	func_NM(arr, isused, 0);
//
//	delete[] isused;
//	delete[] arr;
//	return 0;
//}
//
//void func_NM(int* arr, bool* isused, int k) {
//	if (k == M) {
//		for (int i = 0; i < M; ++i) cout << arr[i] + 1 << ' ';
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 0; i < N; ++i) {
//		if (!isused[i]) {
//			arr[k] = i;
//			isused[i] = true;
//			func_NM(arr, isused, k + 1);
//			isused[i] = false;
//		}
//	}
//}