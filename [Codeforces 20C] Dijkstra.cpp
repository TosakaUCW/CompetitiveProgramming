#include <stdio.h>
#define Rep(i,x,y) for(register int i=x;i<=y;++i)

const int N=100000;
const int M=100000;
const long long INF=1e12;
int n,m,num_edge,head[M+5],pre[N+5];
int front=1,tail,queue[100*M];
long long dis[N+5];
bool vis[N+5];
struct node {
    int next,to;
	long long dis;
} edge[2*M+5];

void add_edge(int from,int to,int dis) {
    ++num_edge;
    edge[num_edge].next=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}

void pop() {
    vis[queue[front++]]=false;
}

void push(int x) {
    if(vis[x])return;
    vis[x]=true;
    queue[++tail]=x;
}

void SPFA(int start) {
    Rep(i,0,n+100)dis[i]=INF;
    dis[start]=0;
    push(start);
    while(front<=tail) {
        int u=queue[front];
        pop();
        for(int i=head[u]; i; i=edge[i].next) {
            long long v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].dis) {
                dis[v]=dis[u]+edge[i].dis;
                pre[v]=u;
                push(v);
            }
        }
    }
}

void print(int k){
    if(pre[k]!=-1)print(pre[k]);
    printf("%d ",k);
}

int main() {
    scanf("%d%d",&n,&m);
    Rep(i,1,m) {
        int from,to,dis;
        scanf("%d%d%d",&from,&to,&dis);
        add_edge(from,to,dis);
        add_edge(to,from,dis);
    }
    SPFA(1);
    if(dis[n]==INF){
    	printf("-1");
    	return 0;
    }
    pre[1]=-1;
    print(n);
    return 0;
}
