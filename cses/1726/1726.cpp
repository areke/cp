#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<long double> > res(8, vector<long double>(8, 1));
	vector<vector<int> > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int k = n;

			vector<vector<long double> > board(8, vector<long double>(8, 0));
			board[i][j] = 1;
			while (k--) {
				vector<vector<long double> > next(8, vector<long double>(8, 0));
				for (int a = 0; a < 8; a++) {
					for (int b = 0;  b < 8; b++) {
						long double val = 0;
						for (auto dir : dirs) {
							if (dir[0] + a >= 0 && dir[0] + a < 8 && dir[1] + b >= 0 && dir[1] + b < 8) {
								val++;
							}
						}
						for (auto dir : dirs) {
							if (dir[0] + a >= 0 && dir[0] + a < 8 && dir[1] + b >= 0 && dir[1] + b < 8) {
								next[dir[0] + a][dir[1] + b] += board[a][b] / val;
							}
						}
					}
				}
				board = next;
			}
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					res[a][b] *= (1 - board[a][b]);
				}
			}
		}
	}
	long double ans = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ans += res[i][j];
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
