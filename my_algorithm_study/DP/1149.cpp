#include<iostream>
using namespace std;

#define MINNUM(x, y) ((x) > (y) ? (y) : (x))

int RGB[1000][3];
int home[1000][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) cin >> RGB[i][j];
	}
	home[0][0] = RGB[0][0]; home[0][1] = RGB[0][1]; home[0][2] = RGB[0][2];
	
	for (int i = 1; i < N; ++i) {
		home[i][0] = RGB[i][0] + MINNUM(home[i-1][1], home[i-1][2]);
		home[i][1] = RGB[i][1] + MINNUM(home[i-1][0], home[i-1][2]);
		home[i][2] = RGB[i][2] + MINNUM(home[i-1][0], home[i-1][1]);
	}

	int min_num = MINNUM(home[N-1][0], home[N-1][1]);
	if (min_num > home[N-1][2]) cout << home[N-1][2];
	else cout << min_num;

	return 0;
}