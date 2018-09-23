#include <stdio.h>
#include <string>
#include <iostream>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define K 100
#define N 1000

std::string c,k;
char r['z'+1]['z'+1];
bool big[N+5];

int main() {
  REP(i,'a','z') {
    r[i]['a']=i;
    REP(j,'a'+1,'z')
    if(r[i][j-1]=='z')r[i][j]='a';
    else r[i][j]=r[i][j-1]+1;
  }
  std::cin>>k>>c;
  int len_k=k.length(),len_c=c.length();

  REP(i,0,len_k-1)k[i]=tolower(k[i]);
  REP(i,0,len_c-1)if(c[i]>='A' and c[i]<='Z') {
    big[i]=true,c[i]=tolower(c[i]);
  }

  for(int i=0,j=0; i<=len_c-1; i++,j++) {
    if(j==len_k)j=0;
    char s;
    REP(p,'a','z')if(r[k[j]][p]==c[i]) {
      s=p;
      break;
    }
    if(big[i])s=s-'a'+'A';
    printf("%c",s);
  }
  return 0;
}

