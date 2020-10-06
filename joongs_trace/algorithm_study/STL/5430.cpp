#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int T; cin >> T;
	string oper;
	string arr_str;
	int n;
	while (T--) {
		cin >> oper >> n;
		int begin = 0, end = n - 1;
		bool r = false;
		int d = 0;
		vector<int>v(n);
		cin >> arr_str;
		for (int i = 0; i < arr_str.length(); ++i) {
			if (arr_str[i] == '[' || arr_str[i] == ']' || arr_str[i] == ',') continue;
			v[begin++] = arr_str[i];
		}
		begin = 0;
		for (int i = 0; i < oper.length(); ++i) {
			if (oper[i] == 'D') d++;
			else {
				if (!r) r = true;
				else r = false;
			}
		}
		if (begin + d > end) {
			cout << "error\n";
			continue;
		}

		cout << '[';
		if (r == false) 
			for (int i = begin + d; i < end; ++i) cout << v[i] << ',';
		
		else 
			for (int i = end - d; i >= begin; --i) cout << v[i] << ',';
		cout << "]\n";
	}


	return 0;
}