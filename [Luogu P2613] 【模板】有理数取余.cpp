#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int P = 19260817;
int a, b;
std::string s, t;

int pow(int x, int k, int res = 1)
{
	for (x %= P, k %= (P - 1); k; k >>= 1, x = x * x % P) if (k & 1) res = res * x % P;
	return res;
}

signed main()
{
	std::cin >> s >> t;
	for (auto ch : s) a = (a * 10 + ch - 48) % P;
	for (auto ch : t) b = (b * 10 + ch - 48) % P;
	if (!b) puts("Angry!");
	else printf("%lld", a * pow(b, P - 2) % P);
	return 0;
}

