#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<char>ins;
int L, C;
void make_pass(int vow_cnt, int con_cnt, int idx, vector<char>pw, vector<bool>chk) {

	if (vow_cnt + con_cnt == L) {
		if (vow_cnt < 1 || con_cnt < 2) return;
		else {
			for (int i = 0; i < L; ++i) cout << pw[i];
			cout << '\n';
			return;
		}
	}
	else{
		for (int i = idx; i < C; ++i) {
			if (chk[i])continue;
			chk[i] = true;
			if (ins[i] == 'a' || ins[i] == 'e' || ins[i] == 'i' || ins[i] == 'o' || ins[i] == 'u') {
				pw.push_back(ins[i]);
				make_pass(vow_cnt + 1, con_cnt, idx + 1, pw, chk);
				pw.pop_back();
			}
			else {
				pw.push_back(ins[i]);
				make_pass(vow_cnt, con_cnt + 1, idx + 1, pw, chk);
				pw.pop_back();
			}
			
		}
	}
	
}


int main() {
	cin >> L >> C;
	ins.resize(C);
	vector<bool>chk(C, false);
	vector<char>pw;
	int cnt = 0;
	for (int i = 0; i < C; ++i) cin >> ins[i];
	sort(ins.begin(), ins.end());
	make_pass(0, 0, 0, pw, chk);

}