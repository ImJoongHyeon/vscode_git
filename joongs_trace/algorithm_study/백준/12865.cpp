#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int value[101]; int weight[101];
int answer[101][100001] = { 0, };

#define LARGER(x, y) (x) > (y) ? (x) : (y)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; ++i) cin >> weight[i] >> value[i];
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j >= weight[i]) answer[i][j] = LARGER(answer[i - 1][j], answer[i - 1][j - weight[i]] + value[i]);
			else answer[i][j] = answer[i - 1][j];
		}
	}

	cout << answer[N][K];

	return 0;
}
