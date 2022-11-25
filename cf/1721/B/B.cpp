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
	loc(int x, int y, int d) {
		this->x = x;
		this->y = y;
		this->d = d;
	}
};

int dist(int x, int y, int xx, int yy) {
	return (abs(x-xx) + abs(y - yy));
}

int main() {
	int tests;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tests;
	while (tests--) {
		int n, m, sx, sy, d;
		cin >> n >> m >> sx >> sy >> d;
		int res = n + m - 2;
		int cnt = 0;
		bool f = true;
		if (sy + d >= m && sy - d <= 1) f = false;
		if (sx + d >= n && sx - d <= 1) f = false;
		if (sy + d >=m && sx + d >= n) f = false;
		if (sy -d <= 1 && sx -d <= 1) f = false;
		if (!f) {
			cout << -1 << endl;
		} else {
			cout << res<< endl;
		}
	}
	return 0;
}
