#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m, x1, y1, x2, y2;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		bool found = false;
		int dx = 1;
		int dy = 1;
		int res = 0;
		while (!found) {
			
			
			if (x1 == x2 || y1 == y2) {
				break;
			}
			if (x1 + dx > n || x1 + dx < 1) {
				dx *= -1;
			} 
			if (y1 + dy > m || y1 + dy < 1) {
				dy *= -1;
			}
			x1 += dx;
			y1 += dy;
			
			res++;	
		}
		cout << res  << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
