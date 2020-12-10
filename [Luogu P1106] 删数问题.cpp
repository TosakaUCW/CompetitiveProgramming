#include <stdio.h>
#include <string.h>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 240

char n[N+5];
int len,s;

int main() {
	int len,s;
	scanf("%s%d",n,&s),len=strlen(n);
	
	while(s--) {
		REP(i,0,len-2)
		if(n[i]>n[i+1]) {
			REP(j,i,len-2)
			n[j]=n[j+1];
			break;
		}
		len--;
	}

	int i=0;
	while(i<=len-1 and n[i]=='0')i++;
	if(i==len)printf("0");
	else REP(j,i,len-1)
		printf("%c",n[j]);
	return 0;
}
