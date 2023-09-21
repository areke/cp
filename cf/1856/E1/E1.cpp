#include <bits/stdc++.h>
using namespace std;
 
using namespace std;
const int MAXLEN = 1e6 + 5;

template <int len = 1>
long long knapsack(int n, map<long long, int> & m, long long su) {
	if (n > len) {
			return knapsack<std::min(len*2, MAXLEN)>(n, m, su);
	}
	bitset<len> bs = 1;
	for (auto &[a, b] : m) {
		long long cur = 0;
		for (int i = 0; i < 20; i++) {
			long long add = 0;
			if (b - cur - (1 << i) >= 0) {
				add = (1 << i) * a;
			} else if (b - cur >= 0){
				add = (b - cur) * a;
			} else {
				break;
			}
			cur += add / a;
			//cout << add << endl;
			bs = bs | (bs << add);
		}
	}
	long long maxi = 0;

	for (int i = len - 1; i >= 0; i--) {
		if (bs.test(i)) {
			maxi = max(maxi, 1LL * (su - i) * i);
		}
	}
	return maxi;
}


int dfs(int x, vector<vector<int> > & v, vector<int> & c, int last = -1) {
	int res = 1;
	for (int n : v[x]) {
		if (n == last) continue;
		res += dfs(n, v, c, x);
	}
	return c[x] = res;
}
 
long long solve(int x, vector<vector<int> > & v, vector<int> & c, int last = -1) {
	long long res = 0;
	map<long long, int> m;
	int maxi = 0;
	long long su = c[x] - 1;
	
	for (int n : v[x]) {
		if (n == last) {
			continue;
		}
		res += solve(n, v, c, x);
		m[c[n]]++;
		maxi = max(maxi, c[n]);
	}
	long long y;
	if (maxi > c[x] / 2) {
		y = maxi * (su - maxi);
	} else {
		y = knapsack(su, m, su);
	}


	//cout << x << " h " << y << endl;
	
	return res + y;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		x--;
		v[i].push_back(x);
		v[x].push_back(i);
	}
	vector<int> c(n, 0);
	dfs(0, v, c);
	long long res = 0;
	cout << solve(0, v, c) << endl;
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}