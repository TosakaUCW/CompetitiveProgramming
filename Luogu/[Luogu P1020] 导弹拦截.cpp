#include <stdio.h>
#include <algorithm>

#define REP(i,x,y) for(int i=x;i<=y;i++)
#define N 100000

int n,a[N+5],f[N+5],len;
int d[N+5];

int main() {
	while(~scanf("%d",&a[++n]));
	//N^2������ �����鷳���nlogn����
	//��½�������
	//d[i]��ʾ����Ϊi���½�������ĩβԪ�ص���Сֵ
	d[1]=-a[1],len=1;
	REP(i,2,n) {
		if(-a[i]>=d[len])d[++len]=-a[i];
		else {
			int j=std::upper_bound(d+1,d+len,-a[i])-d;
			d[j]=-a[i];
		}
	}
	printf("%d\n",len-1);
	//����������� 
	d[1]=a[1],len=1;
	REP(i,2,n)
	if (a[i]>d[len]) d[++len]=a[i];
	else {
		int j=std::lower_bound(d+1,d+len+1,a[i])-d;
		d[j]=a[i];
	}
	printf("%d",len);
	return 0;
}
