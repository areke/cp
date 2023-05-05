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
	vector<trie*> next;
	bool term = false;

	trie() {
		next = {NULL, NULL};
		term = false;
	}

	void add(long long a) {
		long long p = 1;
		trie* cur = this;
		for (int i = 31; i >= 0; i--) {
			long long c = ((((long long)1) << i) & a) >> i;
			//cout << a << " " << i << " " << c << endl;
			trie* el = cur->next[c];
			if (el == NULL) {
				el = new trie();
			}
			cur->next[c] = el;
			cur = el;
		}
	}
};

long long solve(int s, int e, vector<long long> & a) {
	if (s > e) return 0;
	if (s == e) return a[s];
	int ind = (s + e) / 2;	
	long long res = solve(s, ind - 1, a);
	res = max(res, solve(ind + 1, e, a));
	trie* t = new trie();
	long long p = 0;
	t->add(p);
	for (int i = s; i < ind; i++) {
		p ^= a[i];
		//cout << p << endl;
		t->add(p);
	}
	p ^= a[ind];
	for (int i = ind; i <= e; i++) {
		p ^= a[i];
		long long m = ((long long)1 << 32) - 1;
		long long d = p ^ m;
		long long actual = 0;
		for (long long j = 31; j >= 0; j--) {
			actual *= 2;
			long long c = ((((long long)1) << j) & d) >> j;
			if (t->next[c] == NULL) {
				c ^= 1;
				//cout << "HUH" << endl;
			} else {
				//cout << "COOL" << endl;
			}
			assert(t->next[c] != NULL);
			t = t->next[c];
			//cout << j << " " << c << " " << m << " " << p << endl;
			actual += c;
			//cout << a[ind] << " " << c << endl;
		}
		//cout << actual << " " <<  a[ind] << endl;
		res = max(res, actual ^ p);
		//cout << s << " " << e << " " << i << " " << actual << " " << p << endl;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		trie cur;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << solve(0, n - 1, a) << endl;
		//cout << "----" << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
