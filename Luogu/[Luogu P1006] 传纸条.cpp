#include <stdio.h>
#include <algorithm>

#define N 50
#define REP(i,x,y) for(int i=x;i<=y;i++)

int n,m,f[N+5][N+5][N+5][N+5],map[N+5][N+5];

int main() {
	scanf("%d%d",&m,&n);
	REP(i,1,m)REP(j,1,n)
	scanf("%d",&map[i][j]);
	REP(i,1,m)REP(j,1,n)REP(a,1,m)REP(b,1,n) {
		int x=std::max(f[i-1][j][a-1][b],f[i-1][j][a][b-1]);
		int y=std::max(f[i][j-1][a-1][b],f[i][j-1][a][b-1]);
		f[i][j][a][b]=std::max(x,y)+map[i][j]+map[a][b];
		if(i==a and j==b)f[i][j][a][b]-=map[i][j];
	}
	printf("%d",f[m][n][m][n]);
	return 0;
}
