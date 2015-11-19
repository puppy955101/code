#include<iostream>
using namespace std;

int main(){
	int n, x, k;
	cin >> n;
	while (n--){
		cin >> x >> k;
		x %= (k + 1);
		x += (x == 0)*(k + 1);
		if (k % 2){
			if (x % 2 == 0){
				cout << 1 << endl;
			}
			else
				cout << 2 << endl;
		}
		else{
			if (x==k+1)
				cout << 1 << endl;
			else if(x==k){
				cout << 2 << endl;
			}
			else if (x == k - 1){
				cout << 3 << endl;
			}
			else{
				if (x % 2){
					cout << 2 << endl;
				}
				else{
					cout << 1 << endl;
				}
			}
		}
	}
}