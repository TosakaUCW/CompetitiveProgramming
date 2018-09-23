#include <stdio.h>
#include <algorithm>

#define N 1000
#define REP(i,x,y) for(int i=x;i<=y;i++)

long long t,len,n;
long long sw[N+5],sd[N+5][N+5],a[N+5],w[N+5];
double f[N+5];

int main() {
	scanf("%lld%lld%lld",&t,&len,&n);
	REP(i,1,n) {
		scanf("%d%d",&w[i],&a[i]);
		sw[i]=sw[i-1]+w[i];
		sd[i][i]=a[i];
	}

	REP(i,1,n-1)
	REP(j,i+1,n)
	sd[i][j]=std::min(sd[i][j-1],a[j]);

	REP(i,1,n) {
		f[i]=(double)len/a[i]+f[i-1];
		for (int j=i-1; j>=1; j--)
			if (sw[i]-sw[j-1]<=t) f[i]=std::min(f[i],f[j-1]+(double)len/(sd[j][i]));
			else break;
	}


	printf("%.1lf",f[n]*60);
	return 0;
}
