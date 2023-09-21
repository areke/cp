#include <bits/stdc++.h>
using namespace std;

int k;


struct node {
	vector<node*> c;
	vector<int> cnt;
	int ind;

	node() {
		c.assign(2, NULL);
		cnt.assign(2, 0);
	}

	void add(int x, int ind) {
		node* cur = this;
		for (int i = k - 1; i >= 0; i--) {
			int b = (x >> i) & 1;
			if (cur->c[b] == NULL) {
				cur->c[b] = new node();
			}
			cur->cnt[b]++;
			cur = cur->c[b];
		}
		cur->ind = ind;
	}

	int find(int x) {
		node* cur = this;
		bool same = true;
		for (int i = k - 1; i >= 0; i--) {
			//cout << x << " " << i << endl;
			int b = (x >> i) & 1;
			if (cur->cnt[b] > 1 || (!same && cur->cnt[b])) {
				cur = cur->c[b];
			} else {
				same = false;
				cur = cur->c[b ^ 1];
			}
		}
		assert(cur != NULL);
		//cout << "?" << endl;
		return cur->ind;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<int, int> m;
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (m.count(a[i])) {
				found = true;
				int i1 = i;
				int i2 = m[a[i]];
				int x = 0;
				for (int j = 0; j < k; j++) {
					if (!((a[i1] >> j) & 1)) {
						x += (1 << j);
					}
				}
				cout << i + 1 << " " << m[a[i]] + 1 << " " << x << endl;
				break;
			}
			m[a[i]] = i;
		}
		if (found) continue;
		
		node* trie = new node();
		for (int i = 0; i < n; i++) {
			trie->add(a[i], i);
		}
		//cout << "K" << endl;
		int best = 0;
		int i1 = 0;
		int i2 = 1;
		for (int i = 0; i < n; i++) {
			int ind = trie->find(a[i]);
			int mask = 0;
			for (int j = 0; j < 30; j++) {
				if (((a[i] >> j) & 1) == ((a[ind] >> j) & 1)) {
					mask += (1 << j);
				}
			}
			if (mask > best) {
				best = mask;
				i1 = i;
				i2 = ind;
			}
		}
		int x = 0;
		for (int i = 0; i < k; i++) {
			if (!((a[i1] >> i) & 1)) {
				x += (1 << i);
			}
		}
		cout << i1 + 1 << " " << i2 + 1 << " " << x << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
