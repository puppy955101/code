#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a[500];
	int ans;
	int i;
	for(i=1;i<11;i++){
		ans = 0;
		int j;
		for(j=0;j<=i;j++)a[j] = j+1;
		do{
			for(j=1;j<i;j++){
				if(a[j]==a[j-1]+1)
					break;	
			}
			if(j==i)
				ans++;
		}while(next_permutation(a,a+i));
		cout << i << " " << ans << endl;
	}
}


