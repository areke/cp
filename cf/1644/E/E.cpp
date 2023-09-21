#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		string s;
		cin >> s;
		long long tx = 1, ty = 1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'R') tx++;
			else ty++;
		}
		long long x = 1;
		long long y = 1;
		long long res = 1;
		bool f = false;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != s[i - 1]) {
				f = true;
				break;
			}
			res++;
		}
		if (!f) {
			cout << n << endl;
			continue;
		}
		long long lx = -1;
		long long ly = -1;
		if (s[0] == 'R') x++;
		else y++;
		f = false;
		for (int i = 1; i < s.length(); i++) {
			int dx = 0, dy = 0;
			if (s[i] == 'R') dx++;
			else dy++;

			if (s[i] != s[i - 1] || f) {
				long long mx = n - (tx - x - dx);
				long long my = n - (ty - y - dy);
				cout << x << " " << y << " " << mx << " " << my << " " << lx << " " << ly << endl;
				res += (mx - x + 1) * (my - y + 1);
				if (lx != -1) {
					if (x <= lx && y <= ly) {
						res -= (lx - x + 1) * (ly - y + 1);
					}
				}
				lx = mx;
				ly = my;
			}
			x += dx;
			y += dy;
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
