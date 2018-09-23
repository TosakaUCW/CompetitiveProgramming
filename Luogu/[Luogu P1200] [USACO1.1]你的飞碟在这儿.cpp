#include <stdio.h>
#include <string>
#include <iostream>

#define REP(i,x,y) for(int i=x;i<=y;i++)

std::string a,b;
int x=1,y=1;

int main() {
	std::cin>>a>>b;
	REP(i,0,a.length()-1)x*=a[i]-'A'+1;
	REP(i,0,b.length()-1)y*=b[i]-'A'+1;
	if(x%47==y%47)printf("GO");
	else printf("STAY");
	return 0;
}
