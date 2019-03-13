#include <stdio.h>

const int N = 2e6 + 5;

int n, k;
int a[N], queue[3 * N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int head = 1, tail = 0;
	puts("0");
	for (int i = 1; i <= n - 1; i++)
	{
		while (head <= tail and queue[head] + k <= i)
			++head;
		while (head <= tail and a[queue[tail]] > a[i])
			--tail;
		queue[++tail] = i;
		printf("%d\n", a[queue[head]]);
	}
	return 0;
}