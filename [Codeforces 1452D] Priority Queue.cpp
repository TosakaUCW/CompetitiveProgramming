#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

#define int long long

const int N = 5e2 + 5;
const int P = 998244353;

int n, a[N], sum[N], f[N][N], ans;

signed main()
{
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char opt; std::cin >> opt;
		sum[i] = sum[i - 1];
        if(opt == '+') sum[i]++, std::cin >> a[i];
	}
	for (int x = 1; x <= n; x++)
	{
		if (!a[x]) continue;
		memset(f, 0, sizeof f), f[0][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= sum[i]; j++)
			{
				if (i != x) 
					f[i][j] = f[i - 1][j];
				if (!a[i])
				{
					if (i < x)
					{
						if (j == 0) 
							f[i][0] = (f[i][0] + f[i - 1][0] + f[i - 1][1]) % P;
						else 
							f[i][j] = (f[i][j] + f[i - 1][j + 1]) % P;
					}
					else
						f[i][j] = (f[i][j] + f[i - 1][j + 1]) % P;
				}
				else
				{
					if (a[i] < a[x] or a[i] == a[x] and i < x) 
						f[i][j] = (f[i][j] + f[i - 1][j - 1]) % P;
					else
						f[i][j] = (f[i][j] + f[i - 1][j]) % P;
				}
			}
		for (int j = 0; j <= sum[n]; j++) 
			ans = (ans + f[n][j] * a[x] % P) % P;
	}
	return printf("%lld", ans), 0;
}
