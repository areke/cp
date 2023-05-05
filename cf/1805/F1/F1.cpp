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

long long MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int t = n - 1; t >= 1; t--) {
		priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>> > pq;
		pq.push({(v[0] + v[1]) % MOD, 0, 1});
		vector<long long> nv(t);
		int cur = 0;
		while (!pq.empty()) {
			array<long long, 3> next = pq.top();
			//cout << next[0] << " " << next[1] << " " << next[2] << endl;
			pq.pop();
			nv[cur++] = next[0];
			if (cur >= t) break;
			if (next[2] + 1 < v.size() && next[1] != next[2] + 1) {
				pq.push({(v[next[1]] + v[next[2] + 1]) % MOD, next[1], next[2] + 1});
			}
			if (next[1] + 1 < v.size() && next[1] + 1 != next[2]) {
				pq.push({(v[next[1] + 1] + v[next[2]]) % MOD, next[1] + 1, next[2]});
			}
		}
		v = nv;
	}
	cout << v[0] << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
