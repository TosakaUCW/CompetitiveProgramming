#include<stdio.h>
#include<algorithm>

#define N 100
#define REP(x,y,z) for(int x=y;x<=z;x++)

int n,m,e[2*N+5],f[2*N+5][2*N+5],ans;

int main() {
	scanf("%d",&n),m=2*n-1;
	REP(i,1,n)scanf("%d",&e[i]),e[i+n]=e[i];
	e[0]=e[n];

	REP(j,1,m)
	for(int i=j; i>=1 and i>j-n; i--)
		REP(k,i,j-1) {
		int s=e[i]*e[k+1]*e[j+1];
		f[i][j]=std::max(f[i][j],f[i][k]+f[k+1][j]+s);
		ans=std::max(f[i][j],ans);
	}
	printf("%d",ans);
	return 0;
}
