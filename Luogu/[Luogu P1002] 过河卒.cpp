#include <stdio.h>
#include <algorithm>

#define N 20
#define REP(i,x,y) for(int i=x;i<=y;i++)

long long n,m,x,y,f[N+5][N+5],map[N+5][N+5];

int main() {
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	n++,m++,x++,y++;
	f[0][1]=1;
	map[x][y]=1;
	map[x-1][y-2]=1;
	map[x-2][y-1]=1;
	map[x-2][y+1]=1;
	map[x-1][y+2]=1;
	map[x+1][y-2]=1;
	map[x+2][y-1]=1;
	map[x+2][y+1]=1;
	map[x+1][y+2]=1;
	REP(i,1,n)REP(j,1,m)
	if(map[i][j])continue;
	else f[i][j]=f[i-1][j]+f[i][j-1];
	printf("%lld",f[n][m]);
	return 0;
}
