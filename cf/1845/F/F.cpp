#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <uint MD> struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
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
using Mint = ModInt<998244353>;
template<> const Mint Mint::G = Mint(3);

template <class Mint> void nft(bool type, V<Mint>& a) {
    int n = int(a.size()), s = 0;
    while ((1 << s) < n) s++;
    assert(1 << s == n);

    static V<Mint> ep, iep;
    while (int(ep.size()) <= s) {
        ep.push_back(Mint::G.pow(Mint(-1).v / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }
    V<Mint> b(n);
    for (int i = 1; i <= s; i++) {
        int w = 1 << (s - i);
        Mint base = type ? iep[i] : ep[i], now = 1;
        for (int y = 0; y < n / 2; y += w) {
            for (int x = 0; x < w; x++) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        swap(a, b);
    }
}

template <class Mint> V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    int lg = 0;
    while ((1 << lg) < n + m - 1) lg++;
    int z = 1 << lg;
    auto a2 = a, b2 = b;
    a2.resize(z);
    b2.resize(z);
    nft(false, a2);
    nft(false, b2);
    for (int i = 0; i < z; i++) a2[i] *= b2[i];
    nft(true, a2);
    a2.resize(n + m - 1);
    Mint iz = Mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a2[i] *= iz;
    return a2;
}

const long long M = 2e5;
const long long MOD = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long l, t;
	cin >> l >> t;
	int n;
	cin >> n;
	vector<int> primes(2 * M + 1, 0);

	vector<int> pp(2 * M + 1, 1);
	vector<vector<int> > div(2 * M + 1);
	for (int i = 2; i <= 2 * M; i++) {
		if (!primes[i]) primes[i] = 1;
		for (int j = i; j <= 2 * M; j += i) {
			div[j].push_back(i);
			if (j != i) primes[j] = 2;
			if (primes[i] == 1) {
				pp[j] *= -1;
				if ((j / i) % i == 0) pp[j] = 0;
			}
		}
	}
	for (int i = 1; i <= 2 * M; i++) div[i].push_back(1);
	vector<int> v(n);

	vector<Mint> a(M + 1, 0), b(M + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		a[v[i]] = 1;
		b[v[i]] = 1;
	}
	auto c = multiply(a, b);
	set<int> s;
	for (int i = 0; i <= 2 * M; i++) {
		int minus = 0;
		if (i % 2 == 0 && a[i / 2]) minus = 1;
		if (c[i].v - minus > 0) {
			s.insert(i);
		}
	}
	fill(a.begin(), a.end(), 0);
	fill(b.begin(), b.end(), 0);
	for (int i = 0; i < n; i++) {
		a[v[i]] = 1;
		b[M - v[i]] = 1;
	}
	c = multiply(a, b);
	for (int i = M + 1; i <= 2 * M; i++) {
		if (c[i].v > 0) {
			s.insert(i - M);
		}
	}
	vector<long long> res(2 * M + 1, 0);
	for (auto x : s) {
		
		res[x] = t * x / (2 * l);
	}
	for (int i = 2 * M; i >= 0; i--) {
		if (!res[i]) continue;
		for (int d : div[i]) {
			res[i / d] = max(res[i / d], t * i / (2 * l) / d);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 2 * M; i++) {
		if (!res[i]) continue;
		for (int d : div[i]) {
			
			ans += pp[d] * (res[i] / d);
			//cout << d << " " << pp[d] << " " << res[i] << " " << i << " " << ans << endl;
			ans %= MOD;
		}
	}
	cout << ans << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
