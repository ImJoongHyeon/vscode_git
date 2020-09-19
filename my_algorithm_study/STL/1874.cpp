#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int a[100001];
stack<int>s;
vector<char>ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int pos = 0;
	int val;
	cin >> val;
	for (int i = 0; i < val; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= val; ++i) {
		s.push(i), ans.push_back('+');
		while (!s.empty() && s.top() == a[pos]) {
			pos++, s.pop(), ans.push_back('-');
		}
	}
	if (s.empty()) {
		for (auto i : ans) cout << i << '\n';
	}
	else cout << "NO";

	return 0;
}