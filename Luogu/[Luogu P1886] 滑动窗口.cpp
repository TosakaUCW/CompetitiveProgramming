#include <stdio.h>
#define Rep(i,x,y) for(register int i=x;i<=y;++i)

const int N=1e6;
int n,k,a[N+5],queue[3*N+5];

void min() {
	int head=1,tail=0;
	Rep(i,1,n) {
		while(head<=tail and queue[head]+k<=i)++head;
		while(head<=tail and a[queue[tail]]>a[i])--tail;
		queue[++tail]=i;
		if(i>=k)printf("%d ",a[queue[head]]);
	}
}

void max() {
	int head=1,tail=0;
	Rep(i,1,n) {
		while(head<=tail and queue[head]+k<=i)++head;
		while(head<=tail and a[queue[tail]]<a[i])--tail;
		queue[++tail]=i;
		if(i>=k)printf("%d ",a[queue[head]]);
	}
}

int main() {
	scanf("%d%d",&n,&k);
	Rep(i,1,n)scanf("%d",&a[i]);
	min();
	printf("\n");
	max();
	return 0;
}
