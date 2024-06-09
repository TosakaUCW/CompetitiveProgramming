#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <string>

using namespace std;

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	int n = read();
	std::string s;
	std::cin >> s;
	if (s.find('B') == s.npos and s.find('R') == s.npos)
		for (int i = 0; i < n; i++) s[i] == i % 2 ? 'B' : 'R';
	else
	{
		for (int i = 0; i < n; i++)
			if (s[i] != '?')
			{
				for (int j = i - 1; j >= 0 and s[j] == '?'; j--)
					s[j] = s[j + 1] == 'B' ? 'R' : 'B';
				for (int j = i + 1; j < n and s[j] == '?'; j++)
					s[j] = s[j - 1] == 'B' ? 'R' : 'B';
			}
	}
	std::cout << s << '\n';
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

