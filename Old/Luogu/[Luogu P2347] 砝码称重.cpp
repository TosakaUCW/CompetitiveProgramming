#include<stdio.h>
#include<algorithm>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 1000

int s[]= {0,1,2,3,5,10,20},ans,n,w[N+5];
bool sum[N+5];

int main() {
	REP(i,1,6) {
		int tmp;
		scanf("%d",&tmp);
		REP(j,1,tmp)w[++n]=s[i];
	}
	
	sum[0]=1;
	REP(i,1,n)
	for(int j=N; j>=0; j--)
		if(sum[j])sum[j+w[i]]=true;

	REP(i,1,1000)if(sum[i])ans++;
	
	printf("Total=%d",ans);
	return 0;
}
