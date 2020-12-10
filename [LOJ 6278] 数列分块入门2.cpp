#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define Rep(i,x,y) for(register int i=x;i<=y;i++)

const int N=5e4;

int n,a[N+5];
int belong[N+5],l[N+5],r[N+5],lazy[N+5],num,block;
std::vector <int> k[N+5];

void build(){
	block=sqrt(n);
	num=n/block;
	if(n%block)num++;
	Rep(i,1,num){
		l[i]=(i-1)*block+1;
		r[i]=i*block;
	}
	r[num]=n;
	Rep(i,1,n){
		belong[i]=(i-1)/block+1;
		k[belong[i]].push_back(a[i]);
	}
	Rep(i,1,num)std::sort(k[i].begin(),k[i].end());
}

void update(int x,int y,int num){
	if(belong[x]==belong[y]){
		k[belong[x]].clear();

		Rep(i,x,y)
			a[i]+=num;

		Rep(i,l[belong[x]],r[belong[x]])
			k[belong[x]].push_back(a[i]);

		std::sort(k[belong[x]].begin(),k[belong[x]].end());
	}
	else{
		k[belong[x]].clear();
		Rep(i,x,r[belong[x]])
			a[i]+=num;
		Rep(i,l[belong[x]],r[belong[x]])
			k[belong[x]].push_back(a[i]);
		std::sort(k[belong[x]].begin(),k[belong[x]].end());

		k[belong[y]].clear();
		Rep(i,l[belong[y]],y)
			a[i]+=num;
		Rep(i,l[belong[y]],r[belong[y]])
			k[belong[y]].push_back(a[i]);
		std::sort(k[belong[y]].begin(),k[belong[y]].end());

		Rep(i,belong[x]+1,belong[y]-1)
			lazy[i]+=num;
	}
}

void query(int x,int y,int num){
	int ans=0;
	if(belong[x]==belong[y]){
		Rep(i,x,y)
			if(a[i]+lazy[belong[x]]<num)
				ans++;
	}
	else{
		Rep(i,x,r[belong[x]])
			if(a[i]+lazy[belong[x]]<num)
				ans++;

		Rep(i,l[belong[y]],y)
			if(a[i]+lazy[belong[y]]<num)
				ans++;

		Rep(i,belong[x]+1,belong[y]-1){
			std::vector<int>::iterator pos;
			pos=std::upper_bound(k[i].begin(),k[i].end(),num-lazy[i]-1);
			ans+=pos-k[i].begin();
		}
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&n);
	Rep(i,1,n)scanf("%d",&a[i]);
	build();
	Rep(i,1,n){
		int opt,le,ri,c;
		scanf("%d%d%d%d",&opt,&le,&ri,&c);
		if(!opt)update(le,ri,c);
		else query(le,ri,c*c);
	}
	return 0;
}
