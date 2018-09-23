#include <stdio.h>
#include <algorithm>

#define N 9
#define REP(i,x,y) for(int i=x;i<=y;i++)

int n,f[N+5][N+5][N+5][N+5],map[N+5][N+5];

int main() {
	scanf("%d",&n);
	while(true) {
		int x,y,num;
		scanf("%d %d %d",&x,&y,&num);
		if (x==0 and y==0 and num==0) break;
		map[x][y]=num;
	}
	scanf("%*d%*d%*d");
	REP(i,1,n)REP(j,1,n)REP(a,1,n)REP(b,1,n) {
		int x=std::max(f[i-1][j][a-1][b],f[i-1][j][a][b-1]);
		int y=std::max(f[i][j-1][a-1][b],f[i][j-1][a][b-1]);
		f[i][j][a][b]=std::max(x,y)+map[i][j]+map[a][b];
		if(i==a)f[i][j][a][b]-=map[i][j];
	}
	printf("%d",f[n][n][n][n]);
	return 0;
}
