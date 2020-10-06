#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool>v(100001, false);

int main() {
	int N, K; cin >> N >> K;
	int soobin, cnt;

	int minus, plus, teleport;

	queue<pair<int, int>>q;
	q.push({ N, 0 });
	while (!q.empty()) {
		soobin = q.front().first;
		cnt = q.front().second;
		q.pop();
		v[soobin] = true;
		if (soobin == K) break;
		minus = soobin - 1;
		plus = soobin + 1;
		teleport = soobin * 2;
		if (minus >= 0 && !v[minus]) q.push({ minus, cnt + 1 });
		if (plus <= 100000 && !v[plus]) q.push({ plus, cnt + 1 });
		if (teleport <= 100000 && !v[teleport]) q.push({ teleport, cnt + 1 });
	}
	cout << cnt;
	return 0;
}