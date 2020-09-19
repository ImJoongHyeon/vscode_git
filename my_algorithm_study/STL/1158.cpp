#include<iostream>
#include<list>
#include<vector>
using namespace std;

list<int>l;
list<int>::iterator cur;
int N, K;

void mv() {
	for (int i = 0; i < K; ++i) {
		cur++;
		if (cur == l.end()) cur = l.begin();
	}
}

void del() {
	list<int>::iterator rm = cur;
	if (cur == l.begin()) cur = l.end();
	cur--;
	cout << *rm << ", ";
	l.remove(*rm);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) l.push_back(i + 1);
	cur = l.begin();
	for (int i = 0; i < K - 1; ++i) cur++;
	cout << '<';
	while (l.size() != 1) {
		del();
		mv();
	}
	cout << *l.begin() << '>';
	return 0;
}