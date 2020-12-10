#include <stdio.h>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 100

int a[N+5],ans,n;
bool b[200*N+5];

int main() {
	scanf("%d",&n);
	REP(i,1,n)scanf("%d",&a[i]),b[a[i]]=true;
	REP(i,1,n)REP(j,1,n)
	if(i!=j and b[a[i]+a[j]])b[a[i]+a[j]]=false,ans++;
	printf("%d",ans);
	return 0;
}
