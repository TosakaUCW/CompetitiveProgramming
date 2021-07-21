#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

#define judge

int read(int x = 0, int f = 0, char ch = getchar()) 
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;

int n, k, tot, cnt, buk[N], ans[N];
long long fac[N];
bool vis[N];

void init()
{
	fac[1] = fac[2] = 1;
	for (int i = 3; i <= 20; i++) fac[i] = fac[i - 1] * (i - 1);
	buk[1] = 4, buk[2] = 7;
	tot = 0, cnt = 2;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = tot + 1; j <= tot + (1 << i); j++)
			buk[++cnt] = buk[j] * 10 + 4, buk[++cnt] = buk[j] * 10 + 7;
		tot += 1 << i;
	}
}

int find(int pos = 1)
{
	for (; pos <= n + 1; pos++) if (k < fac[pos]) break;
	return pos - 1;
}

bool judge(int x, int y)
{
	for (; x; x /= 10) if (x % 10 != 4 and x % 10 != 7) return false;
	for (; y; y /= 10) if (y % 10 != 4 and y % 10 != 7) return false;
	return true;
}

int main() {
#ifdef judge
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
#endif
	init(), n = read(), k = read();
	if (n <= 18 and k > fac[n + 1] or !k) return puts("-1"), 0;
	k--;
	int pos = find();
	for (int i = pos; i >= 1; i--)
	{
		int tmp = k / fac[i] + 1, p = 0;
		k %= fac[i];
		for (int j = 1; j <= pos; j++) if (!vis[j]) if (++p == tmp) { p = j, vis[j] = 1; break;}
		ans[pos - i + 1] = p;
	}
	long long res = 0;
	for (int i = 1; i <= cnt; i++) 
		if (buk[i] > n - pos) break;
		else res++;
	for (int i = 1; i <= pos; i++)
		if (judge(n - pos + i, n - pos + ans[i]))
			res++;
	printf("%lld", res);
	return 0;
}
