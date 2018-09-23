#include<stdio.h>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define V 25
#define N 10000

long long w[N+5],f[N+5],n,v;

int main() {
	scanf("%lld%lld",&n,&v),f[0]=1;
	REP(i,1,n)scanf("%lld",&w[i]);
	
	REP(i,1,n)
	REP(j,w[i],v)
	f[j]+=f[j-w[i]];

	printf("%lld",f[v]);
	return 0;
}
