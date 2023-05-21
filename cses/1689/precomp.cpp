#include <bits/stdc++.h>
using namespace std;

int v[64][8];
int res[64];

bool found = false;


using namespace chrono;

int maxi = 0;

int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
long long calls = 0;
void dfs(int x, int cnt, unsigned long long vis) {
	if (cnt == 64) {
		found = true;
	}
	if (found) return;
	calls++;
	if (calls > 1e6) return;
	if ((1ULL << x) & vis) return;
	vis |= (1ULL << x);
	res[cnt++] = x;
	for (int i = 0; i < 8; i++) {
		if (v[x][i] == -1) continue;
		dfs(v[x][i], cnt, vis);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int x, y;
	for (int test = 0; test < 64; test++) {
		found = false;
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 8; j++) {
				v[i][j] = -1;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					if (i + dir[k][0] < 0 || i + dir[k][0] >= 8) continue;
					if (j + dir[k][1] < 0 || j + dir[k][1] >= 8) continue;
					v[8 * i + j][cnt++] = 8 * (i + dir[k][0]) + j + dir[k][1];
				}
			}
		}
		int attempts = 0;
		while (!found) {
			for (int i = 0; i < 64; i++) {
				random_shuffle(v[i], v[i] + 8);
			}
			unsigned long long vis = 0;
			dfs(test, 0, vis);
			attempts++;
			calls = 0;
		}
		for (int i = 0; i < 64; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
