#include <bits/stdc++.h>
using namespace std;
 
 
int p[20][1000001];
int a[1000001];
vector<int> c = {-1};
int s[1000001];
vector<int> res;
vector<int> v[1000001];
 
int ans = 0;
 
void solve(int x) {
	if (x != -1) {
		s[a[x]]++;
		if (s[a[x]] == 1) ans++;
		res[x] = ans;
	}
	for (int n : v[x]) {
		solve(n);
	}
	if (x != -1) {
		s[a[x]]--;
		if (s[a[x]] == 0) ans--;
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	int cur = -1;
 
	int last = 0;
	int cnt = 0;
 
	vector<int> queries;
	int mq = q;
	while (q--) {
		char t;
		int x;
		cin >> t;
		if (t == '+') {
			cin >> x;
			a[cnt] = x;
			p[0][cnt] = cur;
			int y = cnt;
			for (int i = 1; i < 20; i++) {
				y = p[i - 1][cnt];
				if (y == -1) break;
				p[i][cnt] = p[i - 1][y];
			}
			cur = cnt;
			c.push_back(cur);
			cnt++;
		} else if (t == '-') {
			cin >> x;
			int y = cur;
			for (int j = 0; j < 20; j++) {
				if ((x >> j) & 1) {
					y = p[j][y];
				}
			}
			cur = y;
			c.push_back(cur);
		} else if (t == '!') {
			c.pop_back();
			cur = c.back();
		} else {
			queries.push_back(cur);
		}
	}
 
	for (int i = 0; i < cnt; i++) {
		v[p[0][i]].push_back(i);
	}
	res.assign(cnt, 0);
	int ans = 0;
	solve(-1);
	for (int i = 0; i < queries.size(); i++) {
		if (queries[i] == -1) {
			cout << 0 << endl;
		} else {
			cout << res[queries[i]] << endl;
		}
	}
 
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}