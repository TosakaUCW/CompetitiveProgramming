#include<stdio.h>

#define Rep(i,x,y) for(register int i=x;i<=y;i++)

const int N = 500000;
int n,ans,a[N+5];

void merge(int l,int m,int r) {
	int tmp[N+5];
	int x=l,y=m+1,k=x;
	while (k<=r)
		if (y>r or x<=m and a[x]<=a[y])tmp[k++]=a[x++];
		else tmp[k++]=a[y++],ans+=m-x+1;
	Rep(i,l,r) a[i]=tmp[i];
}

void merge_sort(int l,int r) {
	if (l<r) {
		int m=(l+r)/2;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge(l,m,r);
	}
}

int main() {
	scanf("%d",&n);
	Rep(i,1,n)scanf("%d",&a[i]);
	merge_sort(1,n);
	printf("%d",ans);
	return 0;
}
