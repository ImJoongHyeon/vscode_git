#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int cnt[26] = { 0, };
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); ++i) cnt[S[i] - 'a']++;

	for (int i = 0; i < 26; ++i) {
		cout << cnt[i] << ' ';
	}

	return 0;
}