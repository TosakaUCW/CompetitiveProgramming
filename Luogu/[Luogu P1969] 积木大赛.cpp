#include <stdio.h>

#define Rep(i,x,y) for(register int i=x;i<=y;i++)

int n,ans,num;

int main() {
	scanf("%d",&n);
	scanf("%d",&ans);
	num=ans;
	Rep(i,2,n){
		int tmp;
		scanf("%d",&tmp);
		if(tmp>num)ans+=tmp-num;
		num=tmp;
	}
	printf("%d",ans);
	return 0;
}
