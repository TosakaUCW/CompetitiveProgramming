#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long
#define gcd std::__gcd

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 1e2 + 5;
const int P = 1e9 + 7;

int lcm[N], n, res;

void solve()
{
	n = read(), lcm[1] = 1, res = 0;
	for (int i = 2; lcm[i - 1] <= n ; i++)
	{
		lcm[i] = i / gcd(lcm[i - 1], i) * lcm[i - 1];
		(res += i * (n / lcm[i - 1] - n / lcm[i]) % P) %= P;
	}
	printf("%lld\n", res);
}

signed main()
{
	for (int T = read(); T--; solve());
	return 0;
}
