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
	if (b % 2) res *= a;
	return res;
}
int k = 30;

struct node {
	node* c[2];
	int cnt[2];
 
	node() {
    for (int i = 0; i < 2; i++) {
      c[i] = NULL;
    }
    for (int i = 0; i < 2; i++) {
      cnt[i] = 0;
    }
	}
 
	void add(int x) {
		node* cur = this;
		for (int i = k - 1; i >= 0; i--) {
			int b = (x >> i) & 1;
			if (cur->c[b] == NULL) {
				cur->c[b] = new node();
			}
			cur->cnt[b]++;
			cur = cur->c[b];
		}
	}
 
	mi find(int x) {
		node* cur = this;
		bool same = true;
    int o = 0;
    mi res = 0;
		for (int i = k - 1; i >= 0; i--) {
			int b = (x >> i) & 1;
      node* other = cur->c[b ^ 1];
      mi oc = cur->cnt[b ^ 1];

      cur = cur->c[b];
      if (b) {
        res += oc * (o + 1); 
        o++;
      } else {
        res += oc * (o + 2);
      }
		}
		assert(cur != NULL);
		//cout << "?" << endl;
		return res;
	}
};
 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
  // if a != b
  // x = consider # of ones before first bit that differs,
  // expectation if both are chosen is (2x + 1) / 2

  // if numbers are equal, expectation = x + 1
	for (int test = 1; test <= tests; test++) {
		int n;
    cin >> n;
    node* trie = new node();
    vector<int> v(n);

    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      trie->add(v[i]);
      m[v[i]]++;
    }
    mi res = 0;

    for (int i = 0; i < n; i++) {
      res += trie->find(v[i]);
      int oc = 0;
      for (int j = 0; j < k; j++) {
        if ((v[i] >> j) & 1) {
          oc++;
        }
      }
      res += mi(oc + 1) * m[v[i]];
    }
    res = res / mi(n);
    res = res / mi(n);
    cout << res.v << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
