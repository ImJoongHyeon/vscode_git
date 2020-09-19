#include<iostream>
using namespace std;

int Distance[301][3] = { 0, };

inline int larger(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int N; cin >> N;
	int* P = new int[N + 1];
	P[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}
	

	Distance[1][1] = P[1];
	if (N >= 2) { Distance[2][1] = P[2]; Distance[2][2] = P[2] + P[1]; }

	if (N > 3) {
		for (int i = 3; i <= N; ++i) {
			Distance[i][1] = P[i] + larger(Distance[i - 2][1], Distance[i - 2][2]);
			Distance[i][2] = P[i] + P[i - 1] + larger(Distance[i - 3][1], Distance[i - 3][2]);
		}
	}
	cout << larger(Distance[N][1], Distance[N][2]);

	return 0;
}