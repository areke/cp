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
	int tests = 1;
	vector<vector<long long> > f(300001);
	for (int i = 2; i <= 300000; i++) {
		if (f[i].size()) continue;
		for (int k = i; k <= 300000; k+= i) {
			f[k].push_back(i);
		}
	}
	while (tests--) {
		long long n;
		cin >> n;
		vector<long long> a(n);
 
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<long long, long long> m;
		long long s, t;
		cin >> s >> t;
		if (s == t) {
			cout << 1 << endl;
			cout << s << endl;
			return 0;
		}
		s--;
		t--;
 
 //
		if (a[s] == 1 || a[t] == 1) {
			cout << -1 << endl;
			return 0;
		}
		if (a[s] == a[t]) {
			cout << 2 << endl;
			cout << (s + 1) << " " << (t + 1) << endl;
			return 0;
		}
		for (int i = 0; i < n; i++) {
			m[a[i]] = i;
		}
		m[a[s]] = s;
		m[a[t]] = t;
		vector<long long> d(n, 1e9);
		vector<long long> b(n, -1);
		queue<long long> q;
		d[s] = 0;
		bool found = false;
		q.push(a[s]);
		set<long long> r;
		set<long long> vis;
		for (int i = 0; i < n; i++) {
			r.insert(a[i]);
		}
		while (!q.empty()) {
			long long top = q.front();
			//cout << top << endl;
			q.pop();
			if (m[top] == t) {
				found = true;
				break;
			}
			for (int i = 0; i < f[top].size(); i++) {
				if (vis.find(f[top][i]) != vis.end()) continue;
				for (long long j = f[top][i]; j <= 300000; j+=f[top][i]) {
					if (r.find(j) != r.end()) {
						//cout << top << " " << j << " " << m[j] << endl;
						r.erase(r.find(j));
						if (d[m[j]] > d[m[top]] + 1) {
							d[m[j]] = d[m[top]] + 1;
							b[m[j]] = m[top];
							q.push(j);
						}
					}
				}
				vis.insert(f[top][i]);
			}
		}
		if (!found) {
			cout << -1 << endl;
			continue;
		}
		vector<int> v;
		long long res = d[t] + 1;
		while (true) {
			v.push_back(t);
			if (t == s) break;
			t = b[t];
		}
		cout << res << endl;
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout <<(v[i] + 1);
			if (i == v.size() - 1) cout << endl;
			else cout << " ";
		}
	}
 
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}