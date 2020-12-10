#include <stdio.h>
#define Rep(i,x,y) for(register int i=x;i<=y;++i)

const int N=10000;
const int M=500000;
const int INF=2147483647;
int n,m,start,num_edge,dis[N+5],head[N+5];
int front=1,tail,queue[4*M];
bool vis[N+5];
struct node {
    int next,to,dis;
} edge[M+5];

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
    Rep(i,1,n)dis[i]=INF;
    dis[start]=0;
    push(start);
    while(front<=tail) {
        int u=queue[front];
        pop();
        for(int i=head[u]; i; i=edge[i].next) {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].dis) {
                dis[v]=dis[u]+edge[i].dis;
                push(v);
            }
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&start);
    Rep(i,1,m) {
        int from,to,dis;
        scanf("%d%d%d",&from,&to,&dis);
        add_edge(from,to,dis);
    }
    SPFA(start);
    Rep(i,1,n)printf("%d ",dis[i]);
    return 0;
}
