#include <stdio.h>
#include <algorithm>

#define int long long

const int N = 1e5 + 5;

int n, p = 1, a[N];

signed main()
{
	scanf("%lld", &n);
	for (int i = 1; i < n; i++)
		if (std::__gcd(n, i) == 1)
			a[i] = 1, p = p * i % n;
	if (p != 1) a[p] = 0;
	printf("%d\n", std::count(a + 1, a + 1 + n, 1));
	for (int i = 1; i < n; i++)
		if (a[i]) printf("%lld ", i);
	return 0;
}
