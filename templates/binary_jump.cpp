#include <bits/stdc++.h>
using namespace std;

int LEVELS = 30;
vector<vector<int> > jump(LEVELS, vector<int>(1e5, -1));

// jumps to the dth ancestor of x
// returns the ancestor with the answer on a segment (NOT INCLUDING LAST NODE)
int jmp(int x, int d) {
	int ret = x;
	for (int i = 0; i < LEVELS; i++) {
		if ((1 << i) & d) {
			ret = jump[i][x];
			x = ret;
		}
		if (x == -1) return -1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n ; i++) {
		cin >> p[i];
		p[i]--;
	}
  
	jump[0] = p;

	for (int i = 1; i < jump.size(); i++) {
		for (int j = 0; j < n; j++) {
			auto old = jump[i - 1][j];
			if (old == -1) continue;
			auto next = jump[i - 1][old];
			jump[i][j] = next;
		}
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
