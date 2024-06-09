#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <string>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57)
		f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57)
		x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 4e2 + 5;
const int P = 1e9 + 7;
const int INF = 2147483647;

int n, m, ans;
int a[N][N], s[N][N], b[N];
std::string str;
int inv[N], fac[N], ifc[N];

int pow(int x, int k, int res = 1)
{
	for (x %= P, k %= (P - 1); k; k >>= 1, res = res * x % P)
		if (k & 1)
			res = res * x % P;
	return res % P;
}

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % P;
	inv[n] = pow(fac[n], P - 2);
	for (int i = n - 1; i >= 1; i--)
		inv[i] = inv[i + 1] * i % P;
}

#define C(n, m) ((m < 0 or m > n)0 \
				 : fac[n] * ifc[m] % P * ifc[n - m] % P)
#define S(a, b, c, d) (s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1])

void solve()
{
	n = read(), m = read(), ans = n * m;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j + 1] = str[j] - '0';
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

	for (int l = 1; l <= m; l++)
		for (int r = l + 3; r <= m; r++)
		{
			for (int i = n - 3; i >= 1; i--)
				if (i != n - 3)
					b[i] = r - l - 1 - S(i + 3, l + 1, i + 3, r - 1),
					b[i] += S(i, l + 1, i + 2, r - 1) - S(i, l, i + 2, l) - S(i, r, i + 2, r) + 6,
					b[i] = std::min(b[i], b[i + 1] + (!a[i][l]) + (!a[i][r]) + S(i, l + 1, i, r - 1));
				else
					b[i] = r - l - 1 - S(n, l + 1, n, r - 1),
					b[i] += S(i, l + 1, n - 1, r - 1) - S(i, l, n - 1, l) - S(i, r, n - 1, r),
					b[i] += 2 * n - 2 * i;
			for (int i = 1; i <= n - 4; i++)
				ans = std::min(ans, b[i + 1] + r - l - 1 - S(i, l + 1, i, r - 1));
		}
	printf("%lld\n", ans);
}

signed main()
{
	init(400);
	for (int T = read(); T--; solve())
		;
	return 0;
}
