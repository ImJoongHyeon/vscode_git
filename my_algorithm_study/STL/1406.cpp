#include<iostream>
#include<string>
#include<list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int M = 0;
	cin >> S >> M;
	list<char> L;

	for (auto c : S) L.push_back(c);

	list<char>::iterator it = L.end();
	
	while (M--) {
		char op;
		cin >> op;
		if (op == 'P') {
			char add;
			cin >> add;
			L.insert(it, add);
		}
		else if (op == 'L') {
			if (it != L.begin()) it--;
		}
		else if (op == 'D') {
			if (it != L.end()) it++;
		}
		else {
			it--;
			it = L.erase(it);
		}
	}
	cout << S;
	return 0;
}