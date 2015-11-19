#include<iostream>
#include<algorithm>
using namespace std;

struct xx{
	long long a, b;
};
long long gcd(long long a, long long b){
	long long t;
	if (a == b&&a == 0)return 1;
	while (b){
		t = a%b, a = b, b = t;
	}
	return a;
}
xx s(xx a){
	long long g = gcd(a.a, a.b);
	a.a /= g;
	a.b /= g;
	if (a.b < 0)
		a.a *= -1, a.b *= -1;
	return a;
}
xx add(xx a, xx b){
	long long g = gcd(a.b, b.b);
	xx c;
	c.b = a.b / g*b.b;
	c.a = a.a*(c.b / a.b) + b.a*(c.b / b.b);
	return c;
}
xx x[50][50];
long long n;
void p(){
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j <= n; j++){
			cout << x[i][j].a << "/" << x[i][j].b << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int sol(){
	int ans = 0;
	int i, j, k;
	/*for (i = 0; i < n; i++){
	for (j = i + 1; j < n; j++){
	for (k = 1; k <= n; k++){
	if (x[i][k - 1].a*x[j][k].a*x[i][k].b*x[j][k - 1].b != x[i][k - 1].b*x[j][k].b*x[i][k].a*x[j][k - 1].a)
	break;
	}
	if (k == n){
	ans = 1;
	}
	if (k == n + 1 && ans == 0){
	ans = 2;
	}
	}
	}*/
	for (i = 0; i < n; i++){
		if (x[i][i].a)
			ans++;
		else if (x[i][n].a)
			return 1;
	}
	if (ans == n)
		return 0;
	return 2;
}
int main(){
	int tc = 0;
	cin >> n;
	long long i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j <= n; j++){
		cin >> x[i][j].a, x[i][j].b = 1;
		}
	long long ans = 0;
	/*for (i = 0; i < n; i++){
	for (j = 0; j <= n; j++)
	if (x[i][j].a)break;
	if (j == n){
	ans = 1;
	}
	if (j == n + 1 && ans != 1){
	ans = 2;
	}
	}*/
	for (i = 0; i < n; i++){
		if (x[i][i].a == 0){
			for (j = i + 1; j < n; j++){
				if (x[j][i].a){
					for (k = 0; k <= n; k++){
						xx t = x[j][k];
						x[j][k] = x[i][k], x[i][k] = t;
					}
					break;
				}
			}
		}
	}
	if (ans == 0){
		for (i = 1; i <= n; i++){
			if (x[0][0].a == 0)break;
			if (x[0][i].a%x[0][0].a == 0)
				x[0][i].a /= x[0][0].a;
			else{
				x[0][i].b *= x[0][0].a;
				x[0][i] = s(x[0][i]);
			}
		}
		if (i == n + 1)x[0][0].a = x[0][0].b = 1;
		for (i = 0; i < n - 1; i++){
			for (j = i + 1; j < n; j++){
				xx a;
				a.a = x[i][i].b*x[j][i].a;
				a.b = x[j][i].b*x[i][i].a;
				if (a.b == 0)a.b = 1, a.a = 0;
				a = s(a);
				for (k = i; k < n + 1; k++){
					xx b;
					b = x[i][k];
					b.a *= a.a;
					b.b *= a.b;
					b.a *= -1;
					b = s(b);
					x[j][k] = add(x[j][k], b);
				}
				if (j == i + 1){
					for (k = j + 1; k <= n; k++){
						if (x[j][j].a == 0)break;
						x[j][k].a *= x[j][j].b;
						x[j][k].b *= x[j][j].a;
						x[j][k] = s(x[j][k]);
					}
					if (k == n + 1)x[j][j].a = x[j][j].b = 1;
				}
				//	p();
			}
		}
		for (i = n - 2; i >= 0; i--){
			for (j = n - 1; j > i; j--){
				xx a;
				a.a = x[j][n].a*x[i][j].a;
				a.a *= -1;
				a.b = x[j][n].b*x[i][j].b;
				if (a.b == 0)a.b = 1, a.a = 0;
				a = s(a);
				x[i][n] = add(x[i][n], a);
				x[i][j].a = 0;
				x[i][j].b = 1;
				//p();
			}
		}
		ans = sol();
		/*for (i = 0; i < n; i++){
		for (j = 0; j <= n; j++)
		if (x[i][j].a)break;
		if (j == n){
		ans = 1;
		}
		if (j == n + 1 && ans != 1){
		ans = 2;
		}
		}*/
	}
	if (ans == 0){
		cout << 1 << endl;
		for (i = 0; i < n; i++){
			x[i][n] = s(x[i][n]);
			if (x[i][n].b != 1)
				cout << "x" << i + 1 << " = " << x[i][n].a << "/" << x[i][n].b << endl;
			else
				cout << "x" << i + 1 << " = " << x[i][n].a << endl;
		}
	}
	else if (ans == 1){
		cout << 0 << endl;
	}
	else
		cout << 'N';
}