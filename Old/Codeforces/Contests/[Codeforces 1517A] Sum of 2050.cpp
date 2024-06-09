#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int K = 2050;

int n, ans;

int pow(int x, int k, int res = 1)
{
	for (; k; x = x * x, k >>= 1)
		if (k & 1) res *= x;
	return res;
}

signed main()
{
	for (int T = read(); T--; )
	{
		n = read(), ans = 0;
		while (n >= 2050)
		{
			int res;
			for (int L = 0, R = 18, mid; L <= R; )
				if (K * pow(10LL, mid = L + R >> 1) <= n)
					res = mid, L = mid + 1;
				else 
					R = mid - 1;
			ans += n / (K * pow(10LL, res));
			n %= K * pow(10LL, res);
		}
		printf("%lld\n", n ? -1 : ans);
	}
	return 0;

}
