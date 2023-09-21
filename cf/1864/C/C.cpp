#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<long long> v;
    long long x;
    cin >> x;
    v.push_back(x);
    for (int i = 0; i < 30; i++) {
      if ((x >> i) & 1) {
        x -= (1LL << i);
        v.push_back(x);
      }
    }
    v.pop_back();
    int cur = v.back();
    while (cur != 1) {
      v.push_back(cur / 2);
      cur /= 2;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " \n"[i == v.size() - 1];
    }
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
