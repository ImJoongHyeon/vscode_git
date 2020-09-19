#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	int coin[100];
	vector<int>result1(k + 1);
	vector<int>result2(k + 1);

	for (int i = 0; i < n; ++i) cin >> coin[i];
	int temp = coin[0];
	for (int j = 0; j <= k; ++j){
		if(j % temp == 0) result1[j] = 1;
	}
	for (int i = 1; i < n; ++i) {
		fill(result2.begin(), result2.end(), 0);
		for (int j = 0; j <= k; ++j) {
			result2[j] = result1[j];
			if (j - coin[i] >= 0) result2[j] += result2[j - coin[i]];
		}
		result1 = result2;
	}
	cout << result1[k];
	return 0;
}