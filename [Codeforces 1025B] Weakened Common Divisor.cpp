#include <bits/stdc++.h>
using namespace std;

long long n,f[150000],top;
long long a,b,ans;

int main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld %lld",&a,&b);
		if(i==1) {
			for(int j=2; j<=sqrt(a); j++) {
				bool flag = false;
				while(a%j==0) {
					a/=j,flag=true;
				}
				if(flag)f[top++]=j;
			}
			if(a>1)f[top++]=a;
			for(int j=2; j<=sqrt(b); j++) {
				bool flag = false;
				while(b%j==0) {
					b/=j,flag=true;
				}
				if(flag)f[top++]=j;
			}
			if(b>1)f[top++]=b;
			continue;
		}
		for(int j=0; j<=top-1; j++) {
			if(a%f[j] and b%f[j]) {
				f[j]=-1;
			}
		}
	}
	for(int j=0; j<=top-1; j++) {
		if(f[j]!=-1) {
			printf("%lld",f[j]);
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}
