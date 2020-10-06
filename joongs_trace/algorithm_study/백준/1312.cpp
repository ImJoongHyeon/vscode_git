#include<iostream>
using namespace std;


int main() {
	int A, B, N; 
	cin >> A >> B >> N;
	A = A % B;
	for (int i = 0; i < N - 1; ++i) A = (A * 10) % B;
	cout << (int)((A * 10) / B);
	return 0;
}