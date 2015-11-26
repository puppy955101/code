#include<iostream>
using namespace std;

struct x{
	int a, b, c;
};

x a[400], b[400];
int main(){
	int n1, n2, i, j, ans = 0;
	cin >> n1;
	for (i = 0; i < n1; i++){
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	cin >> n2;
	for (i = 0; i < n2; i++){
		cin >> b[i].a >> b[i].b >> b[i].c;
	}
	int ok = 1;
	for (i = 0; i < n1; i++){
		ok = 1;
		for (j = 0; j < n2; j++){
			if (a[i].a == b[j].a&&a[i].b == b[j].b){
				if (a[i].c != b[j].c){
					ans += 2;
				}
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	for (i = 0; i < n2; i++){
		ok = 1;
		for (j = 0; j < n1; j++){
			if (a[j].a == b[i].a&&a[j].b == b[i].b){
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	cout << ans << endl;
}