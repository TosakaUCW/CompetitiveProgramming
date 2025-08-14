ostream &operator<<(ostream &os, i128 n) {
    if (n == 0) return os << 0;
    string s; while (n > 0) s += char('0' + n % 10), n /= 10;
    reverse(s.begin(), s.end());
    return os << s;
}