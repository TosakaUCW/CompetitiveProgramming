#include <stdio.h>
#include <algorithm>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 30000
#define M 25

int w[M+5],v[M+5],f[N+5],n,m;

int main() {
	scanf("%d%d",&m,&n);
	
	REP(i,1,n) {
		scanf("%d%d",&v[i],&w[i]);
		w[i]*=v[i];
	}
	
	REP(i,1,n)
	for(int j=m; j>=v[i]; j--)
		if(j>=v[i])
			f[j]=std::max(f[j],f[j-v[i]]+w[i]);
			
	printf("%d",f[m]);
	return 0;
}
