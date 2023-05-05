#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
char dc[4] = { 'R', 'L', 'D', 'U'};

bool vis[7][7];

char s[48];

char t[48];
int res = 0;

void solve(int xx, int ind) {
	int x = xx / 7;
	int y = xx % 7;
	if (vis[x][y]) return;

	vis[x][y] = true;
	if (x == 0 && y == 6) {
		if (ind == 48) {
			res++;
		}
		vis[x][y] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = dirx[i] + x;
		int ny = diry[i] + y;
		if (nx >= 0 && nx < 7 && ny >= 0 && ny < 7) {
			
			if (s[ind] == '?' || s[ind] == dc[i]) {
				int nnx = dirx[i] + nx;
				int nny = diry[i] + ny;
				bool cand = false;
				if (vis[nx][ny]) continue;
				if (nnx < 0 || nnx >= 7 || nny < 0 || nny >= 7) cand = true;
				if (!cand && vis[nnx][nny]) cand = true;
				if ((cand || nx == 0 || nx == 6) && ny >= 1 && ny <= 5 && !vis[nx][ny - 1] && !vis[nx][ny + 1]) {
					continue;
				} 
				if ((cand || ny == 0 || ny == 6) && nx >= 1 && nx <= 5 && !vis[nx - 1][ny] && !vis[nx + 1][ny]) {
					continue;
				} 
				t[ind] = dc[i];
				solve(7 * nx + ny, ind + 1);
			}
		}
	}
	vis[x][y] = false;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 48; i++) cin >> s[i];
	solve(0, 0);
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
