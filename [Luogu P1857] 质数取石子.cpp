#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e4 + 5;
const int INF = 2147483647;

int pri[N], g[N], cnt;
bool vis[N], f[N];


void init()
{
	for (int i = 2; i < N; i++)
	{
		if (!vis[i]) pri[++cnt] = i;
		for (int j = 1; j <= cnt and i * pri[j] < N; j++)
		{
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	g[0] = g[1] = 0;
	for (int i = 2; i < N; i++)
	{
		int min = INF, max = -INF, flag = 0;
		for (int j = 1; j <= cnt and pri[j] <= i; j++)
			if (!f[i - pri[j]]) flag = 1, min = std::min(min, g[i - pri[j]]);
		for (int j = 1; j <= cnt and pri[j] <= i; j++)
			if (f[i - pri[j]]) max = std::max(max, g[i - pri[j]]);
		if (flag) f[i] = 1, g[i] = min + 1;
		else g[i] = max + 1;
	}
}

int main()
{
	init();
	for (int T = read(), x; T--; ) x = read(), printf("%d\n", f[x] ? g[x] : -1);
	return 0;
}
