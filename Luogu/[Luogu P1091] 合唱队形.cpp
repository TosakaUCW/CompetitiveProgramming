#include <stdio.h>
#include <algorithm>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 100

int n,a[N+5],f[N+5],g[N+5],ans;

int main() {
	scanf("%d",&n);
	REP(i,1,n)scanf("%d",&a[i]);

	f[1]=1;
	REP(i,2,n){
		f[i]=1;
		REP(j,0,i-1)
	if(a[i]>a[j])f[i]=std::max(f[i],f[j]+1);
	}
	
	g[1]=1;
	for(int i=n; i>=1; i--)
		for(int j=n+1; j>i; j--)
			if(a[i]>a[j])g[i]=std::max(g[i],g[j]+1);

	REP(i,1,n)
	ans=std::max(ans,g[i]+f[i]-1);
	printf("%d",n-ans);
	return 0;
}
