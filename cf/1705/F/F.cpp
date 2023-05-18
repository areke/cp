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

int lg = 0;


int guess(vector<int> &v) {
	string s = "";
	for (int i = 0; i < v.size(); i++) {
		if (v[i]) s += 'T';
		else s += 'F';
	}
	cout << s << endl;
	int x;
	cin >> x;
	lg = x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n, 1);
	
	vector<int> f(n, 1);
	vector<int> tf(n, 1);
	for (int i = 0; i < n / 2; i++) {
		tf[2 * i + 1] = 0;
	}
	int fans = guess(f); if (lg == n) return 0;
	int tfans = guess(tf); if (lg == n) return 0;
	int cur = 0;
	int l = fans;
	while (cur + 2 < n) {
		v[cur] = 0;
		v[cur + 1] = 0;
		int c = guess(v); if (lg == n) return 0;
		if (c - l == 2) {
			l = c;
			cur += 2;
			continue;
		} else if (c - l == -2) {
			l = c + 2;
			v[cur] = 1;
			v[cur + 1] = 1;
			cur += 2;
			continue;
		} else {
			vector<int> g = tf;
			for (int j = 0; j < 3; j++) {
				g[cur + j] ^= 1;
			}
			int ans = guess(g); if (lg == n) return 0;
			// last guess is p 001 11111...
			// 
			if (g[cur] == 1) swap(ans, tfans);
			if (ans - tfans == 3) {
				v[cur] = 0;
				v[cur + 1] = 1;
				v[cur + 2] = 0;
				l = c + 2;
			}
			else if (ans - tfans == 1) {
				v[cur] = 0;
				v[cur + 1] = 1;
				v[cur + 2] = 1;
				l = c + 1;
			}
			else if (ans - tfans == -1) {
				v[cur] = 1;
				v[cur + 1] = 0;
				v[cur + 2] = 0;
				l = c + 2;
			}
			else if (ans - tfans == -3) {
				v[cur] = 1;
				v[cur + 1] = 0;
				v[cur + 2] = 1;
				l = c + 1;
			} else {
				assert(1 == 0);
			}
			if (g[cur] == 1) swap(ans, tfans);
			cur += 3;
		}
	}
	for (int i = cur; i < n; i++) {
		vector<int> best = v;
		int cc = guess(v); if (lg == n) return 0;
		v[i] ^= 1;
		int op = guess(v); if (lg == n) return 0;
		if (op < cc) {
			v[i] ^= 1;
		}
	}
	guess(v); if (lg == n) return 0;
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
