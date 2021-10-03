#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 10 + 5;

int n[N], a[N], nn, k, x;

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0) return x = 1, y = 0, a;
    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y, y = z - a / b * y;
    return d;
}

signed main()
{
	k = read(), nn = 1;
	for (int i = 1; i <= k; i++) n[i] = read(), a[i] = read(), nn *= n[i];
	for (int i = 1; i <= k; i++)
	{
		int m = nn / n[i], mm, y;
		exgcd(m, n[i], mm, y);
		x = (x + a[i] * m * mm % nn) % nn;
	}
	return printf("%lld", (x % nn + nn) % nn), 0;
}
