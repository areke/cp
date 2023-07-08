#include <bits/stdc++.h>
using namespace std;


#define MAXLEN 1000010

constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}


uint64_t base_pow[MAXLEN];


void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

        for (int i = n; i >= 1; i--){
            suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }
    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	init();
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<unsigned long long> h(n, 0);
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') h[i] = 1;
			else h[i] = 2;
		}
		PolyHash p(h);
		int cnt = 0;
		bool bad = false;
		int res = 0;
		int last = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') cnt++;
			else cnt--;
			if (cnt < 0) bad = true;
			int mid = (i + last) / 2;
			if (cnt == 0 && !bad) {
				res++;
				last = i+ 1;
				cnt = 0;
				bad = false;
			} else if (i - last + 1 >= 2) {
				bool pal = false;
				if ((i - last + 1) % 2) {
					if (p.get_hash(last, mid) == p.rev_hash(mid, i)) {
						pal = true;
					}
				} else {
					if (p.get_hash(last, mid) == p.rev_hash(mid + 1, i)) {
						pal = true;
					}
				}
				if (pal) {
					res++;
					last = i + 1;
					cnt = 0;
					bad = false;
				}
			}
		}
		cout << res << " " << n - last << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
