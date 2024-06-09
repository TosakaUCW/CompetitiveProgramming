#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <unordered_map>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;

int n, siz[N], a[N], dep[N], fa[N], sum;
std::unordered_map<int, int> b;

signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) b[a[i] = read()] = i, siz[i] = 1;
	std::sort(a + 1, a + 1 + n);
	for (int i = n; i > 1; i--)
	{
		int u = b[a[i]], f = b[a[i] + siz[u] * 2 - n];
		fa[u] = f, siz[f] += siz[u];
		if (!f or fa[f]) return puts("-1"), 0;
	}
	for (int i = 2, u; i <= n; i++) 
		u = b[a[i]], dep[u] = dep[fa[u]] + 1, sum += dep[u];
	if (sum != a[1]) return puts("-1"), 0;
	for (int i = 2, u; i <= n; i++) u = b[a[i]], printf("%lld %lld\n", u, fa[u]);
	return 0;
}
