#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	int count = 0;
	int tile[1000];
	tile[0] = 1;
	tile[1] = 2;
	for (int i = 2; i < 1000; ++i) {
		tile[i] = tile[i - 1] + tile[i - 2];
		if (tile[i] >= 10007) {
			tile[i] %= 10007;
		}
	}
	cout << tile[N - 1];
	
	return 0;
}