#include<iostream>
using namespace std;

#define LARGER(x, y) ((x > y) ? (x) : (y))

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	int arr[1001];
	int result[1001];
	for (int i = 0; i < N; ++i) cin >> arr[i];
	result[0] = 1;
	int mx = 1;

	for (int i = 1; i < N; ++i) {
		result[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[i]) result[i] = LARGER(result[i], result[j] + 1);
		}
		if (mx < result[i]) mx = result[i];
	}
	cout << mx;

	return 0;
}