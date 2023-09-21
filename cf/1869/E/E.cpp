#include <bits/stdc++.h>
using namespace std;


const long long MOD = 998244353;

struct mi { // WARNING: needs some adjustment to work with FFT
 	long long v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(long long _v):v((int)(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, long long p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

const int MAXN = 200000 + 5;
mi fact[MAXN], invfact[MAXN];
mi nCr(int n, int r) {
	return fact[n] * invfact[r] * invfact[n - r];
}

void prepareFact() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i;
	}
	invfact[MAXN - 1] = mi(1) / fact[MAXN - 1];
	for (int i = MAXN - 2; i >= 0; i--) {
		invfact[i] = invfact[i + 1] * (i + 1);
	}
}

mi modExp(mi a, long long b) {
	if (b == 0) return 1;
	mi res = modExp(a, b / 2);
	res *= res;
	if (b & 1) res *= a;
	return res;
}


vector<mi> solve(long long n, map<long long, vector<mi> > & m) {
  if (m.count(n)) return m[n];
  auto res = vector<mi>(130, 0);
  if (n == 0) return res;
  if (n == 1) {
    res[1] = 1;
    return res;
  }
  int h = 0;
  for (int i = 0; i < 63; i++) {
    if ((n >> i) & 1) {
      h = i;
    }
  }
  long long mid = 1LL << (h - 1);
  long long left = mid - 1;
  long long right = mid - 1;
  if (left + right + 1 + (1LL << (h - 1)) <= n) {
    left += (1LL << (h - 1));
  } else {
    left += n - left - right - 1;
  }
  right = n - left - 1;
  auto lr = solve(left, m);
  auto rr = solve(right, m);
  for (int i = 0; i < 130; i++) {
    res[i] = lr[i] + rr[i];
  }

  for (int i = 0; i <= h; i++) {
    mi l = 1LL << i;
    if (i > 0) l -= 1LL << (i - 1);
    if (i == h) {
      l = left - (mid - 1);
    }
    for (int j = 0; j <= h; j++) {
      mi r = 1LL << j;
      if (j > 0) r -= 1LL << (j - 1); 
      if (j == h) {
        r = right - (mid - 1);
      }
      res[i + j + 1] += l * r;
    }
  }
  //cout << n << " " << len << " " << res.v << " " << h << " " << mid << " " << mid - 1 << " " << n - mid << endl;
  return m[n] = res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  map<long long, vector<mi> > mp;
  for (int test = 1; test <= tests; test++) {
    long long n, m;
    cin >> n >> m;
    
    vector<mi> path = solve(n, mp);
    mi res = 0;

    vector<mi> cur(m + 1, 1);
    cur[0] = 0;
    for (int i = 0; i < 128; i++) {
      if (i > n) break;
      mi c = modExp(m, n - i);
      mi last = 0;
      for (int j = 1; j <= m; j++) {
        mi count = cur[j] - cur[j - 1];
        mi val  = mi(j) * count * c * path[i];
        res += val;
      }
      for (int j = 1; j <= m; j++) {
        cur[j] *= j;
      }
    }
    cout << res.v << endl;

  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
