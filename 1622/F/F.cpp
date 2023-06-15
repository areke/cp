#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 1000010;

uint64_t base_pow[MAXLEN];

constexpr uint64_t mod = (1ULL << 61) - 1;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::random_device rd; 
  std::mt19937_64 eng(rd());
 
  std::uniform_int_distribution<unsigned long long> distr;
	
	int n;
	cin >> n;
	vector<unsigned long long> m(n + 1, 0);
	vector<vector<int> > v(n + 1);
	for (int i = 2; i <= n; i++) {
		if (v[i].size()) continue;
		m[i] = distr(eng);
		for (int j = i; j <= n; j+= i) {
			v[j].push_back(i);
		}
	}
	for (int i = 2; i <= n; i++) {
		vector<int> nv;
		int x = i;
		for (int j : v[i]) {
			int cnt = 0;
			while (x % j == 0) {
				x /= j;
				cnt++;
			}
			if (cnt & 1) nv.push_back(j);
		}
		swap(nv, v[i]);
	}
	vector<unsigned long long> h(n + 1, 0);
	map<unsigned long long, vector<int> > mp;
	unsigned long long cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j : v[i]) {
			cur ^= m[j];
		}
		h[i] = cur;
		mp[h[i]].push_back(i);
	}
	cur = 0;
	for (int i = 1; i <= n; i++) {
		cur ^= h[i];
	}
	if (h[n] == 0) {
		cout << n << endl;
		for (int j = 1; j <= n; j++) {
			cout << j << " \n"[j == n];
		}
		return 0;
	} 
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (cur == h[i]) {
			for (int j = 1; j <= n; j++) {
				if (j == i) continue;
				res.push_back(j);
			}
			break;
		}
	}
	if (res.size()) {
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " \n"[i == res.size() - 1];
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (mp[cur ^ h[i]].size() > 1 && mp[cur ^ h[i]][0] == i)  {
			swap(mp[cur ^ h[i]][0], mp[cur ^ h[i]][1]);
		}
		if (mp[cur ^ h[i]].size() && mp[cur ^ h[i]][0] != i) {
			for (int j = 1; j <= n; j++) {
				if (j != i && j != mp[cur ^ h[i]][0]) res.push_back(j);
			}
			break;
		}

	}
	if (res.size()) {
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " \n"[i == res.size() - 1];
		}
		return 0;
	}
	cout << n - 3 << endl;
	for (int i = 1; i <= n; i++) {
		if (i == 2 || i == n / 2 || i == n) continue;
		cout << i << " "; 
	}
	cout << endl;

	


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
