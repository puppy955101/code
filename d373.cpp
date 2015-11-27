#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int m[1010][1010] = {};
struct qq {
	int x, y, s;
};
int gcd(int a, int b) {
	int t;
	while (b) {
		t = a%b, a = b, b = t;
	}
	return a;
}
queue<qq>q;
int main() {
	string s;
	int x, y, i, j, k, a, b;
	cin >> x >> y;
	cin >> s;
	cin >> i >> j >> k >> a;
	if (s == ".mb") {
		if (i == k) {
			for (b = min(j, a);b <= max(j, a);b++) {
				qq t;
				t.x = i, t.y = b, t.s = 0;
				q.push(t);
				m[i][b] = 1;
			}
		}
		else {
			for (b = min(i, k);b <= max(i, k);b++) {
				qq t;
				t.x = b, t.y = j, t.s = 0;
				q.push(t);
				m[b][j] = 1;
			}
		}
	}
	else {
		if (i == k) {
			for (b = min(j, a);b <= max(j, a);b++) {
				m[i][b] = 2;
			}
		}
		else {
			for (b = min(i, k);b <= max(i, k);b++) {
				m[b][j] = 2;
			}
		}
	}
	cin >> s;
	cin >> i >> j >> k >> a;
	if (s == ".mb") {
		if (i == k) {
			for (b = min(j, a);b <= max(j, a);b++) {
				qq t;
				t.x = i, t.y = b, t.s = 0;
				q.push(t);
				m[i][b] = 1;
			}
		}
		else if (j == a) {
			for (b = min(i, k);b <= max(i, k);b++) {
				qq t;
				t.x = b, t.y = j, t.s = 0;
				q.push(t);
				m[b][j] = 1;
			}
		}
		else {
			if (i > k) {
				swap(i, k);
				swap(j, a);
			}
			int c = j;
			for (b = i;b <= k;b++) {
				for (c = j;c <= a;c++) {
					qq t;
					t.x = b, t.y = c, t.s = 0;
					q.push(t);
					m[b][c] = 1;
				}
			}
		}
	}
	else {
		if (i == k) {
			for (b = min(j, a);b <= max(j, a);b++) {
				m[i][b] = 2;
			}
		}
		else if (j == a) {
			for (b = min(i, k);b <= max(i, k);b++) {
				m[b][j] = 2;
			}
		}
		else {
			if (i > k) {
				swap(i, k);
				swap(j, a);
			}
			int c = j;
			for (b = i;b <= k;b++) {
				for (c = j;c <= a;c++) {
					m[b][c] = 2;
				}
			}
		}
	}
	cin >> s;
	while (cin >> s, s != ".be") {
		i = 0;
		for (b = 0;b != s.size();b++) {
			i = i * 10 + s[b] - '0';
		}
		cin >> j >> k >> a;
		if (i == k) {
			for (b = min(j, a);b <= max(j, a);b++) {
				m[i][b] = 1;
			}
		}
		else {
			for (b = min(i, k);b <= max(i, k);b++) {
				m[b][j] = 1;
			}
		}
	}
	int ans = -1;
	while (!q.empty()) {
		qq t;
		t = q.front();
		q.pop();
		if (m[t.x][t.y] == 2) {
			ans = t.s;
			break;
		}
		if (t.x + 1 < x&&m[t.x + 1][t.y] != 1) {
			m[t.x + 1][t.y] = max(1, m[t.x + 1][t.y]);
			qq tt;
			tt = t;
			tt.x++, tt.s++;
			q.push(tt);
		}
		if (t.x - 1 >= 0 && m[t.x - 1][t.y] != 1) {
			m[t.x - 1][t.y] = max(1, m[t.x - 1][t.y]);
			qq tt;
			tt = t;
			tt.x--, tt.s++;
			q.push(tt);
		}
		if (t.y + 1 < y&&m[t.x][t.y + 1] != 1) {
			m[t.x][t.y + 1] = max(1, m[t.x][t.y + 1]);
			qq tt;
			tt = t;
			tt.y++, tt.s++;
			q.push(tt);
		}
		if (t.y - 1 >= 0 && m[t.x][t.y - 1] != 1) {
			m[t.x][t.y - 1] = max(1, m[t.x][t.y - 1]);
			qq tt;
			tt = t;
			tt.y--, tt.s++;
			q.push(tt);
		}
	}
	if (ans != -1)
		cout << ans << endl;
	else
		cout << "no path" << endl;
}

