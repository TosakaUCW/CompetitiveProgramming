#include <stdio.h>
#include <math.h>
#define Rep(i,x,y) for(register int i=x;i<=y;i++)

const int N=5e4;

int n,a[N+5];
int belong[N+5],l[N+5],r[N+5],num,block,lazy[N+5];
	
void build(){
	block=sqrt(n);
	num=n/block;
	if(n%block)num++;
	Rep(i,1,num){
		l[i]=(i-1)*block+1;
		r[i]=i*block;
	}
	r[num]=n;
	Rep(i,1,n)
		belong[i]=(i-1)/block+1;
}

void update(int x,int y,int num){
	if(belong[x]==belong[y])
		Rep(i,x,y)a[i]+=num;
	else{
		Rep(i,x,r[belong[x]]) a[i]+=num;
		Rep(i,l[belong[y]],y) a[i]+=num;
		Rep(i,belong[x]+1,belong[y]-1) lazy[i]+=num;
	}
}

void query(int x){
	printf("%d\n",a[x]+lazy[belong[x]]);
}

int main(){
	scanf("%d",&n);
	Rep(i,1,n)scanf("%d",&a[i]);
	build();
	Rep(i,1,n){
		int opt,le,ri,c;
		scanf("%d%d%d%d",&opt,&le,&ri,&c);
		if(!opt)update(le,ri,c);
		else query(ri);
	}
	return 0;
} 
