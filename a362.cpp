#include<iostream>
#include<algorithm>
using namespace std;

struct x {
	int h, w, i;
};
bool cmp(x a, x b) {
	if (a.h != b.h)return a.h < b.h;
	if (a.w != b.w)return a.w < b.w;
	return a.i < b.i;
}
x a[10010], b[10010];
int n;
int s(x t) {
	int L, R, m;
	L = 0;
	R = n;
	while (R > L + 1) {
		m = (L + R) / 2;
		if (a[m].h == t.h&&a[m].w == t.w&&a[m].i == t.i)
			return m;
		if (a[m].h > t.h || (a[m].h == t.h&&a[m].w > t.w) || (a[m].h == t.h&&a[m].w == t.w&&a[m].i > t.i))
			R = m;
		else
			L = m;
	}
	m = L;
	if (a[m].h == t.h&&a[m].w == t.w&&a[m].i == t.i)
		return m;
	m = R;
	if (a[m].h == t.h&&a[m].w == t.w&&a[m].i == t.i)
		return m;
}
int main() {
	cin >> n;
	int i;
	for (i = 0;i < n;i++)cin >> a[i].h >> a[i].w, a[i].i = i, b[i] = a[i];
	sort(a, a + n, cmp);
	int ans = 0;
	for (i = 0;i < n;i++) {
		ans += abs(i - s(b[i]));
	}
	cout << ans << endl;
}