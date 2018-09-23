#include<stdio.h>
#include<algorithm>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 1000
#define M 100

int n,m,f[M+5][N+5],w[M+5],c[M+5];

int main() {
	scanf("%d%d",&m,&n);
	REP(i,1,n)scanf("%d%d",&c[i],&w[i]);
	REP(i,1,n)
	REP(j,1,m)
	f[i][j]= j<c[i] ? f[i-1][j] : std::max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
	printf("%d",f[n][m]);
	return 0;
}
