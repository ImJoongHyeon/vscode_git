#include<iostream>

using namespace std;

#define MOD 9901

int main() {
	int N; cin >> N;
	int arr[3][1000];
	for (int i = 0; i < 3; ++i) arr[i][0] = 1;
	
	for (int i = 1; i < N; ++i) {
		arr[0][i] = (arr[0][i - 1] + arr[1][i - 1] + arr[2][i - 1] ) % MOD; // i��° �ٿ� i - 1��° ���� ���ڰ� ��� �ǰ� ��� �־ ��� ����
		arr[1][i] = (arr[0][i - 1] + arr[2][i - 1]) % MOD; // i ��° ���� ���ʿ� ���ڰ� ���� �� i-1���� ���ų� �����ʿ� �־����.
		arr[2][i] = (arr[0][i - 1] + arr[1][i - 1]) % MOD;
	}

	N = N - 1;
	cout << (arr[0][N] + arr[1][N] + arr[2][N]) % MOD;
	return 0;
}