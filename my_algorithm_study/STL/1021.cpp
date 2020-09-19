#include<iostream>
#include<queue>
#include<deque>

using namespace std;

int main() {	
	int N, M;
	int count = 0;
	cin >> N >> M;
	int temp, i, mid;
	queue<int>q; for (int i = 0; i < M; ++i) { cin >> temp; q.push(temp); }
	deque<int>dq(N); for (int i = 1; i <= N; ++i) dq[i - 1] = i;
	
	while (M != 0) {
		i = 0;
		temp = q.front();
		while (temp != dq[i]) i++;
		if (i != 0) {
			mid = (int)(dq.size() / 2);
			if (i <= mid) {
				while (q.front() != dq.front()) {
					dq.push_back(dq.front());
					dq.pop_front();
					count++;
				}
			}
			else {
				while (q.front() != dq.front()) {
					dq.push_front(dq.back());
					dq.pop_back();
					count++;
				}
			}
		}
		q.pop();
		dq.pop_front();
		M--;
	}
	cout << count;
	return 0;
}