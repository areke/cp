#include <bits/stdc++.h>
using namespace std;

long long solve(string & s) {
	int n = s.length();
	vector<long long> val = {1, 10, 100, 1000, 10000};
	vector<vector<long long> > c(5, vector<long long>(n + 1, 0));
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 5; j++) {
			c[j][i + 1] = c[j][i];
		}
		c[s[i] - 'A'][i + 1]++;
	}
	long long cur = 0;
	for (int i = 0; i < s.length(); i++) {
		bool pos = true;
		for (char j = s[i] + 1; j <= 'E'; j++) {
			if (c[j - 'A'][n] - c[j - 'A'][i + 1]) {
				pos = false;
			}
		}
		if (pos) {
			cur += val[s[i] - 'A'];
		} else {
			cur -= val[s[i] - 'A'];
		}
	}
	return cur;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		
		
		vector<int> last(5, -1);
		vector<int> first(5, -1);
		for (int i = 0; i < s.length(); i++) {
			last[s[i] - 'A'] = i;
		}
		for (int i = 0; i < s.length(); i++) {
			if (first[s[i] -'A'] == -1) {
				first[s[i] -'A'] = i;
			}
		}
		long long res = -1e18;
		for (int i = 0; i < 5; i++) {
			if (last[i] == -1) continue;
			char old = 'A' + i;
			for (char j = 'A'; j <='E'; j++) {
				s[last[i]] = j;
				res = max(res, solve(s));
			}

			s[last[i]] = old;
		}
		for (int i = 0; i < 5; i++) {
			if (first[i] == -1) continue;
			char old = 'A' + i;
			for (char j = 'A'; j <='E'; j++) {
				s[first[i]] = j;
				res = max(res, solve(s));
			}

			s[first[i]] = old;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
