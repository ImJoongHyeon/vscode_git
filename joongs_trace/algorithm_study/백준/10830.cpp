#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Mat {
private:	
	int N;
	int mat[5][5];
	int A[5][5];
	stack<bool>bit_s;
public:
	void init();
	void mat_mul();
	void mat_square();
	void print();
};

void Mat::mat_mul() {
	bit_s.pop();
	int result[5][5];
	long long int temp;

	while (!(this->bit_s.empty())) {
		if (this->bit_s.top() == true) {
			this->mat_square();
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					temp = 0;
					for (int k = 0; k < N; ++k) {
						temp += (mat[i][k] * this->A[k][j])%1000;
					}
					result[i][j] = temp % 1000;
				}
			}
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					this->mat[i][j] = result[i][j];
				}
			}
		}
		else {
			this->mat_square();
		}
		this->bit_s.pop();
	}
}

void Mat::mat_square() {
	long long int temp;
	int result[5][5];
	int n = this->N;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp = 0;
			for (int k = 0; k < n; ++k) {
				temp += (this->mat[i][k] * this->mat[k][j])%1000;
			}
			result[i][j] = temp % 1000;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			this->mat[i][j] = result[i][j];
		}
	}
}

void Mat::print()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << this->mat[i][j] << ' ';
		}
		cout << '\n';
	}
}

void Mat::init() {
	int n, b; cin >> n >> b;
	this->N = n;

	for (int i = 0; i < this->N; ++i) {
		for (int j = 0; j < this->N; ++j) {
			cin >> this->mat[i][j];
			this->A[i][j] = this->mat[i][j];
		}
	}
	int t = 1;
	while (b != 0) {
		if ((b & t) == 1) this->bit_s.push(true);
		else this->bit_s.push(false);
		b >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Mat m; m.init();
	m.mat_mul();
	m.print();
	return 0;
}