#include <stdio.h>
#include <algorithm>

#define N 5000
#define M 200000
#define REP(i,x,y) for(register int i=x;i<=y;i++)

struct Node {
	int u,v,dis;
} edge[M+5];

int n,m,tot,k,father[N+5];

inline int find(int x) {
	while(x!=father[x]) x=father[x]=father[father[x]];
	return x;
}

inline void unite(int son,int dad) {
	father[son]=dad;
}

inline bool cmp(Node a,Node b) {
	return a.dis<b.dis;
}

void kruskal() {
	REP(i,1,n)father[i]=i;
	std::sort(edge+1,edge+1+m,cmp);
	REP(i,1,m) {
		int find_u=find(edge[i].u);
		int find_v=find(edge[i].v);
		if(find_u!=find_v) {
			unite(find_u,find_v);
			tot-=edge[i].dis;
			k++;
			if(k==n-1)break;
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	REP(i,1,m)scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].dis),tot+=edge[i].dis;
	kruskal();
	printf("%d",tot);
	return 0;
}
