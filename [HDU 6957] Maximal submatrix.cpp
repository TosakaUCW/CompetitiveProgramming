#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e3 + 5;

int n, m, ans, a[N][N], l[N][N], r[N][N], h[N][N];

void solve()
{
	n = read(), m = read(), ans = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = read(), l[i][j] = r[i][j] = j, h[i][j] = 1;
	for (int j = 1; j <= m; j++) for (int i = 1; i < n; i++) if (a[i][j] <= a[i + 1][j]) h[i + 1][j] = h[i][j] + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) while (l[i][j] > 1 and h[i][j] <= h[i][l[i][j] - 1]) l[i][j] = l[i][l[i][j] - 1];
	for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--) while (r[i][j] < m and h[i][j] <= h[i][r[i][j] + 1]) r[i][j] = r[i][r[i][j] + 1];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans = std::max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
	printf("%d\n", ans);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
/*
4 4
9 9 9 9
9 10 10 9
9 9 9 9
9 9 9 9
*/
