#include <bits/stdc++.h>
using namespace std;



template <long long MD> struct ModInt {
    using M = ModInt;
    const static M G;
    long long v;
    ModInt(long long _v = 0) { set_v(_v % MD + MD); }
    M& set_v(long long _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v((unsigned long long)(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(long long n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};


const long long MOD1 = 1e9 + 7;
const long long MOD2 = 998244353;


const ModInt<MOD1> B = 29;

const ModInt<MOD2> B2 = 31;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	vector<pair<ModInt<MOD1>, ModInt<MOD2> > > h(s.length() + 1, {0, 0});
	ModInt<MOD1> a = 1;
	ModInt<MOD2> b = 1;
	for (int i = 0; i < s.length(); i++) {
		h[i + 1].first = h[i].first + a * (s[i] - 'a' + 1);
		h[i + 1].second = h[i].second + b * (s[i] - 'a' + 1);
		a *= B;
		b *= B2;
	}
	pair<ModInt<MOD1>, ModInt<MOD2> > hash = {0, 0};
	a = 1;
	b = 1;
	for (int i = 0; i < t.length(); i++) {
		hash.first += a * (t[i] - 'a' + 1);
		hash.second += b * (t[i] - 'a' + 1);
		a *= B;
		b *= B2;
	}
	int res = 0;
	pair<ModInt<MOD1>, ModInt<MOD2> > g = {0, 0};

	for (int i = t.length(); i <= s.length(); i++) {
		g.first = (h[i].first - h[i - t.length()].first);
		g.second = (h[i].second - h[i - t.length()].second);
		if (g == hash) {
			res++;
		}
		hash.first *= B;
		hash.second *= B2;

	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
