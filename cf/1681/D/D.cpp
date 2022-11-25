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


// 1 never
// 2
// 3
// 4
// 5
// 6 can always do >= 6 next
// 7 9 is next
// 8
// 9
//

int count(long long x) {
	int cnt = 0;
	while (x) {
		x/=10;
		cnt++;
	}
	return cnt;
}

int main() {
	unsigned long long n, x;
	cin >> n >> x;
	pair<int, long long> p = make_pair(0, x);
	priority_queue<pair<int, long long> > pq;
	set<long long> vis;
	int res = -1;
	pq.push(p);
	while (!pq.empty()) {
		p = pq.top();
		pq.pop();
		if (vis.find(p.second) != vis.end()) {
			continue;
		}
		vis.insert(p.second);
		if (count(p.second) >= n) {
			res = -p.first;
			break;
		}
		long long y = p.second;
		set<int> dig;
		while (y) {
			dig.insert(y % 10);
			y/=10;
		}
		for (auto it = dig.rbegin(); it != dig.rend(); it++) {
			if (*it == 1 || *it == 0) continue;
			pq.push(make_pair(p.first - 1, *it * p.second));
		}
	}
	cout << res << endl;
	return 0;
}
