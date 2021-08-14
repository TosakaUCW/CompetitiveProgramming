#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e5 + 5;
const int INF = 2147483647;

int n, k, ans, ansL, ansR, cnt;
int ch[N << 4][2], t[N << 4];

void insert(int num, int pos)
{
	for (int i = 30, p = 0; i >= 0; i--)
	{
		int x = num >> i & 1;
		if (!ch[p][x]) ch[p][x] = ++cnt;
		p = ch[p][x], t[p] = std::max(t[p], pos);
	}
}

int query(int num)
{
	int res = -1, p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int x = num >> i & 1;
		if (k >> i & 1) p = ch[p][!x];
		else res = std::max(res, t[ch[p][!x]]), p = ch[p][x];
		if (!p) break;
	}
	if (p) res = std::max(res, t[p]);
	return res;
}

void solve()
{
	n = read(), k = read(), ansL = -1, ansR = cnt = 0, ans = INF;
	memset(ch, 0, sizeof ch), memset(t, -1, sizeof t);
	for (int i = 1, sum = 0; i <= n; i++)
	{
		insert(sum, i), sum ^= read();
		int j = query(sum);
		if (j != -1 and i - j + 1 < ans) ans = i - j + 1, ansL = j, ansR = i;
	}
	if (ansL != -1) printf("%d %d\n", ansL, ansR); else puts("-1");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

