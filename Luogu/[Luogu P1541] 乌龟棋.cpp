#include <stdio.h>
#include <algorithm>

#define Rep(i,x,y) for(register int i=x;i<=y;i++)

const int N = 350;
const int M = 120;

int n,m,score[N+5],f[M+5][M+5][M+5][M+5],num[5];

int main() {
	scanf("%d%d",&n,&m);
	Rep(i,1,n)scanf("%d",&score[i]);
	Rep(i,1,m) {
		int tmp;
		scanf("%d",&tmp);
		num[tmp]++;
	}
	f[0][0][0][0]=score[1];
	Rep(i,0,num[1])
	Rep(j,0,num[2])
	Rep(k,0,num[3])
	Rep(l,0,num[4]){
		int dis = i+j*2+k*3+l*4+1;
		if(i)f[i][j][k][l] = std::max(f[i][j][k][l],f[i-1][j][k][l]+score[dis]);
		if(j)f[i][j][k][l] = std::max(f[i][j][k][l],f[i][j-1][k][l]+score[dis]);
		if(k)f[i][j][k][l] = std::max(f[i][j][k][l],f[i][j][k-1][l]+score[dis]);
		if(l)f[i][j][k][l] = std::max(f[i][j][k][l],f[i][j][k][l-1]+score[dis]);
	}
	printf("%d",f[num[1]][num[2]][num[3]][num[4]]);
	return 0;
}
