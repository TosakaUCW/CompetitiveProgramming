#include <stdio.h>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define L 100
#define A 1000000

int a,b,l,x,y;

int gcd(int x,int y) {
	if(y==0)return x;
	return gcd(y,x%y);
}


int main() {
	scanf("%d%d%d",&a,&b,&l),x=l,y=1;
	REP(i,1,l)
	REP(j,1,l)
	if(gcd(i,j)==1 and i*b>=a*j and i*y<j*x)x=i,y=j;
	printf("%d %d",x,y);
	return 0;
}
