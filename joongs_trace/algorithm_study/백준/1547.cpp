#include<iostream>

using namespace std;

int main() {
	bool cups[3] = { true, false, false };
	int N; cin >> N;
	int X, Y;
	while (N--) {
		cin >> X >> Y;
		X -= 1;
		Y -= 1;
		if (cups[X]) {
			cups[X] = false;
			cups[Y] = true;
		}
		else if (cups[Y]) {
			cups[X] = true;
			cups[Y] = false;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (cups[i]){ 
			cout << i + 1;
			break;
		}
	}

	return 0;
}