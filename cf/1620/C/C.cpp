#include <bits/stdc++.h>
using namespace std;

using ll = __int128_t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k, x;
		cin >> n >> k >> x;
		string s;
		cin >> s;
		char last = 'x';
		x--;
		int a = 0;
		vector<ll> v;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '*') {
				a++;
			} else {
				if (last == '*') {
					v.push_back(a * k + 1);
					a = 0;
				}
			}
			last = s[i];
		}
		if (a) v.push_back(a * k + 1);
		vector<ll> c;
		ll cur = 1;
		int first = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			c.push_back(cur);
			cur *= v[i];
			if (cur > x) {
				first = i;
				break;
			}
		}
		reverse(c.begin(), c.end());
		vector<int> cnt;
		for (int i = first; i < v.size(); i++) {
			cnt.push_back(x / c[i - first]);
			x = x % c[i - first];
		}
		reverse(cnt.begin(), cnt.end());
		vector<string> res(s.length(), "");
		int p = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '*' && i < s.length() - 1 && s[i + 1] == '*') continue;
			if (s[i] == '*' && p < cnt.size()) {
				for (int j = 0; j < cnt[p]; j++) {
					res[i] += 'b';
				}
				p++;
			} else if (s[i] == 'a') {
				res[i] = 'a';
			}
		}
		string ans = "";
		for (string & t : res) {
			ans += t;
		}
		cout << ans << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
