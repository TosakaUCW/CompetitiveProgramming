#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define M 100
#define N 1000
#define INF 0x7fffffff
#define CLR(x,c) memset(x,c,sizeof(x))
#define REP(i,x,y) for(int i=x;i<=y;i++)

int m,n,map[M+5][M+5],mem[M+5][M+5],ans=INF;
int move_x[]= {0,1,-1,0,0},move_y[]= {0,0,0,-1,1};

void dfs(int x,int y,int tot,bool flag) {
	if(x<1 or y<1 or x>m or y>m or !map[x][y] or tot>=mem[x][y])return;
	mem[x][y]=tot;
	if(x==m and y==m)ans=std::min(ans,tot);
	else REP(i,1,4) {
		int xx=x+move_x[i];
		int yy=y+move_y[i];
		if(map[xx][yy]) {
			if(map[xx][yy]==map[x][y])dfs(xx,yy,tot,false);
			else dfs(xx,yy,tot+1,false);
		} else if(!map[xx][yy] and !flag) {
			map[xx][yy]=map[x][y];
			dfs(xx,yy,tot+2,true);
			map[xx][yy]=0;
		}
	}
}

int main() {
	CLR(mem,0x7f);
	scanf("%d%d",&m,&n);
	REP(i,1,n) {
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c+1;
		///2»Æ1ºì
	}
	dfs(1,1,0,false);
	if(ans<INF)printf("%d",ans);
	else printf("-1");
	return 0;
}
