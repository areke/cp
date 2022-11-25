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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

struct loc {
	int x, y, d;
	pair<int, int> last;
	loc(int x, int y, int d) {
		this->x = x;
		this->y = y;
		this->d = d;
		this->last = make_pair(-1, -1);
	}

	bool operator <(const loc & o) const {
		return o.d < d;
	}
	vector<pair<int, int> > v;
};


int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<string> grid(n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			grid[i] = s;
		}
		priority_queue<loc> pq;
		for (int i = 0; i < n; i++) {
			if (i > 0 && grid[i - 1][0] == '#') continue;
			if (i < n - 1 && grid[i + 1][0] == '#') continue;
			if (1 < m && grid[i][1] == '#') continue;
			pq.push(loc(i, 0, grid[i][0] != '#'));
		}
		map<pair<int, int>, pair<int, int> > last;
		pair<int, int> res = make_pair(-1, -1);
		while (!pq.empty()) {
			loc t = pq.top();
			pq.pop();
			bool valid = true;
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (i != 0 && j != 0) continue;
					if (i == 0 && j == 0) continue;
					if (t.x + i < 0 || t.x + i >= n) continue;
					if (t.y + j < 0 || t.y + j >= m) continue;
					if (grid[t.x + i][t.y + j] == '#') valid = false;
				}
			}
			
			if (!valid) continue;
			//cout << t.x << " " << t.y << " " << t.d << endl; 
			if (last.count(make_pair(t.x, t.y))) continue;
			last[make_pair(t.x, t.y)] = t.last;
			if (t.y == m - 1) {
				res = make_pair(t.x, t.y);
				break;
			}
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (i == 0 || j == 0) continue;
					if (t.x + i < 0 || t.x + i >= n) continue;
					if (t.y + j < 0 || t.y + j >= m) continue;
					loc next = loc(t.x + i, t.y + j, t.d + (grid[t.x + i][t.y + j] != '#'));
					next.last = make_pair(t.x, t.y);
					pq.push(next);
				}
			}
		}
		if (res == make_pair(-1, -1)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			vector<pair<int, int> > add;
			while (res != make_pair(-1, -1)) {
				add.push_back(res);
				res = last[res];
			}
			for (int i = 0; i < add.size(); i++) {
				grid[add[i].first][add[i].second] = '#';
			}
			for (int i = 0; i < grid.size(); i++) {
				cout << grid[i] << endl;
			}
		}
	}
	return 0;
}
