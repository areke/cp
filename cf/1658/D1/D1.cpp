#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
 
		int l, r;
		cin >> l  >> r;
		vector<int> a(r - l + 1);
		
		int n = r - l + 1;
		vector<int> e(n);
		for (int i = 0; i < r - l + 1; i++) {
			cin >> a[i];
			e[i] = l + i;
		}
		int cur = 0;
		for (int i = 0; i < 17; i++) {
			int c[2] = {0};
			int ec[2] = {0};
			int MASK = (1 <<(i + 1)) - 1;
			for (int j = 0; j < n; j++) {
				c[(a[j] >> i) & 1]++;
				ec[(e[j] >> i) & 1]++;
			}
			int nxt = 0;
			if (c[0] != c[1]) {
				if (c[0] != ec[0]) {
					nxt = (1 << i);
				}
			} else {
				if (n % (1 << (i + 1)) != 0) {
					int MASK = (1 << (i + 1)) - 1;
					bool found = false;
					for (int t = 0; t < 2; t++) {
						int b = t << i;
						map<int, int> m;
						for (int j = 0; j < n; j++) {
							m[(e[j] & MASK)]++;
							m[(a[j] & MASK) ^ (cur | b)]--;
						}
						bool ok = true;
						for (auto it : m) {
							//cout << b << " " << i << " " << it.first << " " << it.second << endl;
							if (it.second != 0) {
								ok = false;
							}
						}
						if (ok) {
							cur |= b;
							found = true;
							break;
						}
					}
					
				} 
			}
			cur |= nxt;
		}
		cout << cur << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}