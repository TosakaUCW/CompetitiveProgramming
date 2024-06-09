#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

int f[10];

void solve()
{
	int a = read(), b = read(), c = read();
	int x = 1, y = 1, z = 1;
	while (x < f[c]) x *= 2;
	y = z = x;
	while (y < f[a]) y *= 2;
	while (z < f[b]) z *= 3;
	printf("%d %d\n", y, z);
}

int main()
{
	f[1] = 1;
	for (int i = 2; i <= 9; i++) f[i] = f[i - 1] * 10;
	for (int T = read(); T--; solve());
	return 0;
}

