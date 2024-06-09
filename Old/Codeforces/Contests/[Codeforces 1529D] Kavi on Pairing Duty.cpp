#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e6 + 5;
const int P = 998244353;

int n, f[N], g[N], sum;

int main()
{
	n = read();
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			g[j]++;
	for (int i = 1; i <= n; i++)
		f[i] = (g[i] + sum) % P, sum = (sum + f[i]) % P;
	return printf("%d", f[n]), 0;
}
