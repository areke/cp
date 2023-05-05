#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		string s;
		cin >> n;
		cin >> s;
		vector<long long> a(26, 0);
		for (int i = 0; i < n; i++) {
			a[s[i] - 'a']++;
		}
		map<char, int> m;
		vector<pair<int, char> > v(26);
		for (int i = 0; i < n; i++) {
			v[s[i] - 'a'].first++;
			m[s[i]]++;
		}
		for (int i = 0; i < 26; i++) {
			v[i].second = 'a' + i;
		}
		sort(a.begin(), a.end());
		sort(v.begin(), v.end());
		long long res = 1e18;
		long long tar = 0;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				long long t = n / i;
				if (t > 26) {
					continue;
				}
				long long cur = 0;
				for (long long j = 0; j < t; j++) {
					if (a[25 - j] > i) {
						cur += abs(a[25 - j] - i);
					}
				}
				for (int j = t; j < 26; j++) {
					cur += a[25 - j];
				}
				res = min(res, cur);
				if (res == cur) {
					tar = i;
				}
			}
		}
		
		cout << res << endl;
		long long num = n / tar;
		set<char> se;
		for (int i = 0; i < num; i++) {
			se.insert(v[25 - i].second);
		}
		for (int i = 0; i < num; i++) {
			char cur = v[25 - i].second;
			for (int j = 0; j < n; j++) {
				if (m[cur] < tar && (se.find(s[j]) == se.end() || (tar < m[s[j]]))) {
					m[s[j]]--;
					s[j] = cur;
					m[cur]++;
				}
			}
		}
		cout << s << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
