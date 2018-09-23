#include <stdio.h>

double k,a;

int main() {
	scanf("%lf",&k);
	for(double i=1;; i++) {
		a+=1/i;
		if(a>k) {
			printf("%.lf",i);
			break;
		}
	}
	return 0;
}
