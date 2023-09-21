#include <bits/stdc++.h>
using namespace std;


int query(int l, int r) {
	cout << "? " << l << " " << r << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}
int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			v.push_back(i);
		}
		while (v.size() != 1) {
			vector<int> cands;
			for (int i = 0; i < v.size() / 2; i++) {
				int l = v[2 * i];
				int r = v[2 * i + 1];
				int f = query(l, r);
				if (r - l == 1) {
					if (f == 0) {
						cands.push_back(r);
					} else {
						cands.push_back(l);
					}
				} else {
					
					int last = query(l, r - 1);
					if (f == last) {
						cands.push_back(r);
					} else {
						cands.push_back(l);
					}
				}
			}
			if (v.size() % 2) {
				cands.push_back(v.back());
			}
			v = cands;
		}
		cout << "! " << v[0] << endl;
		cout.flush();
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
