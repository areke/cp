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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


vector<vector<int> > dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

vector<char> ch = {'R', 'L', 'U', 'D'};

string res = "";

int ex, ey;

struct loc {
	int x, y, d;

	bool operator<(const loc & a) const {
		return this->d > a.d;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<pair<int, int> > > vis(n, vector<pair<int, int> >(m, {-1, -1}));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'A') {
				sx = i;
				sy = j;
			}
			if (v[i][j] == 'B') {
				ex = i;
				ey = j;
			}
			
		}
	}
	string path;
	priority_queue<loc> pq;
	pq.push({sx, sy, 0});
	pair<int, int> BAD = {-1, -1};
	vis[sx][sy] = {sx, sy};
	while (!pq.empty()) {
		loc t = pq.top();
		pq.pop();
		
		for (int i = 0; i < 4; i++) {
			auto d = dir[i];
			if (d[0] + t.x < 0 || d[0] + t.x >= v.size()) continue;
			if (d[1] + t.y < 0 || d[1] + t.y >= v[0].size()) continue;
			if (vis[d[0] + t.x][d[1] + t.y] != BAD) continue;
			if (v[d[0] + t.x][d[1] + t.y] == '#') continue;
			pq.push({d[0] + t.x, d[1] + t.y, t.d + 1});
			vis[d[0] + t.x][d[1] + t.y] = {t.x, t.y};
		}
	}
	if (vis[ex][ey] != BAD) {
		cout << "YES" << endl;
		pair<int, int> cur = {ex, ey};
		string res = "";
		while (cur != (pair<int, int>){sx, sy}) {
			pair<int, int> next = vis[cur.first][cur.second];
			for (int i = 0; i < 4; i++) {
				if (dir[i][0] == cur.first - next.first && dir[i][1]== cur.second - next.second) {
					res += ch[i];
					break;
				}
			}
			cur = next;
		}
		reverse(res.begin(), res.end());
		cout << res.size() << endl;
		cout << res << endl;
	} else {
		cout << "NO" << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
