#include <stdio.h>
#include <algorithm>

#define N 100000
#define Rep(i,x,y) for(register int i=x;i<=y;i++)

int n,a[N+5],b[N+5];

int func(int a[],int b[]) {
    int head_a=1,head_b=1,tail_a=n,tail_b=n,ans=0;
    while (head_a<=tail_a) {
        if (a[head_a]>b[head_b]) head_a++,head_b++,ans+=2;
        else if (a[tail_a]>b[tail_b]) tail_a--,tail_b--,ans+=2;
        else {
            if (a[head_a]==b[tail_b]) ans++;
            head_a++,tail_b--;
        }
    }
    return ans;
}

int main() {
	scanf("%d",&n);
	Rep(i,1,n)scanf("%d",&a[i]);
	Rep(i,1,n)scanf("%d",&b[i]);
	std::sort(a+1,a+1+n);
	std::sort(b+1,b+1+n);
	printf("%d %d",func(a,b),2*n-func(b,a));
	return 0;
}
