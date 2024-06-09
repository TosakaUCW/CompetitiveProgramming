#include <stdio.h>

int n;

int main(){
	scanf("%d",&n);
	while(n--){
		long long l,r;
		scanf("%I64d%I64d",&l,&r);
		long long x=1;
		while((l|x)<=r){
			l=l|x;
			x=x<<1;
		}
		printf("%I64d\n",l);
	}
	return 0;
}
