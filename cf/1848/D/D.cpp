#include <bits/stdc++.h>
#define pb emplace_back
#define sz(x) int(x.size())
using namespace std;



using bi = __int128;

std::ostream& operator<<(std::ostream& os, bi x) {
  vector<int> ret;
 
  if (x == 0) ret.push_back(0);
  while (x) {
    ret.push_back(x % 10);
    x /= 10;
  }
 
  reverse(ret.begin(), ret.end());
 
  for (int i = 0; i < sz(ret); ++i)
    os << ret[i];
 
  return os;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long S, K;
		cin >> S >> K;
		bi s, k;
		s = S;
		k = K;

		bi a = s;
		bi res = 0;
		for (int i = 0; i <= 10; i++) {
			if (k < 0) break;
			bi d = a % 10;
			bi cur = a;
			bi p = 0;
			bi b = 0;
			//cout << i << " " << a << " " << d << " " << k << endl;
			res = max(res, a * k);
			if (d == 2 || d == 4 || d == 6 || d == 8) {
				p = 4;
				b = 20;
			} else {
				a += d;
				k--;
				continue;
			}
			//cout << i << " " << b << endl;
			bi best = (k * b - a * p) / (2 * p * b);
			for (bi j = -p; j <= p; j++) {
				bi x = best + j;
				if (x >= 0 && p * x <= k) {
					//cout << a << " " << d << " " << x << " " << k - x << endl;
					res = max(res, (a + x * b) * (k - p * x));
				}
			}
			a += d;
			k--;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
