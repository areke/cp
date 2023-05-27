#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> & b) {
	vector<int> a(b.size(), 0);
	int n = b.size() - 1;
	vector<array<int, 3> > v;
	for (int i = 1; i <= n; i++) {
		int maxi = n;
		if (b[i] != 0) {
			maxi = max(1, i / b[i]);
		}
		int mini = i / (b[i] + 1);

		mini++;
		//cout << i << " " << mini << " " << maxi << endl;
		v.push_back({mini, maxi, i});
	}
	sort(v.begin(), v.end());
	set<pair<int, int> > s;
	for (int i = 1, j = 0; i <= n; i++) {
		while (j < n && v[j][0] <= i) {
			s.insert({v[j][1], v[j][2]});
			j++;
		}
		auto it = s.begin();

		a[it->second] = i;
		s.erase(it);
	}
	return a;
}

bool validate() {
	for (int n = 1; n <= 6; n++) {
	vector<int> a(n + 1, 0);

	vector<int> b(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	do {
		for (int i = 1; i <= n; i++) {
			b[i] = i / a[i];
		}
		vector<int> c = solve(b);
		bool eq = true;
		for (int i = 1; i <= n; i++) {
			if (b[i] != i / c[i]) {
				eq = false;
			}
		}
		if (!eq) {
			for (int i = 1; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			for (int i = 1; i <= n; i++) {
				cout << b[i] << " ";
			}
			cout << endl;
			for (int i = 1; i <= n; i++) {
				cout << c[i] << " ";
			}
			cout << endl;
			return false;
		}
	} while (next_permutation(a.begin() + 1, a.end()));
	}
	return true;
}

/**
5 1 3 4 2 
0 2 1 1 2 
*/
int main() {
	//validate();
	/**/
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> b(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		vector<int> a = solve(b);
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " \n"[i == n];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
