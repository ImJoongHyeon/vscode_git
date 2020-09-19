#include<iostream>

using namespace std;

// long long int mul(long long int A, long long int B, long long int C) {
// 	if (B == 1) {
// 		return A;
// 	}
// 	if (B % 2 == 0) {
// 		long long r = mul(A, B / 2, C);
// 		return (r * r) % 2;
// 	}
// 	else {
// 		return (A * mul(A, B - 1, C)) % C;
// 	}
// } --> 왜 이게 안되는 것인가...ㅠ

long long int mul(long long int A, long long int B, long long int C) {
	long long r = 1;
	while (B != 0) {
		if (B & 1) r = (r * A) % C;
		A = (A * A) % C;
		B >>= 1;
	}
	return r;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c);
	return 0;
}