#include <stdio.h>
#include <algorithm>
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

int n, k;
int a[N];
std::unordered_map<int, bool> map;

void solve()
{
	n = read(), k = read(), map.clear();
	for (int i = 1; i <= n; i++) map[a[i] = read()] = true;
	if (!k) return printf("%lld", n), void();
	std::sort(a + 1, a + 1 + n);
	int mex = a[n] + 1;
	if (a[1]) mex = 0;
	else 
		for (int i = 2; i <= n; i++)
			if (a[i] != a[i - 1] + 1) { mex = a[i - 1] + 1; break; }
	if (mex == a[n] + 1) printf("%lld", n + k);
	else if (!map[(mex + a[n] + 1) / 2]) printf("%lld", n + 1);
	else printf("%lld", n);
}

signed main()
{
	for (int T = read(); T--; solve(), puts(""));
	return 0;
}
