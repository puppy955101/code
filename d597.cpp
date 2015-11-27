#include<iostream>
using namespace std;

int a[50], t[50], c[50], ans, x;

void sol(int n, int k, int no, int fr){
	int i;
	if (no == k){
		ans++;
		for (i = 0; i < k; i++)if (t[i] != a[i])break;
		if (i == k)x = ans;
		if (ans == x + 1){
			cout << x << endl;
			for (i = 0; i < k; i++)cout << t[i] << " ";
			cout << endl;
		}
		return;
	}
	for (i = fr; i <= n; i++){
		if (c[i] == 0){
			c[i] = 1;
			t[no] = i;
			sol(n, k, no + 1, i + 1);
			c[i] = 0;
		}
		if (ans == x + 1)
			return;
	}
	return;
}

int main(){
	int n, k;
	cin >> n >> k;
	int i;
	ans = 0;
	x = -10;
	for (i = 0; i < k; i++)cin >> a[i];
	for (i = 0; i <= n; i++)c[i] = 0;
	sol(n, k, 0, 1);
	if (ans != x + 1){
		cout << x << endl << "no next combination" << endl;
	}
}