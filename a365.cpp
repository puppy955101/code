#include<iostream>
#include<string>
using namespace std;

int main() {
	int dp[5000] = {};
	int x[100] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,2304,1152,768,384,272,192,136,48,24,18,12,9 };
	int i, j;
	for (i = 0;i < 12;i++)dp[x[i]] = 2;
	int ok = 1;
	while (ok) {
		ok = 0;
		for (i = 1;i < 5000;i++) {
			for (j = 0;j < 24;j++) {
				if ((i&x[j]) == 0 && dp[i]) {
					if (dp[i + x[j]] == 0) {
						ok = 1;
						if (dp[i] == 1)
							dp[i + x[j]] = 2;
						else
							dp[i + x[j]] = 1;

					}
					else if (dp[i + x[j]] == 2) {
						if (dp[i] == 2)
							dp[i + x[j]] = 1,ok = 1;
					}
				}
			}
		}
	}
	string s;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		int a = 0;
		for (i = 0;i != s.size();i++) {
			if (s[i] == '1')
				a += x[11-i];
		}
		if (dp[a] == 2)
			cout << 0;
		else
			cout << dp[a];
	}
}