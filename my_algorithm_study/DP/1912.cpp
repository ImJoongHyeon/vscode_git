#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int* arr = new int[n + 1];
	arr[0] = -10000;
	int temp;
	int mx = -10000;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] < arr[i] + arr[i - 1]) arr[i] = arr[i] + arr[i - 1];
		if (arr[i] > mx) mx = arr[i];
	}
	cout << mx;
	return 0;
}