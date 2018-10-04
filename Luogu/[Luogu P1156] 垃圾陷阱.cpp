#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define Rep(i,x,y) for(register int i=x;i<=y;i++)

const int N = 100;
struct Node {
	int t,f,h;
} a[N+5];
int max_depth,tot_life,n,f[N+5][40*N+5];

inline bool compare(Node a,Node b) {
	return a.t<b.t;
}

int main() {
	scanf("%d%d",&max_depth,&n);
	Rep(i,1,n) {
		scanf("%d%d%d",&a[i].t,&a[i].f,&a[i].h);
		tot_life+=a[i].f;
	}

	std::sort(a+1,a+1+n,compare);
	memset(f,-127,sizeof(f));
	f[0][10]=0;

	Rep(i,1,n)
	Rep(j,10,10+tot_life) {
		if(j>=a[i].t) {
			f[i][j+a[i].f] = std::max(f[i][j+a[i].f],f[i-1][j]);
			f[i][j] = std::max(f[i-1][j]+a[i].h,f[i][j]);
		}
	}

	Rep(i,1,n)
	Rep(j,10,10+tot_life)
	if(f[i][j]>=max_depth) {
		printf("%d",a[i].t);
		return 0;
	}

	int tmp=10;
	Rep(i,1,n) {
		if(tmp<a[i].t) {
			printf("%d",tmp);
			return 0;
		}
		tmp+=a[i].f;
	}
	printf("%d",tmp);
	return 0;
}
