#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;
const int K = 17 + 1;

int n, k;
int f[1 << K];
int g[N][K];
char s[N];

bool judge(int len)
{
	for (int i = 1; i <= k; i++) g[n + 1][i] = g[n + 2][i] = n + 2;
	for (int  j = 1; j <= k; j++)
	{
		int tot = 0;
		for (int i = n; i >= 1; i--)
		{
			if (s[i] == '?' or s[i] - 96 == j)
				tot++;
			else
				tot = 0;
			if (tot >= len)
				g[i][j] = i + len;
			else
				g[i][j] = g[i + 1][j];
		}
	}
	for (int i = 0; i < (1 << k); i++) f[i] = n + 2;
	f[0] = 1;
	for (int i = 0; i < (1 << k); i++)
		for (int j = 1; j <= k; j++)
			if (((i >> (j - 1)) & 1) == 0)
				f[i ^ (1 << (j - 1))] = std::min(f[i ^ (1 << (j - 1))], g[f[i]][j]);
	return f[(1 << k) - 1] <= n + 1; 
}

int main()
{
	n = read(), k = read();
	scanf("%s", s + 1);
	int L = 0, R = n, res = -1;
	while (L <= R)
	{
		int mid = (L + R) >> 1;
		if (judge(mid)) res = mid, L = mid + 1;
		else R = mid - 1;
	}
	return printf("%d", res), 0;
}

