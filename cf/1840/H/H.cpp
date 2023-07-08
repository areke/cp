#include <bits/stdc++.h>
using namespace std;

std::random_device rd; 
std::mt19937_64 eng(rd());
std::uniform_int_distribution<long long> distr;


int query(int x) {
	cout << "+ " << x << endl;
	int y;
	cin >> y;
	return y;
}


int main() {
	long double mini = 1e9;
	int maxn = 1e6;
	int ans = 0;
	int q=  0;
	long double prec = 4;
	for (int i = 1; i <= 999999; i++) {
		long double cur =  2 * sqrt((long double)(maxn - i)) + prec / (log10(maxn) - log10(i));
		if (cur < mini) {
			mini = cur;
			ans = i;
			q =  prec / (log10(maxn) - log10(i));
		}
	}
	cout << ans << " " << mini << " " << q << endl;
	int x;
	cin >> x;
	set<int> s;
	s.insert(x);
	map<int, int> m;
	vector<long long> v;
	long long tot = 0;
	for (int i = 0; i < 50; i++) {
		v.push_back((distr(eng) % 1000000));
		int x = query(v[i]);
		s.insert(x);
		tot += v[i];
		if (i == 49) m[x] = 0;
	}
	int maxi = *s.rbegin();

	int res = -1;
	for (int i = 1; i <= 450; i++) {
		int y = query(1);
		if (m.count(y)) {
			res = i;
			break;
		}
		m[y] = i;
	}
	if (res != -1) {
		cout << "! " << res << endl;
		return 0;
	}
	int shift = 0;
	if (maxi >= 1000) {
		shift = maxi - 900;
		int y = query(shift);
	}
	for (int i = 1; i <= 450; i++) {
		int y = query(450);
		if (m.count(y)) {
			res = 450 * (i + 1) + shift - m[y];
			break;
		}
	}

	cout << "! " << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
