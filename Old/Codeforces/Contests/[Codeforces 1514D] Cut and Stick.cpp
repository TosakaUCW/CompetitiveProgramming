#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <map>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;
const int SIZE = 8e2 + 5;

int n, m, S;
int a[N], pos[N], cnt[N], sum[N];
int zs[SIZE][SIZE], bel[N], L[N], R[N];
std::map<int, int> b;
std::vector<int> vec[N];

int main()
{
	n = read(), m = read(), S = sqrt(n);
	for (int i = 1; i <= n; i++)
		b[a[i] = read()] = 0;
	for (int i = 1; i <= S; i++)
		L[i] = n / S * (i - 1) + 1, R[i] = n / S * i;
	R[S] = n;
	for (int i = 1; i <= S; i++)
		for (int j = L[i]; j <= R[i]; j++)
			bel[j] = i;
	int cnt = 0;
	for (std::map<int, int>::iterator it = b.begin(); it != b.end(); it++)
		it->second = ++cnt;
	for (int i = 1; i <= n; i++)
		a[i] = b[a[i]],
		vec[a[i]].push_back(i),
		pos[i] = vec[a[i]].size() - 1;
	for (int i = 1; i <= S; i++)
	{
		memset(::cnt, 0, sizeof ::cnt);
		for (int j = i; j <= S; j++)
		{
			zs[i][j] = zs[i][j - 1];
			for (int k = L[j]; k <= R[j]; k++)
				zs[i][j] = std::max(zs[i][j], ++::cnt[a[k]]);
		}
	}
	for (int ans, x, y; m--;)
	{
		x = read(), y = read(), ans = 0;
		if (x > y) std::swap(x, y);
		if (bel[y] - bel[x] <= 3)
		{
			for (int i = x; i <= y; i++) sum[a[i]] = 0;
			for (int i = x; i <= y; i++) ans = std::max(ans, ++sum[a[i]]);
		}
		else
		{
			ans = zs[bel[x] + 1][bel[y] - 1];
			for (int i = x, now; i <= R[bel[x]]; i++)
			{
				now = pos[i];
				while (now + ans < vec[a[i]].size() and vec[a[i]][now + ans] <= y) ans++;
			}
			for (int i = L[bel[y]], now; i <= y; i++)
			{
				now = pos[i];
				while (now - ans >= 0 and vec[a[i]][now - ans] >= x) ans++;
			}
		}
		int len = y - x + 1;
		printf("%d\n", ans <= (len + 1) / 2 ? 1 : 2 * ans - len);
	}
	return 0;
}
