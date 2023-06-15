#include <bits/stdc++.h>
using namespace std;


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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	string s;
	cin >> s;
	int k;
	cin >> k;
	set<int> cnts;
	vector<unordered_map<unsigned long long, int> > v(s.length() + 1);
	vector<string> q;
	for (int i = 0; i < k; i++){ 
		string t;
		cin >> t;
		q.push_back(t);
		cnts.insert(t.length());
	}
	vector<unsigned long long> h(s.length() + 1, 0);
	vector<unsigned long long> b(s.length() + 1, 1);
	for (int i = 1; i <= s.length(); i++) {
		b[i] = modmul(b[i - 1], base);
	}
	for (int i = 1; i <= s.length(); i++) {
		h[i] = h[i - 1] + modmul(b[i - 1], s[i - 1] - 'a');
	}
	for (int c : cnts) {
		for (int i = c - 1; i < s.length(); i++) {
			v[c][modmul(b[s.length() - (i - c + 1)], h[i + 1] - h[i + 1 - c])]++;
		}
	}
	for (string & t : q) {

		unsigned long long cur = 0;
		for (int i = 0; i < t.length(); i++) {
			cur += modmul(b[i], (t[i] -'a'));
		}
		cur = modmul(cur, b[s.length()]);
		cout << (v[t.length()][cur]) << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
