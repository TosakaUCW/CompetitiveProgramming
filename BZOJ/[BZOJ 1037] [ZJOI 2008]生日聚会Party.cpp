#include <stdio.h>
#include <algorithm>
#define Rep(i,x,y) for(register int i=x;i<=y;i++)

using std::min;
using std::max;

const int K=20;
const int N=150;
const int P=12345678;
int ans,n,m,x,f[N+5][N+5][K+5][K+5];

int main() {
	scanf("%d%d%d",&n,&m,&x);

	f[0][0][0][0]=1;
	Rep(i,0,n)
	Rep(j,0,m)
	Rep(k,0,min(x,i))
	Rep(l,0,min(x,j)) {
		if(k<x)
			f[i+1][j][k+1][max(l-1,0)] = ( f[i][j][k][l] + f[i+1][j][k+1][max(l-1,0)] )%P;
		if(l<x)
			f[i][j+1][max(k-1,0)][l+1] = ( f[i][j][k][l] + f[i][j+1][max(k-1,0)][l+1] )%P;
	}

	Rep(i,0,x)
	Rep(j,0,x)
	ans=(ans+f[n][m][i][j])%P;

	printf("%d",ans);
	return 0;
}
