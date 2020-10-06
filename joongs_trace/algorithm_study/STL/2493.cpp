#include<iostream>
#include<stack>
	
using namespace std;
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int* result = new int[N];
	stack<pair<int, int>>s;
	int t, max_num;

	s.push(make_pair(0, 0));
	max_num = 0;
	
	for (int i = 1; i <= N; ++i) {
		cin >> t;
		if (max_num < t) {
			while (!s.empty()) s.pop();
			result[i - 1] = 0;
			s.push(make_pair(t, i));
			max_num = t;
		}
		else {
			if (s.top().first < t) {
				while (s.top().first < t) s.pop();
				result[i - 1] = s.top().second;
				s.push(make_pair(t, i));
			}
			else {
				result[i - 1] = s.top().second;
				s.push(make_pair(t, i));
			}
		}
	}

	for (int i = 0; i < N; ++i) cout << result[i] << ' ';
	delete[]result;
	return 0;
}