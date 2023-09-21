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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, l;
		cin >> n >> l;
		vector<vector<int> > v(l);
		vector<int> cnt(n, 0);
		for (int i = 0; i < l; i++) {
			int k;
			cin >> k;
			v[i].resize(k);
			cout << i << endl;
			for (int j = 0; j < k; j++) {
				cout << j << " ";
				cin >> v[i][j];
				v[i][j]--;
				cnt[v[i][j]]++;
			}
			cout << endl;
		}
		int res = 0;
		for (int i = 0; i < l; i++) {
			bool need = false;
			for (int j = 0; j < v[i].size(); j++) {
				if (cnt[v[i][j]] == 1) {
					need = true;
				}
			}
			if (need) res++;
		}
		cout << "Case #" << test << ": " << res << endl;

	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
