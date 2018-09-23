#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define N 100
#define INF 0x7f7f7f7f
#define REP(i,x,y) for(int i=x;i<=y;i++)

int n,m,a[2*N+5],s[2*N+5],f[2*N+5][2*N+5],g[2*N+5][2*N+5],min=INF,max=-INF;

int main() {
	scanf("%d",&n),m=2*n-1;
	REP(i,1,n)scanf("%d",&a[i]),a[i+n]=a[i];
	REP(i,1,m)s[i]=s[i-1]+a[i];

	for(int i=m; i>=1; i--)
		REP(j,i+1,i+n-1) {
		g[i][j]=INF;
		REP(k,i,j-1) {
			f[i][j]=std::max(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
			g[i][j]=std::min(g[i][j],g[i][k]+g[k+1][j]+s[j]-s[i-1]);
		}
	}

	REP(i,1,n) {
		min=std::min(min,g[i][i+n-1]);
		max=std::max(max,f[i][i+n-1]);
	}

	printf("%d\n%d",min,max);
}

