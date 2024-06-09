#include <cmath>
#include <stdio.h>
#include <algorithm>

#define N 1000
#define REP(i,x,y) for(int i=x;i<=y;i++)

int n,q,a[N+5];

int main() {
	scanf("%d%d",&n,&q);
	REP(i,1,n)scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	REP(i,1,q) {
		int len,num,ans=-1;
		scanf("%d%d",&len,&num);
		REP(i,1,n)
		if(a[i]%(int)(pow(10,len))==num) {
			ans=a[i];
			break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

