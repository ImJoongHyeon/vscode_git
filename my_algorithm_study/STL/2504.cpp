#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void) {
	string br; cin >> br;
	stack<pair<char, int>>s;
	int total = 0, mid_tot = 0;
	char chr_temp;
	char chr_temp2;
	int num_temp;
	bool imp = false;
	for (auto i : br) {
		if (i == '(' || i == '[') {
			s.push(make_pair(i, 0));
		}
		else{
			if (s.empty()) {
				imp = true;
				break;
			}
			chr_temp = s.top().first;
			num_temp = s.top().second;
			s.pop();


			if (num_temp == 0) {
				if (chr_temp == '(') s.push(make_pair(' ', 2));
				else s.push(make_pair(' ', 3));
			}
			else {
				mid_tot += num_temp;
				while (s.top().first != '(' && s.top().first != '[') {
					mid_tot += s.top().second;
					s.pop();
				}
				chr_temp2 = s.top().first;
				s.pop();
				if (chr_temp2 == '(') s.push(make_pair(' ', 2 * mid_tot));
				else s.push(make_pair(' ', 3*mid_tot));
				mid_tot = 0;
			}
		}
		
	}
	while (!s.empty()) {
		total += s.top().second;
		s.pop();
	}
	cout << total;
	return 0;
}