#include<iostream>
using namespace std;

struct x{
	string a, b;	
};
x j[1000];
int t, n, m;
int a[1000]={};

int c(){
	int i, ok = 0;
	int aa, bb;
	for(i=0;i<m;i++){
		int k;
		aa = bb = 0;
		for(k=1;k!=j[i].a.size();k++){
			aa = aa*10+j[i].a[k]-'0';	
		}
		for(k=1;k!=j[i].b.size();k++){
			bb = bb*10+j[i].b[k]-'0';	
		}
		aa--;
		bb--;
		if(j[i].a[0]=='m'&&a[aa]==0){
			ok = 1;
		}
		else if(j[i].a[0]=='h'&&a[aa]==1){
			ok = 1;
		}
		else if(j[i].b[0]=='m'&&a[bb]==0){
			ok = 1;
		}
		else if(j[i].b[0]=='h'&&a[bb]==1){
			ok = 1;
		}
		else
			return 0;
	}
	return 1;
}	

int p(int k){
	if(k==n){
		if(c()==1){
			return 1;
		}
		return 0;
	}
	int i;
	for(i=0;i<2;i++){
		a[k] = i;
		if(p(k+1))
			return 1;	
	}
	return 0;
}

int sol(){
	return p(0);	
}

int main(){
	int i;
	while(cin >> t){
		while(t--){
			cin >> n >> m;
			for(i=0;i<m;i++){
				cin >> j[i].a >> j[i].b;
			}
			int ok = sol();
			if(ok)
				cout << "GOOD" << endl;	
			else
				cout << "BAD" << endl;
		}
	}
}

