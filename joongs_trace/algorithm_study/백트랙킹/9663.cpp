//#include<iostream>
//#include<vector>
//using namespace std;
//
//int N;
//int noc = 0;
//void N_Queen(int k);
//
//vector<bool>isused1(14, false);
//vector<bool>isused2(27, false);
//vector<bool>isused3(27, false);
//vector<bool>isused4(14, false);
//
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> N;
//	N_Queen(0);
//	cout << noc;
//	
//	return 0;
//}
//
//void N_Queen(int k) {
//	if (k == N) {
//		noc++;
//		return;
//	}
//	else {
//		for (int i = 0; i < N; ++i) {
//			if (isused1[k] == false && isused2[i + k] == false && isused3[k - i + N - 1] == false && isused4[i] == false) {
//				isused1[k] = true;
//				isused2[i + k] = true;
//				isused3[k - i + N - 1] = true;
//				isused4[i] = true;
//				N_Queen(k + 1);
//				isused1[k] = false;
//				isused2[i + k] = false;
//				isused3[k - i + N - 1] = false;
//				isused4[i] = false;
//			}
//		}
//	}
//}