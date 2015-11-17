#include<iostream>
using namespace std;

int gcd(int a, int b){
	int t;
	while (b){
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	int n, a, b;
	while(cin >> n){
		cin >> a;
		n--;
		while(n--){
			cin >> b;
			a = gcd(a,b);
		}
		cout << a << endl;
	}
}
