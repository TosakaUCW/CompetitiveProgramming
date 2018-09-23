#include <stdio.h>
#include <algorithm>

#define N 300
#define M 50000
#define Scan(a) (a=Read())
#define Rep(i,x,y) for(register int i=x;i<=y;i++)

int n,m,ans,k;

inline int Read() {
	int in;
	char ch,sign;
	while(ch=getchar(),ch^'-'&&(ch<'0' || ch>'9'));
	if (ch^'-')sign=1,in=ch-'0';
	else sign=-1,in=0;
	while(ch=getchar(),ch>='0'&&ch<='9')in=(in<<3)+(in<<1)+ch-'0';
	return in*sign;
}

namespace graph {
	int father[N+5];

	struct Node {
		int u,v,dis;
	} edge[M+5];

	inline void add_edge(int k,int u,int v,int dis) {
		graph::edge[k].u=u;
		graph::edge[k].v=v;
		graph::edge[k].dis=dis;
	}
}

inline bool cmp(graph::Node a,graph::Node b) {
	return a.dis<b.dis;
}

namespace mst {
	inline int find(int x) {
		while(x!=graph::father[x]) x=graph::father[x]=graph::father[graph::father[x]];
		return x;
	}

	inline void unite(int son,int dad) {
		graph::father[son]=dad;
	}

	void kruskal() {
		Rep(i,1,n)graph::father[i]=i;
		std::sort(graph::edge+1,graph::edge+1+m,cmp);
		Rep(i,1,m) {
			int find_u=mst::find(graph::edge[i].u);
			int find_v=mst::find(graph::edge[i].v);
			if(find_u!=find_v) {
				mst::unite(find_u,find_v);
				ans=std::max(ans,graph::edge[i].dis);
				k++;
				if(k==n-1)break;
			}
		}
	}
}

int main() {
	Scan(n),Scan(m);
	Rep(i,1,m) {
		int u,v,dis;
		Scan(u),Scan(v),Scan(dis);
		graph::add_edge(i,u,v,dis);
	}
	mst::kruskal();
	printf("%d %d",n-1,ans);
	return 0;
}
