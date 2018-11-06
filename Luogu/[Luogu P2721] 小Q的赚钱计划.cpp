#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e4;
const int DAY = 365;
const int day[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int n;
double f[DAY + 5];
struct Node
{
	int start, end;
	double k;
} a[N + 5];

inline bool cmp(Node a, Node b)
{
	return a.end > b.end;
}

int main()
{
	scanf("%d", &n);
	Rep(i, 1, n)
	{
		int date, len;
		scanf("%d%d%lf", &date, &len, &a[i].k);
		a[i].start = day[date / 100] + date % 100;
		a[i].end = len + a[i].start - 1;
		a[i].k = a[i].k / 100 / 365 * len + 1;
	}
	std::sort(a + 1, a + 1 + n, cmp);
	f[0] = 1;
	Rep(i, 1, DAY)
	{
		f[i] = f[i - 1];
		Rep(j, 1, n)
		{
			if (a[j].end < i)
				break;
			if (a[j].end == i)
				f[i] = std::max(f[i], f[a[j].start - 1] * a[j].k);
		}
	}
	printf("%.2lf", f[DAY] * 100000);
	return 0;
}