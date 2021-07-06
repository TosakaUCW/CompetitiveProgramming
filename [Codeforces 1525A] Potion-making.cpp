#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int x = read();
	int y = std::__gcd(100, x);
	printf("%d\n", 100 / y);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
