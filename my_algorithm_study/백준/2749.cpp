#include<iostream>

using namespace std;

long long int fibo_arr[1500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int n; cin >> n;
	fibo_arr[0] = 0; fibo_arr[1] = 1;
	for (int i = 0; i < 1500000 - 1; ++i) {
		fibo_arr[i + 2] = fibo_arr[i] + fibo_arr[i + 1];
		fibo_arr[i + 2] %= 1000000;
	}
	cout << fibo_arr[n % 1500000];

	return 0;
}