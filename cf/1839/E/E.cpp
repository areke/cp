#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	vector<int> dp(300 * 300 + 1, 0);
	int MAXI = 300 * 300;
	dp[0] = 1;
	int found = -1;
	for (int j = 0; j < a.size(); j++) {
		if (a[j] == 0) continue;
		if (found != -1) break;
		for (int i = MAXI; i >= 0; i--) {
			if (!dp[i] && i - a[j] >= 0 && dp[i - a[j]]) {
				dp[i] = j + 2;
				if (2 * i == s) {
					found = 1;
					break;
				}
			}
		}
	}
	
	if (found == -1) {
		cout << "First" << endl;
		int x = -1;
		while (x != 0) {
			found = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] != 0 && (found == -1 || a[found] > a[i])) {
					found = i + 1;
				}
			}
			cout << found << endl;
			cin >> x;
			assert(x != -1);
			if (x == 0) break;
			int mini = min(a[found - 1], a[x - 1]);
			a[found - 1] -= mini;
			a[x - 1] -= mini;
		}
	} else {
		cout << "Second" << endl;
		int st = s / 2;
		set<int> o;
		while (st != 0) {
			o.insert(dp[st] - 1);
			st -= a[dp[st] - 2];
		}
		int x = -1;
		while (x != 0) {
			cin >> x;
			assert(x != -1);
			if (x == 0) return 0;
			int last = a[x - 1];
			a[x - 1] = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] != 0 && (o.count(i + 1) != o.count(x))) {
					found = i + 1;
					break;
				}
			}
			cout << found << endl;
			
			a[x - 1] = last;
			int mini = min(a[found - 1], a[x - 1]);
			a[found - 1] -= mini;
			a[x - 1] -= mini;
		}
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}