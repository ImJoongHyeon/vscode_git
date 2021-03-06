#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string Add_large_num(string& a, string& b) {
	string result(max(a.length(), b.length()), '0');
	bool carry = false;
	int temp;
	for (int i = 0; i < result.length(); ++i) {
		temp = carry;
		carry = false;

		if (i < a.size()) temp += a[a.length() - i - 1] - '0';
		if (i < b.size()) temp += b[b.length() - i - 1] - '0';
		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}
		result[result.length() - i - 1] = temp + '0';
	}
	if (carry) result.insert(result.begin(), '1');
	return result;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string A, B;
	cin >> A >> B;
	cout << Add_large_num(A, B);
	return 0;
}