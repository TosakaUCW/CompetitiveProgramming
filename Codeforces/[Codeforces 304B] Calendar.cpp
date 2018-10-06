#include <stdio.h>
#include <algorithm>
#define Rep(i,x,y) for(register int i=x;i<=y;i++)

int year_1,month_1,day_1;
int year_2,month_2,day_2;
bool vis[2039][13][32];
int ans;

void dfs(int year,int month,int day) {
	if(vis[year][month][day])return;
	if(year==year_2 and month==month_2 and day==day_2)return;
	vis[year][month][day]=true;
	ans++;
	if(month==1 and day==31)dfs(year,month+1,1);
	else if(month==2 and day==28 and !(year%400==0 or (year%4==0 and year%100!=0)))dfs(year,month+1,1);
	else if(month==2 and day==29 and (year%400==0 or (year%4==0 and year%100!=0)))dfs(year,month+1,1);
	else if(month==3 and day==31)dfs(year,month+1,1);
	else if(month==4 and day==30)dfs(year,month+1,1);
	else if(month==5 and day==31)dfs(year,month+1,1);
	else if(month==6 and day==30)dfs(year,month+1,1);
	else if(month==7 and day==31)dfs(year,month+1,1);
	else if(month==8 and day==31)dfs(year,month+1,1);
	else if(month==9 and day==30)dfs(year,month+1,1);
	else if(month==10 and day==31)dfs(year,month+1,1);
	else if(month==11 and day==30)dfs(year,month+1,1);
	else if(month==12 and day==31)dfs(year+1,1,1);	
	else dfs(year,month,day+1);
}

int main() {
	scanf("%d:%d:%d\n",&year_1,&month_1,&day_1);
	scanf("%d:%d:%d",&year_2,&month_2,&day_2);
	if(year_1>year_2 or (year_1==year_2 and month_1>month_2) or (year_1==year_2 and month_1==month_2 and day_1>day_2)) {
		std::swap(year_1,year_2);
		std::swap(month_1,month_2);
		std::swap(day_1,day_2);
	}
	dfs(year_1,month_1,day_1);
	printf("%d",ans);
	return 0;
}
