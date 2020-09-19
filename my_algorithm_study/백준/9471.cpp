#include<iostream>
#include<cstdio>
using namespace std;

void pisano_period(int P);

int main() {
	int P; scanf_s("%d", &P);
	pisano_period(P);
	return 0;
}

void pisano_period(int P) {
	int N, M;
	long long period;
	int now, pre;
	int temp;
	while (P--) {
		scanf_s("%d %d", &N, &M);
		now = 1, pre = 1;
		period = 2;
		do {
			temp = now;
			now = (now + pre) % M;
			pre = temp;
			period++;
		} while (!(now == 0 && pre == 1));
		printf("%d %lld\n", N, period);
	}
}