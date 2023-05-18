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


const int LEVELS = 19;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n;
	vector<int> v(n);
	vector<int> cnt(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
		cnt[v[i]]++;
	}
	vector<int> d(n, 0);
	vector<int> c(n, 0);
	vector<bool> vis(n, 0);
	queue<int> qq;
	for (int i = 0; i < n; i++) {
		if (!cnt[i]) {
			qq.push(i);
		}
	}
	vector<int> rev;
	while (!qq.empty()) {
		int t = qq.front();
		qq.pop();
		cnt[v[t]]--;
		rev.push_back(t);
		if (!cnt[v[t]]) qq.push(v[t]);
	}
	for (int i = rev.size() - 1; i >= 0; i--) {
		d[rev[i]] = d[v[rev[i]]] + 1;
	}
	for (int i = 0; i < n; i++) {
		if (!d[i] && !c[i]) {
			int cnt = 1;
			int x = v[i];
			while (x != i) {
				x = v[x];
				cnt++;
			}
			x = v[i];
			c[x] = cnt;
			while (x != i) {
				x = v[x];
				c[x] = cnt;
			}
		}
	}
	for (int i = rev.size() - 1; i >= 0; i--) {
		c[rev[i]] = c[v[rev[i]]];
	}
	vector<vector<int > > jump(LEVELS, vector<int >(n, -1));
	jump[0] = v;


	for (int i = 1; i < jump.size(); i++) {
		for (int j = 0; j < n; j++) {
			auto old = jump[i - 1][j];
			if (old == -1) continue;
			auto next = jump[i - 1][old];
			jump[i][j] = next;
		}
	}
	auto jmp = [&](int x, int d) {
		int ret = x;
		for (int i = 0; i < LEVELS; i++) {
			if ((1 << i) & d) {
				ret = jump[i][x];
				x = jump[i][x];
			}
			if (x == -1) return -1;
		}
		return ret;
	};
	
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = d[i] + c[i];
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}



	



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
