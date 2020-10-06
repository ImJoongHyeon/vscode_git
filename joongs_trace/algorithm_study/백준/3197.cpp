#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K; cin >> N >> K;
	
	int l = (K >= N - K ? K : N - K);
	int s = (K < N - K ? K : N - K);


	long long int answer = 1;
	long long int div = 1;

	if (s != 0) {
		for (int j = 1; j <= s; ++j) {
			div *= j;
			if (div > 1000000007) div %= 1000000007;
		}
	}

	bool div_ok = false;

	for (int i = l + 1; i <= N; ++i) {
		answer *= i;
		if (answer > 1000000007) answer %= 1000000007;
		if (div_ok == false && answer % div == 0) {
			answer /= div;
			div_ok = true;
		}
	}
	
	cout << answer;

	return 0;
}
