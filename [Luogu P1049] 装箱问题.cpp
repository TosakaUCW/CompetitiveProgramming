#include<stdio.h>
#include<algorithm>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define V 20000
#define N 30

int n,m,f[N+5][V+5],w[N+5];

int main() {
	scanf("%d%d",&m,&n);
	REP(i,1,n)scanf("%d",&w[i]);
	REP(i,1,n)
	REP(j,1,m)
	f[i][j]= j<w[i] ? f[i-1][j] : std::max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
	printf("%d",m-f[n][m]);
	return 0;
}
