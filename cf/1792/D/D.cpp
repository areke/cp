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


struct trie {
	map<int, trie*> next;
	bool term = false;

	trie() {
		next = {};
		term = false;
	}

	void add(vector<int> & a) {
		trie* cur = this;
		for (int i = 0; i < a.size(); i++) {
			//cout << a << " " << i << " " << c << endl;
			trie* el;
			if (!cur->next.count(a[i])) {
				el = new trie();
			} else {
				el = cur->next[a[i]];
			}
			cur->next[a[i]] = el;
			cur = el;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > p(n, vector<int>(m, 0));
		vector<vector<int> > d(n, vector<int>(m, 0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> p[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				d[i][p[i][j] - 1] = j + 1;
			}
		}
		trie* t = new trie();
		for (int i = 0; i < n; i++) {
			t->add(d[i]);
		}
		vector<int> res(n, 0);
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			trie* cur = t;
			for (int j = 0; j < m; j++) {
				if (cur->next.count(p[i][j])) {
					cur = cur->next[p[i][j]];
					cnt++;
				} else {
					break;
				}
			}
			res[i] = cnt;
		}
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
