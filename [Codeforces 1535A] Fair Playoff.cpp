#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

int a[4];

void solve()
{
	for (int i = 0; i < 4; i++) a[i] = read();
	int x = std::max(a[0], a[1]), y = std::max(a[2], a[3]);
	if (x < y) std::swap(x, y);
	std::sort(a, a + 4);
	if (x == a[3] and y == a[2]) puts("YES");
	else puts("NO");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

