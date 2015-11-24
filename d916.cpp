#include<iostream>
using namespace std;

unsigned long long max(unsigned long long a, unsigned long long b) {
	if (a > b)return a;
	return b;
}
int ps[4000][4000];
unsigned long long c(unsigned long long a, unsigned long long b) {
	return ps[a][b];
}

unsigned long long h(unsigned long long a, unsigned long long b) {
	return c(a + b - 1, b);
}
void init() {
	int i, j;
	ps[0][0] = 1;
	for (i = 1;i <= 3010;i++) {
		ps[i][0] = ps[i][i] = 1;
		for (j = 1;j < i;j++) {
			ps[i][j] = ps[i - 1][j] + ps[i - 1][j - 1];
			ps[i][j] %= 10000;
		}
	}
}
int main() {
	unsigned long long n, m;
	init();
	while (cin >> n >> m) {
		unsigned long long ans = 1;
		unsigned long long i;
		for (i = 1;i < n;i++) {
			if (n < (i - 1)*m + i)
				break;
			ans += h(i + 1, n - (i - 1)*m - i);
			ans %= 10000;
			//cout << i << endl;
		}
		cout << ans << endl;
	}
}