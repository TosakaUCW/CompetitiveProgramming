#include <math.h>
#include <stdio.h>

#define N 10000
#define Scan(a) (a=Read())
#define Rep(i,x,y) for(int i=x;i<=y;i++)

int n,m;

inline int Read() {
	int in;
	char ch, sign;
	while(ch=getchar(),ch^'-'and(ch<'0' || ch>'9'));
	if (ch^'-')sign=1,in=ch-'0';
	else sign=-1,in=0;
	while(ch=getchar(),ch>='0' and ch<='9')
		in=(in<<3)+(in<<1)+ch-'0';
	return in*sign;
}

inline bool IsPrime(int num) {
	if(num==2 or num==3)return true;
	if(num%6!=1 and num%6!=5 or num==1)return false;
	int tmp=sqrt(num);
	for(int i=5; i<=tmp; i+=6)
		if(num%i==0 or num%(i+2)==0)
			return false;
	return true;
}

int main() {
	Scan(n),Scan(m);
	Rep(i,1,m){
		int tmp;
		Scan(tmp);
		if(IsPrime(tmp))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

