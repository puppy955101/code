#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	long long x, m;
	int n[500];
	int s = 0;
	cin >> m;
	for (x = 1;x <= m / 2;x++) {
		if (x*x%m == 1) {
			n[s] = x, s += 1;
		}
	}
	int i;
	for (i = 1;i <= s;i++) {
		n[s + i - 1] = m - n[s - i];
	}
	s *= 2;
	printf("%d\n", s);
	for (x = 0;x < s;x++)printf("%d\n",n[x]);
}