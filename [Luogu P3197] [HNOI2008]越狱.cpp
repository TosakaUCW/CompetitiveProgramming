#include <stdio.h>

const int p = 100003;

long long n,m;

template<typename T>
T quick_pow_mod(T a,T b) {
	T ans=1;
	while(b) {
		if(b&1)ans=(ans*a)%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

int main() {
	scanf("%lld%lld",&m,&n);
	long long a = quick_pow_mod(m,n);
	long long b = m*quick_pow_mod(m-1,n-1)%p;
	printf("%lld",(a-b+p)%p);
	return 0;
}
