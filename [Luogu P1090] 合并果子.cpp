#include <queue>
#include <stdio.h>

#define N 10000
#define Scan(a) (a=Read())
#define Rep(i,x,y) for(int i=x;i<=y;i++)

int n,ans;
std::priority_queue<int,std::vector<int>,std::greater<int> >q;

inline int Read() {
	int in;
	char ch, sign;
	while(ch=getchar(),ch^'-'and(ch<'0' || ch>'9'));
	if (ch^'-')sign=1,in=ch-'0';
	else sign=-1,in=0;
	while(ch=getchar(),ch>='0' and ch<='9')
		in=(in<<3)+(in<<1)+ch-'0';
	return in*sign;
}

int main() {
	Scan(n);
	Rep(i,1,n) {
		int tmp;
		Scan(tmp);
		q.push(tmp);
	}
//	while(!q.empty())printf("%d ",q.top()),q.pop();
	Rep(i,1,n-1) {
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	printf("%d",ans);
	return 0;
}
