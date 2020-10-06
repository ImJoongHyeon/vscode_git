#include<iostream>
#include<string>

using namespace std;

void AplusB(string A, string B);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string A, B;
	
	cin >> A >> B;
	AplusB(A, B);

	return 0;
}

void AplusB(string A, string B) {
	string result;
	if (A.length() == B.length()) {
		for (int i = A.length() - 1; i >= 0; --i) {

		}
	}
	else if(A.length() < B.length()){
		for (int i = A.length() - 1; i >= 0; --i) {

		}
	}
	else {
		for (int i = B.length() - 1; i >= 0; --i) {

		}
	}

	cout << result;
}